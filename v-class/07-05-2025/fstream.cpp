#include<iostream>
#include<fstream>
using namespace std;

class A {
    int x;
protected:
    string protectedX;
public:
    A() {
        x = 5;
        protectedX = "test";
    }

    int getX() {
        return x;
    }

    string getProtectedX() {
        return protectedX;
    }

    A(const A& a) {
        this->x = a.x;
        this->protectedX = a.protectedX;
    }

    A& operator=(const A& a) {
        if (this == &a) {
            return *this;
        }

        this->x = a.x;
        this->protectedX = a.protectedX;
        return *this;
    }

    // Friend method: can read/write private and protected data from/to the object given as an argument
    // Can de defined outside of the class
    friend istream& operator>>(istream& in, A& a);
    friend ostream& operator<<(ostream& out, A& A);
};

// Written like this, the operator >> can work both for cin, and for fstream/ifstream
istream& operator>>(istream& in, A& a) {
    in >> a.x >> a.protectedX;
    return in;
}

// Written like this, the operator << can work both for cin, and for fstream/ofstream
ostream& operator<<(ostream& out, A& a) {
    out << a.x << " " << a.protectedX << endl;
    return out;
}

int main() {
    // ifstream - Opens file only for reading - file mode is ios::in
    // ofstream - Opens file only for writing - file mode is ios::out, ios::app, ios::trunc
    // fstream - Opens file for reading and writing - file mode can be ios::in or ios::out, ios::app, ios::trunc

    // f.open("filename.txt", ios:in) - opens a file stream
    // f.close() - closes a file stream

    // ios::out - default mode for ofstream file streams, if the file does not exist, it creates it; 
    // opens the file, starts writing over the existing contents of the file from the beginning (top of the file) without deleting the whole file

    // ios::trunc - if the file does not exist, it creates it;
    // opens the file, deletes everything from the file, starts writing from the beginning (top of the file)

    // ios::app - if the file does not exist, it creates it;
    // opens the file, finds the last character in the file, starts writing new content after this character

    A* a = new A();
    A a1;
    
    fstream f("input.txt", ios::in);
    f >> a;
    f.close();
    cout << a;

    f.open("output.txt", ios::in | ios:: out | ios::app);
    f << a;
    f >> a;
    f.close();
    
    // cout << a;
    // cin >> a;
    // cout << a;

    fstream file("output.txt", ios::in);
    
    //Read until EOF
    string line;
    while(getline(file, line)) {
        cout << line << endl;
    }
    f.close();

    // ofstream file1("output.txt"); // notice how we do not need ios::out here
    // cin >> line;
    // file << line;

    // file1.close();
    return 0;
}