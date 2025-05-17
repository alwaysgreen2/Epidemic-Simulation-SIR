# Epidemic-Simulation-SIR
Compartmental models are a mathematical framework which describes how population moves between various states (compartments).They are widely used in the mathematical modelling of infectious diseases.The compartments are given by a short hand notation usually which is the first letter of the compartment.The sequence of letters indicates the flow pattern between different comparments.
These models are usually implemented with ODEs (Ordinary Differential Equations) providing deterministic results (same input , same output).For more realistic representation we could use stochastic frameworks but they have greater complexity.
Limitation: Works with large populations
We have multiple models and we solve them and plot the results using matplotlib.
The models are SIR,SIRD,SIS,Stochastic SIR.
_______________________________________

1. SIR:
The SIR model divides the population into three compartments: 
•	Susceptible (S): Individuals who can contract the disease.
•	Infected (I): Individuals who have the disease and can transmit it.
•	Recovered (R): Individuals who have recovered and gained immunity. 
The model uses differential equations to describe the rates at which individuals move from susceptible to infected and from infected to recovered.
_______________________________________

2. SIS Model (Susceptible-Infected-Susceptible)
   
In the SIS model, individuals who recover from the disease return to the susceptible state, as no lasting immunity is conferred. This model is suitable for diseases like the common cold or influenza, where reinfection is possible. 
________________________________________

3. SIRD Model (Susceptible-Infected-Recovered-Deceased)
The SIRD model extends the SIR model by adding a Deceased (D) compartment to account for disease-induced mortality. The compartments are
•	Susceptible (S)
•	Infected (I)
•	Recovered (R)
•	Deceased (D)
This model provides a more comprehensive view by tracking fatalities alongside recoveries. 
________________________________________

4. Stochastic SIR Model
The stochastic SIR model incorporates randomness into the transmission and recovery processes, acknowledging that real-world disease spread involves probabilistic events. This model is particularly useful for small populations or early outbreak stages, where chance events significantly influence outcomes.

__________________________________________

The algorithm
A numerical algorithm is used here.The Runge-Kutta (RK) methods, particularly the fourth-order Runge-Kutta (RK4), are widely for solving ordinary differential equations (ODEs) that arise in epidemiological models like SIR, SIS, and SIRD. These models describe the dynamics of disease spread through compartments representing different population groups.

__________________________________________

The code
We solve the ODEs using RK method then output the results to csv. Using matplotlib in python we plot the results. The user can provide input values.We also set a precision for the floating point numbers. We store the derivatives in a struct and the numerical integration is then done.

___________________________________________

Outputs

SIR model


![image](https://github.com/user-attachments/assets/4d74f411-ca8c-49f4-ba9c-ff663aa558bc)
![image](https://github.com/user-attachments/assets/fd86fd17-ab78-44af-a46f-bef37f31b46b)

____________________________________________

SIRD model


![image](https://github.com/user-attachments/assets/d4c1aa6a-cde4-4352-a18f-d1266a730332)
![image](https://github.com/user-attachments/assets/537b36e4-5ab0-473e-aa73-46d5a1bd6bab)


____________________________________________

SIS model


![image](https://github.com/user-attachments/assets/92f2475f-a8c6-4d3b-96e2-c31f0e3c3d25)
![image](https://github.com/user-attachments/assets/5fd3042c-63aa-4803-8a75-0f117587db73)



___________________________________________

Stochastic SIR model 


![image](https://github.com/user-attachments/assets/752cf69c-844f-4bdb-8024-de1475a0d978)
![image](https://github.com/user-attachments/assets/26726a7a-1524-4183-b0e1-63f03f22d30a)











