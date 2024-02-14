#include <iostream>
#include <cmath>

#include <string>
#include <vector>
using namespace std;

//https://en.cppreference.com/w/cpp/header
//https://en.cppreference.com/w/cpp/header/cstdlib


using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
// function prototypes
int add_two_numbers (int a = 0,int b = 0);

int main()
{
    cout << add_two_numbers(1,1) <<endl;
    cout << add_two_numbers(1) <<endl;
    cout << add_two_numbers() <<endl;
    cout << add_two_numbers(0,3) <<endl;
}
int add_two_numbers (int a,int b)
{
    int sum(0);
    sum = a + b;
    return sum;
}