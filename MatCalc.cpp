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
    cout << "Заполните матрицу " << s << ":\n";
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
            cout << m[i][j] << " ";
        cout << "\n";
    }
}



void DelMatrix(int** m, int n)
{
    for (int i = 0; i < n; i++)
        delete[] m[i];
    delete[] m;
}


void SubsMatrix(int** A, int** B, int** buff, int n)
{

}



void TestSub()
{
    int n = 3;
    int** M1 = CreateMatrix(n);
    int** M2 = CreateMatrix(n);
    int** b = CreateMatrix(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M1[i][j] = i + j;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M2[i][j] = i + j;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = -1;

    SubsMatrix(&(*M1), &(*M2), &(*b), n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (b[i][j] != 0)
            {
                cout << "\nОшибка, неверно вычтена матрица\n";
                DelMatrix(&(*M1), n);
                DelMatrix(&(*M2), n);
                DelMatrix(&(*b), n);
                return;
            }
    cout << "\nФункция сработала успешно\n";
    DelMatrix(&(*M1), n);
    DelMatrix(&(*M2), n);
    DelMatrix(&(*b), n);
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

    int** mbuff = CreateMatrix(N);
    cout << "\nРазность матриц 1 и 2\n";
    SubsMatrix(&(*m1), &(*m2), &(*mbuff), N);
    ShowMatrix(&(*mbuff), N);

    TestSub();

    DelMatrix(&(*m1), N);
    DelMatrix(&(*m2), N);

    return 0;
}
