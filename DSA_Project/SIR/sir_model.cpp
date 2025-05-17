#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> 

struct SIR {
    double S;
    double I;
    double R;
};

// Function to compute derivatives
SIR derivatives(const SIR& state, double beta, double gamma, double N) {
    SIR dState;
    dState.S = -beta * state.S * state.I / N;
    dState.I = beta * state.S * state.I / N - gamma * state.I;
    dState.R = gamma * state.I;
    return dState;
}

// RK4 step
SIR rk4_step(const SIR& state, double dt, double beta, double gamma, double N) {
    SIR k1 = derivatives(state, beta, gamma, N);

    SIR temp;
    temp.S = state.S + 0.5 * dt * k1.S;
    temp.I = state.I + 0.5 * dt * k1.I;
    temp.R = state.R + 0.5 * dt * k1.R;
    SIR k2 = derivatives(temp, beta, gamma, N);

    temp.S = state.S + 0.5 * dt * k2.S;
    temp.I = state.I + 0.5 * dt * k2.I;
    temp.R = state.R + 0.5 * dt * k2.R;
    SIR k3 = derivatives(temp, beta, gamma, N);

    temp.S = state.S + dt * k3.S;
    temp.I = state.I + dt * k3.I;
    temp.R = state.R + dt * k3.R;
    SIR k4 = derivatives(temp, beta, gamma, N);

    SIR nextState;
    nextState.S = state.S + (dt / 6.0) * (k1.S + 2 * k2.S + 2 * k3.S + k4.S);
    nextState.I = state.I + (dt / 6.0) * (k1.I + 2 * k2.I + 2 * k3.I + k4.I);
    nextState.R = state.R + (dt / 6.0) * (k1.R + 2 * k2.R + 2 * k3.R + k4.R);

    return nextState;
}

int main() {
    double N, S0, I0, R0;
    double beta, gamma;
    double duration;
    int steps;

    // User input
    std::cout << "Enter total population (N): ";
    std::cin >> N;
    std::cout << "Enter initial infected individuals (I0): ";
    std::cin >> I0;
    std::cout << "Enter initial recovered individuals (R0): ";
    std::cin >> R0;

    // Calculate S0 to ensure S0 + I0 + R0 == N
    S0 = N - I0 - R0;
    if (S0 < 0) {
        std::cerr << "Error: The sum of I0 and R0 exceeds the total population N.\n";
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

    SIR state = {S0, I0, R0};

    std::ofstream file("sir_output.csv");
    file << "Time,Susceptible,Infected,Recovered\n";
    file << std::fixed << std::setprecision(6); // Set precision for floating-point output

    for (int i = 0; i <= steps; ++i) {
        double time = i * dt;
        file << time << "," << state.S << "," << state.I << "," << state.R << "\n";
        state = rk4_step(state, dt, beta, gamma, N);
    }

    file.close();
    std::cout << "Simulation complete. Data written to 'sir_output.csv'.\n";
    return 0;
}

