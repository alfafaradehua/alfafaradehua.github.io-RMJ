/*
Declaring, Initializing and Accessing Vectors
Declare a vector of integers named vec  and initialize the vector to 10,20,30,40, and 50 

Modify the first element of the vector to be 100  and modify the last element of the vector to be 1000 .

The final vector should then be 100, 20, 30, 40, and 1000.

You can find my solution by clicking on the solution.txt file on the left pane.
 But please make sure you give it a go yourself first, and only check the solution if you really get stuck.

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //----WRITE YOUR CODE BELOW THIS LINE----
    vector <int> vec {10,20,30,40,50};
    vec.at(0)=100;
    vec.at(vec.size()-1)=1000;
    cout << vec.at(0) <<" " << vec.at(4) << endl << vec.size();
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----NO NOT MODIFY THE CODE BELOW THIS LINE----
    return 0;
}