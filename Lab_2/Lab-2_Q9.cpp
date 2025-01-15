#include <iostream>
using namespace std;

void leastSquaresPolynomial(double x[], double y[], int n) {
    double sumX = 0, sumY = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0, sumXY = 0, sumX2Y = 0;
    
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumX2 += x[i] * x[i];
        sumX3 += x[i] * x[i] * x[i];
        sumX4 += x[i] * x[i] * x[i] * x[i];
        sumXY += x[i] * y[i];
        sumX2Y += x[i] * x[i] * y[i];
    }
    
    double denominator = n * sumX2 * sumX4 + 2 * sumX * sumX2 * sumX3 - sumX2 * sumX2 * sumX2 - n * sumX3 * sumX3 - sumX * sumX4 * sumX;
    double a = (sumY * sumX2 * sumX4 + sumX * sumX2 * sumX2Y + sumXY * sumX3 * sumX - sumX2 * sumX2 * sumXY - sumX * sumX4 * sumY - sumX3 * sumX3 * sumY) / denominator;
    double b = (n * sumX2Y * sumX4 + sumX * sumX2 * sumX2Y + sumXY * sumX2 * sumX - sumX3 * sumX3 * sumY - sumX2 * sumX4 * sumY) / denominator;
    double c = (sumY * sumX3 * sumX2 + sumX * sumX2 * sumX2Y + sumX2 * sumX2 * sumXY - sumX2 * sumX4 * sumY - sumX3 * sumX3 * sumY) / denominator;
    
    cout << "Polynomial fit: y = " << a << "x^2 + " << b << "x + " << c << endl;
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
    leastSquaresPolynomial(x, y, n);
    return 0;
}

