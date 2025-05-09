#include<iostream>

using namespace std;

string getCityValue (City city) {
    if (city == SOFIA) {
        return "sofia";
    } else if (city == PLOVDIV) {
        return "Plovdiv";
    } else if (city == BURGAS) {
        return "Burgas";
    }
}

// default index starting from 0
enum City {
    SOFIA, PLOVID, BURGAS
};

// Polymorphism and abstraction
// polymorphism - static & dynamic
class A {
protected:
    int a;
    City city = SOFIA;
public:
    // static polymorphism
    int foo(int x) {
        return x + 5;
    }

    // static polymorphism
    double foo(double x) {
        return x + 10;
    }

    // -------- Virtual methods enable the creation of the vtable and vpointer for the given class.
    // -------- This is what enables us to use the DYNAMIC polymorphism! 


    // dynamic polymorphism
    // dynamic polymorphism
    // not fully virtual method
    // not compulasary to be overriden in the Child classes
    // does not make the class abstract
    virtual void test() {
        cout << "In A test()" << endl;
    }

    // Here we have an example of both static polymorphism
    // and dynamic polymorphism
    // not fully virtual method
    // not compulasary to be overriden in the Child classes
    // does not make the class abstract
    virtual void test(int x) {
        cout << x << endl;
    }

    // dynamic polymorphism
    // fully virtual method
    // compulsary to be overriden in the Child classes!
    // makes the class abstract -> the class cannot be instantiated anymore
    virtual void testAgain() = 0;
};

class B : public A {
public:
    void printCity() {
        cout << city << endl;
    }

    void test() {
        cout << "In B test()" << endl;
    }

    void testAgain() {
        cout << "In B testAgain()" << endl;
    }
};

class C : public A {
public:
    void testAgain() {
        cout << "In C testAgain()" << endl;
    }
};

int main() {
    // A* a = new A();
    // cout << a->foo(10) << endl;
    // cout << a->foo(20.0) << endl;
    // a->test();

    B* b = new B();
    b->test();
    b->printCity();

    A* a1 = new B();
    a1->test();

    A* a2 = new C();
    a2->test();

    return 0;

}