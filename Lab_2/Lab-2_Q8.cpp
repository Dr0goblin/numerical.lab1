#include <iostream>
#include <cmath>
using namespace std;

void leastSquaresNonLinear(double x[], double y[], int n) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += log(y[i]);
        sumXY += x[i] * log(y[i]);
        sumX2 += x[i] * x[i];
    }
    
    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = exp((sumY - b * sumX) / n);
    
    cout << "Non-linear fit: y = " << a << " * e^(" << b << "x)" << endl;
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
    leastSquaresNonLinear(x, y, n);
    return 0;
}

