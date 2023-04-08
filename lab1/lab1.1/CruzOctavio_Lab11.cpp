/*
Octavio Cruz
Winter 2017
Lab 1
Problem 1.1.0
Description of problem:
working with new, delete, and string class
*/


/* ******************** getSize ********************
asks user for size
size saved in calling function via reference parameter
*/
#include <iostream>
#include <string>
using namespace std;
void getSize(int&);
void getSpace(int, string*);
void inputData(int, string*);
void printData(string* , int);
void Destroy(string*);
int main()
{
int sizeOfString;
string ptrSpace;
getSize(sizeOfString);
getSpace(sizeOfString, &ptrSpace);
inputData(sizeOfString, &ptrSpace);
printData(&ptrSpace, sizeOfString);
Destroy(&ptrSpace);
}

/*********** getSize ************
Ask user to input how many strings
they want.
*/

void getSize(int &sizeOfString)
{
cout << "how many strings do you want? ";
cin >> sizeOfString;
}

/*********** getSpace ************
gets an array in heap of the size
requested by the user
*/

void getSpace(int sizeOfString, string *ptrSpace)
{
ptrSpace  = new string[sizeOfString];
}

/*********** inputData ************
Allow users to input string values
and store them in the array
*/

void inputData(int sizeOfString, string *space)
{
cout << "now put the string you want : ";
string data;
for (int i = 0; i < sizeOfString; i++)
{
cin >> data;
cout << data << endl;
space[i] = data;
cout << space[i];
}
}
/*********** printData ************
Print out all the strings
One string per line
*/


void printData( string *space, int sizeOfString)
{
for (int i = 0; i < sizeOfString; i ++)
{
cout << space[i] << endl;
}
}
void Destroy(string *space)
{
delete [] space;
}
