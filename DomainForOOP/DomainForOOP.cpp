// Description of domain: Here descripted some classes of Deposit and Client, that i can use in some bank system
// I can expend logic of deposit and client using inheritance in the future (for example, VIPDeposite+VIPClient)
// Using friendship i can expend operations with my classes
// Using MoveSemantic i can use rvalues in constructor

// inheritance - deposite+VIPDeposite, DefaultClient+Client
// friendship - BankOperation+Deposite+Client
// MoveSemantic - Client

#include <iostream>
#include <string>
using namespace std;

class BankOperation;


class Deposite
{
    
    
protected:
    friend class DepositeOperation;
    int _id;         // id of deposite
    int _profileId;  // id of client profile
    double _balance; // balance of deposite
    float _rate;     // percent rate of deposite
    
public:
    
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

class DefaultClient{
    
protected:
    int _id;
    string _name;

public:
    DefaultClient(int id, string name)
    {
        _id = id;
        _name = name;
    }
};

class Client : DefaultClient
{
    friend class DepositeOperation;
    
public:
    Deposite *_deposite;
    
    Client(int id, string name) : DefaultClient(id,name)
    {
        _deposite = new Deposite(id,id,3);
    }
    ~Client()
    {
        delete _deposite;
    }
    Client(Client &&clientForMove) : DefaultClient(clientForMove._id, clientForMove._name)
    {
        this->_deposite = clientForMove._deposite;
        clientForMove._deposite = nullptr;
    }
};

static class DepositeOperation
{
public:
    static void PutOnDeposite(Client &client, double sum)
    {
        client._deposite->_balance+=sum;
    }
    
    // return true if operation is success
    static bool WithdrawFromDeposite(Client &client, double sum)
    {
        if((client._deposite->_balance-sum) < 0)
            return false;
        client._deposite->_balance-=sum;
        return true;
    }
};



Client CreateClient()
{
    Client client(1,"Client");
    return client;
}

int main(int argc, char* argv[])
{
    Deposite defaultDep(12,2,3);
    VIPDeposite vip(4,5,6);
    
    Client user(13, "Alex");

    DepositeOperation::PutOnDeposite(user, 100);
    DepositeOperation::WithdrawFromDeposite(user, 5);
    user._deposite->Display();

    // example with rvalue
    Client user2(CreateClient());
    user2._deposite->Display();
    return 0;
}
