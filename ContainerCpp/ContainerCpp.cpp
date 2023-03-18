// ContainerCpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iterator>
#include <cstddef>
#include <string>
using namespace std;

struct User
{
    private:
        string Login;
        string Password;
};

struct Iterator
{
    using iterator_category = std::forward_iterator_tag;
    //using difference_type = std::ptrdiff_t; хз зачем эт
    using value_type = int;
    using pointer = int*;
    using reference = int&;

    Iterator(pointer ptr) : m_ptr(ptr) {}
    
    Iterator(Iterator& iterator) : Iterator{ iterator.m_ptr } { }

    Iterator(Iterator&& iterator) : Iterator {iterator.m_ptr}
    {
        iterator.m_ptr = nullptr;
    }

    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }
    pointer operator+(int countPlus) { return m_ptr+countPlus; }
    Iterator& operator++() { m_ptr++; return *this; }
    Iterator& operator--() { m_ptr--; return *this; }
    Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
    Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }
    /*friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };*/
    bool operator== (const Iterator& b) { return m_ptr == b.m_ptr; };
    bool operator!= (const Iterator& b) { return m_ptr != b.m_ptr; };
    private:
     pointer m_ptr;
};

class Numbers
{
    public:
        Iterator begin() { return Iterator(&dataArray[0]); }
        Iterator end() { return Iterator(&dataArray[10]); }

    private:
        int dataArray[10] = {1,2,3,4,5,6,7,8,9,10};

};


int main()
{
  /*  std::cout << "Hello World!\n";
    Numbers integers;
    
    cout << "tens element is " << *(integers.begin()+9) << " " << endl;
    for (auto i : integers)
        std::cout << i << "\n";*/

    int a = 1;
    int b = 4;
    Iterator first = Iterator(&a);
    Iterator second = Iterator(&a);
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
