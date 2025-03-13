#include <iostream>
#include <cstring>

using namespace std;

// Shallow copy vs Deep copy
class Shadow {
    int length;
    double density;
    char* casterName;
public:
    // Getters, Setters, Default & Custom constructors
    // Destructor
    Shadow() {
        cout << "In default constructor" << endl;
        length = 1;
        density = 0.01;
        casterName = new char[1];
        casterName[0] = '-';
    }
    
    // Initializer list
    Shadow(int length, double density, char* casterName)
        : length(length), density(density) {
        cout << "In custom constructor" << endl;
        this->casterName = new char[strlen(casterName) + 1];
        strcpy(this->casterName, casterName);
    }
    
    // Copy constructor
    Shadow(const Shadow& shadow) 
    : Shadow(shadow.length, shadow.getDensity(), shadow.casterName) {
        cout << "In copy constructor" << endl;
        // this->length = shadow.getLength();
        // this->density = shadow.getDensity();
        // this->casterName = new char[strlen(shadow.casterName) + 1];
        // strcpy(this->casterName, shadow.casterName);
    }
    
    // Operator=
    Shadow& operator=(const Shadow& shadow) {
        cout << "In operator=" << endl;
        
        if (this != &shadow) {
            this->length = shadow.length;
            this->density = shadow.getDensity();
        
            delete [] this->casterName;
            this->casterName = new char[strlen(shadow.casterName) + 1];
            strcpy(this->casterName, shadow.casterName);
        }
        
        return *this;
    }
    
    int getLength() const {
        return length;
    }
    
    void setLength(int length) {
        this->length = length;
    }
    
    double getDensity() const {
        return density;
    }
    
    void setDensity(double density) {
        this->density = density;
    }
    
    char* getCasterName() const {
        return casterName;
    }
    
    void setCasterName(char* casterName) {
        strcpy(this->casterName, casterName);
    }
    
    ~Shadow() {
        cout << "In destructor" << endl;
    }
};

int main() {
    char* name = new char[5];
    strcpy(name, "Ivan");
    
    Shadow* s = new Shadow();
    Shadow* s1 = new Shadow(20, 0.3, name);
    
    *s = *s1; // s & s1 already exist

    cout << s->getCasterName() << " " << s << endl;
    cout << s1->getCasterName() << " " << s1 << endl;

    Shadow ss(10, 0.93, name);
    
    // Copy consructor
    Shadow* s2 = new Shadow(*s); // only s already exists and s2 is created by it
    cout << s2->getCasterName() << " " << s2 << endl;
    delete s;
    return 0;
}