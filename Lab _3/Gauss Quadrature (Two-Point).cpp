#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x;
}

double gauss_quadrature(double a, double b) {
    double x1 = -1 / sqrt(3), x2 = 1 / sqrt(3);
    double t1 = (b - a) / 2 * x1 + (a + b) / 2;
    double t2 = (b - a) / 2 * x2 + (a + b) / 2;
    return (b - a) / 2 * (f(t1) + f(t2));
}

int main() {
    double a, b;
    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;

    cout << "Integral using Gauss Quadrature: " << gauss_quadrature(a, b) << endl;
    return 0;
}

