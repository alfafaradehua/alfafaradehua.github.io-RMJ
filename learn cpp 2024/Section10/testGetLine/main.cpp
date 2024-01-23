#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void main(){
    string name{""};
    /*
    cin >> name;
    cout << name;
    */
    getline(cin,name);
    cout << name;
}