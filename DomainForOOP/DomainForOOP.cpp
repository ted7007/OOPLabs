// Насследование: дефолтный депозит, вип-депозит
// Дружба:  ClientProfile, Deposit
// Виртуальные функции чето с депозитом
// Move semantics                     

#include <iostream>
#include <string>
using namespace std;


class Deposite
{
public:
    int _id;         // id of deposite
    int _profileId;  // id of client profile
    double _balance; // balance of deposite
    float _rate;     // percent rate of deposite

    Deposite(int id, int profileId, float rate)
    {
        _id = id;
        _profileId= profileId;
        _balance= 0;
        _rate=rate;
    }
    
    virtual void Display() // method for write info about deposite in console
    {
        cout << "Display default deposite:" << endl
       << "Id:" << _id << "\tBalance:" << _balance << "\tRate:" << _rate << endl;
    }
};

class VIPDeposite : public Deposite
{
public:
    
    VIPDeposite(int id, int profileId, float rate) : Deposite(id,_profileId,rate)
    {
        _balance = 1000;
    }
    
    void GetSupport(string message)
    {
        cout << "[" << _id << "-Support]:" << message << endl;
    }
    
    void Display() override
    {
        cout << "Display VIP deposite:" << endl
        << "Id:" << _id << "\tBalance:" << _balance << "\tRate:" << _rate << endl;
    }
    
};


int main(int argc, char* argv[])
{
    Deposite dep1(2,5,7);
    VIPDeposite dep2(1,2,3);
    dep1.Display();
    dep2.Display();
    
    return 0;
}
