#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/* ================== Q1: POLYGON → RECTANGLE, TRIANGLE ================== */
class Polygon {
protected:
    int width, height;
public:
    void set_value(int w, int h) {
        width = w;
        height = h;
    }
};

class Rectangle : public Polygon {
public:
    int area() { return width * height; }
};

class Triangle : public Polygon {
public:
    int area() { return width * height / 2; }
};



/* ================== Q2: SHAPE (VIRTUAL FUNCTION) ================== */
class Shape {
public:
    virtual void area() = 0;
    virtual void display() = 0;
};

class Circle : public Shape {
    float r;
public:
    Circle(float x) { r = x; }
    void area() { cout << "Area: " << 3.14 * r * r << endl; }
    void display() { cout << "Circle\n"; }
};

class Rect : public Shape {
    float l,b;
public:
    Rect(float x,float y){ l=x; b=y; }
    void area(){ cout << "Area: " << l*b << endl; }
    void display(){ cout << "Rectangle\n"; }
};

class Tri : public Shape {
    float b,h;
public:
    Tri(float x,float y){ b=x; h=y; }
    void area(){ cout << "Area: " << 0.5*b*h << endl; }
    void display(){ cout << "Triangle\n"; }
};



/* ================== Q3: FUNCTION OVERLOADING ================== */
float area(float b, float h) { return 0.5*b*h; }                // right
float area(float s) { return (sqrt(3)/4)*s*s; }                 // equilateral
float area(float a, float b, float c) {                         // isosceles
    float s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}



/* ================== Q4: ABSTRACT CLASS STUDENT ================== */
class Student {
public:
    virtual void show() = 0;
};

class Engineering : public Student {
public:
    void show(){ cout<<"Engineering\n"; }
};

class Medicine : public Student {
public:
    void show(){ cout<<"Medicine\n"; }
};

class Science : public Student {
public:
    void show(){ cout<<"Science\n"; }
};



/* ================== Q5: OPERATOR + (TIME) ================== */
class Time {
    int h,m,s;
public:
    Time(int h=0,int m=0,int s=0){
        this->h=h; this->m=m; this->s=s;
    }

    Time operator+(Time t){
        Time temp;
        temp.s = s + t.s;
        temp.m = m + t.m + temp.s/60;
        temp.s %= 60;
        temp.h = h + t.h + temp.m/60;
        temp.m %= 60;
        return temp;
    }

    void show(){
        cout<<h<<":"<<m<<":"<<s<<endl;
    }
};



/* ================== Q6: STRING OPERATOR ================== */
class STRING {
    char str[100];
public:
    STRING(char s[]=""){ strcpy(str,s); }

    bool operator==(STRING s){
        return strcmp(str,s.str)==0;
    }

    STRING operator+(STRING s){
        STRING temp;
        strcpy(temp.str,str);
        strcat(temp.str,s.str);
        return temp;
    }

    void show(){ cout<<str<<endl; }
};



/* ================== Q7: MATRIX MULTIPLICATION ================== */
class Matrix {
    int a[2][2];
public:
    void input(){
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                cin>>a[i][j];
    }

    void display(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }

    friend Matrix operator*(Matrix, Matrix);
};

Matrix operator*(Matrix m1, Matrix m2){
    Matrix temp;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            temp.a[i][j]=0;
            for(int k=0;k<2;k++)
                temp.a[i][j]+=m1.a[i][k]*m2.a[k][j];
        }
    return temp;
}



/* ================== Q8: OPERATOR [] ================== */
class Array {
    int arr[5];
public:
    int& operator[](int i){
        if(i<0 || i>=5){
            cout<<"Out of bounds\n";
            exit(0);
        }
        return arr[i];
    }
};



/* ================== Q9: OPERATOR () ================== */
class Demo {
public:
    void operator()(int a,int b){
        cout<<"Sum="<<a+b<<endl;
    }
};



/* ================== Q10: >> AND << ================== */
class Test {
    int x;
public:
    friend istream& operator>>(istream &in, Test &t){
        in>>t.x;
        return in;
    }

    friend ostream& operator<<(ostream &out, Test &t){
        out<<t.x;
        return out;
    }
};



/* ================== Q11: BASIC → UDT ================== */
class Convert1 {
    float x;
public:
    Convert1(float a){ x=a; }
};



/* ================== Q12: UDT → BASIC ================== */
class Convert2 {
    float x;
public:
    Convert2(float a){ x=a; }
    operator float(){ return x; }
};



/* ================== Q13: POLAR → CARTESIAN ================== */
class Cartesian;

class Polar {
    float r,theta;
public:
    Polar(float r,float t){ this->r=r; this->theta=t; }
    operator Cartesian();
};

class Cartesian {
    float x,y;
public:
    Cartesian(float x=0,float y=0){ this->x=x; this->y=y; }
    void show(){ cout<<"x="<<x<<" y="<<y<<endl; }
};

Polar::operator Cartesian(){
    return Cartesian(r*cos(theta), r*sin(theta));
}



/* ================== MAIN ================== */
int main() {

    // Q1
    Rectangle r; Triangle t;
    Polygon *p=&r;
    p->set_value(10,5);
    cout<<"Rect Area="<<r.area()<<endl;

    p=&t;
    p->set_value(10,5);
    cout<<"Tri Area="<<t.area()<<endl;


    // Q2
    Shape *s;
    Circle c(5); Rect r1(4,6); Tri t1(3,7);

    s=&c; s->display(); s->area();
    s=&r1; s->display(); s->area();
    s=&t1; s->display(); s->area();


    // Q3
    cout<<area(3,4)<<endl;
    cout<<area(5)<<endl;
    cout<<area(5,5,6)<<endl;


    // Q4
    Student* arr[3];
    Engineering e; Medicine m; Science sc;
    arr[0]=&e; arr[1]=&m; arr[2]=&sc;
    for(int i=0;i<3;i++) arr[i]->show();


    // Q5
    Time t2(5,15,34), t3(9,53,58), t4;
    t4=t2+t3;
    t4.show();


    // Q6
    STRING a("Hello "), b("World");
    STRING c1=a+b;
    c1.show();


    // Q7
    Matrix m1,m2,m3;
    // (input manually if needed)


    // Q8
    Array arr1;
    arr1[0]=10;


    // Q9
    Demo d;
    d(3,4);


    // Q10
    Test t5;
    cin>>t5;
    cout<<t5<<endl;


    // Q11
    Convert1 obj1=5.5;


    // Q12
    Convert2 obj2(7.5);
    float f=obj2;


    // Q13
    Polar p1(10,5);
    Cartesian c2=p1;
    c2.show();

    return 0;
}