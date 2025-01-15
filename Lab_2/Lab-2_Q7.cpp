#include <iostream>
using namespace std;

void leastSquaresLinear(double x[], double y[], int n) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }
    
    double m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double b = (sumY - m * sumX) / n;
    
    cout << "Linear fit: y = " << m << "x + " << b << endl;
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
    leastSquaresLinear(x, y, n);
    return 0;
}

