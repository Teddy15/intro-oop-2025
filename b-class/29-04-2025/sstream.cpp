#include <iostream>
#include <sstream>

using namespace std;

class Account {
protected:
    double* withdraws;
    int numberOfWithdraws;
    double* deposits;
    int numberOfDeposits;
    static int numberOfActiveAccounts;
public:
    Account() {
        numberOfWithdraws = 1;
        numberOfDeposits = 1;
        withdraws = new double[1];
        deposits = new double[1];
        numberOfActiveAccounts++;
    }

    Account(double *withdraws, size_t numberOfWithdraws, double *deposits, size_t numberOfDeposits) {
        if (numberOfDeposits < 0 || numberOfWithdraws < 0) {
            throw invalid_argument("Invalid number of withdraws/deposits");
        }
        
        if (withdraws == nullptr || deposits == nullptr) {
            throw invalid_argument("Invalid number of withdraws/deposits");
        }
        
        this->numberOfWithdraws = numberOfWithdraws;
        this->numberOfDeposits = numberOfDeposits;
        
        this->deposits = new double[numberOfDeposits];
        this->withdraws = new double[numberOfWithdraws];
        
        for (int i = 0; i < this->numberOfDeposits; i++) {
            this->deposits[i] = deposits[i];
        }
        
        for (int i = 0; i < this->numberOfWithdraws; i++) {
            this->withdraws[i] = withdraws[i];
        }
        
        numberOfActiveAccounts++;
    }

    Account(const Account &other) 
    : Account(other.withdraws, other.numberOfWithdraws, other.deposits, other.numberOfDeposits) {}

    Account &operator=(const Account &other) {
        if (this != &other) {
            delete [] deposits;
            delete [] withdraws; 
            
            numberOfWithdraws = other.numberOfWithdraws;
            numberOfDeposits = other.numberOfDeposits;
            
            deposits = new double[numberOfDeposits];
            withdraws = new double[numberOfWithdraws];
            
            for (int i = 0; i < numberOfDeposits; i++) {
                deposits[i] = other.deposits[i];
            }
            
            for (int i = 0; i < numberOfWithdraws; i++) {
                withdraws[i] = other.withdraws[i];
            }
        }
        
        return *this;
    }

    static int getActiveAccounts() {
        return numberOfActiveAccounts;
    }

    double getBalance() const {
        double sum = 0.0;
        
        for (int i = 0; i < numberOfDeposits; i++) {
            sum += deposits[i];
        }
            
        for (int i = 0; i < numberOfWithdraws; i++) {
            sum -= withdraws[i];
        }
        
        return sum;
    }

    void printAccountInformation() const {
        cout << getBalance() << " " << numberOfDeposits << " " << numberOfWithdraws << endl;
    }
    
    ~Account() {
        delete [] deposits;
        delete [] withdraws;
        numberOfActiveAccounts--;
    }
};

int Account::numberOfActiveAccounts = 0;

class BankAccount : public Account {
    string iban;
    string accountHolder;

public:
    BankAccount(const string &IBAN, const string &accountHolder) {
        if (IBAN == "" || accountHolder == "") {
            throw invalid_argument("BankAccount info is invalid!");
        }
        
        iban = IBAN;
        this->accountHolder = accountHolder;
    }

    BankAccount(const BankAccount &other) : Account(other) {
        iban = other.iban;
        accountHolder = other.accountHolder;
    }

    BankAccount &operator=(const BankAccount &other) {
        if (this != &other) {
            Account::operator=(other);
            
            iban = other.iban;
            accountHolder = other.accountHolder;
        }
        
        return *this;
    }

    void printAccountInformation() const {
        cout << iban << " " << accountHolder << " " << getBalance() << " " << numberOfDeposits << " " << numberOfWithdraws << endl;
    }
};


int main() {
    Account a;
    Account* a1 = new Account(new double[]{100,200}, 2, new double[]{100, 100}, 2);
    Account* a2 = new Account(*a1);
        
    cout << a1->getActiveAccounts() << endl;

    a2->printAccountInformation();
    
    delete a1;
    
    cout << a2->getActiveAccounts() << endl;

    delete a2;
    
    cout << a.getActiveAccounts() << endl;
    
    //stringstream
    string test = "I like apples, 10 20 bananas";
    stringstream ss(test);
    
    string f, s, t;
    int number;    
    ss >> f >> s >> t;
    ss >> number;
    
    cout << f << " " << s << " " << t << " " << number << endl;
    
    string input;
    cin >> input;
    getline(cin, input);
    
    stringstream ss1(input);
    string word;
    while (ss1 >> word) {
        cout << word << endl;
    }
    
    getline(cin, input, ',');
    stringstream ss2(input);
    
    while (ss2 >> word) {
        cout << word << endl;
    }
    
    return 0;
}