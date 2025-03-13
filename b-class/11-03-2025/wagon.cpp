#include <iostream>
#include <cstring>

using namespace std;

class Wagon {
    int horsePower;
    char* licencePlate;
    int wheelsCount;
public:
    Wagon() {
        cout << "In default constructor " <<  endl;
        horsePower = 1;
        licencePlate = new char[1];
        licencePlate[0] = '-'; 
        wheelsCount = 2;
    }
    
    Wagon(int horsePower, char* licencePlate, int wheelsCount) 
    : horsePower(horsePower), wheelsCount(wheelsCount) {
        
        this->licencePlate = new char[strlen(licencePlate) + 1];
        setLicencePlate(licencePlate);
    }
    
    // Copy constructor (Deep copy)
    Wagon(const Wagon& wagon) {
        cout << "In copy constructor" << endl;
        this->horsePower = wagon.horsePower;
        this->wheelsCount = wagon.wheelsCount;
        this->licencePlate = new char[strlen(wagon.licencePlate)];
        strcpy(this->licencePlate, wagon.licencePlate);
    }
    
    Wagon& operator=(const Wagon& wagon) {
        cout << "In operator=" << endl;
        
        if (&wagon != this) {
            this->horsePower = wagon.horsePower;
            this->wheelsCount = wagon.wheelsCount;
        
            delete [] licencePlate;

            this->licencePlate = new char[strlen(wagon.licencePlate)+1];
            strcpy(this->licencePlate, wagon.licencePlate);
        } 

        return *this;
    }
    
    int getHorsePower() {
        return horsePower;
    }
    
    void setHorsePower(int horsePower) {
        this->horsePower = horsePower;
    }
    
    int getWheelsCount() {
        return wheelsCount;
    }
    
    void setWheelsCount(int wheelsCount) {
        this->wheelsCount = wheelsCount;
    }
    
    char* getLicencePlate() {
        return licencePlate;
    }
    
    void setLicencePlate(char* licencePlate) {
         this->licencePlate = licencePlate;
        strcpy(this->licencePlate, licencePlate);
    }
    
    ~Wagon() {
        cout << "In Destructor" << endl;
    }
};

// Shallow vs Deep copy
int main() {
    Wagon* w = new Wagon(120, "СВ0000АХ", 4);
    cout << w->getLicencePlate()  << " "  << w  << endl;

    Wagon* w1 = new Wagon();
    cout << w1->getLicencePlate()  << " "  << w1  << endl;
    
    Wagon* w2 = new Wagon(*w1);
    cout << w2->getLicencePlate()  << " "  << w2  << endl;
    
    // Shallow copy if operator= is not overriden in Wagon
    //Shallow copy again because we are using pointers instead of references to the object
    // Wagon* w3 = new Wagon(); 
    // w3 = w;
    
    //Deep copy using overriden operator=
    Wagon* w3 = new Wagon(); 
    *w3 = *w;
    cout << w3->getLicencePlate()  << " "  << w3  << endl;

    delete w;
    return 0;
}