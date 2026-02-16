#include <iostream>
using namespace std;

struct StudentStruct {
    string name;
    int rollNo;
    string degree;
    string hostel;
    float cgpa;

    void addDetails() { cin >> name >> rollNo >> degree >> hostel >> cgpa; }
    void updateDetails() { cin >> name >> degree; }
    void updateCGPA() { cin >> cgpa; }
    void updateHostel() { cin >> hostel; }
    void displayDetails() { cout << name << " " << rollNo << " " << degree << " " << hostel << " " << cgpa << endl; }
};

class Student {
private:
    string name;
    int rollNo;
    float cgpa;
    void privateFunc() { cout << "Private Called" << endl; }

public:
    string degree;
    string hostel;

    void addDetails() { cin >> name >> rollNo >> degree >> hostel >> cgpa; }
    void updateCGPA() { cin >> cgpa; }
    void callPrivate() { privateFunc(); }
    void display() { cout << name << " " << rollNo << " " << degree << " " << hostel << " " << cgpa << endl; }
};

class Rectangle {
    int width, height;
public:
    void getdata() { cin >> width >> height; }
    void calculatearea() { cout << width * height << endl; }
};

class Complex {
    float real, imag;
public:
    void setComplex(float r, float i) { real = r; imag = i; }
    Complex add(Complex c) {
        Complex t;
        t.real = real + c.real;
        t.imag = imag + c.imag;
        return t;
    }
    void displayComplex() { cout << real << " + " << imag << "i" << endl; }
};

int x = 100;

class Test {
public:
    static int y;
    void show();
};

int Test::y = 200;

void Test::show() {
    int x = 50;
    cout << ::x << " " << x << " " << Test::y << endl;
}

namespace A {
    int x = 5;
    void show() { cout << "A " << x << endl; }
}

namespace B {
    int x = 10;
    void show() { cout << "B " << x << endl; }
}

int main() {
    StudentStruct s1;
    s1.addDetails();
    s1.displayDetails();

    Student s2;
    s2.addDetails();
    s2.callPrivate();
    s2.display();

    Rectangle r;
    r.getdata();
    r.calculatearea();

    Complex c1, c2, c3;
    c1.setComplex(2,3);
    c2.setComplex(4,5);
    c3 = c1.add(c2);
    c3.displayComplex();

    Test t;
    t.show();
    std::cout << "Hello" << endl;

    A::show();
    B::show();
}
