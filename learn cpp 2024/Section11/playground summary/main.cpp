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
int add_two_numbers (int a,int b);

void hello_world();


int main()
{
    cout << add_two_numbers(1,1) <<endl;
        double num {};

    cout << "Enter a number (double) : ";
    cin >> num;
    
    cout << "The sqrt of " << num << " is: " << sqrt(num) << endl;
    cout << "The cubed root of " << num << " is: " << cbrt(num) << endl;
    
    cout << "The sine of " << num << " is: " << sin(num) << endl;
    cout << "The cosine of " << num << " is: " << cos(num) << endl;
    
    cout << "The ceil of " << num << " is: " << ceil(num) << endl;
    cout << "The floor of " << num << " is: " << floor(num) << endl;
    cout << "The round of " << num << " is: " << round(num) << endl;

    
    double power {};
    cout << "\nEnter a power to raise " << num << " to: ";
    cin >> power;
    cout << num << " raised to the " << power << " power is: " << pow(num, power) << endl;
    
    cout <<  endl;
    hello_world();
    hello_world();
    hello_world();
    cout << "after installing platformIO";
    return 0;
}

int add_two_numbers (int a,int b)
{
    int sum(0);
    sum = a + b;
    return sum;
}

void hello_world()
{
    cout << "Hello world! after installing platformIO" << endl;
}
