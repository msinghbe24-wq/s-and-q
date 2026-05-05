#include <iostream>
using namespace std;

/* ================== FUNCTION TEMPLATE ================== */


/* ================== Q1: SWAP ================== */
template <class T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}



/* ================== Q2: MIN IN ARRAY ================== */
template <class T>
T findMin(T arr[], int n) {
    T min = arr[0];
    for(int i=1;i<n;i++)
        if(arr[i] < min)
            min = arr[i];
    return min;
}



/* ================== Q3: BUBBLE SORT ================== */
template <class T>
void bubbleSort(T arr[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j] > arr[j+1])
                mySwap(arr[j], arr[j+1]);
}



/* ================== Q4: LINEAR SEARCH ================== */
template <class T>
int linearSearch(T arr[], int n, T key) {
    for(int i=0;i<n;i++)
        if(arr[i] == key)
            return i;
    return -1;
}



/* ================== Q5: FUNCTION OVERLOADING ================== */
template <class T>
void process(T a) {
    cout << "One parameter: " << a << endl;
}

template <class T>
void process(T a, T b) {
    cout << "Two same type: " << a << " " << b << endl;
}

template <class T, class U>
void process(T a, U b) {
    cout << "Two different types: " << a << " " << b << endl;
}



/* ================== CLASS TEMPLATE ================== */


/* ================== Q6: STACK ================== */
template <class T>
class Stack {
    T arr[5];
    int top;
public:
    Stack() { top = -1; }

    void push(T x) {
        if(top == 4) cout << "Stack Full\n";
        else arr[++top] = x;
    }

    void pop() {
        if(top == -1) cout << "Stack Empty\n";
        else cout << "Popped: " << arr[top--] << endl;
    }
};



/* ================== Q7: QUEUE ================== */
template <class T>
class Queue {
    T arr[5];
    int front, rear;
public:
    Queue() { front = rear = -1; }

    void enqueue(T x) {
        if(rear == 4) cout << "Queue Full\n";
        else {
            if(front == -1) front = 0;
            arr[++rear] = x;
        }
    }

    void dequeue() {
        if(front == -1 || front > rear)
            cout << "Queue Empty\n";
        else
            cout << "Dequeued: " << arr[front++] << endl;
    }
};



/* ================== Q8: PAIR ================== */
template <class T>
class Pair {
    T a, b;
public:
    Pair(T x, T y) {
        a = x;
        b = y;
    }

    void display() {
        cout << a << " " << b << endl;
    }
};



/* ================== Q9: ARITHMETIC ================== */
template <class T>
class Calc {
    T a, b;
public:
    Calc(T x, T y) { a = x; b = y; }

    void operations() {
        cout << "Add: " << a + b << endl;
        cout << "Sub: " << a - b << endl;
        cout << "Mul: " << a * b << endl;
        cout << "Div: " << a / b << endl;
    }
};



/* ================== Q10: ARRAY INPUT DISPLAY ================== */
template <class T>
class Array {
    T arr[5];
public:
    void input() {
        for(int i=0;i<5;i++)
            cin >> arr[i];
    }

    void display() {
        for(int i=0;i<5;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};



/* ================== MAIN FUNCTION ================== */
int main() {

    // Q1
    int x=5,y=10;
    mySwap(x,y);
    cout << x << " " << y << endl;


    // Q2
    int arr1[5]={5,2,8,1,9};
    cout << findMin(arr1,5) << endl;


    // Q3
    bubbleSort(arr1,5);
    for(int i=0;i<5;i++) cout<<arr1[i]<<" ";
    cout<<endl;


    // Q4
    cout << linearSearch(arr1,5,8) << endl;


    // Q5
    process(5);
    process(5,10);
    process(5,2.5);


    // Q6
    Stack<int> s;
    s.push(10); s.push(20);
    s.pop();


    // Q7
    Queue<int> q;
    q.enqueue(10); q.enqueue(20);
    q.dequeue();


    // Q8
    Pair<int> p(3,4);
    p.display();


    // Q9
    Calc<int> c(10,5);
    c.operations();


    // Q10
    Array<int> a;
    // a.input(); // optional
    // a.display();

    return 0;
}