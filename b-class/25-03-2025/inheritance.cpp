#include <iostream>

using namespace std;

class Vehicle {
  string type;
  int horsePower;
 
protected:
    int wheelsCount;

public:
    Vehicle() {
        cout << "In Vehicle Default constructor" << endl;
        type = "";
        horsePower = 0;
    }
    
    Vehicle(string type, int horsePower)
    : type(type), horsePower(horsePower) {
        cout << "In Vehicle Custom constructor" << endl;
    }
    
    
    Vehicle(const Vehicle& vehicle)
    : Vehicle(vehicle.getType(), vehicle.horsePower) {
        cout << "In Vehicle Copy constructor" << endl;
    }
    
    Vehicle& operator=(const Vehicle& vehicle) {
        cout << "In Vehicle operator=" << endl;
        if (this != &vehicle) {
            this->type = vehicle.getType();
            setHorsePower(vehicle.getHorsePower());
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

class Car : public Vehicle {
public:
    Car() {
        cout << "In Car Default constructor" << endl;
        wheelsCount = 10;
    }
    
    Car(int wheelsCount) {
        cout << "In Car Custom constructor" << endl;
        this->wheelsCount = wheelsCount;
    }
    
    Car(string type, int horsePower, int wheelsCount) : Vehicle(type, horsePower) {
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
            
            this->wheelsCount = car.getWheelsCount();
        }
        
        return *this;
    }
    
    ~Car() {
        cout << "In Car destructor" << endl;
    }
};

int main() {

    Car* c = new Car();
    cout << c->getWheelsCount() << endl;
    cout << c->getHorsePower() << endl;
    
    Car* c1 = new Car(4);
    cout << c1->getWheelsCount() << endl;
    cout << c1->getHorsePower() << endl;
    
    Car* c2 = new Car("Car", 120, 4);
    cout << c2->getWheelsCount() << endl;
    cout << c2->getHorsePower() << endl;
    cout << c2->getType() << endl;
    
    Car* c3 = new Car(*c2);
    cout << c3->getWheelsCount() << endl;
    cout << c3->getHorsePower() << endl;
    cout << c3->getType() << endl;
    
    *c1 = *c3; 
    cout << c1->getWheelsCount() << endl;
    cout << c1->getHorsePower() << endl;
    
    delete c3;
    return 0;
}