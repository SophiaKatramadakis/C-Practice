#include <iostream>
#include <cmath>

void runSimulation() {
    double Vd, dose, kel, dt, cutoff;
    std::cout << "Vd (L): "; std::cin >> Vd;
    std::cout << "Dose (mg): "; std::cin >> dose;
    std::cout << "Elim rate k_el (1/hr): "; std::cin >> kel;
    std::cout << "Time step dt (hr): "; std::cin >> dt;
    std::cout << "Terminate conc cutoff (mg/L): "; std::cin >> cutoff;

    double Cp = dose / Vd;
    double t = 0;
    std::cout << "\nTime(hr)\tConc(mg/L)\n";
    while (Cp > cutoff) {
        std::cout << t << "\t\t" << Cp << "\n"; // progress
        Cp *= std::exp(-kel * dt);
        t += dt;
    }
    std::cout << t << "\t\t" << Cp << "  // below cutoff\n\n";
}

int main() {
    std::cout << "=== Drug Infusion PK Simulator ===\n";
    char choice;
    do {
        runSimulation();
        std::cout << "Run again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
