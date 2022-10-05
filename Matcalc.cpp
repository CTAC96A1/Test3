// test3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

void SummMatrix(int** A, int** B, int** buff, int n)
{
    //for (int i = 0; i < n; i++)
      //  for (int j = 0; j < n; j++)
        //    buff[i][j] = A[i][j] + B[i][j];
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

    cout << "\nСложение матриц 1 и 2\n";
    SummMatrix(&(*m1), &(*m2), &(*mbuff), N);
    ShowMatrix(&(*mbuff), N);
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
