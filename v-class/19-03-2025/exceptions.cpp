#include <iostream>
#include <stdexcept>

using namespace std;

// Try & catch
class Test {
    
public:
    int a;
    static int b;
    // Test() {
    //     cout << "Please enter a number:" << endl;
    //     throw invalid_argument("Invalid value");
    // }
    Test() {
        a = 10;
        b++;
    }

    ~Test() {
        b--;
    }
    
    // Const here is used when methods are read-only. Meaning you cannot
    // modify anything inside the method!
    // int getA() const {
    //     a++;
    //     return a;
    // }
    
    // Const here refers to the type of value returned. It can be used with const and non-const variables.
    // const int getA() {
    //     a++;
    //     return a;
    // }
};

int Test::b = 0;

// Exception, static, const
int main() {
    // try {
    //     Test t;
    // } catch (const invalid_argument& e) {
    //     cout << "In catch block" << endl;
    //     cout << e.what() << endl;
    // }
    cout << Test::b << endl;
    Test t1;
    cout << t1.b << endl;
    Test t2;
    
    cout << t1.b << endl;

    cout << t2.b << endl;
    
    Test* t = new Test();
    cout << t1.b << endl;
    delete t;
    cout << t1.b << endl;
    
    // int k = t1.getA();
    // cout << k << endl;
    
    // Non-constant pointer to constant value
    int a = 10;
    int b = 20;
    int c = 30;
    const int* x = &a;
    
    a = 15;
    x = &b;
    //*x = 15; CTE

    // Constant pointer to non-constant value
    int* const y = &b;
    b = 15;
    //y = &c; CTE
    *y = 25;
    
    // Const pointer to constant value
    const int* const z = &c;
    c = 35;
    //z = &a; CTE
    //*z = 45; CTE
    
    return 0;
}