import pandas as pd
import matplotlib.pyplot as plt

# Read CSV
data = pd.read_csv('sir_output.csv')

# Plotting
plt.figure(figsize=(10,6))
plt.plot(data['Time'], data['Susceptible'], label='Susceptible', color='blue')
plt.fill_between(data['Time'], data['Susceptible'], color='blue', alpha=0.3)

plt.plot(data['Time'], data['Infected'], label='Infected', color='red')
plt.fill_between(data['Time'], data['Infected'], color='red', alpha=0.3)

plt.plot(data['Time'], data['Recovered'], label='Recovered', color='green')
plt.fill_between(data['Time'], data['Recovered'], color='green', alpha=0.3)

plt.xlabel('Time')
plt.ylabel('Population')
plt.title('SIR Model Simulation')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

