#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account {
private:
    // attributes
    std::string name;
    double balance;
    
public:
    // methods
    // declared inline
    void set_balance(double bal) { balance = bal; }
    double get_balance() { return balance; }
    
    // methods will be declared outside the class declaration
    void set_name(std::string n);
    std::string get_name();
    
    bool deposit(double amount);
    bool withdraw(double amount);
    // constructors
    Account(){
        name = "";
        balance = 0.0;
    }
};

#endif // _ACCOUNT_H_

/*
Starting build...
cmd /c chcp 65001>nul && cl.exe /Zi /EHsc /nologo "/FeC:\Users\alfaf\alfafaradehua.github.io\learn cpp 2024\Section13\ImplementingMethods2\main.exe" /std:c++20 "C:\Users\alfaf\alfafaradehua.github.io\learn cpp 2024\Section13\ImplementingMethods2\main.cpp"
main.cpp
main.obj : error LNK2019: unresolved external symbol "public: void __thiscall Account::set_name(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)" (?set_name@Account@@QAEXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z) referenced in function _main
main.obj : error LNK2019: unresolved external symbol "public: bool __thiscall Account::deposit(double)" (?deposit@Account@@QAE_NN@Z) referenced in function _main
main.obj : error LNK2019: unresolved external symbol "public: bool __thiscall Account::withdraw(double)" (?withdraw@Account@@QAE_NN@Z) referenced in function _main
C:\Users\alfaf\alfafaradehua.github.io\learn cpp 2024\Section13\ImplementingMethods2\main.exe : fatal error LNK1120: 3 unresolved externals
*/