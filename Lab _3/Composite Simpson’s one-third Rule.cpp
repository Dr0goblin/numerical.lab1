#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x;
}

double composite_simpson_one_third(double a, double b, int n) {
    if (n % 2 != 0) {
        cout << "n must be even for Simpson's 1/3 Rule.";
        return 0;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        sum += (i % 2 == 0 ? 2 : 4) * f(a + i * h);
    }
    return (h / 3) * sum;
}

int main() {
    double a, b;
    int n;
    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (n, even): ";
    cin >> n;

    cout << "Integral using Composite Simpson's 1/3 Rule: " << composite_simpson_one_third(a, b, n) << endl;
    return 0;
}

