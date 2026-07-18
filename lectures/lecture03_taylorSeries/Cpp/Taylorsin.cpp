#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <Eigen/Dense>

using namespace std;

// Funzione poly_eval semplice e affidabile
double poly_eval(const Eigen::VectorXd& coeffs, double x) {
    double result = 0.0;
    double xp = 1.0;
    for (int i = 0; i < coeffs.size(); ++i) {
        result += coeffs[i] * xp;
        xp *= x;
    }
    return result;
}

int main() {
    const int num_points = 2000;
    vector<double> x(num_points);
    
    for (int i = 0; i < num_points; ++i) {
        x[i] = -10.0 + (20.0 * i) / (num_points - 1);
    }

    vector<double> y_sin(num_points);
    for (int i = 0; i < num_points; ++i) {
        y_sin[i] = sin(x[i]);
    }

    Eigen::VectorXd c1(2);   c1 << 0.0, 1.0;
    Eigen::VectorXd c3(4);   c3 << 0.0, 1.0, 0.0, -1.0/6.0;
    Eigen::VectorXd c5(6);   c5 << 0.0, 1.0, 0.0, -1.0/6.0, 0.0, 1.0/120.0;
    Eigen::VectorXd c7(8);   c7 << 0.0, 1.0, 0.0, -1.0/6.0, 0.0, 1.0/120.0, 0.0, -1.0/5040.0;
    Eigen::VectorXd c9(10);  c9 << 0.0, 1.0, 0.0, -1.0/6.0, 0.0, 1.0/120.0, 0.0, -1.0/5040.0, 0.0, 1.0/362880.0;

    vector<double> y1(num_points), y3(num_points), y5(num_points), y7(num_points), y9(num_points);

    for (int i = 0; i < num_points; ++i) {
        y1[i] = poly_eval(c1, x[i]);
        y3[i] = poly_eval(c3, x[i]);
        y5[i] = poly_eval(c5, x[i]);
        y7[i] = poly_eval(c7, x[i]);
        y9[i] = poly_eval(c9, x[i]);
    }

    ofstream file("taylor_series.csv");
    if (!file.is_open()) {
        cerr << "Errore file" << endl;
        return 1;
    }

    file << "x,sin(x),Taylor_1,Taylor_3,Taylor_5,Taylor_7,Taylor_9\n";
    file << fixed << setprecision(8);

    for (int i = 0; i < num_points; ++i) {
        file << x[i] << "," << y_sin[i] << "," 
             << y1[i] << "," << y3[i] << "," 
             << y5[i] << "," << y7[i] << "," << y9[i] << "\n";
    }

    file.close();
    cout << "✅ taylor_series.csv creato con successo!" << endl;

    return 0;
}
