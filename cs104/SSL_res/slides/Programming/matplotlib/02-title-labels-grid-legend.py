import numpy as np
import matplotlib.pyplot as plt

# Data for the first plot (Sports Watch Data)
x = np.array([80, 85, 90, 95, 100, 105, 110, 115, 120, 125])
y = np.array([240, 250, 260, 270, 280, 290, 300, 310, 320, 330])

# Data for the sine wave plot
x_sine = np.linspace(0, 2 * np.pi, 100)  # X values for sine wave
y_sine = np.sin(x_sine)  # Y values for sine wave

# Font settings
font1 = {'family': 'serif', 'color': 'blue', 'size': 20}
font2 = {'family': 'serif', 'color': 'darkred', 'size': 15}

# Plot the first graph (Sports Watch Data)
plt.title("Sports Watch Data", fontdict=font1, loc='left')
plt.xlabel("Average Pulse", fontdict=font2)
plt.ylabel("Calorie Burnage", fontdict=font2)
plt.plot(x, y, label="Calories vs Pulse")  # Adding label for the legend

# Add grid and legend to the first plot
plt.grid(axis='y')
plt.legend(loc='upper left')  # Show legend

# Show the first plot
plt.show()

# Plot the second graph (Sine Wave)
plt.title("Sine Wave", fontdict=font1, loc='left')
plt.xlabel("Angle in Radians", fontdict=font2)
plt.ylabel("Sine of Angle", fontdict=font2)
plt.plot(x_sine, y_sine, label="Sine Function")  # Adding label for the legend

# Add grid and legend to the second plot
plt.grid()
plt.legend(loc='upper right')  # Show legend

# Show the second plot
plt.show()

