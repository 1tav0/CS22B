/*
Octavio Cruz
winter 2017
Lab 3
Problem 3.1
Description of problem:
Introduction to structures
Structures to classes
Introduction to classes
Object oriented design
*/
#include <iostream>
#include <string>

using namespace std;

// Class Declaration
class Car {
   private:
       string reportingMark;
       int carNumber;
       string carKind;
       bool loaded;
       string destination;

   public:
       // Constructor
       Car() {
           reportingMark = "None";
           carNumber = 0;
           carKind = "None";
           loaded = false;
           destination = "None";
       }

       // Destructor
       ~Car() { };

       // Mutator member functions
       void setReportingMark(string repMark) {
           reportingMark = repMark;
       };
       void setCarNumber(int carNum){
           carNumber = carNum;
       };
       void setKind(string kind){
           carKind = kind;
       };
       void setLoaded(bool load){
           loaded = load;
       };
       void setDestination(string dest){
           destination = dest;
       };

       // Accessor member functions
       string getReportingMark() const {
           return reportingMark;
       };
       int getCarNumber() const {
           return carNumber;
       };
       string getKind() const {
           return carKind;
       };
       bool getLoaded() const {
           return loaded;
       };
       string getDestination() const {
           return destination;
       };

       // Class specific functions
       void output();
       void setUp(const string &mark, const int &num, const string &make, const bool &state, const string &dest);

}; // end class Car

// input prototype
void input(string &repMark, int &carNum, string &kind, bool &load, string &dest);

/******************** Main ********************/
int main() {

   string repMark;
   int carNum;
   string kind;
   bool  load;
   string dest;

   input(repMark, carNum, kind, load, dest);

   Car car1;
   car1.Car::setUp(repMark, carNum, kind, load, dest);
   car1.Car::output();

   return 0;
}

/******************** output ********************
print the data in a neat format
*/
void Car::output() {
   cout << endl;
   cout << "Reporting Mark:\t" << reportingMark << endl;
   cout << "Car Number:\t" << carNumber << endl;
   cout << "Kind:\t\t" << carKind << endl;
   cout << "Loaded:\t\t";
   if (loaded)
       cout << "true" << endl;
   else cout << "false" << endl;
       cout << "Destination:\t" << destination << endl;
}

/******************** setUp ********************
creates an object using a constructor that takes the reference parameters
pointer to the object c1 returned.
*/
void Car::setUp(const string &repMark, const int &carNum, const string &kind, const bool &load, const string &dest) {
   reportingMark = repMark;
   carNumber = carNum;
   carKind = kind;
   loaded = load;
   destination = dest;
};

/******************** input ********************
reads all the data from the user
after all the data has been read, puts all this data into the object
*/
void input(string &repMark, int &carNum, string &kind, bool &load, string &dest) {

   cout << "Enter the reporting mark: " << endl;
   cin >> repMark;
   cout << "Enter the car number" << endl;
   cin >> carNum;
   cout << "Enter the kind of car (box, tank, flat, or other):" << endl;
   cin >> kind;
   cout << "Is the car loaded? Enter 'true' if loaded, or 'false' if not loaded:" << endl;
   cin >> boolalpha >> load;
   if (load) {
       cout << "Enter the destination:" << endl;
       cin.ignore();
       getline(cin, dest);
   } else
       dest = "NONE";
}


