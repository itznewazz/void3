#include <iostream>
#include <cmath>

using namespace std;

int deg, c = 0;
double e, dx, coff[100];

double horner(double x) {
    double result = coff[deg];
    for (int i = deg - 1; i >= 0; i--) {
        result = result * x + coff[i];
    }
    return result;
}

void bisection(double a, double b) {
    double x1 = a, x2 = x1 + dx, x0, f1, f2, f0;

    cout << "\nRoots found in the interval: ";

    while (x2 <= b) {
        f1 = horner(x1);
        f2 = horner(x2);

        // If f1 * f2 > 0, there is no sign change, so skip this interval
        if (f1 * f2 > 0) {
            x1 = x2;
            x2 += dx;
            continue;
        }

        // Root Refinement using Bisection Method
        do {
            c++;
            x0 = (x1 + x2) / 2;
            f0 = horner(x0);

            if (fabs(f0)==0) {
                cout << x0 << " ";
                return;
            }

            if (f1 * f0 < 0) {
                x2 = x0;
                f2 = f0;
            } else {
                x1 = x0;
                f1 = f0;
            }

        } while (fabs((b - a) / b) >= e);

        cout << x0 << " ";
        x1 = x2;
        x2 += dx;
    }
}

int main() {
    double lo, hi;

    cout << "Enter the degree of the polynomial: ";
    cin >> deg;



    cout << "\n";
    for (int i = deg; i >= 0; i--) {
        cout << "Enter the coefficient for x^" << i << ": ";
        cin >> coff[i];
    }

    cout << "\nEnter the range (lowest and highest limits): ";
    cin >> lo >> hi;

    cout << "\nEnter the increment step (dx): ";
    cin >> dx;

    cout << "\nEnter the error tolerance: ";
    cin >> e;

    cout << "\n";
    bisection(lo, hi);

    cout << "\nTotal iterations needed: " << c << endl;

    return 0;
}




