#include <iostream>
#include <cmath>

using namespace std;

void addPoly(int* a, int* b, int s, int l) {
    int highestDeg = s;
    int lowestDeg = l;

    if (s < l) {
        highestDeg = l;
        lowestDeg = s;
    }

    int* c = new int[highestDeg + 1];

    for (int i = 0; i <= highestDeg; i++) {
        if (highestDeg == s) {
            c[i] = a[i];
        }
        else {
            c[i] = b[i];
        }


    }
    int diff = highestDeg - lowestDeg;
    int x = 0;
    for (int i = diff; i <= highestDeg; i++) {

        if (highestDeg == s) {
            c[i] += b[x];
            x++;
        }
        else {
            c[i] += a[x];
            x++;
        }

    }

    cout << endl;
    for (int i = 0; i <= highestDeg; i++) {
        if (c[i] != 0 && highestDeg - i != 0 && c[i] > 1 && highestDeg - i != 1) {
            cout << c[i] << "x^" << highestDeg - i << " + ";
        }
        else if (highestDeg - i == 0) {
            cout << c[i] << endl;
        }
        else if (highestDeg - i == 1) {
            cout << c[i] << "x" << " + ";
        }
        else if (c[i] == 1) {
            cout << "x^" << highestDeg - i << " + ";
        }
    }

}

int multiplyX(int* arr, int deg) {
    int sum = 0;
    int x = 0;

    cout << "Enter value to multiply polynomial by: ";
    cin >> x;

    for (int i = 0; i <= deg; i++) {
        sum += arr[i] * pow(x, deg - i);
    }
    return sum;
}

int main()
{
    int deg1;
    cout << "Enter highest degree of first polynomial:";
    while (!(cin >> deg1) || deg1 < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a non-negative integer: ";
    }
    int* arrA = new int[deg1 + 1];
    cout << "Enter polynomial coefficients:" << endl;
    for (int i = 0; i <= deg1; i++) {
        cin >> arrA[i];
    }
    for (int i = 0; i < deg1; i++) {
        if (arrA[i] != 0 && arrA[i] > 1 && deg1 - i != 1) {
            cout << arrA[i] << "x^" << deg1 - i << " + ";
        }
        else if (arrA[i] == 1) {
            cout << "x^" << deg1 - i << " + ";
        }
        else if (deg1 - i == 1) {
            cout << arrA[i] << "x" << " + ";
        }
    }
    cout << arrA[deg1] << endl;

    int deg2;
    cout << "Enter highest degree of second polynomial:";
    while (!(cin >> deg2) || deg2 < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a non-negative integer: ";
    }
    int* arrB = new int[deg2 + 1];
    cout << "Enter polynomial coefficients:" << endl;
    for (int i = 0; i <= deg2; i++) {
        cin >> arrB[i];
    }
    for (int i = 0; i < deg2; i++) {
        if (arrB[i] != 0 && arrB[i] > 1 && deg2 - i != 1) {
            cout << arrB[i] << "x^" << deg2 - i << " + ";
        }
        else if (arrB[i] == 1) {
            cout << "x^" << deg2 - i << " + ";
        }
        else if (deg2 - i == 1) {
            cout << arrB[i] << "x" << " + ";
        }
    }
    cout << arrB[deg2] << endl;

    int choice;
    cout << "Enter a menu option: \n" << "1. Evaluate Polynomial\n"  << "2. Add Polynomial" << endl;
    cin >> choice;

    if (choice == 1) {
        int polyChoice;
        cout << "Which polynomial do you wish to evaluate?: (1 or 2)";
        cin >> polyChoice;
        if (polyChoice == 1) {
            cout << "\nValue of polynomial multiplied by x is" << "\n" << multiplyX(arrA, deg1) << endl;
        }
        else if (polyChoice == 2) {
            cout << "\nValue of polynomial multiplied by x is" << "\n" << multiplyX(arrB, deg2) << endl;
        }
    }
    else if (choice == 2) {
        cout << "The addition of polynomials results to: ";
        addPoly(arrA, arrB, deg1, deg2);
    }

    return 0;
}