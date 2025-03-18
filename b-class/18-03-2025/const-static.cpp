#include <iostream>
#include <stdexcept>

using namespace std;

class Test {
public:
  int a;
  static int b;
  Test() {
      a = 10;
      b++;
    try {
        throw invalid_argument("Invalid value");
    } catch(const invalid_argument& e) {
        cout << "In catch block" << endl;
        cout << e.what() << endl;
    }
  }
  
  ~Test() {
      b--;
  }
  
// Const here does not let the method modify any variables or properties
//   int getA() const {
//       a++;
//       return a;
//   }
  
// Const here refers to the type of the variable returned by the method.
//     const int getA() {
//       a++;
//       return a;
//   }
};

int Test::b = 0;

// Exception, static, const
// Exceptions - throw, try, catch
int main() {
    cout << Test::b << endl;
    Test t1, t2;
    cout << t1.a << endl;
    cout << t2.a << endl;
    cout << t1.b << endl;
    cout << t2.b << endl;
    
    int a = 10;
    int b = 20;
    int c = 30;
    
    // Non-constant pointer to constant value
    const int* x = &a;
    a = 15;
    x = &b;
    //*x = 15; CTE
    
    // Constant pointer to non-constant value
    int* const y = &b;
    b = 25;
    //y = &c; CTE
    *y = 25;
    
    // Constant pointer to constant value
    const int* const z = &c;
    c = 35;
    // z = &a; CTE
    // *z = 35; CTE

    return 0;
}