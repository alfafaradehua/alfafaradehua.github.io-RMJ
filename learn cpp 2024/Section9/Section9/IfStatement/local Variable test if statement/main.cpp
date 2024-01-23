#include <iostream>
#include <windows.h>
#include <string>
using std::cout;
using std::cin;
using std::endl;

int main(){
    int var{0};
    var = 1;
    cout << var;
    if (var == 0) {
        cout << "var is zero" << endl;
        int var_local{1};
        cout << var_local;
    }
    else{
        cout << "var is not zero";
    }
    //cout << var_local;
    cout << "test" << endl;
    cout << "test2" << endl;
    cout << "test3" << endl;
    Sleep(1000);
    for (int i = 0; i < 100; i++) {
        cout << "\n";
    }
    
    cout << "test4" << endl;
    Sleep(1000);
    int machu {0};
    cin >> machu;
    return 0;
}