#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x;
}

double composite_trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }
    return (h / 2) * sum;
}

int main() {
    double a, b;
    int n;
    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (n): ";
    cin >> n;

    cout << "Integral using Composite Trapezoidal Rule: " << composite_trapezoidal(a, b, n) << endl;
    return 0;
}

