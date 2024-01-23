#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(){
    vector <int> vec {1,2,3};

    for (auto val:vec){
     cout << val << " ";   
    }
    cout << endl;
    int result{0};
    unsigned i{0};
    for (auto val:vec){
        for (unsigned j{0};j<=(vec.size()-1);j++){
            if ((i != j) && (j > i)){
                result += val*vec[j];
                cout << val << " * " << vec[j] << endl;
                cout << "sum so far " << result <<endl;
            }
            else{
                cout << "skipping " << val << " * " << vec[j] << endl;
            }
        }
        i++;
    } 
    
    cout << "overall results is " << result;
}