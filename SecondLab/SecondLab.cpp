// Косилов А., вариант 7
//Сформировать двумерный массив. Удалить из него строку и столбец, на пересечении которых находится минимальный элемент.

#include <iostream>

using namespace std;

bool Remove (int **arr, int *n,int*m, int posi, int posj)
{
 
    int *temp = new int[*n, *m];
    int dub;
    // 5 вариантов, строка 0 и (колонка 0 или не 0), или колонка 0 и строка не 0, или колонка/строка не 0.
    if(!posi)
    {
        if(posj)
            for(int i = 1; i < *n; i++)
            {
                for(int j = 0; j < posj; j++)   
                    temp[i-1,j] = (*arr)[i,j];
                for(int j = posj+1; j < *m; j++)
                    temp[i-1,j-1] = (*arr)[i,j];
            }
        else if (!posj)
            for(int i = 1; i < *n; i++)
                for(int j = 1; j < *m; j++)
                    temp[i-1, j-1] = (*arr)[i,j];
    }
    else if (!posj)
    {
        for(int i = 0; i < posi; i++)
        {
            for(int j = 1; j < *m; j++)   
                temp[i,j-1] = (*arr)[i,j];
        }
        for(int i = posi+1; i < *n; i++)
        {
            for(int j = 1; j < *m; j++)
                temp[i,j-1] = (*arr)[i,j];
        }
    }
    else
    {
        for (int i = 0; i<posi; i++)
            for (int j = 0; j<posj; j++)
            {
                dub = (*arr)[i,j];
                temp[i,j] = (*arr)[i,j];
            }
        for (int i = posi+1; i<*n; i++)
            for (int j = posj+1; j<*m; j++)
                temp[i-1,j-1] = (*arr)[i,j];
                  
    }

    // перезапись указателя
    delete [] (*arr);
    (*n)--;
    (*m)--;
    int debug;
    *arr = new int [*n, *m];
    for (int i = 0; i<*n; i++)
        for (int j = 0; j<*m; j++)
        {
            (*arr)[i,j] = temp[i,j];
            debug = (*arr)[i,j];
        }
    
    delete [] temp;
    return true;
}

int main(int argc, char* argv[])
{
    const int MAX_N = 10; // максимально-допустимая размерность матрицы
    const int MIN_VALUE = -5; // максимальное значение элементов матрицы
    const int MAX_VALUE = 5; // минимальное значение
    int* A; // исходная матрица
    int n; // текущий размер матрицы n
    int m; // текущий размер матрицы m

    // Ввод n
    cout << "n = ";
    cin >> n;
    cout << endl << "m = ";
    cin >> m;
    //  Проверка n на корректность
    if (n && ((n <= 1) || (n > MAX_N) || (m<=1) || (m>MAX_N)))
    {
        cout << "Wrong size of array." << endl;
        return 0;
    }
    A = new int[n,m];
    //  Формирование матрицы A случайных чисел,
    // установить генератор случайных чисел
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            // взять случайное число
            A[i,j] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
        }

    //  Вывести массив A для проверки
    cout << endl << "Array A:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << A[i,j] << '\t';
        cout << endl;
    }

    // поиск минимального элемента
     int min = MAX_VALUE;
     int iMin = -1, jMin = -1;
    
     for(int i = 0; i < n; i++)
     {
         for(int j = 0; j < m; j++)
         {
             if(A[i,j] < min)
             {
                 min = A[i,j];
                 iMin = i;
                 jMin = j;
             }
         }
     }
    
     if(iMin == -1)
     {
         cout << "Min isnt find";
         return 0;
     }
    
     Remove(&A, &n, &m, iMin, jMin);
    
     cout << endl << "Array A:" << endl;
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < m; j++)
             cout << A[i,j] << '\t';
         cout << endl;
     }
    

    
    return 0;
}
