#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return exp(-x) - x;
}

void secant_method(double x0, double x1, double tolerance, int maxIterations) {
    double x2, fx0, fx1, fx2;
    int iterations = 0;

    fx0 = f(x0);
    fx1 = f(x1);

    cout << fixed << setprecision(6);

    while (fabs(fx1) > tolerance && iterations < maxIterations) {
        if (fabs(x1 - x0) < 1e-10) { 
            cout << "Error: Division by zero detected. Secant method fails.\n";
            return;
        }

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        x0 = x1;
        fx0 = fx1;

        x1 = x2;
        fx1 = f(x1);

        iterations++;
    }

    if (fabs(fx1) <= tolerance) {
        cout << "Estimated root: " << x1 << endl;
        cout << "Functional value at root: " << fx1 << endl;
        cout << "Number of iterations: " << iterations << endl;
    } else {
        cout << "Secant method did not converge within the maximum number of iterations.\n";
    }
}

int main() {
    double x0, x1, tolerance;
    int maxIterations;

    cout << "Enter the first initial guess (x0): ";
    cin >> x0;

    cout << "Enter the second initial guess (x1): ";
    cin >> x1;

    cout << "Enter the tolerance (e.g., 0.0001): ";
    cin >> tolerance;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    secant_method(x0, x1, tolerance, maxIterations);

    return 0;
}

