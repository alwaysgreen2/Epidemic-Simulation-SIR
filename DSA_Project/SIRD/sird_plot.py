import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("sird_output.csv")

plt.figure(figsize=(10, 6))
plt.plot(data['Time'], data['Susceptible'], label='Susceptible', color='blue')
plt.plot(data['Time'], data['Infected'], label='Infected', color='red')
plt.plot(data['Time'], data['Recovered'], label='Recovered', color='green')
plt.plot(data['Time'], data['Deceased'], label='Deceased', color='black')

# Fill areas
plt.fill_between(data['Time'], data['Susceptible'], color='blue', alpha=0.3)
plt.fill_between(data['Time'], data['Infected'], color='red', alpha=0.3)
plt.fill_between(data['Time'], data['Recovered'], color='green', alpha=0.3)
plt.fill_between(data['Time'], data['Deceased'], color='black', alpha=0.3)

plt.xlabel('Time (days)')
plt.ylabel('Number of Individuals')
plt.title('SIRD Model Simulation')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

