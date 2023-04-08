
/*
Octavio Cruz
Winter 2017
Lab 1
Problem 1.2.1-1.2.6
working with strings
*/
#include <iostream>
#include <string>
#include <cstring>


using namespace std;


int main() {
    const int SIZE = 100;


    /* ******************** 1.2.1 ********************
    Read a string from the user into a string named string1
    */
    char string1[SIZE];
    cout << "Enter a string:" << endl;
    cin.getline(string1, SIZE);
    cout << "Exercise 1" << endl;
    cout << string1 << endl << endl;

    /* ******************** 1.2.2 ********************
    Create a new string named string2 containing the contents from string1.
    Append the following text to the end of string 2.
     sleepy heads
    */
    string string2(string1);
    string2.append(" sleepy heads");
    cout << "Exercise 2" << endl;
    cout << string2 << endl << endl;

    /* ******************** 1.2.3 ********************
    Create string3 with an initial value of:
    bellow cello fellow hello mellow Novello Othello pillow Rollo solo yellow
    Find the location of the first h in string3
    */
    string string3("bellow cello fellow hello mellow Novello Othello pillow Rollo solo yellow ");
    int pos = string3.find("h");
    cout << "Exercise 3" << endl;
    cout << pos << endl << endl;

    /* ******************** 1.2.4 ********************
    Create an empty string named string4.
    Copy string3 into string4.
    Using the location found in exercise 3,
    change the first h into J
    */
    string string4;
    string4.assign(string3);
    string4.replace(20, 1, 1,'j');
    cout << "Exercise 4" << endl;
    cout << string4 << endl << endl;

    /* ******************** 1.2.5 ********************
    Create a copy of string3 named string5.
    Use the find_last_of member function to find the position of the last  l
    */
    string string5(string3);
    int pos2 = string5.find_last_of('l');
    cout << "Exercise 5" << endl;
    cout << pos2-1 << endl << endl;

    /* ******************** 1.2.6 ********************
    Create a new string named string6 containing the contents from string3.
    Using the position of the last  l found in exercise 5, erase all
    characters from string6 following the last  l
    */
    string string6(string3);
    string6.erase(70,5);
    cout << "Exercise 6" << endl;
    cout << string6;

}
