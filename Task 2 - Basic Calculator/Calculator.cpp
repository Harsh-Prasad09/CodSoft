#include <iostream>
using namespace std;

int main() {
    char op;
    float num1, num2;

    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    cout << "Enter operation (+, -, *, /): ";
    cin >> op;

    switch (op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                cout << num1 << " / " << num2 << " = " << num1 / num2;
            } else {
                cout << "Error! Division by zero is not defined.";
            }
            break;
        default:
            cout << "Invalid operator! Please try again.";
            break;
    }

    return 0;
}
