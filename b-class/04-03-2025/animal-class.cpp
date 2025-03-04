#include <iostream>

using namespace std;

struct animal_t {
    int age;
    char* name;
};

// snake_case, camelCase, kebap-case

class Test {};

class Animal {
// Encapsulation - private, public, protected
    int age;
    string name;

public: 
    // Default constuctor
    Animal() {
        cout << "In Animal default constuctor" << endl;
        age = 1;
        name = "Test";
    }
    
    // Custom constructor
    Animal(int age, string name) {
        cout << "In Animal custom constuctor" << endl;
        this->age = age;
        this->name = name;
    }
    
    // Destructor
    ~Animal() {
        // Delete all memory used by class
        // delete [] name;
        cout << "In Animal destructor" << endl;
    }
    
    // Method
    void printInfo() {
        cout << "Age: " << getAge() << ", Name: " << this->getName() << endl;
    }
    
    // Getters
    int getAge() {
        return age;
    }
    
    string getName() {
        return name;
    }
    
    // Setters
    void setAge(int age) {
        this->age = age;
    }
    
    void setName(string name) {
        this->name = name;
    }
    
};

int main() {
    // Stack objects
    Animal a1;
    a1.printInfo();
    
    Animal a(10, "Ally");
    a.printInfo();
    
    // Heap object
    // Class Animal, object animal, instance of the class
    Animal* animal = new Animal(10, "Sally");
    animal->printInfo();
    
    delete animal;
    
    return 0;
}