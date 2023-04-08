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
        // Constructors
        Car();
        Car(const Car &c);
        Car(string repMark, int carNum, string kind, bool load, string dest);

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

        // Class specific function
        void output();
        void setUp(const string &mark, const int &num, const string &make, const bool &state, const string &dest);

        // Friend function for == operator
        friend bool operator == (const Car &first, const Car &second);

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

    Car car1(repMark, carNum, kind, load, dest);
    Car car2(car1);
    Car car3;

    cout << endl << "Contents of car1:" << endl;
    car1.Car::output();
    cout << "Contents of car2:" << endl;
    car2.Car::output();
    cout << "Contents of car3:" << endl;
    car3.Car::output();

    if (car1 == car2)
        cout << "car1 is the same car as car2\n";
    else
        cout << "car1 is not the same car as car2\n";
    if (car2 == car3)
        cout << "car2 is the same car as car3\n";
    else
        cout << "car2 is not the same car as car3\n";

    return 0;
}

/******************** Default constructor ********************
sets default values
*/
Car::Car() {
    reportingMark = "";
    carNumber = 0;
    carKind = "other";
    loaded = false;
    destination = "NONE";
}

/******************** Copy constructor ********************
takes values from another object
*/
Car::Car(const Car &c) {
    reportingMark = c.reportingMark;
    carNumber = c.carNumber;
    carKind = c.carKind;
    loaded = c.loaded;
    destination = c.destination;
}

/******************** constructor that accepts five constant reference parameters ********************
takes parameters and places them in object
*/
Car::Car(string repMark, int carNum, string kind, bool load, string dest) {
    setUp(repMark, carNum, kind, load, dest);
}

/******************** output ********************
print the data in a neat format
*/
void Car::output() {
    cout << "Reporting Mark:\t" << reportingMark << endl;
    cout << "Car Number:\t" << carNumber << endl;
    cout << "Kind:\t\t" << carKind << endl;
    cout << "Loaded:\t\t";
    if (loaded)
        cout << "true" << endl;
    else cout << "false" << endl;
        cout << "Destination:\t" << destination << endl << endl;
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

/******************** function operator == ********************
tests to see if two objects are equivalent
*/
bool operator == (const Car &first, const Car &second) {
    if ((first.reportingMark == second.reportingMark) && (first.carNumber == second.carNumber))
        return true;
    else
        return false;
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
