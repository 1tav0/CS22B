
#include
#include
#include
#include
using namespace std;


/* *************** Class Car **************** */
class Car
{
    private:
        static const int FIELD_WIDTH = 22;
        std::string reportingMark;
        int carNumber;
        std::string kind;
        bool loaded;
        std::string destination;

    public:
        /* ******* default constructor ***** */
        Car()
        {
            setUp(reportingMark = "", carNumber = 0, kind = "other", loaded = false, destination ="NONE");
        }


        /* *** copy constructor ************ */
        Car(const Car &userCar)
        {
            setUp(userCar.reportingMark, userCar.carNumber, userCar.kind, userCar.loaded, userCar.destination);
        }


        /* *** input constructor *********** */
        Car(std::string reportingMark, int carNumber, std::string kind, bool loaded, std::string destination)
        {
        setUp(reportingMark, carNumber, kind, loaded, destination);
        }


        /* ******* destructor ************* */
        ~Car(){};


        /* ************** Output *****************
        -Prints Data to the console by calling
         the object
        */
        void output()
        {
        std::cout << std::setw(FIELD_WIDTH) << std::left << "Reporting Mark: " << std::setw(FIELD_WIDTH) << reportingMark << std::endl;
        std::cout << std::setw(FIELD_WIDTH) << "Car Number: "<< std::setw(FIELD_WIDTH) << carNumber<< std::endl;
        std::cout << std::setw(FIELD_WIDTH) << "Kind: "<< std::setw(FIELD_WIDTH) << kind<< std::endl;
        std::cout << std::setw(FIELD_WIDTH) << "Loaded: "<< std::setw(FIELD_WIDTH);
            if(loaded)
            {
                std::cout << "true" << std::endl;
            }
            else
            {
                std::cout << "false" << std::endl;
            }
        std::cout << std::setw(FIELD_WIDTH) << "Destination: "<< std::setw(FIELD_WIDTH) << destination<< std::endl;
        std::cout << std::endl;
        }

        /* ************ setUp ***********************
        -takes in information given by the user
        -it then stores the information in the car
        objects variables
        */
        void setUp(std::string reportingMark, int carNumber, std:: string kind, bool loaded, std::string destination)
        {
            this->reportingMark = reportingMark;
            this->carNumber = carNumber;
            this->kind = kind;
            this->loaded = loaded;
            this->destination = destination;
        }


        /* ************ Operator= ***********************
        -overload member function that returns the
         left hand operator by reference
        */
        Car & operator=(const Car & carB)
        {
            reportingMark= carB.reportingMark;
            carNumber = carB.carNumber;
            kind = carB.kind;
            loaded = carB.loaded;
            destination = carB.destination;
            return * this;
        }

    friend bool operator == (const Car &car1, const Car &car2);
};


/* *************** Class StringOfCar **************** */
class StringOfCars
{
    private:
        Car *ptr;
        static const int ARRAY_SIZE = 10;
        int carCount;
    public:
    /* ******* default constructor ***** */
    StringOfCars()
    {
        ptr = new Car[ARRAY_SIZE];
        carCount = 0;
    }


    /* *** copy constructor ************ */
    StringOfCars(const StringOfCars &obj)
    {
        ptr = new Car[ARRAY_SIZE];
        for(int i = 0; i > ARRAY_SIZE; i++)
        {
            ptr[i] = obj.ptr[i];
            carCount = obj.carCount;
        }
    }


    /* ******* destructor ************* */
    ~StringOfCars(){delete []ptr;}


    /* ******************** output ********************
    prints the cars inside the string of cars along with its heading.
    */
    void output()
    {
        if(carCount == 0)
        {
            std::cout << "NO Cars!" << std::endl;
        }
        else
        {
            for(int i = 0; i < carCount; i++)
            {
                std::cout << "Car Number " << i + 1 << std::endl;
                ptr[i].output();
            }
        }
    }


    /* ******************** push ********************
    adds a car to the string of cars
    */
    void push(Car &obj)
    {
        if(carCount < ARRAY_SIZE)
        {
            ptr[carCount] = obj;
            carCount++;
        }
        else
        {
            std::cout << "StringOfCars is full!" << std::endl;
        }
    }

    /* ******************** pop ********************
    removes a car from the string of cars, Last in First Out.
    */
    void pop(Car &obj)
    {
        if(carCount > 0)
        {
            obj = ptr[carCount - 1];
            carCount--;
        }
        else
        {
            std::cout << "StringOfCars is empty!" << std::endl;
        }
    }

};


/* ***************** operator == *****************
-tests for equality between two Car objects based
on the input for variables reportingMark and carNumber
*/
bool operator == (const Car &car1, const Car &car2)
{
    if(car1.reportingMark == car2.reportingMark && car1.carNumber == car2.carNumber)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/* ******************** input ********************
-takes the carType, reportingMark, carNumber, kind, loaded
and destination from file
-Pushes car data to String Of Cars
*/
void input(StringOfCars &carArray)
     {
         string carType;
         string reportingMark;
         int carNumber;
         string kind;
         bool loaded;
         string destination;
         ifstream inputFile;
         inputFile.open("carData.txt");
         if (inputFile.fail())
             {
                 cout << "ERROR: Cannot open the file. \n";
                 exit(-1);
             }
         while(inputFile.peek() != EOF)
             {
                 inputFile >> carType;
                 inputFile >> reportingMark;
                 inputFile >> carNumber;
                 inputFile >> kind;
                 inputFile >> boolalpha >> loaded;
                 while(inputFile.peek() == ' ')
                 inputFile.get();
                 getline(inputFile, destination);
                 if(carType == "Car")
                     {
                         Car temp(reportingMark, carNumber, kind, loaded, destination);
                         carArray.push(temp);
                     }
                 else
                     {cout << "Error";}
                 inputFile.clear();
                 }

        inputFile.close();
     }

void input(StringOfCars&carArray);


/* *************************************************End of Global Area*************************************************** */


/* **************** Main ******************* */
int main()
{
    cout << "TEST 1" << endl << endl;
    Car car1("SP", 34567, "Business", true, "Salt Lake City");
    Car car2;
    car2 = car1;
    car2.output();
    cout << endl << endl << "TEST 2" << endl << endl << "STRING 1";
    StringOfCars string1;
    input(string1);
    string1.output();
    cout << endl << endl << "TEST 3" << endl << endl;
    Car car3;
    cout << "CAR 3" << endl << endl;
    string1.pop(car3);
    car3.output();
    cout << endl << "STRING 1" << endl;
    string1.output();
}
