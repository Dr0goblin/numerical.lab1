#include <iostream>
using namespace std;

float newtonForward(float x[], float y[], int n, float xi) {
    float diffTable[n][n];
    for (int i = 0; i < n; i++)
        diffTable[i][0] = y[i];
    for (int j = 1; j < n; j++)
        for (int i = 0; i < n - j; i++)
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
    float result = diffTable[0][0];
    float term = 1.0;
    float h = x[1] - x[0];
    float u = (xi - x[0]) / h;
    for (int i = 1; i < n; i++) {
        term *= (u - i + 1) / i;
        result += term * diffTable[0][i];
    }
    return result;
}

int main() {
    float x[] = {0, 1, 2, 3};
    float y[] = {1, 2, 0, 5};
    int n = 4;
    float xi = 2.5;
    cout << "Newton Forward Difference result at x = " << xi << " is: " << newtonForward(x, y, n, xi) << endl;
    return 0;
}

