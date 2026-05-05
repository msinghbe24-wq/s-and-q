#include <iostream>
#include <string>
using namespace std;

/* ================== Q1: LIBRARY (ARRAY OF OBJECTS) ================== */
class Book {
public:
    string title, author, ISBN;
};

class Library {
    Book books[10];
    int count = 0;

public:
    bool addNewBook(string &title, string &author, string &ISBN) {
        if(count >= 10) return false;

        books[count].title = title;
        books[count].author = author;
        books[count].ISBN = ISBN;
        count++;
        return true;
    }

    bool removeBooks(string &ISBN);

    void displayDetails() {
        for(int i=0;i<count;i++) {
            cout << books[i].title << " "
                 << books[i].author << " "
                 << books[i].ISBN << endl;
        }
    }
};

bool Library::removeBooks(string &ISBN) {
    for(int i=0;i<count;i++) {
        if(books[i].ISBN == ISBN) {
            for(int j=i;j<count-1;j++)
                books[j] = books[j+1];
            count--;
            return true;
        }
    }
    return false;
}



/* ================== Q2: CONSTRUCTORS + THIS ================== */
class Book2 {
    string title, author, ISBN;

public:
    Book2() {}

    Book2(string title, string author, string ISBN) {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
    }

    Book2(const Book2 &b) {
        title = b.title;
        author = b.author;
        ISBN = b.ISBN;
    }

    void display() {
        cout << title << " " << author << " " << ISBN << endl;
    }

    string getISBN() { return ISBN; }
};

class Library2 {
    Book2 books[10];
    int count = 0;

public:
    void addBook(Book2 b) {
        books[count++] = b;
    }

    bool removeBooks(string ISBN) {
        for(int i=0;i<count;i++) {
            if(books[i].getISBN()==ISBN) {
                for(int j=i;j<count-1;j++)
                    books[j]=books[j+1];
                count--;
                return true;
            }
        }
        return false;
    }

    void displayDetails() {
        for(int i=0;i<count;i++)
            books[i].display();
    }
};



/* ================== Q3: ACCOUNT CLASS ================== */
class Account {
    long accNo;
    long transactionID;
    string type;
    double balance;

public:
    Account(long acc, double bal) {
        accNo = acc;
        balance = bal;
        transactionID = 0;
        type = "none";
    }

    long depositAmount(const long to, const long from, const double amount) {
        if(accNo == to) {
            balance += amount;
            type = "credit";
            return ++transactionID;
        }
        return -1;
    }

    long creditAmount(const long to, const long from, const double amount) {
        if(accNo == from && balance >= amount) {
            balance -= amount;
            type = "debit";
            return ++transactionID;
        }
        return -1;
    }

    void displayDetails() const {
        cout << accNo << " " << balance << " " << type << endl;
    }
};



/* ================== Q4: FRIEND FUNCTION ================== */
class B;

class A {
    int x;
public:
    A(int x){ this->x = x; }
    friend int add(A,B);
};

class B {
    int y;
public:
    B(int y){ this->y = y; }
    friend int add(A,B);
};

int add(A a, B b) {
    return a.x + b.y;
}



/* ================== Q5: COMPLEX NUMBER ================== */
class Complex {
    int real, imag;

public:
    Complex(int r=0,int i=0) {
        real = r;
        imag = i;
    }

    Complex(const Complex &c) {
        real = c.real;
        imag = c.imag;
    }

    void display() {
        cout << real << "+" << imag << "i" << endl;
    }

    friend Complex sum(Complex, Complex);
};

Complex sum(Complex c1, Complex c2) {
    return Complex(c1.real + c2.real,
                   c1.imag + c2.imag);
}



/* ================== MAIN FUNCTION ================== */
int main() {

    // Q1
    Library lib;
    string t="C++", a="Bjarne", i="101";
    lib.addNewBook(t,a,i);
    lib.displayDetails();


    // Q2
    Library2 l2;
    Book2 b1("Java","James","102");
    l2.addBook(b1);
    l2.displayDetails();


    // Q3
    Account a1(101,1000), a2(102,2000);
    if(a2.creditAmount(101,102,500)!=-1)
        a1.depositAmount(101,102,500);
    a1.displayDetails();
    a2.displayDetails();


    // Q4
    A obj1(5);
    B obj2(10);
    cout << add(obj1,obj2) << endl;


    // Q5
    Complex c1(2,3), c2(4,5);
    Complex c3 = sum(c1,c2);
    c3.display();

    return 0;
}