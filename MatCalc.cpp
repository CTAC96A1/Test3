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




void DelMatrix(int** m, int n)
{
    for (int i = 0; i < n; i++)
        delete[] m[i];
    delete[] m;
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

    return 0;
}
