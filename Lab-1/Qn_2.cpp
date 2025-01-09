#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return exp(-x) - x;
}

double f_prime(double x) {
    return -exp(-x) - 1;
}

void newton_method(double initial_guess, double tolerance, int maxIterations) {
    double x = initial_guess;
    int iterations = 0;
    double fx = f(x);
    
    cout << fixed << setprecision(6); 

    while (fabs(fx) > tolerance && iterations < maxIterations) {
        double fpx = f_prime(x);
        
        if (fabs(fpx) < 1e-10) { 
            cout << "Error: Derivative near zero. Newton's method fails.\n";
            return;
        }
        x = x - fx / fpx;
        fx = f(x);
        iterations++;
    }

    if (fabs(fx) <= tolerance) {
        cout << "Estimated root: " << x << endl;
        cout << "Functional value at root: " << fx << endl;
        cout << "Number of iterations: " << iterations << endl;
    } else {
        cout << "Newton's method did not converge within the maximum number of iterations.\n";
    }
}

int main() {
    double initial_guess, tolerance;
    int maxIterations;

    cout << "Enter the initial guess: ";
    cin >> initial_guess;

    cout << "Enter the tolerance (e.g., 0.0001): ";
    cin >> tolerance;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    newton_method(initial_guess, tolerance, maxIterations);

    return 0;
}

