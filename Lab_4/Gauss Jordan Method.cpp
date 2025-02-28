#include<iostream>
using namespace std;

void gaussJordan(float a[10][10], float b[10], int n) {
    for(int i = 0; i < n; i++) {
        float temp = a[i][i];
        for(int j = 0; j < n; j++) {
            a[i][j] /= temp;
        }
        b[i] /= temp;

        for(int j = 0; j < n; j++) {
            if(i != j) {
                temp = a[j][i];
                for(int k = 0; k < n; k++) {
                    a[j][k] -= a[i][k] * temp;
                }
                b[j] -= b[i] * temp;
            }
        }
    }

    cout << "Solution is: " << endl;
    for(int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << b[i] << endl;
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

    gaussJordan(a, b, n);
    return 0;
}

