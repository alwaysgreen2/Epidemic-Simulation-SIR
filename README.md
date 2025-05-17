# Epidemic-Simulation-SIR
Compartmental models are a mathematical framework which describes how population moves between various states (compartments).They are widely used in the mathematical modelling of infectious diseases.The compartments are given by a short hand notation usually which is the first letter of the compartment.The sequence of letters indicates the flow pattern between different comparments.
These models are usually implemented with ODEs (Ordinary Differential Equations) providing deterministic results (same input , same output).For more realistic representation we could use stochastic frameworks but they have greater complexity.
Limitation: Works with large populations
We have multiple models and we solve them and plot the results using matplotlib.
The models are SIR,SIRD,SIS,Stochastic SIR.
SIR:
The SIR model divides the population into three compartments: 
•	Susceptible (S): Individuals who can contract the disease.
•	Infected (I): Individuals who have the disease and can transmit it.
•	Recovered (R): Individuals who have recovered and gained immunity. 
The model uses differential equations to describe the rates at which individuals move from susceptible to infected and from infected to recovered.
SIS Model (Susceptible-Infected-Susceptible)
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

