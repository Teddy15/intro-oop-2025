#include <iostream>
#include <cstring>
#include <exception>
#include <string>
#include <sstream>

using namespace std;

class Registry {
protected:
    char* registryName;
    string* records;
    size_t numberOfRecords;
    static int numberOfActiveRegistries;
public:
    Registry() {
        registryName = new char[1];
        //registryName[0] = ' ';
        
        records = new string[2];
        numberOfRecords = 2;
        numberOfActiveRegistries++;
    }

    Registry(const char *registryName, const string *records, size_t numberOfRecords) {
        if (records == nullptr || registryName == nullptr) {
            throw invalid_argument("Invalid input data for records/registryName");
        }
        
        if (numberOfRecords <= 0) {
            throw invalid_argument("Invalid input data for numberOfRecords ");
        }
        
        this->numberOfRecords = numberOfRecords;
        
        this->records = new string[numberOfRecords];
        for (int i = 0; i < numberOfRecords; i++) {
            this->records[i] = records[i];
        }
        
        this->registryName = new char[strlen(registryName) + 1];
        strcpy(this->registryName, registryName);
        
        numberOfActiveRegistries++;
    }

    Registry(const Registry &other) 
    : Registry(other.registryName, other.records, other.numberOfRecords) {}

    ~Registry() {
        delete [] registryName;
        delete [] records;
        
        numberOfActiveRegistries--;
    }

    Registry& operator=(const Registry &other) {
        if (this != &other) {
            delete [] registryName;
            delete [] records;
            
            numberOfRecords = other.numberOfRecords;
        
            records = new string[numberOfRecords];
            for (int i = 0; i < numberOfRecords; i++) {
                records[i] = other.records[i];
            }
        
            registryName = new char[strlen(other.registryName) + 1];
            strcpy(registryName, other.registryName);
        }
        
        return *this;
    }

    static int getActiveRegistries() {
        return numberOfActiveRegistries;
    }

    void printRegistryInformation() const {
        cout << registryName << endl;
        for (int i = 0; i < numberOfRecords; i++) {
            cout << records[i] << endl;
        }
    }
};

int Registry::numberOfActiveRegistries = 0;

class PhoneRegistry : public Registry {
    string* phoneNumbers;
    size_t numberOfPhoneNumbers;
public:
    PhoneRegistry(const char *registryName, const string *records, size_t numberOfRecords, const string *phoneNumbers, size_t numberOfPhoneNumbers)
    : Registry(registryName, records, numberOfRecords) {
        if (phoneNumbers == nullptr || numberOfPhoneNumbers <= 0) {
            throw invalid_argument("Invalid input data for phoneNumbers / numberOfPhoneNumbers");
        }
        
        this->numberOfPhoneNumbers = numberOfPhoneNumbers;
        this->phoneNumbers = new string[numberOfPhoneNumbers];
        for (int i = 0; i < numberOfPhoneNumbers; i++) {
            this->phoneNumbers[i] = phoneNumbers[i];
        }
    }

    PhoneRegistry(const PhoneRegistry &other)
    : Registry(other) {
        this->numberOfPhoneNumbers = other.numberOfPhoneNumbers;
        
        this->phoneNumbers = new string[other.numberOfPhoneNumbers];
        for (int i = 0; i < other.numberOfPhoneNumbers; i++) {
            this->phoneNumbers[i] = other.phoneNumbers[i];
        }
    }

    ~PhoneRegistry() {
        delete [] phoneNumbers;
    }

    PhoneRegistry &operator=(const PhoneRegistry &other) {
        if (this != &other) {
            Registry::operator=(other);
            
            delete [] phoneNumbers;
            
            this->numberOfPhoneNumbers = other.numberOfPhoneNumbers;
        
            this->phoneNumbers = new string[other.numberOfPhoneNumbers];
            for (int i = 0; i < other.numberOfPhoneNumbers; i++) {
                this->phoneNumbers[i] = other.phoneNumbers[i];
            }
        }
        
        return *this;
    }

    void printRegistryInformation() const {
        Registry::printRegistryInformation();
        for (int i = 0; i < numberOfPhoneNumbers; i++) {
            cout << phoneNumbers[i] << endl;
        }
    }
};

int main() {
    Registry* r = new Registry();
    Registry* r1 = new Registry(new char[3]{'t', 'e', 't'}, new string[2]{"record1", "record2"}, 2);
    cout << r->getActiveRegistries() << endl;
    delete r;
    cout << r1->getActiveRegistries() << endl;
    
    Registry* r2 = new Registry(*r1);
    r2->printRegistryInformation();
    
    PhoneRegistry* ph = new PhoneRegistry(new char[3]{'t', 'e', 't'}, new string[2]{"record1", "record2"}, 2, new string[2]{"u238238", "2932939"}, 2);
    ph->printRegistryInformation();
    
    delete r2;
    delete ph;
    delete r1;
    
    string s1 = "I like 10";
    stringstream ss(s1);
    
    string f, s;
    int t;
    ss >> f >> s >> t;

    cout << f << " " <<  s << " " << t + 5 <<  endl;
    
    //cin >> f;
    
    getline(cin, s1);
    stringstream ss1(s1);
    string word;
    while(ss1 >> word) {
        cout << word << endl;
    }
    
    return 0;
}