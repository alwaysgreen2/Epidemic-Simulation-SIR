#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>

int main() {
    int N, S, I, R;
    double beta, gamma;
    double duration;
    int steps;

    std::cout << "Enter total population (N): ";
    std::cin >> N;

    std::cout << "Enter initial infected (I): ";
    std::cin >> I;

    std::cout << "Enter initial recovered (R): ";
    std::cin >> R;

    S = N - I - R;
    if (S < 0) {
        std::cerr << "Invalid initial values.\n";
        return 1;
    }

    std::cout << "Calculated initial susceptible (S): " << S << "\n";

    std::cout << "Enter transmission rate (beta) [0.1 - 0.5]: ";
    std::cin >> beta;
    std::cout << "Enter recovery rate (gamma) [0.05 - 0.2]: ";
    std::cin >> gamma;
    std::cout << "Enter duration in days: ";
    std::cin >> duration;
    std::cout << "Enter number of time steps: ";
    std::cin >> steps;

    double dt = duration / steps;

    std::ofstream file("stochastic_sir.csv");
    file << "Time,Susceptible,Infected,Recovered\n";
    file << std::fixed << std::setprecision(6);

    std::random_device rd;
    std::mt19937 gen(rd());

    for (int step = 0; step <= steps; ++step) {
        double t = step * dt;
        file << t << "," << S << "," << I << "," << R << "\n";

        if (I == 0) break; // epidemic ends

        double p_infect = beta * S * I / static_cast<double>(N) * dt;
        double p_recover = gamma * I * dt;

        std::binomial_distribution<int> infect_dist(S, std::min(p_infect, 1.0));
        std::binomial_distribution<int> recover_dist(I, std::min(p_recover, 1.0));

        int new_infections = infect_dist(gen);
        int new_recoveries = recover_dist(gen);

        new_infections = std::min(new_infections, S);
        new_recoveries = std::min(new_recoveries, I);

        S -= new_infections;
        I += new_infections - new_recoveries;
        R += new_recoveries;
    }

    file.close();
    std::cout << "Simulation complete. Data saved to 'stochastic_sir.csv'.\n";
    return 0;
}

