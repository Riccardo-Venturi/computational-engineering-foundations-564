#include <iostream>
#include <vector>

// Simulates weather changes with Markov Chain
//Discrete markov Chain
int main() {

    std::vector<std::vector<double>> A = {
        {0.25, 0.5,  0.25},
        {0.5,  0.5,  0.25},
        {0.25, 0.0,  0.5 }
    };

    std::vector<double> x = {1.0, 0.0, 0.0}; // initial state: Rain 100%

    int days = 10;

    // Better output formatting
    std::cout << "Initial: Rain=" << x[0]
              << " Cloud=" << x[1]
              << " Sun=" << x[2] << "\n";

    for (int day = 0; day < days; ++day) {

        std::vector<double> nuovo_x(3, 0.0);

        // Matrix * Vector multiplication
        for (size_t i = 0; i < A.size(); ++i) {
            for (size_t j = 0; j < A[i].size(); ++j) {
                nuovo_x[i] += A[i][j] * x[j];
            }
        }

        x = nuovo_x;

        std::cout << "Day " << day+1
                  << ": Rain=" << x[0]
                  << " Cloud=" << x[1]
                  << " Sun=" << x[2] << '\n';
    }

    return 0;
}
