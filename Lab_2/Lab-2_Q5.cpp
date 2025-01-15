#include <iostream>
#include <cmath>
using namespace std;

void cubicSplineInterpolation(double x[], double y[], int n) {
    double h[n - 1], alpha[n - 1], l[n], mu[n], z[n];
    double a[n], b[n], c[n], d[n];

    for (int i = 0; i < n - 1; i++) {
        h[i] = x[i + 1] - x[i];
        alpha[i] = (3.0 / h[i]) * (y[i + 1] - y[i]) - (3.0 / h[i - 1]) * (y[i] - y[i - 1]);
    }

    l[0] = 1;
    mu[0] = 0;
    z[0] = 0;
    for (int i = 1; i < n - 1; i++) {
        l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }
    l[n - 1] = 1;
    z[n - 1] = 0;
    c[n - 1] = 0;

    for (int j = n - 2; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3.0;
        d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
    }

    for (int i = 0; i < n - 1; i++) {
        a[i] = y[i];
        cout << "Spline " << i + 1 << ": " << endl;
        cout << "a = " << a[i] << ", b = " << b[i] << ", c = " << c[i] << ", d = " << d[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;
    double x[n], y[n];
    cout << "Enter the x and y values: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cubicSplineInterpolation(x, y, n);
    return 0;
}

