#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <iomanip>

// Read space-separated doubles from a line
std::vector<double> parseDoubles(const std::string &line) {
    std::vector<double> vals;
    std::istringstream iss(line);
    double x;
    while (iss >> x) vals.push_back(x);
    return vals;
}

// Gaussian style force length
double forceLength(double lm, double l0) {
    double rel = (lm / l0 - 1.0) / 0.25;
    return std::exp(-rel * rel);
}

// Hill force velocity relationship
double forceVelocity(double vel, double Vmax) {
    if (vel < 0) {            // shortening (concentric)
        return (Vmax - vel) / (Vmax + 1.5 * (-vel));
    } else {                  // lengthening (eccentric)
        return 1.8;
    }
}

int main() {
    std::cout << "Hill-Type Muscle Model Simulator\n";

    double Fmax, l0, Vmax;
    std::cout << "Max isometric force Fmax (N): ";
    std::cin >> Fmax;
    std::cout << "Optimal length l0 (m): ";
    std::cin >> l0;
    std::cout << "Max shortening velocity Vmax (m/s): ";
    std::cin >> Vmax;
    std::cin.ignore();  // clear newline

    while (true) {
        std::cout << "\nEnter activation (0–1), length (m), vel (m/s)\nor 'q' to quit:\n> ";
        std::string line;
        std::getline(std::cin, line);
        if (line == "q" || line == "Q") break;

        auto input = parseDoubles(line);
        if (input.size() != 3) {
            std::cout << "Please enter 3 numbers.\n";
            continue;
        }

        double a   = std::clamp(input[0], 0.0, 1.0);
        double lm  = input[1];
        double vel = input[2];

        double FL   = forceLength(lm, l0);
        double FV   = forceVelocity(vel, Vmax);
        double Fmus = Fmax * a * FL * FV;

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "FL = " << FL
                  << "  FV = " << FV
                  << "  Muscle Force = " << Fmus << " N\n";
    }

    std::cout << "Exiting simulator.\n";
    return 0;
}
