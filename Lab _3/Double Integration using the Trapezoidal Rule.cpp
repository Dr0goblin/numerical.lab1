#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
    return x * y;
}

double double_trapezoidal(double a, double b, double c, double d, int m, int n) {
    double hx = (b - a) / m;
    double hy = (d - c) / n;
    double sum = 0.0;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            double x = a + i * hx;
            double y = c + j * hy;
            double coeff = 1.0;

            if (i == 0 || i == m) coeff *= 0.5;
            if (j == 0 || j == n) coeff *= 0.5;

            sum += coeff * f(x, y);
        }
    }

    return hx * hy * sum;
}

int main() {
    double a, b, c, d;
    int m, n;

    cout << "Enter lower limit of x (a): ";
    cin >> a;
    cout << "Enter upper limit of x (b): ";
    cin >> b;
    cout << "Enter lower limit of y (c): ";
    cin >> c;
    cout << "Enter upper limit of y (d): ";
    cin >> d;
    cout << "Enter number of intervals in x-direction (m): ";
    cin >> m;
    cout << "Enter number of intervals in y-direction (n): ";
    cin >> n;

    cout << "Double Integral using Trapezoidal Rule: " << double_trapezoidal(a, b, c, d, m, n) << endl;

    return 0;
}

