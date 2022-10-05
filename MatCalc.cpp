// MatCalc.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int** CreateMatrix(int n)
{
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];
    return matrix;
}



void FillMatrix(int** m, int n, int s)
{
    cout << "Заполните матрицу " <<s<<":\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
}



void ShowMatrix(int** m, int n)
{
    cout << "\nВаша матрица:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << m[i][j]<<" ";
        cout << "\n";
    }
}



void Get_matr(int** matr, int n, int** temp_matr, int indRow, int indCol)
{
    int ki = 0;
    for (int i = 0; i < n; i++) {
        if (i != indRow) {
            for (int j = 0, kj = 0; j < n; j++) {
                if (j != indCol) {
                    temp_matr[ki][kj] = matr[i][j];
                    kj++;
                }
            }
            ki++;
        }
    }
}



int Det(int** matr, int n)
{
    int temp = 0;   
    int k = 1;      
    if (n < 1) {
        cout << "Не верный размер матрицы!!!" << endl;
        return 0;
    }
    else if (n == 1)
        temp = matr[0][0];
    else if (n == 2)
        temp = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1];
    else {
        for (int i = 0; i < n; i++) {
            int m = n - 1;
            int** temp_matr = new int* [m];
            for (int j = 0; j < m; j++)
                temp_matr[j] = new int[m];
            Get_matr(matr, n, temp_matr, 0, i);
            temp = temp + k * matr[0][i] * Det(temp_matr, m);
            k = -k;
        }
    }
    return temp;
}




void DelMatrix(int** m, int n)
{
    for (int i = 0; i < n; i++)
        delete[] m[i];
    delete[] m;
}


void MultMatrix(int** A, int** B, int** buff, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            buff[i][j] = 0;
            for (int k = 0; k < n; k++)
                buff[i][j] += A[i][k] * B[k][j];
        }
    }
}



void TestDet()
{
    int n = 3;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = i + j;
    int det = Det(&(*matrix), n);
    if (det != 0)
        cout << "\nОшибка, неверно посчитан определитель\n";
    else
        cout << "\nФункция сработала верно\n";
}


int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int N;
    cout << "Введите размер матрицы\n";
    cin >> N;
    int** m1 = CreateMatrix(N);
    FillMatrix(&(*m1), N, 1);
    ShowMatrix(&(*m1), N);

    int** m2 = CreateMatrix(N);
    FillMatrix(&(*m2), N, 2);
    ShowMatrix(&(*m2), N);

    TestDet();

    cout << "\nПеремножение матриц 1 и 2\n";
    int** mbuff = CreateMatrix(N);
    MultMatrix(&(*m1), &(*m2), &(*mbuff), N);
    ShowMatrix(&(*mbuff), N);


    DelMatrix(&(*m1), N);
    DelMatrix(&(*m2), N);
    DelMatrix(&(*mbuff), N);

    return 0;
}
