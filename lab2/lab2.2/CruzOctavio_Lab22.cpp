/*
Octavio Cruz
winter 2017
Lab 2
Problem 2.1
Description of problem:
Introduction to structures
Structures to classes
Introduction to classes
Object oriented design
*/

#include<iostream>
#include<string>
using namespace std;

class Car
{
   public:
   char reportingMark[5];
   int carNumber;
   char kind[5];
   bool loaded;
   char destination[50];

   void input()
   {
       int i=0;
       cout << "Enter Reporting Mark: ";
       cin >> this->reportingMark;

       cout << "Enter Car Number: ";
       cin >> this->carNumber;

       cout << "Enter Car Kind (box, tank, flat, or other): ";
       cin >> this->kind;

       cout << "Is the car loaded? Enter 1 for yes and 0 for no: ";
       cin >> i;

       if(i==0)this->loaded=false; else this->loaded=true;

       cout << "Enter Destination: ";
       cin >> this->destination;



   }
   void output()
   {


       cout << "Mark: "<< this->reportingMark<<endl;


       cout <<"Number: "<< this->carNumber<<endl;


       cout << "Kind: "<< this->kind<<endl;


       if(this->loaded) cout <<"Loaded\n"; else cout<<"Not Loaded\n";

       cout<<"Dest: "<< this->destination<<endl;



   }
};
int main()
{
   Car *santro=new Car();

   santro->input();
   santro->output();


}
