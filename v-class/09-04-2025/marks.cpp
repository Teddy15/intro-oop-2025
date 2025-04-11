#include<iostream>

using namespace std;

class Marks {
    double* marks;
    int size;
    int capacity;
public:
    Marks() {
        cout << "In Marks default constructor" << endl;
        size = 0;
        capacity = 2;
        marks = new double[capacity];
    }

    Marks(double* marks, int size, int capacity) {
        cout << "In Marks custom constructor" << endl;
        this->marks = new double[capacity];
        for (int i = 0; i < size; i++) {
            this->marks[i] = marks[i];
        }
        
        this->size = size;
        this->capacity = capacity;
    }

    // Same as the one below but reusing existing code!
    // Marks(const Marks& object) : Marks(object.marks, object.size, object.capacity) {
    //     cout << "In Marks copy constructor" << endl;
    // }

    Marks(const Marks& object) {
        cout << "In Marks copy constructor" << endl;
        this->size = object.size;
        this->capacity = object.capacity;
        
        this->marks = new double[object.capacity];
        for (int i = 0; i < size; i++) {
            this->marks[i] = object.marks[i];
        }
    }

    Marks& operator=(const Marks& object) {
        if (this != &object) {
            this->size = object.size;
            this->capacity = object.capacity;
            
            delete [] marks;
            
            this->marks = new double[object.capacity];
            for (int i = 0; i < size; i++) {
                this->marks[i] = object.marks[i];
            }
        }
        
        return *this;
    }

    int getCapacity() const {
        return capacity;
    }
    
    int getSize() const {
        return size;
    }

    double* getMarks() const {
        return marks;
    }
    
    void printMarks() {
        for(int i = 0; i < size; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    ~Marks() {
        cout << "In Marks destructor" << endl;
        delete [] marks;
    }
};

class Person {
protected:
    string firstName;
    string lastName;
    int age;
	static int personCounter;
public:
    Person() {
        cout << "In Person default constructor" << endl;
        firstName = "nqkvopurvoime";
        lastName = "nqkvovtoroime";
        age = 10;
		personCounter++;
    }

    Person(string firstName, string lastName, int age) {
        cout << "In Person custom constructor" << endl;
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
		personCounter++;
    }

    Person(string firstName) {
        cout << "In Marks custom constructor 2" << endl;
        this->firstName = firstName;
		personCounter++;
    }

    string getFirstName() {
        return firstName;
    }
    
    string getLastName() {
        return lastName;
    }

    int getAge() {
        return age;
    }

    void printInfo() {
        cout << "FirstName: " << firstName << endl;
        cout << "LastName: " << lastName << endl;
        cout << "Age: " << age << endl;
    }

    ~Person() {
        cout << "In Person destructor" << endl;
		personCounter--;
    }
};

int Peron::personCounter = 0;

class Student : public Person {
    Marks* marks;
public:
    Student() {
        cout << "In Student default constructor" << endl;
        firstName = "Ivan";
        lastName = "Ivanov";
        age = 5;
        marks = new Marks();
    }

    Student(string firstName, string lastName, int age, Marks* marks) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->marks = new Marks(*marks);
    }
    
    double getAverageMark() const {
        double sum = 0;
        for(int i = 0; i < size; i++) {
            sum += this->marks[i];
        }
        return sum / (double) this->size;
    }

    void printInfo() {
        Person::printInfo();
        cout << "Marks: ";
        for (int i = 0; i < marks.getSize(); i++) {
            cout << marks.getMarks()[i] << " ";
        }
        cout << endl;
    }

    ~Student() {
        delete [] marks;
    }
};

int main() {

    return 0;
}