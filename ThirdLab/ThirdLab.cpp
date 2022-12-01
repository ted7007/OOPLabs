#include <fstream>
#include <string>
#include <iostream>
#include <windows.h>

struct Notebook
{
    struct Size
    { 
       float x;
       float y;
       float z;
    };
    std::string model; // наименование
    float Weight; // вес 
    float HDD; // вместимость hdd в мб
    int Price; // ценаstruct
    Size size;
    
    
};

/*
 
Для хранения данных о ноутбуках описать структуру вида, описанного в варианте 10.

Написать функцию, которая читает данные о ноутбуках из файла note.txt в структуру приведенного вида.
Структура note.txt: первые 4 байта (целое) — число записей в файле; далее записи в формате структуры NOTEBOOK.

Написать функцию, которая записывает содержимое структуры в конец бинарного файла.
Структура бинарного файла: первые 4 байта (целое) — число записей в файле; далее записи в формате структуры NOTEBOOK.

Написать программу, в которой на основе разработанных функций осуществляется чтение данных только для тех ноутбуков,
объем HDD которых меньше 1 Гбайт, и запись считанных данных в бинарный файл в алфавитном порядке по наименованию.
*/

std::ostream& operator<<(std::ostream& os, const Notebook::Size& data)
{
    return os << "{" << data.x << ";" << data.y << ";" << data.z << "}";
}

std::istream& operator>>(std::istream& is, Notebook::Size& data)
{
    char c, c2;
    std::string otl;
    if(!(is >> c && c == '{'))                      // начинается с '{'
    {
        is.setstate(std::ios_base::failbit);
        return is;
    }
    is >> data.x;
    is.get(c);
    is >> data.y;
    is.get(c);
    is >> data.z;
    
    return is;
    
}

std::ostream& operator<<(std::ostream& os, const Notebook& data)
{
    return os << "{" << data.model << ";" << data.Weight << ";" << data.HDD << ";" << data.Price << ";" << data.size << "}"; 
}

std::istream& operator>>(std::istream& is, Notebook& data)
{
    char c, c2;
    std::string otl;
    data.model = "";
    if(!(is >> c && c == '{'))                      // начинается с '{'
    {
        is.setstate(std::ios_base::failbit);
        return is;
    }
    
    int numberField = 0;
    
    while(is.get(c))                   
    {
        if(c == ';')
        {
            numberField++;
        }
        else if(c == '}')
        {
            break;
        }
        switch (numberField)
        {
        case 0:
            data.model+=c;        
            break;
        case 1:
            is >> data.Weight;
            break;
        case 2:
            is >> data.HDD;
            break;
        case 3:
            is >> data.Price;
            break;
        case 4:
            is >> data.size;
            break;
        }
    }
    is >> c;
    if(c!='}')
        is.setstate(std::ios_base::failbit);
    return is;
}

void WriteNotes(Notebook* notes, int count, std::string fileName)
{
    std::ofstream out(fileName, std::ios::binary|std::ios::out);
    out << count;
    for(int i = 0; i < count; i++)
        out << notes[i];
    out.close();
}

void ReadNotes(Notebook*& notes, int& count, std::string fileName)
{
    std::ifstream in(fileName, std::ios::binary|std::ios::in);
    in >> count;
    if(count == 0 || !in)
        return;
    notes = new Notebook[count];
    for(int i = 0; i < count; i++)
        in >> notes[i];
    in.close();
}

int main(int argc, char* argv[])
{
    
    // Notebook::Size size{1,2,3};
    // int count = 10; 
    // Notebook* array = new Notebook[count];
    //
    // for(int i = 0; i < count; i++)
    // {
    //     Notebook book{"Lenovo", 1221, 200*(float)i+1, 10, size};
    //     array[i] = book;
    // }
    // for(int i = 0; i < count; i++)
    //     std::cout << array[i] << std::endl;
    // WriteNotes(array, count, "note.txt") ;

    Notebook* array;
    int count = -1;
    ReadNotes(array, count, "note.txt");
    
    int needNotes = 0;
    for(int i = 0; i < count; i++)      // Подсчет ноутов с hd > 1024mb
        if(array[i].HDD >= 1024)
            needNotes++;
    
    if(needNotes == 0)
        return 0;
    int currentNodes = 0;
    Notebook* newArray = new Notebook[needNotes];       // считывание ноутов с hd > 1024mb
    for(int i = 0; i < count; i++)
        if(array[i].HDD >= 1024)
        {
            newArray[currentNodes] = array[i];
            currentNodes++;
        }
    
    if(needNotes>2)                                   // сортировка
        for (int i = 1; i < needNotes; ++i)
            for (int j = needNotes - 1; j >= i; --j)
                if (newArray[j-1].model > newArray[j].model) 
                {
                    Notebook tmp = newArray[j - 1];
                    newArray[j - 1] =newArray[j];
                    newArray[j] = tmp;
                }
    
    WriteNotes(newArray, needNotes, "data2.txt");
    return 1;
}

