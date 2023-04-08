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
struct Car
{
   char reportingMark[5];
   int carNumber;
   char kind[5];
   bool loaded;
   char destination[50];
};

void input(Car *santro);
void output(Car *santro);
int main()
{
   Car *santro=new Car();

   input(santro);
   output(santro);
}
void input(Car *santro)
{
   int i=0;
   cout << "Enter Reporting Mark: ";
   cin >> santro->reportingMark;

   cout << "Enter Car Number: ";
   cin >> santro->carNumber;

   cout << "Enter Car Kind (box, tank, flat, or other): ";
   cin >> santro->kind;

   cout << "is it loaded? Enter 1 for yes and 0 for no: ";
   cin >> i;

   if(i==0)santro->loaded=false; else santro->loaded=true;

   cout << "Enter Destination: ";
   cin >> santro->destination;



}
void output(Car *santro)
{


   cout << "Mark: "<<santro->reportingMark<<endl;


   cout <<"Number: "<< santro->carNumber<<endl;


   cout << "Kind: "<< santro->kind<<endl;


   if(santro->loaded) cout <<"Loaded\n"; else cout<<"Not Loaded\n";

   cout<<"Dest: "<< santro->destination<<endl;

}



