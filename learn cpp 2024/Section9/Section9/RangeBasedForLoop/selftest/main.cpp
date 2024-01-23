#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(){
    /*
    int ssn [] {7,3,1,1,4,8,4,1,8};
    cout << ssn << endl;
    for (auto i: ssn){
        cout << i;
    }
    cout << endl;
    double average_sibling_age {0};
    vector <double> sibling_age {35, 34, 33, 31,29};
    for (auto i:sibling_age){
        cout << i <<" ";
        average_sibling_age += i;
    }
    average_sibling_age = average_sibling_age / sibling_age.size();
    cout << endl << average_sibling_age << endl;

    // create for loop to replace characters in a string
    string input_string{"BryanyyYY"};
    for (char c: input_string){
        if (c == 'Y'){
            cout << 'I';
        }
        else if (c == 'y'){
            cout << 'i';
        }
        else{
            cout << c;
        }
    }
    cout << endl;
    */
    vector <int> vec{};
    bool done {false};
    int index {0};
    int count {0};
    while (!done){
        if ((vec[index] == -99)||index >= vec.size())
            done = true;
        else 
            count++;
        index++;
    }
    cout << count;
    return 0;
}