
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
// Косилов А., вариант 7
//Дана матрица размером NxM. Упорядочить ее строки по возрастанию их первых элементов.

template<size_t countColumns> void SwapLine(int A[][countColumns], int pos1, int pos2)
{
    for(int i = 0; i < countColumns; i++)
    {
        int t = (A)[pos1][i];   
        A[pos1][i] = A[pos2][i];
        A[pos2][i] = t;
    }
}

int main(int argc, char* argv[])
{
    const int MIN_VALUE = -5; // максимальное значение элементов матрицы
    const int MAX_VALUE = 5; // минимальное значение

    const int constN = 4;// заданный размер матрицы n
    const int constM = 4;// заданный размер матрицы m

    srand(time(NULL));
    int A[constN][constM];
    for (int i = 0; i < constN; i++)
        for (int j = 0; j < constM; j++)
        {
            // взять случайное число
            A[i][j] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
        }

    //  Вывести массив A до сортировки
    cout << endl << "Array A:" << endl;
    for (int i = 0; i < constN; i++)
    {
        for (int j = 0; j < constM; j++)
            cout << A[i][j] << '\t';
        cout << endl;
    }

    // Сортировка в лоб
    for(int i = 0; i < constN; i++)
    {
        for(int j = i; j < constN; j++)
        {
            if(A[i][0] > A[j][0])
            {
                SwapLine<constM>(A,i,j);    
            }
        }
    }
    
    // Вывод для проверки
    cout << endl << "Array A:" << endl;
    for (int i = 0; i < constN; i++)
    {
        for (int j = 0; j < constM; j++)
            cout << A[i][j] << '\t';
        cout << endl;
    }
    
    return 0;
}
