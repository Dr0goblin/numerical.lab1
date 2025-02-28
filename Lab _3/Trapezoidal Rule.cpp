#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x;
}

double trapezoidal_rule(double a, double b) {
    return (b - a) * (f(a) + f(b)) / 2.0;
}

int main() {
    double a, b;
    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;

    cout << "Integral using Trapezoidal Rule: " << trapezoidal_rule(a, b) << endl;
    return 0;
}

