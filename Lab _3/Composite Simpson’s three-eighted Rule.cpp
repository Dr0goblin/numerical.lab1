#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x;
}

double composite_simpson_three_eighth(double a, double b, int n) {
    if (n % 3 != 0) {
        cout << "n must be a multiple of 3 for Simpson's 3/8 Rule.";
        return 0;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        sum += ((i % 3 == 0) ? 2 : 3) * f(a + i * h);
    }
    return (3 * h / 8) * sum;
}

int main() {
    double a, b;
    int n;
    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (n, multiple of 3): ";
    cin >> n;

    cout << "Integral using Composite Simpson's 3/8 Rule: " << composite_simpson_three_eighth(a, b, n) << endl;
    return 0;
}

