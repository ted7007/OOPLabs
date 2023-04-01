﻿// ContainerCpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iterator>
#include <cstddef>
#include <string>
#include <vector>
using namespace std;

struct User
{
    private:
        string Login;
        string Password;
};

//legacy iterator
struct Iterator
{

public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t; 
    using value_type = int;
    using pointer = int*;
    using reference = int&;
    
    Iterator(pointer ptr) : m_ptr(ptr) {}
    
    // Destructible
    ~Iterator()
    {
        m_ptr = nullptr;
    }

    // copy constructable
    Iterator(const Iterator& iterator) { m_ptr = iterator.m_ptr; }

    // move constructible
    Iterator(Iterator&& iterator) : Iterator {iterator}
    {
        iterator.m_ptr = nullptr;
    }

    // move assignable
    Iterator& operator=(Iterator&& iterator) { m_ptr = iterator.m_ptr; iterator = nullptr; return *this; }

    // copy assignable
    Iterator& operator=(Iterator& iterator) { m_ptr = iterator.m_ptr; return *this; }


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

    //swapable
    void swap(Iterator& other) 
    {
        pointer tmp = m_ptr;
        m_ptr = other.m_ptr;
        other.m_ptr = tmp;
    }

    static void swap(Iterator& i1, Iterator& i2)
    {
        i1.swap(i2);
    }

private:
    pointer m_ptr;
    
};

//
class Numbers
{
public:
    using difference_type = std::ptrdiff_t;
    using value_type = int;
    using pointer = vector<int>*;
    using reference = int&;
    using size_type = unsigned int;

    Numbers()
    {

    }

    virtual ~Numbers() { dataArray.clear(); }

    Numbers(Numbers& c) : dataArray(c.dataArray)
    {

    }

    Numbers(Numbers&& c) : Numbers(c)
    {
    }

    // move assignable
    Numbers& operator=(Numbers&& container) { dataArray = container.dataArray;  return *this; }

    // copy assignable
    Numbers& operator=(Numbers& container) { dataArray = container.dataArray; return *this; }


    Iterator begin() noexcept { return Iterator(dataArray.data()); }

    Iterator end() noexcept { return Iterator(dataArray.data() + dataArray.size()); }

    bool operator== (const Numbers& b)
    {
        return std::equal(dataArray.begin(), dataArray.end(), b.dataArray.begin(), b.dataArray.end());
    };
    bool operator!= (const Numbers& b) 
    { 
        return !(*this == b);
    };


    void swap(Numbers& other)
    {
        vector<int> *tmp = &dataArray;
        dataArray = other.dataArray;
        other.dataArray = *tmp;
        tmp = nullptr;
    }

    static void swap(Numbers& i1, Numbers& i2)
    {
        i1.swap(i2);
    }

    size_type size()
    {
        return std::distance(begin(), end());
    }

    size_type maxSize()
    {
        return dataArray.max_size();
    }

    size_type empty()
    {
        return begin() == end();
    }
    
    private:
       vector<int> dataArray;

};


int main()
{
  /*  std::cout << "Hello World!\n";
    Numbers integers;
    
    cout << "tens element is " << *(integers.begin()+9) << " " << endl;
    for (auto i : integers)
        std::cout << i << "\n";*/

    Numbers n;
    
    n.~Numbers();
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