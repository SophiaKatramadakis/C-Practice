#include <iostream>

double computeEffort(double load, double loadDist, double effDist) {
    return load * loadDist / effDist;
}

int main() {
    std::cout << "## Lever Effort Calculator ##\n";
    while (true) {
        double load, ld, ed;
        std::cout << "\nEnter load(N), load arm(m), effort arm(m) (0 to quit): ";
        std::cin >> load;
        if (load == 0) break;
        std::cin >> ld >> ed;
        if (ed == 0) {
            std::cout << "do not enter zero distance\n";
            continue;
        }
        double effort = computeEffort(load, ld, ed);
        std::cout << "--> You need " << effort << " N of effort\n";
    }
    return 0;
}
