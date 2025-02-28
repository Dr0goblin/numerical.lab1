#include<iostream>
#include<cmath>
using namespace std;

void jacobi(float a[10][10], float b[10], float x[10], int n, float tolerance) {
    float x_new[10];
    do {
        for(int i = 0; i < n; i++) {
            x_new[i] = b[i];
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    x_new[i] -= a[i][j] * x[j];
                }
            }
            x_new[i] /= a[i][i];
        }

        bool stop = true;
        for(int i = 0; i < n; i++) {
            if(fabs(x_new[i] - x[i]) > tolerance) {
                stop = false;
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            x[i] = x_new[i];
        }

        if(stop) break;
    } while(true);

    cout << "Solution is: " << endl;
    for(int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    float a[10][10], b[10], x[10] = {0};
    cout << "Enter the augmented matrix (coefficients + constants): " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        cin >> b[i];
    }

    float tolerance;
    cout << "Enter the tolerance: ";
    cin >> tolerance;

    jacobi(a, b, x, n, tolerance);
    return 0;
}

