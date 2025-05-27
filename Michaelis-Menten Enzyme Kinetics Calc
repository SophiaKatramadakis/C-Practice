#include <iostream>
#include <vector>
#include <sstream>

double rateMM(double Vmax, double Km, double S) {
    return Vmax * S / (Km + S);
}

std::vector<double> parseList(const std::string &line) {
    std::vector<double> vals;
    std::istringstream iss(line);
    double v;
    while (iss >> v) vals.push_back(v);
    return vals;
}

int main() {
    std::cout << "Enzyme Michaelis-Menten Calc\n";
    double Vmax, Km;
    std::cout << "Vmax: "; std::cin >> Vmax;
    std::cout << "Km: "; std::cin >> Km;
    std::cin.ignore(); // flush newline

    while (true) {
        std::cout << "\nEnter substrate concentrations separated by spaces\n(or 'q' to quit):\n> ";
        std::string line;
        std::getline(std::cin, line);
        if (line == "q") break;
        auto Slist = parseList(line);
        std::cout << "\n[S]\tRate\n";
        for (double S : Slist) {
            double v = rateMM(Vmax, Km, S);
            std::cout << S << "\t" << v << "\n"; // kinetics party
        }
    }
    return 0;
}
