#include <iostream>
using namespace std;

class Test {
    int x;
public:
    void set(int x) { this->x = x; }
    void show() { cout << x << endl; }
};

class B;

class A {
    int a;
public:
    void set(int x) { a = x; }
    friend void swap(A &, B &);
    friend int add(A, B);
    friend class FriendClass;
};

class B {
    int b;
public:
    void set(int y) { b = y; }
    friend void swap(A &, B &);
    friend int add(A, B);
};

void swap(A &x, B &y) {
    int t = x.a;
    x.a = y.b;
    y.b = t;
}

int add(A x, B y) {
    return x.a + y.b;
}

class FriendClass {
public:
    void show(A obj) { cout << obj.a << endl; }
};

class Rectangle {
    int l, b;
public:
    void set(int x, int y) { l = x; b = y; }
    void area() { cout << l * b << endl; }
};

inline int cube(int x) { return x * x * x; }

class Obj {
    int x;
public:
    void set(int a) { x = a; }
    Obj process(Obj o) {
        Obj t;
        t.x = x + o.x;
        return t;
    }
    void show() { cout << x << endl; }
};

int main() {
    Test t;
    Test *p = &t;
    p->set(10);
    t.show();

    A a; B b;
    a.set(5);
    b.set(8);
    swap(a,b);
    cout << add(a,b) << endl;

    FriendClass f;
    f.show(a);

    Rectangle r[3];
    r[0].set(2,3);
    r[1].set(4,5);
    r[2].set(6,7);
    for(int i=0;i<3;i++) r[i].area();

    cout << cube(3) << endl;

    Obj o1,o2,o3;
    o1.set(5);
    o2.set(7);
    o3 = o1.process(o2);
    o3.show();
}
