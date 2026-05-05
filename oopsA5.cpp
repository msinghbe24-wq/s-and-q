#include <iostream>
using namespace std;

/* ================== Q1: SIMPLE INHERITANCE ================== */
class Base {
public:
    void show() { cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void display() { cout << "Derived class\n"; }
};



/* ================== Q2: PROTECTED ACCESS ================== */
class ProtectedBase {
protected:
    int x = 100;
};

class ProtectedDerived : public ProtectedBase {
public:
    void showX() { cout << "Protected x = " << x << endl; }
};



/* ================== Q3: ACCESS MODIFIERS ================== */
class A {
public:
    int x = 5;
};

class PublicDer : public A {};
class ProtectedDer : protected A {};
class PrivateDer : private A {};



/* ================== Q4: TYPES OF INHERITANCE ================== */

/* Single */
class Book {
public:
    string title;
};

class Textbook : public Book {
public:
    string subject;
};

/* Multiple */
class Speedometer { public: int speed = 80; };
class FuelGauge { public: int fuel = 50; };
class Thermometer { public: int temp = 30; };

class CarDashboard : public Speedometer, public FuelGauge, public Thermometer {
public:
    void display() {
        cout << "Speed: " << speed << " Fuel: " << fuel << " Temp: " << temp << endl;
    }
};

/* Hierarchical */
class LibraryUser {
public:
    string name;
};

class Student : public LibraryUser {
public:
    int grade;
};

class Teacher : public LibraryUser {
public:
    string dept;
};

/* Multilevel */
class Vehicle {
public:
    string model;
};

class Truck : public Vehicle {
public:
    int capacity;
};

class RefrigeratedTruck : public Truck {
public:
    int tempControl;
};

/* Hybrid */
class Person {
public:
    string name;
};

class Staff : public Person {
public:
    int empID;
};

class Student2 : public Person {
public:
    int studentID;
};

class TeachingAssistant : public Staff, public Student2 {
public:
    void show() { cout << "Hybrid Inheritance\n"; }
};



/* ================== Q5: CONSTRUCTOR & DESTRUCTOR ================== */
class C1 {
public:
    C1() { cout << "Constructor C1\n"; }
    ~C1() { cout << "Destructor C1\n"; }
};

class C2 : public C1 {
public:
    C2() { cout << "Constructor C2\n"; }
    ~C2() { cout << "Destructor C2\n"; }
};



/* ================== Q6: BOOK → TEXTBOOK ================== */
class Book2 {
public:
    string title, author;
    double price;
};

class Textbook2 : public Book2 {
public:
    string subject;
    void display() {
        cout << title << " " << author << " " << price << " " << subject << endl;
    }
};



/* ================== Q7: CAR DASHBOARD (MULTIPLE INHERITANCE) ================== */
class Speedo { public: int speed = 70; };
class Fuel { public: int fuel = 40; };
class Temp { public: int temp = 25; };

class Dashboard : public Speedo, public Fuel, public Temp {
public:
    void show() {
        cout << "Speed=" << speed << " Fuel=" << fuel << " Temp=" << temp << endl;
    }
};



/* ================== Q8: HIERARCHICAL (LIBRARY USER) ================== */
class User {
public:
    string name;
};

class StudentUser : public User {
public:
    int grade;
};

class TeacherUser : public User {
public:
    string dept;
};



/* ================== Q9: MULTILEVEL (VEHICLE) ================== */
class Vehicle2 {
public:
    string make;
};

class Truck2 : public Vehicle2 {
public:
    int load;
};

class RefrigeratedTruck2 : public Truck2 {
public:
    int tempControl;
};



/* ================== Q10: HYBRID INHERITANCE ================== */
class Person2 {
public:
    string name;
};

class Staff2 : public Person2 {
public:
    int empID;
};

class Student3 : public Person2 {
public:
    int studentID;
};

class TA : public Staff2, public Student3 {
public:
    void show() { cout << "Teaching Assistant\n"; }
};



/* ================== MAIN FUNCTION ================== */
int main() {

    // Q1
    Derived d;
    d.show();
    d.display();


    // Q2
    ProtectedDerived pd;
    pd.showX();


    // Q4 Multiple
    CarDashboard cd;
    cd.display();


    // Q5
    C2 obj;


    // Q6
    Textbook2 t;
    t.title = "C++";
    t.author = "Bjarne";
    t.price = 500;
    t.subject = "Programming";
    t.display();


    // Q7
    Dashboard db;
    db.show();


    // Q10
    TA ta;
    ta.show();

    return 0;
}