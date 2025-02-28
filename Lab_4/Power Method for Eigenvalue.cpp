#include<iostream>
#include<cmath>
using namespace std;

void powerMethod(float a[10][10], int n, int maxIter, float tolerance) {
    float x[10] = {1};
    float eigenvalue = 0;

    for(int iter = 0; iter < maxIter; iter++) {
        float new_x[10] = {0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                new_x[i] += a[i][j] * x[j];
            }
        }
        eigenvalue = fabs(new_x[0]);
        for(int i = 1; i < n; i++) {
            if(fabs(new_x[i]) > eigenvalue) {
                eigenvalue = fabs(new_x[i]);
            }
        }
        for(int i = 0; i < n; i++) {
            new_x[i] /= eigenvalue;
        }

        float diff = 0;
        for(int i = 0; i < n; i++) {
            diff += fabs(new_x[i] - x[i]);
        }

        if(diff < tolerance) break;

        for(int i = 0; i < n; i++) {
            x[i] = new_x[i];
        }
    }

    cout << "Estimated Eigenvalue: " << eigenvalue << endl;
    cout << "Eigenvector: ";
    for(int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, maxIter;
    float tolerance;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    float a[10][10];
    cout << "Enter the matrix: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    cout << "Enter tolerance: ";
    cin >> tolerance;

    powerMethod(a, n, maxIter, tolerance);
    return 0;
}

