#include <iostream>

int main() {
    // Matrice di transizione (riga: oggi, colonna: domani)
    double A[3][3] = {
        {0.25, 0.5, 0.25},
        {0.5,  0.5, 0.25},
        {0.25, 0.0, 0.5 }
    };

    // Stato iniziale: Pioggia=1, Nuvole=0, Sole=0
    double x[3] = {1.0, 0.0, 0.0};

    int giorni = 10;

    std::cout << "Previsione meteo (C++)" << std::endl;
    std::cout << "Stato iniziale: Pioggia=" << x[0]
              << " Nuvole=" << x[1]
              << " Sole=" << x[2] << std::endl;

    for (int giorno = 0; giorno < giorni; giorno++) {
        double nuovo_x[3] = {0.0, 0.0, 0.0};

        // Calcolo del prodotto matrice-vettore
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                nuovo_x[i] += A[i][j] * x[j];
            }
        }

        // Copia i nuovi valori in x
        for (int i = 0; i < 3; i++) {
            x[i] = nuovo_x[i];
        }

        // Stampa formattata
        std::cout << "Giorno " << giorno + 1 << ": "
                  << "Pioggia=" << x[0]
                  << " Nuvole=" << x[1]
                  << " Sole=" << x[2] << std::endl;
    }

    return 0;
}
