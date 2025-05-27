#include <iostream>
#include <vector>
#include <iomanip>

// logistic growth increment
double deltaN(double N, double r, double K) {
    return r * N * (1 - N / K);
}

int main() {
    std::cout << "Bacterial Population Growth\n";
    double r, K, N0;
    int steps;
    std::cout << "Enter growth rate (r): ";              std::cin >> r;
    std::cout << "Enter carrying capacity (K): ";        std::cin >> K;
    std::cout << "Enter initial population (N0): ";      std::cin >> N0;
    std::cout << "Enter number of time steps: ";         std::cin >> steps;

    std::vector<double> N(steps + 1);
    N[0] = N0;

    // simulate
    for (int t = 0; t < steps; ++t) {
        double dN = deltaN(N[t], r, K);
        N[t+1] = N[t] + dN;
        if (N[t+1] < 0) N[t+1] = 0;               // no negative bugs
    }

    // output table
    std::cout << "\nTime\tPopulation\n";
    for (int t = 0; t <= steps; ++t) {
        std::cout << std::setw(4) << t << "\t"
                  << std::fixed << std::setprecision(2)
                  << N[t] << "\n";
    }
    return 0;
}
