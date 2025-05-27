#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

std::vector<double> loadSignal(const std::string &fname) {
    std::ifstream in(fname);
    if (!in) {
        std::cerr << "Oops, cannot open " << fname << "\n";
        return {};
    }
    std::vector<double> sig;
    double x;
    while (in >> x) sig.push_back(x);
    return sig;
}

std::vector<double> smooth(const std::vector<double> &sig, int w) {
    int n = sig.size();
    std::vector<double> f(n, 0.0);
    for (int i = 0; i < n; ++i) {
        double sum = 0; int cnt = 0;
        for (int j = i - w; j <= i + w; ++j) {
            if (j >= 0 && j < n) { sum += sig[j]; ++cnt; }
        }
        f[i] = sum / cnt; // average it
    }
    return f;
}

std::vector<int> detectPeaks(const std::vector<double> &filt, double thr) {
    std::vector<int> beats;
    for (size_t i = 1; i + 1 < filt.size(); ++i) {
        if (filt[i] > filt[i-1] && filt[i] > filt[i+1] && filt[i] > thr)
            beats.push_back(i);
    }
    return beats;
}

int main() {
    std::cout << "Enter ECG data file: ";
    std::string fname; std::cin >> fname;
    auto sig = loadSignal(fname);
    if (sig.empty()) return 1;
    int window; double threshold;
    std::cout << "Smoothing window half-size: "; std::cin >> window;
    std::cout << "Peak threshold: "; std::cin >> threshold;
    auto filt = smooth(sig, window);
    auto beats = detectPeaks(filt, threshold);
    std::cout << "\nDetected " << beats.size() << " beats at indices:\n";
    for (int idx : beats) std::cout << idx << "  ";
    // estimate BPM assuming sampling rate e.g. 250 Hz
    double fs = 250.0;
    if (beats.size() > 1) {
        double duration = (beats.back() - beats.front()) / fs;
        double bpm = (beats.size() - 1) / duration * 60.0;
        std::cout << "\nEstimated HR: " << std::fixed << std::setprecision(1) << bpm << " bpm\n";
    }
    return 0;
}
