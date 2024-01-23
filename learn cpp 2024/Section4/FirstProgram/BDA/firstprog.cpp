#include <iostream>
#include <Windows.h>

int main ()
{
    int favnum;
    std::cout <<"Gimme a num between 1 and 100" <<std::endl;
    std::cin >> favnum;
    std::cout << favnum << " is a good choice man" <<std::endl;
    if (favnum == 24)
    {
        std::cout <<"Thats my favorite number" <<std::endl;
    }
    if (favnum != 24)
    {
        std::cout <<"24 is my favorite though" <<std::endl;
    }
    Sleep(1000);
    return 0;
}