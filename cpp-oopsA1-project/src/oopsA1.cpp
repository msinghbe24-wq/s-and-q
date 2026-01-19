#include <bits/stdc++.h>
using namespace std;

int main() {

    // 1. Hello World
    cout << "Hello World" << endl;

    // 2. Input integer, decimal and character
    cout << "2. Input Integer, Decimal and Character\n";
    int i;
    float f;
    char c;
    cout << "Enter integer: ";
    cin >> i;
    cout << "Enter decimal: ";
    cin >> f;
    cout << "Enter character: ";
    cin >> c;
    cout << "Integer: " << i << endl;
    cout << "Decimal: " << f << endl;
    cout << "Character: " << c << "\n\n";

    // 3. Arithmetic operations
    float a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << "\n\n";

    // 4. Celsius to Fahrenheit
    float cel, fah;
    cout << "Enter temperature in Celsius: ";
    cin >> cel;
    fah = (9 * cel) / 5 + 32;
    cout << "Temperature in Fahrenheit: " << fah << "\n\n";

    // 5. Formatting output
    cout << "5. Formatting Output\n";
    cout << "Hello\nWorld\n";
    cout << "Hello\tWorld\n";
    cout << "Hello\b World\n";
    cout << setw(10) << "C++\n\n";

    // 6. Assignment operators += and -=
    cout << "6. Assignment Operators\n";
    int x = 10;
    x += 5;
    cout << "After += 5: " << x << endl;
    x -= 3;
    cout << "After -= 3: " << x << "\n\n";

    // 7. Swap using bitwise operator
    int p, q;
    cout << "Enter two numbers: ";
    cin >> p >> q;
    p = p ^ q;
    q = p ^ q;
    p = p ^ q;
    cout << "After swapping: p = " << p << ", q = " << q << "\n\n";

    // 8. Library fine problem
    int days;
    cout << "Enter number of late days: ";
    cin >> days;

    if (days <= 5)
        cout << "Fine: 50 paise\n\n";
    else if (days <= 10)
        cout << "Fine: 1 rupee\n\n";
    else if (days <= 30)
        cout << "Fine: 5 rupees\n\n";
    else
        cout << "Membership cancelled\n\n";

    // 9. Arithmetic using switch-case
    int m, n;
    char op;
    cout << "Enter two numbers: ";
    cin >> m >> n;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    switch (op) {
        case '+': cout << "Result: " << m + n; break;
        case '-': cout << "Result: " << m - n; break;
        case '*': cout << "Result: " << m * n; break;
        case '/': cout << "Result: " << m / n; break;
        default: cout << "Invalid operator";
    }
    cout << "\n\n";

    // 10. Even or Odd (if-else & conditional)
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num % 2 == 0)
        cout << "Even (if-else)\n";
    else
        cout << "Odd (if-else)\n";

    (num % 2 == 0) ? cout << "Even (conditional)\n" : cout << "Odd (conditional)\n";

    return 0;
}