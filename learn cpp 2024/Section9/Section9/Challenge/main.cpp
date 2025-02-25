// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using namespace std;

int main() {
    bool done{false};
    vector <string> available_commands {"P - Print numbers", "A - Add a number", "M - Display mean of the numbers","S - Display the smallest number","L - Display the largest number","Q - Quit"};
    vector <int> stored_list {};
    while (!done){
        for (auto val: available_commands)
        cout << "\t" << val << endl;
        char input_command{' '};
        cin >> input_command;
        cout << "You have entered " << input_command << endl;
        switch (input_command){
            case 'p':
            case 'P':
            {
                cout << "[ ";
                for (int i:stored_list)
                { 
                    cout << i << " ";
                }
                cout << "]" << endl;
                if (stored_list.size()==0)
                    cout << " - the list is empty" << endl;
                break;
            }
            case 'a':
            case 'A':
            {
                int int_to_add{};
                cout << "Please enter an integer to add to the list." << endl;
                cin >> int_to_add;
                stored_list.push_back(int_to_add);
                cout << int_to_add << " added" <<endl;
                break;
            }
            case 'm':
            case 'M':
            {
                cout << "The mean or average of the list is ";
                if (stored_list.size()==0){
                    cout << "Unable to calculate the mean - no data" << endl;
                }
                double running_sum{0};
                for (int i:stored_list)
                { 
                    running_sum += i;
                }
                cout << (running_sum/stored_list.size()) << "." << endl;
                break;
            }
            case 's':
            case 'S':
            {
                int smallest_number{stored_list.at(0)};
                //cout << "list size is " << stored_list.size() << ". \n";
                if (stored_list.size()==0){
                    cout << "Unable to determine the smallest number - list is empty";
                }
                else { 
                    for (int i:stored_list)
                    { 
                        //cout << "comparing " << i << " and " << smallest_number << ". \n";
                        if (i < smallest_number){
                            smallest_number = i;
                        }
                    }
                
                    cout << "The smallest number is " << smallest_number << ". \n";
                }
                
                break;
            }
            case 'l':
            case 'L':
            {
                int largest_number{stored_list.at(0)};
                //cout << "list size is " << stored_list.size() << ". \n";
                if (stored_list.size()==0){
                    cout << "Unable to determine the largest number - list is empty";
                }
                else { 
                    for (int i:stored_list)
                    { 
                        //cout << "comparing " << i << " and " << largest_number << ". \n";
                        if (i > largest_number){
                            largest_number = i;
                        }
                    }
                
                    cout << "The largest number is " << largest_number << ". \n";
                }
                break;
            }
            case 'q':
            case 'Q':
            {
                done = true;
                cout << "goodbye!";
                break;
            }
            default:
                cout << "Unknown selection, please try again" << endl;
                break;
            
            }
    }
    return 0;
}

