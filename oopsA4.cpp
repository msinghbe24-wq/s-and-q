#include <iostream>
using namespace std;

class Rectangle {
    int length, breadth;

public:
    Rectangle() { length = 0; breadth = 0; }
    Rectangle(int l, int b) { length = l; breadth = b; }
    Rectangle(int x) { length = breadth = x; }
    Rectangle(int l=1, int b=1, int dummy=0) { length=l; breadth=b; }

    int area() { return length * breadth; }

    ~Rectangle() { cout << "Destructor Called" << endl; }
};

int main() {
    Rectangle r1;
    Rectangle r2(5);
    Rectangle r3(4,6);

    cout << r1.area() << endl;
    cout << r2.area() << endl;
    cout << r3.area() << endl;

    Rectangle arr[3] = {Rectangle(), Rectangle(3), Rectangle(2,5)};
    for(int i=0;i<3;i++) cout << arr[i].area() << endl;

    int *pi = new int(10);
    float *pf = new float(5.5);

    int *arrInt = new int[3]{1,2,3};
    float *arrFloat = new float[3]{1.1,2.2,3.3};

    Rectangle *obj = new Rectangle(7,8);
    Rectangle *objArr = new Rectangle[2]{Rectangle(2,3), Rectangle(4,5)};

    delete pi;
    delete pf;
    delete[] arrInt;
    delete[] arrFloat;
    delete obj;
    delete[] objArr;
}
