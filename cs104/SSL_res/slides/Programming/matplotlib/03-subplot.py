import numpy as np
import matplotlib.pyplot as plt

# 1. SALES Plot (1x2 grid)
x = np.array([0, 1, 2, 3])
y = np.array([3, 8, 1, 10])

# Create 1x2 grid, select the first subplot
plt.subplot(1, 2, 1)
plt.plot(x, y, 'b-o', label='Sales')  # Blue solid line with markers
plt.title("SALES")
plt.xlabel("Months")
plt.ylabel("Amount")
plt.grid(True)
plt.legend(loc='upper right')

# Create 1x2 grid, select the second subplot
x = np.array([0, 1, 2, 3])
y = np.array([10, 20, 30, 40])

plt.subplot(1, 2, 2)
plt.plot(x, y, 'r--', label='Income')  # Red dashed line
plt.title("INCOME")
plt.xlabel("Months")
plt.ylabel("Amount")
plt.grid(True)
plt.legend(loc='upper left')

# Show Sales and Income plots
plt.show()

# 2. DATA TRENDS Plot (2x3 grid)
# Create 2x3 grid, select the first subplot
x = np.array([0, 1, 2, 3])
y = np.array([3, 8, 1, 10])
plt.subplot(2, 3, 1)
plt.plot(x, y, 'b-o', label='Trend 1')
plt.title("Trend 1")
plt.grid(True)
plt.legend(loc='upper right')

# Create 2x3 grid, select the second subplot
x = np.array([0, 1, 2, 3])
y = np.array([10, 20, 30, 40])
plt.subplot(2, 3, 2)
plt.plot(x, y, 'r--', label='Trend 2')
plt.title("Trend 2")
plt.grid(True)
plt.legend(loc='upper left')

# Create 2x3 grid, select the third subplot
x = np.array([0, 1, 2, 3])
y = np.array([2, 4, 5, 10])
plt.subplot(2, 3, 3)
plt.plot(x, y, 'g-.', label='Trend 3')
plt.title("Trend 3")
plt.grid(True)
plt.legend(loc='upper right')

# Create 2x3 grid, select the fourth subplot
x = np.array([0, 1, 2, 3])
y = np.array([10, 15, 25, 40])
plt.subplot(2, 3, 4)
plt.plot(x, y, 'm:', label='Trend 4')
plt.title("Trend 4")
plt.grid(True)
plt.legend(loc='upper right')

# Create 2x3 grid, select the fifth subplot
x = np.array([0, 1, 2, 3])
y = np.array([3, 0, 6, 10])
plt.subplot(2, 3, 5)
plt.plot(x, y, 'c--', label='Trend 5')
plt.title("Trend 5")
plt.grid(True)
plt.legend(loc='upper left')

# Create 2x3 grid, select the sixth subplot
x = np.array([0, 1, 2, 3])
y = np.array([10, 12, 8, 40])
plt.subplot(2, 3, 6)
plt.plot(x, y, 'y-.', label='Trend 6')
plt.title("Trend 6")
plt.grid(True)
plt.legend(loc='upper right')

# Show Data Trends plot
plt.show()

# 3. SINE and COSINE Plot (2x3 grid)
# Create 2x3 grid, select the first subplot
x = np.linspace(0, 10, 100)
y_sin = np.sin(x)
y_cos = np.cos(x)

plt.subplot(2, 3, 1)
plt.plot(x, y_sin, 'r-', label='Sine Wave')
plt.title("Sine Wave")
plt.grid(True)
plt.legend(loc='upper right')

# Create 2x3 grid, select the second subplot
plt.subplot(2, 3, 2)
plt.plot(x, y_cos, 'b-', label='Cosine Wave')
plt.title("Cosine Wave")
plt.grid(True)
plt.legend(loc='upper right')

# Create 2x3 grid, select the third subplot
plt.subplot(2, 3, 3)
plt.plot(x, y_sin, 'r-', label='Sine Wave')
plt.plot(x, y_cos, 'b-', label='Cosine Wave')
plt.title("Sine and Cosine Waves")
plt.grid(True)
plt.legend(loc='upper right')

# Show Sine and Cosine plot
plt.show()
