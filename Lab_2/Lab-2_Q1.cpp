#include <iostream>
using namespace std;

float lagrangeInterpolation(float x[], float y[], int n, float xi) {
    float result = 0.0;
    for (int i = 0; i < n; i++) {
        float term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i)
                term *= (xi - x[j]) / (x[i] - x[j]);
        }
        result += term;
    }
    return result;
}

int main() {
    float x[] = {0, 1, 2, 3};
    float y[] = {1, 2, 0, 5};
    int n = 4;
    float xi = 2.5;
    cout << "Lagrange Interpolation result at x = " << xi << " is: " << lagrangeInterpolation(x, y, n, xi) << endl;
    return 0;
}

