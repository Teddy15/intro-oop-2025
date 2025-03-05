#include <iostream>

using namespace std;

typedef struct vector_t {
    int size;
    int capacity;
    int* array;
} vector_t;

class Animal {
// Encapsulation - private, public, protected
    int age;
    string name;
    // vector_t** vector;
    
    // Custom constructor - overloaded custom constructor, just for example
    Animal(string name, int age) {
        cout << "In Custom constructor" << endl;
        // this->age = age;
        // this->name = name;
        setAge(age);
        setName(name);
    }
    
public: 
    // Default constructor
    Animal() {
        cout << "In default constructor" << endl;
        age = 0;
        name = "test";
    }
    
    // Custom constructor
    Animal(int age, string name) {
        cout << "In Custom constructor" << endl;
        // this->age = age;
        // this->name = name;
        setAge(age);
        setName(name);
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

    int foo(int a) {
        return a;
    }
    
    int foo(int b, int a) {
        return a  + b;
    }

    void printInfo() {
        cout << "Age: " << getAge() << ", Name: " << getName() << endl;
    }
    
    ~Animal() {
        cout << "In Destructor" << endl;
    }
};

int main() {
    Animal a1;
    a1.printInfo();
    
    Animal a(10, "Ally");
    a.setAge(20);
    a.setName("Sally");
    
    a.printInfo();
    cout << a.getName() << endl;
    
    Animal* a2 = new Animal();
    a2->printInfo();
    delete a2;
    
    return 0;
}