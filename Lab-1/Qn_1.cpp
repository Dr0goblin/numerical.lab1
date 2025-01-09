#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return exp(-x) - x;
}

void bisection(double a, double b, double tolerance, int maxIterations) {
    if (f(a) * f(b) >= 0) {
        cout << "Error: The function values at the interval endpoints must have opposite signs.\n";
        return;
    }

    double mid;
    int iterations = 0;

    while ((b - a) / 2 > tolerance && iterations < maxIterations) {
        mid = (a + b) / 2;
        iterations++;

        if (f(mid) == 0.0) {
            break;
        }

        if (f(a) * f(mid) < 0) {
            b = mid;
        } else {
            a = mid;
        }
    }
    mid = (a + b) / 2;
    cout << fixed << setprecision(6);
    cout << "Estimated root: " << mid << endl;
    cout << "Functional value at root: " << f(mid) << endl;
    cout << "Number of iterations: " << iterations << endl;
}

int main() {
    double a, b, tolerance;
    int maxIterations;

    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;

    cout << "Enter the tolerance: ";
    cin >> tolerance;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    bisection(a, b, tolerance, maxIterations);
    return 0;
}
