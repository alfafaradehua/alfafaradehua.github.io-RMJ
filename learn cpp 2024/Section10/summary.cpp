#include <iostream>
#include <vector>
#include <string>

#include <iomanip>

using namespace std;

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
    string name{""};
    cout << name << endl;
    string name2{"bryan"};
    cout << name2 << endl;
    string name3{name};
    cout << name3 << endl;
    string name4{"bryan", 3};
    cout << name4 << endl;
    string name5{name2, 1, 4};
    cout << name5 << endl;
    string name6(3, 'B');
    cout << name6 << endl;
    string firstname{"Bryan"};
    string lastname{"Alfafara"};
    string fullname = firstname + " " + lastname;
    cout << fullname << endl;
    string compoundAssignmentFullname = firstname;
    compoundAssignmentFullname += " ";
    compoundAssignmentFullname += lastname;
    cout << compoundAssignmentFullname << endl;

    cout << fullname.substr(0,5) << endl;
    cout << fullname.substr(6,8) << endl;
    cout << fullname.find("ryan") << endl;
    cout << fullname.rfind("ryan") << endl;
    cout << fullname.find("enr") << endl;
    if (fullname.find("enr")==string::npos)
        cout << fullname.find("enr") << " is actually string::npos for this os" << endl;
    if (fullname.find("enr")!=string::npos)
        cout << fullname.find("enr") << " is not string::npos for this os... i dunno whats goin on \"enr\" doesnt exist in string" << endl;
    cout << fullname.erase(0,1) << endl;
    fullname.clear();
    cout << "cleared fullname is " << fullname << endl;
    fullname = firstname + " " + lastname;
    cout << "using .length()" << endl;
    for (int i{0}; i < fullname.length(); ++i)
        cout << fullname.at(i) << endl;
    cout << "using .size()" << endl;
    for (int i{0}; i < fullname.length(); ++i)
        cout << fullname.at(i) << endl;

    string nameTestRangeFor2{"Yanyan"};
    cout << "using range for loop with inde as an int" << endl;
    for (int i : nameTestRangeFor2)
        cout << i << endl;
    cout << "using range for loop with inde as a char" << endl;
    for (char i : nameTestRangeFor2)
        cout << i << endl;
    string wholeLineStringThatsAName{""};
    cout << "enter your whole name man" << endl;
    getline(cin,wholeLineStringThatsAName);
    cout << wholeLineStringThatsAName << endl;
    cout << "enter your whole name man. make sure there is an lower case character \"a\" in there so i can ignore everything after it mwhahahaha" << endl;
    getline(cin,wholeLineStringThatsAName,'a');
    cout << wholeLineStringThatsAName << endl;
    return 0;
}