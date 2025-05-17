#include <iostream>
#include <fstream>
#include <iomanip> // For std::setprecision

struct SIS {
    double S;
    double I;
};

// Function to compute derivatives
SIS derivatives(const SIS& state, double beta, double gamma, double N) {
    SIS dState;
    dState.S = -beta * state.S * state.I / N + gamma * state.I;
    dState.I = beta * state.S * state.I / N - gamma * state.I;
    return dState;
}

// RK4 step
SIS rk4_step(const SIS& state, double dt, double beta, double gamma, double N) {
    SIS k1 = derivatives(state, beta, gamma, N);

    SIS temp;
    temp.S = state.S + 0.5 * dt * k1.S;
    temp.I = state.I + 0.5 * dt * k1.I;
    SIS k2 = derivatives(temp, beta, gamma, N);

    temp.S = state.S + 0.5 * dt * k2.S;
    temp.I = state.I + 0.5 * dt * k2.I;
    SIS k3 = derivatives(temp, beta, gamma, N);

    temp.S = state.S + dt * k3.S;
    temp.I = state.I + dt * k3.I;
    SIS k4 = derivatives(temp, beta, gamma, N);

    SIS nextState;
    nextState.S = state.S + (dt / 6.0) * (k1.S + 2 * k2.S + 2 * k3.S + k4.S);
    nextState.I = state.I + (dt / 6.0) * (k1.I + 2 * k2.I + 2 * k3.I + k4.I);

    return nextState;
}

int main() {
    double N, S0, I0;
    double beta, gamma;
    double duration;
    int steps;

    // User input
    std::cout << "Enter total population (N): ";
    std::cin >> N;
    std::cout << "Enter initial infected individuals (I0): ";
    std::cin >> I0;

    // Calculate S0 to ensure S0 + I0 == N
    S0 = N - I0;
    if (S0 < 0) {
        std::cerr << "Error: Initial infected individuals exceed total population.\n";
        return 1;
    }

    std::cout << "Calculated initial susceptible individuals (S0): " << S0 << "\n";

    std::cout << "Enter transmission rate (beta) [Typical range: 0.1 to 0.5 per day]: ";
    std::cin >> beta;
    std::cout << "Enter recovery rate (gamma) [Typical range: 0.05 to 0.2 per day]: ";
    std::cin >> gamma;

    std::cout << "Enter total simulation duration in days (e.g., 160): ";
    std::cin >> duration;
    std::cout << "Enter number of time steps (e.g., 1600): ";
    std::cin >> steps;

    double dt = duration / steps;

    SIS state = {S0, I0};

    std::ofstream file("sis_output.csv");
    file << "Time,Susceptible,Infected\n";
    file << std::fixed << std::setprecision(6); // Set precision for floating-point output

    for (int i = 0; i <= steps; ++i) {
        double time = i * dt;
        file << time << "," << state.S << "," << state.I << "\n";
        state = rk4_step(state, dt, beta, gamma, N);
    }

    file.close();
    std::cout << "Simulation complete. Data written to 'sis_output.csv'.\n";
    return 0;
}

