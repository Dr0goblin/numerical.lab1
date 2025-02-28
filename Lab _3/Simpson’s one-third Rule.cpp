#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x;
}

double simpson_one_third(double a, double b) {
    double h = (b - a) / 2;
    return (h / 3) * (f(a) + 4 * f(a + h) + f(b));
}

int main() {
    double a, b;
    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;

    cout << "Integral using Simpson's 1/3 Rule: " << simpson_one_third(a, b) << endl;
    return 0;
}

