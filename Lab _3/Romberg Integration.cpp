#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x;
}

double romberg(double a, double b, int n) {
    double h = (b - a);
    double R[n][n];
    R[0][0] = (h / 2) * (f(a) + f(b));

    for (int i = 1; i < n; i++) {
        h /= 2;
        double sum = 0;
        for (int k = 1; k <= (1 << (i - 1)); k++)
            sum += f(a + (2 * k - 1) * h);
        
        R[i][0] = 0.5 * R[i - 1][0] + h * sum;
        for (int j = 1; j <= i; j++)
            R[i][j] = (4 * R[i][j - 1] - R[i - 1][j - 1]) / 3;
    }
    return R[n - 1][n - 1];
}

int main() {
    double a, b;
    int n;
    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of iterations (n): ";
    cin >> n;

    cout << "Integral using Romberg Integration: " << romberg(a, b, n) << endl;
    return 0;
}

