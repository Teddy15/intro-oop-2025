#include <iostream>
using namespace std;

// Static and Dynamic polymorphism
// Abstraction
// Method overriding vs method overloading

// default index starts from 0
enum City {
  SOFIA, PLOVDIV, VARNA  
};

string getCity(City city) {
    if (city == SOFIA) return "sofia";
    else if (city == PLOVDIV) return "plovdiv";
    else if (city == VARNA) return "varna";
    
    return "test";
}
 
class A {
public:
    A () {
        cout << "IN A" << endl;
    }
    
    // Static polymorphism - decide which method to use during Compile Time
    // Also known as method overloading here in this example
    // To overload a method you need to have the same name of the method with the same return type but different argument list!
    int sum(int x) {
        cout << "In sum A" << endl;
        return x + 5;
    }

    // Static polymorphism - decide which method to use during Compile Time
    // Also known as method overloading here in this example.
    // To overload a method you need to have the same name of the method with the same return type but different argument list!
    int sum(int x, int y) {
        return x + y;
    }
    
    // -------------- Virtual methods enable the creation of the vtable and vpointer for the given class.
    // -------------- This is what enables us to use the DYNAMIC polymorphism!
    
    // Dynamic polymorphism (virtual)
    // Not fully virtual method
    // Not compulsary to be overriden in the child classes
    // Does not make the class A abstract
    virtual void test() {
        cout << "In A test()" << endl;
    }
    
    // Dynamic polymorphism (virtual) AND Static polymorphism (method overloading)
    // Not fully virtual method
    // Not compulsary to be overriden in the child classes
    // Does not make the class A abstract
    virtual void test(int x) {
        cout << "In A test(): " << x << endl;
    }
    
    // Dynamic polymorphism (virtual) and Abstraction
    // Fully virtual method
    // Compulsary to be overriden in the child classes!
    // Makes the class A abstract!
    virtual void testAgain() = 0;
};

class B : public A {
public:  
    B() {
        cout << "IN B" << endl;
    }
    
    // This is method overriding. Overriding is when you have the exact same method signature (method name, return type and argument list)
    // between two methods in a parent-child inheritance, but they have different behaviors.
    int sum(int x) {
        cout << "In sum B" << endl;
        return x + 7;
    }
    
    // Overriding A::test()
    void test() {
        cout << "In B test()" << endl;
    }
    
    void testAgain() {
        cout << "In B testAgain" << endl;
    }
};

class C : public A {
public:
    C() {
        cout << "IN C" << endl;
    }
    
    void testAgain() {
        cout << "In C testAgain" << endl;
    }
};

int main() {
    City city = SOFIA;
    cout << getCity(city) << endl;
    
    // A* a = new A();
    // cout << a->sum(10) << endl;
    // cout << a->sum(10, 20) << endl;
    // a->test();
    
    
    // Dynamic polymorphism - decided during Runtime
    A* b = new B(); // IS-IS relationship -> B IS A
    cout << b->sum(20) << endl;
    cout << b->sum(15, 15)<< endl;
    b->test(); // Example of using Dynamic Polymorphism correctly because of virtual !
    b->testAgain();
    
    A* c = new C();
    c->testAgain();
    return 0;
}