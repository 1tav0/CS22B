#include <iostream>
#include <string>
#include <fstream> // std::ifstream
#include <iomanip>
using namespace std;
/* ********* Class Car *************
********************************* */
class Car
{
private:
string reportingMark;
int carNumber;
string kind;
bool loaded;
string destination;
public:
Car()
{
reportingMark = "";
carNumber = 0;
kind = "Others";
loaded = 0;
destination = "NONE";
}
//copy constructor
Car(Car &car)
{
reportingMark = car.reportingMark;
carNumber = car.carNumber;
kind = car.kind;
loaded = car.loaded;
destination = car.destination;
}
~Car()
{
}


/* ************* Function output ************
show all results of the program
******************************************* */
void output()
{
string strLoaded;
if (loaded==true)
{
strLoaded = "TRUE";
}
else
{
strLoaded = "FALSE";
}
cout << fixed << left << setw(18) << "Reporting Mark" << reportingMark << endl;
cout << fixed << left << setw(18) << "Car Number" << carNumber << endl;
cout << fixed << left << setw(18) << "Kind" << kind << endl;
cout << fixed << left << setw(18) << "Loaded" << strLoaded << endl;
cout << fixed << left << setw(18) << "Destination" << destination << endl;
cout << endl;
}

void setUp(string &r, int &c , string &k, bool &l, string &d)
{
reportingMark =r;
carNumber = c;
kind = k;
loaded = l;
destination = d;
}

friend bool operator== (const Car &c1, const Car &c2);
};

bool operator== (const Car &c1, const Car &c2)
{
return (c1.reportingMark== c2.reportingMark &&
c1.carNumber == c2.carNumber );
}

void input();

//*********** Main **************
int main()
{
string reportingMark;
int carNumber;
string kind;
bool loaded;
string destination;
input ();

Car car1;
car1.setUp(reportingMark,carNumber, kind, loaded, destination);
cout<<"Contents of car1:"<<endl;
car1.output();

//copy constructor
Car car2=car1;
//call output funciton
cout<<"Contents of car1:"<<endl;
car2.output();
//default constructor
Car car3;
cout<<"Contents of car1:"<<endl;
//call output funciton
car3.output();

if (car1 == car2)
cout<< "car1 is the same car as car2\n";
else
cout<< "car1 is not the same car as car2\n";
if (car2 == car3)
cout<< "car2 is the same car as car3\n";
else
cout<< "car2 is not the same car as car3\n";

return 0;
}
/* ************ Function Input **************
Collect the data
****************************************** */
void input()
{
string type;
string reportingMark;
int carNumber;
string kind;
bool loaded;
string destination;

std::ifstream inputFile ("input.txt");

if (inputFile.is_open())
{
while(inputFile.peek() != EOF)
{
inputFile >> type >> reportingMark >> carNumber >> kind >> loaded >> destination;
Car temp(string reportingMark, int carNumber, string kind, bool loaded);
}
}

else
{
// show message:
std::cout << "Error opening file";
return ;
}

inputFile.close();

/*
int len;
string choice;
cout<< "Enter reportingMark with 5 or less upper case characters: ";
getline(cin, reportingMark);
len= reportingMark.length();
while (len > 5)
{
cout<< "invalid! Enter reportingMark with 5 or less upper case characters: ";
getline(cin, reportingMark);
len= reportingMark.length();
}
cout<< "Enter Car Number: ";
cin>> carNumber;
cout << "Enter kind of car: ";
cin>> kind;
do
{
cout<<"Enter the loaded only true or false:";
cin>>choice;
if (choice == "true")
{
loaded = true;
}
else if (choice == "false")
{
loaded = false;
}
else
{
cout<<"error!"<<endl;
}
}
while (choice != "true" && choice != "false");

if(loaded==true)
{
cout<<"Entre the destination:";
cin.ignore();
getline(cin,destination);
}
if(loaded ==false)
{
destination = "NONE";
}

Car temp(string reportingMark, int carNumber, string kind, bool loaded);
*/

}
