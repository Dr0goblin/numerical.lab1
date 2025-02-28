#include<iostream>
using namespace std;

void gaussElimination(float a[10][10], float b[10], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            float ratio = a[j][i] / a[i][i];
            for(int k = i; k < n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
            b[j] -= ratio * b[i];
        }
    }

    float x[10];
    for(int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for(int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    cout << "Solution is: " << endl;
    for(int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    float a[10][10], b[10];
    cout << "Enter the augmented matrix (coefficients + constants): " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        cin >> b[i];
    }

    gaussElimination(a, b, n);
    return 0;
}

