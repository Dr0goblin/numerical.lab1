#include <iostream>
using namespace std;

double centralDifferenceInterpolation(double x[], double y[], int n, double x0) {
    double result = y[n / 2];
    double h = x[1] - x[0];
    double u = (x0 - x[n / 2]) / h;

    for (int i = 1; i < n; i++) {
        double term = 0;
        for (int j = i; j < n - i; j++) {
            term += (y[j + 1] - y[j]);
        }
        result += term * u / (i * h);
        u *= (x0 - x[n / 2 - i]) / (x[n / 2 + i] - x[n / 2 - i]);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;
    double x[n], y[n], x0;
    cout << "Enter the x and y values: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << "Enter the value of x to approximate: ";
    cin >> x0;
    cout << "Approximated value: " << centralDifferenceInterpolation(x, y, n, x0) << endl;
    return 0;
}

