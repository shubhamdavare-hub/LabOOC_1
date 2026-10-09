#include <iostream> 
using namespace std; 
class construct {  
    public: 
    float area;  
    // Constructor with no parameters 
    construct() {
        area=0;
    }
    // Constructor with two parameters
    construct(int a,int b) {
        area=a*b;
    }

    void disp() {
        cout<<area<<endl;
    }
};

int main() {
    // Constructor overloading with two different constructors of class name
    construct o;
    construct o1(10,20);

    o.disp();
    o1.disp();
    return 1;
}