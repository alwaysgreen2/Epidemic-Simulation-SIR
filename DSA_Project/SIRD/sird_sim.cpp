#include <iostream>
#include <fstream>
#include <iomanip>

struct SIRD {
    double S, I, R, D;
};

SIRD derivatives(const SIRD& state, double beta, double gamma, double mu, double N) {
    SIRD dState;
    dState.S = -beta * state.S * state.I / N;
    dState.I = beta * state.S * state.I / N - gamma * state.I - mu * state.I;
    dState.R = gamma * state.I;
    dState.D = mu * state.I;
    return dState;
}

SIRD rk4_step(const SIRD& state, double dt, double beta, double gamma, double mu, double N) {
    SIRD k1 = derivatives(state, beta, gamma, mu, N);

    SIRD temp;
    temp.S = state.S + 0.5 * dt * k1.S;
    temp.I = state.I + 0.5 * dt * k1.I;
    temp.R = state.R + 0.5 * dt * k1.R;
    temp.D = state.D + 0.5 * dt * k1.D;
    SIRD k2 = derivatives(temp, beta, gamma, mu, N);

    temp.S = state.S + 0.5 * dt * k2.S;
    temp.I = state.I + 0.5 * dt * k2.I;
    temp.R = state.R + 0.5 * dt * k2.R;
    temp.D = state.D + 0.5 * dt * k2.D;
    SIRD k3 = derivatives(temp, beta, gamma, mu, N);

    temp.S = state.S + dt * k3.S;
    temp.I = state.I + dt * k3.I;
    temp.R = state.R + dt * k3.R;
    temp.D = state.D + dt * k3.D;
    SIRD k4 = derivatives(temp, beta, gamma, mu, N);

    SIRD next;
    next.S = state.S + (dt / 6.0) * (k1.S + 2*k2.S + 2*k3.S + k4.S);
    next.I = state.I + (dt / 6.0) * (k1.I + 2*k2.I + 2*k3.I + k4.I);
    next.R = state.R + (dt / 6.0) * (k1.R + 2*k2.R + 2*k3.R + k4.R);
    next.D = state.D + (dt / 6.0) * (k1.D + 2*k2.D + 2*k3.D + k4.D);
    return next;
}

int main() {
    double N, I0, R0, D0, beta, gamma, mu, duration;
    int steps;

    std::cout << "Enter total population (N): ";
    std::cin >> N;

    std::cout << "Enter initial infected (I0): ";
    std::cin >> I0;

    std::cout << "Enter initial recovered (R0): ";
    std::cin >> R0;

    std::cout << "Enter initial deceased (D0): ";
    std::cin >> D0;

    double S0 = N - I0 - R0 - D0;
    if (S0 < 0) {
        std::cerr << "Error: I0 + R0 + D0 exceeds N\n";
        return 1;
    }
    std::cout << "Calculated initial susceptible (S0): " << S0 << "\n";

    std::cout << "Enter transmission rate (beta) [0.1 - 0.5]: ";
    std::cin >> beta;

    std::cout << "Enter recovery rate (gamma) [0.05 - 0.2]: ";
    std::cin >> gamma;

    std::cout << "Enter mortality rate (mu) [0.001 - 0.05]: ";
    std::cin >> mu;

    std::cout << "Enter duration (days): ";
    std::cin >> duration;

    std::cout << "Enter number of time steps: ";
    std::cin >> steps;

    double dt = duration / steps;

    SIRD state = {S0, I0, R0, D0};

    std::ofstream file("sird_output.csv");
    file << "Time,Susceptible,Infected,Recovered,Deceased\n";
    file << std::fixed << std::setprecision(6);

    for (int i = 0; i <= steps; ++i) {
        double t = i * dt;
        file << t << "," << state.S << "," << state.I << "," << state.R << "," << state.D << "\n";
        state = rk4_step(state, dt, beta, gamma, mu, N);
    }

    file.close();
    std::cout << "Results saved to 'sird_output.csv'\n";
    return 0;
}

