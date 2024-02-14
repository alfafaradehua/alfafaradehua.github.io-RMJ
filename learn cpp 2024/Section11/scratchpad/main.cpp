#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;


//https://en.cppreference.com/w/cpp/header
//https://en.cppreference.com/w/cpp/header/cstdlib

void displayArray(int arr[], int size);
void setArray(int arr[], int size, int val);
void swapNumbers (int &a, int &b);
void displayVector(const vector <int> &vec);

int main()
{

    cout << "This program plays with functions and arrays" << endl;
    int array1[10];
    
    for (size_t i{0}; i < 10; i++)
    {
        array1[i] = i;
    }
    displayArray(array1,9);
    setArray(array1,9,10);
    displayArray(array1,9);
    setArray(array1,9,1);
    displayArray(array1,9);
    cout << endl << endl;
    int a{1234};
    int b{5678};
    cout << " a is " << a << " and b is " << b << endl;
    swapNumbers(a,b);
    cout << " a is " << a << " and b is " << b << endl;
    cout << endl << endl;
    vector <int> vec1{1,2,3,4,5,6};
    displayVector(vec1);
    int i1 {0};
    int i2 {0};
    int i3 {0};
    i1 = i2 = i3 = 1;

}

void displayArray(int arr[],int size)
{
    size_t arraySize {9};
    for (size_t i {0}; i <= arraySize; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void setArray(int arr[], int size , int val)
{
    size_t arraySize {9};
    for (size_t i {0}; i <= arraySize; i++ )
    {
        arr[i]= val;
    }
    cout << endl;
}

void swapNumbers (int &a, int &b)
{
    int tempA{a};
    int tempB{b};
    a = tempB;
    b = tempA;
}

void displayVector(const vector <int> &vec)
{
    for (size_t i{0}; i < vec.size(); i++)
    {
        cout << " value is " << vec.at(i) << " at location ";
        cout << i << endl;
    }
    cout << endl;
}