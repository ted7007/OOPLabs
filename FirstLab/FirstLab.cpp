
#include <iostream>

int main(int argc, char* argv[])
{
    double res = 0,
    sumRes = 0,
    sumHelper1=1.0/9,
    sumHelper2,
    x=0,
    n=0;
    std::cout << "Enter n and x (numbers)";
    //todo validation input data
    std::cin >> n >> x;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad entry.  Enter a NUMBERS: ";
        std::cin >> n >> x;
    }
    res += 4*x;
    for(int k = 1; k <= n; k++)
    {
        sumHelper1*=9;
        sumRes+=1.0/((2*k-1)*sumHelper1);
    }
    res += 2.0/3 *  sumRes;

    std::cout << std::endl << "res : " << res << std::endl;
    return 0;
}
