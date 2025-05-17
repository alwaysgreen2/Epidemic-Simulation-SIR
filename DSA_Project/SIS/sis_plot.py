import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv('sis_output.csv')

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(data['Time'], data['Susceptible'], label='Susceptible', color='blue')
plt.plot(data['Time'], data['Infected'], label='Infected', color='red')

# Fill areas under the curves
plt.fill_between(data['Time'], data['Susceptible'], color='blue', alpha=0.3)
plt.fill_between(data['Time'], data['Infected'], color='red', alpha=0.3)

plt.xlabel('Time (days)')
plt.ylabel('Number of Individuals')
plt.title('SIS Model Simulation')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

