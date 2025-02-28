#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x;
}

double simpson_three_eighth(double a, double b) {
    double h = (b - a) / 3;
    return (3 * h / 8) * (f(a) + 3 * f(a + h) + 3 * f(a + 2 * h) + f(b));
}

int main() {
    double a, b;
    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;

    cout << "Integral using Simpson's 3/8 Rule: " << simpson_three_eighth(a, b) << endl;
    return 0;
}

