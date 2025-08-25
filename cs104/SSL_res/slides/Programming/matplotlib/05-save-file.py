import matplotlib.pyplot as plt
import numpy as np

# Create some data
x = np.linspace(0, 10, 100)
y = np.sin(x)

# Plot the data
plt.plot(x, y, label='Sine Wave', color='blue')

# Add title and labels
plt.title('Sine Wave Plot')
plt.xlabel('X Axis')
plt.ylabel('Y Axis')

# Display the legend
plt.legend()

# Save the plot with different parameters

# Save the plot with the default parameters (simple PNG)
plt.savefig('sine_wave_default.png')

# Save with high DPI for high resolution (300 DPI), transparent background
plt.savefig('sine_wave_high_dpi.png', dpi=300, transparent=True)

# Save as PDF with a transparent background and tight bounding box
plt.savefig('sine_wave_plot.pdf', transparent=True, bbox_inches='tight')

# Show the plot (this is optional if you only want to save it without displaying)
plt.show()
