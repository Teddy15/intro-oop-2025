#include <iostream>

using namespace std;

// private, public, protected
class Vehicle {
    string type;
    int horsePower;
protected:
    int wheelsCount;
public:
    Vehicle() {
        cout << "In Vehicle Default constructor" << endl;
        type = "_";
        horsePower = 0;
    }
    
    Vehicle(string type, int horsePower) 
    : type(type), horsePower(horsePower) {
        cout << "In Vehicle Custom constructor" << endl;
    }
    
    Vehicle(const Vehicle& vehicle)
    : Vehicle(vehicle.getType(), vehicle.getHorsePower()){
        cout << "In Vehicle Copy constructor" << endl;
    }
    
    Vehicle& operator=(const Vehicle& vehicle) {
        cout << "In Vehicle operator=" << endl;
        if (this != &vehicle) {
            setType(vehicle.type);
            setHorsePower(vehicle.horsePower);
        }
        
        return *this;
    } 

    string getType() const {
        return type;
    }
    
    void setType(string type) {
        this->type = type;
    }
    
    int getHorsePower() const {
        return horsePower;
    }
    
    void setHorsePower(int horsePower) {
        this->horsePower = horsePower;
    }
    
    int getWheelsCount() const {
        return wheelsCount;
    }
    
    ~Vehicle() {
        cout << "In Vehicle destructor" << endl;
    }
};

class Test {
protected:
    bool tested;
public:

    Test() {
        cout << "In Test default constructor" << endl;
    }
    
    bool isTested() const {
        return tested;
    }
};


// TODO Try changing public here to private
class Car : public Vehicle, public Test {
public:
    Car() {
        cout << "In Car Default constructor" << endl;
        wheelsCount = 1;
        tested = true;
    }
    
    Car(int wheelsCount) {
        cout << "In Car Custom constructor" << endl;
        this->wheelsCount = wheelsCount;
    }
    
    Car(string type, int horsePower, int wheelsCount)
    : Vehicle(type, horsePower) {
        cout << "In Car Second Custom constructor" << endl;
        this->wheelsCount = wheelsCount;
    }
    
    Car(const Car& car) : Vehicle(car) {
        cout << "In Car Copy constructor" << endl;
        this->wheelsCount = car.getWheelsCount();
    }
    
    Car& operator=(const Car& car) {
        cout << "In Car operator=" << endl;
        if (this != &car) {
            Vehicle::operator=(car);
            this->wheelsCount = car.wheelsCount;
        }
        
        return *this;
    }
    
    ~Car() {
        cout << "In Car destructor" << endl;
    }
};

int main() {
    Test t;
    cout << t.isTested() << endl;
    Car* c = new Car();
    cout << c->getWheelsCount() << endl;
    cout << c->isTested() << endl;
    
    Car* c1 = new Car(2);
    cout << c1->getWheelsCount() << endl;
    
    Car* c2 = new Car("Car", 120, 4);
    cout << c2->getWheelsCount() << endl;
    
    delete c2;
    
    Car* c3 = new Car(*c1);
    cout << c3->getWheelsCount() << endl;
    
    Car* c4 = new Car();
    *c4 = *c3;
    cout << c4->getWheelsCount() << endl;
    return 0;
}