//Genera 2000 punti tra -10 e 10, calcola sin(x) e vari polinomi di Taylor per approssimare sin(x), poi salva tutto in un file CSV
//

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>      // Per formattare l'output
#include <unsupported/Eigen/Polynomials>  // Per la funzione poly_eval

// Usiamo un alias per rendere il codice più leggibile
using namespace std;

// La funzione poly_eval di Eigen si aspetta i coefficienti in ordine di grado crescente.
// Ad esempio, per il polinomio x^3 - x + 1, il vettore sarà: [1, -1, 0, 1].
// La useremo per valutare i nostri polinomi.

int main() {
    // --- 1. Creazione del vettore x ---
    // Generiamo 2000 punti da -10 a 10
    const int num_points = 2000;
    vector<double> x(num_points);
    for (int i = 0; i < num_points; ++i) {
        x[i] = -10.0 + (20.0 * i) / (num_points - 1);
    }

    // --- 2. Calcolo della funzione sin(x) ---
    vector<double> y_sin(num_points);
    for (int i = 0; i < num_points; ++i) {
        y_sin[i] = sin(x[i]);
    }

    // --- 3. Definizione dei polinomi di Taylor ---
    // ATTENZIONE: i coefficienti sono in ORDINE CRESCENTE di grado!
    // poly_eval([a0, a1, a2, ...], x) calcola: a0 + a1*x + a2*x^2 + ...

    // Primo ordine: x
    Eigen::VectorXd coeffs_1(2);
    coeffs_1 << 0.0, 1.0;      // 0 + 1*x

    // Terzo ordine: x - x^3/6
    Eigen::VectorXd coeffs_3(4);
    coeffs_3 << 0.0, 1.0, 0.0, -1.0/6.0;   // 0 + x + 0*x^2 - (1/6)*x^3

    // Quinto ordine: x - x^3/6 + x^5/120
    Eigen::VectorXd coeffs_5(6);
    coeffs_5 << 0.0, 1.0, 0.0, -1.0/6.0, 0.0, 1.0/120.0;

    // Settimo ordine: x - x^3/6 + x^5/120 - x^7/5040
    Eigen::VectorXd coeffs_7(8);
    coeffs_7 << 0.0, 1.0, 0.0, -1.0/6.0, 0.0, 1.0/120.0, 0.0, -1.0/5040.0;

    // Nono ordine: x - x^3/6 + x^5/120 - x^7/5040 + x^9/362880
    Eigen::VectorXd coeffs_9(10);
    coeffs_9 << 0.0, 1.0, 0.0, -1.0/6.0, 0.0, 1.0/120.0, 0.0, -1.0/5040.0, 0.0, 1.0/362880.0;

    // --- 4. Valutazione dei polinomi su tutto il vettore x ---
    // La funzione poly_eval di Eigen può valutare un polinomio su un intero vettore.
    // Restituisce un Eigen::VectorXd che contiene i risultati.
    Eigen::Map<const Eigen::VectorXd> x_map(x.data(), x.size()); // Mappa il vector<double> in un VectorXd

    Eigen::VectorXd yT1 = poly_eval(coeffs_1, x_map);
    Eigen::VectorXd yT3 = poly_eval(coeffs_3, x_map);
    Eigen::VectorXd yT5 = poly_eval(coeffs_5, x_map);
    Eigen::VectorXd yT7 = poly_eval(coeffs_7, x_map);
    Eigen::VectorXd yT9 = poly_eval(coeffs_9, x_map);

    // --- 5. Salvataggio dei dati in un file CSV ---
    ofstream file("taylor_series.csv");
    if (!file.is_open()) {
        cerr << "Errore: impossibile aprire il file." << endl;
        return 1;
    }

    // Intestazione del file CSV
    file << "x,sin(x),Taylor_1,Taylor_3,Taylor_5,Taylor_7,Taylor_9\n";

    // Scriviamo i dati con una precisione di 6 decimali
    file << fixed << setprecision(6);
    for (int i = 0; i < num_points; ++i) {
        file << x[i] << ","
             << y_sin[i] << ","
             << yT1[i] << ","
             << yT3[i] << ","
             << yT5[i] << ","
             << yT7[i] << ","
             << yT9[i] << "\n";
    }

    file.close();
    cout << "Dati salvati in 'taylor_series.csv'" << endl;

    return 0;
}
