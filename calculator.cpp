#include <iostream>
#include <tuple>
#include <cstdlib>
using namespace std;

tuple<float, float> get_input()
{
    float a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    return make_tuple(a, b);
}

int main()
{
    int choice;
    float num1, num2;

    while (true)
    {
        cout << "\n1. Addition";
        cout << "\n2. Subtraction";
        cout << "\n3. Multiplication";
        cout << "\n4. Division";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tie(num1, num2) = get_input();
            cout << "\nSum = " << num1 + num2;
            break;
        case 2:
            tie(num1, num2) = get_input();
            cout << "\nDifference = " << num1 - num2;
            break;
        case 3:
            tie(num1, num2) = get_input();
            cout << "\nProduct = " << num1 * num2;
            break;
        case 4:
            tie(num1, num2) = get_input();
            cout << "\nQuotient = " << num1 / num2;
            break;
        case 5:
            exit(0);
        default:
            cout << "\nInvalid choice!";
        }

        cout << "\n";
    }

    return 0;
}
