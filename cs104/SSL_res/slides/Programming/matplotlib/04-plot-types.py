import matplotlib.pyplot as plt
import numpy as np

# Scatter Plot 1
x = np.array([5, 7, 8, 7, 2, 17, 2, 9, 4, 11, 12, 9, 6])
y = np.array([99, 86, 87, 88, 111, 86, 103, 87, 94, 78, 77, 85, 86])
plt.scatter(x, y, color='red', label="Group 1")  # Scatter plot with red color for Group 1

# Scatter Plot 2
x = np.array([2, 2, 8, 1, 15, 8, 12, 9, 7, 3, 11, 4, 7, 14, 12])
y = np.array([100, 105, 84, 105, 90, 99, 90, 95, 94, 100, 79, 112, 91, 80, 85])
plt.scatter(x, y, color='green', label="Group 2")  # Scatter plot with green color for Group 2
plt.legend()  # Display the legend
plt.show()  # Show the plot

# Scatter plot with random data
# size is 100 random integers; first argument says between 0 and 99 for x-axis
x = np.random.randint(100, size=(100))  
y = np.random.randint(100, size=(100))
# Colors for each point, chosen randomly
colors = np.random.randint(100, size=(100))  # This assigns a unique color value to each point
# Sizes of the points, chosen randomly
sizes = np.random.randint(100, size=(100))  # This controls the size of each point in the scatter plot (larger = bigger points)

# Scatter plot with various customizations
plt.scatter(x, y, 
            c=colors,        # Color each point according to the value in 'colors' array
            s=sizes,         # Size each point according to the value in 'sizes' array
            alpha=0.6,       # Transparency of the points; 0 is fully transparent, 1 is fully opaque
            cmap='nipy_spectral')  # Color map to map 'colors' to specific colors; 'nipy_spectral' is a built-in colormap
            # 'cmap' defines which color scheme to apply to the data. 'nipy_spectral' is a color map, 
            # but you can experiment with 'viridis', 'plasma', 'inferno', etc., for different visual effects.

# Display the color scale (colorbar)
plt.colorbar()  # Shows a colorbar that reflects the colormap range and how the data values correspond to colors
plt.show()  # Show the plot

# Bar Plot
x = np.array(["A", "B", "C", "D"])  # Labels for the bars
y = np.array([3, 8, 1, 10])  # Heights of the bars
plt.bar(x, y, color='r', width=0.5)  # Plotting the bar chart, with 'r' (red) color and bar width of 0.5
plt.show()  # Show the plot

# Pie Chart
y = np.array([35, 25, 25, 15])  # Percentage data for the pie chart
mylabels = ["Apples", "Bananas", "Cherries", "Dates"]  # Labels for the pie chart sections
plt.pie(y, labels=mylabels)  # Plotting the pie chart with labels
plt.show()  # Show the plot


# Histogram
data = np.random.randn(1000)  # Generate 1000 random numbers from a normal distribution
plt.hist(data, bins=30, edgecolor='black')  # Create a histogram with 30 bins and black edge color
plt.title("Histogram")  # Title for the histogram
plt.show()  # Show the plot


##These are not part of syllabus, more for fun

# Box Plot
data = np.random.rand(10, 5)  # Random data for the box plot (10 rows, 5 columns)
# This creates 5 box plots, one for each column of data
plt.boxplot(data)  # Box plot to show the distribution of the data
plt.title("Box Plot")  # Title for the box plot
plt.show()  # Show the plot



# Area Plot
x = np.arange(0, 10, 0.1)  # Generate x values from 0 to 10, with a step size of 0.1
y1 = np.sin(x)  # Generate y1 values based on the sine of x
y2 = np.cos(x)  # Generate y2 values based on the cosine of x
# Fill the area between y1 and y2 with different colors
plt.fill_between(x, y1, y2, color='skyblue', alpha=0.4)  # Fill between y1 and y2 with skyblue color
plt.fill_between(x, y1, color='orange', alpha=0.6)  # Fill between y1 and x-axis with orange color
plt.fill_between(x, y2, color='green', alpha=0.4)  # Fill between y2 and x-axis with green color
plt.title("Area Plot")  # Title for the area plot
plt.show()  # Show the plot

# Heatmap
data = np.random.rand(10, 10)  # Generate a 10x10 array of random numbers between 0 and 1
# Create a heatmap to visualize the intensity of values
plt.imshow(data, cmap='hot', interpolation='nearest')  # Display the data as an image, using 'hot' colormap
plt.colorbar()  # Display a colorbar to show the intensity scale
plt.title("Heatmap")  # Title for the heatmap
plt.show()  # Show the plot

# Contour Plot
x = np.linspace(-3.0, 3.0, 100)  # Generate 100 evenly spaced values between -3.0 and 3.0 for x-axis
y = np.linspace(-3.0, 3.0, 100)  # Generate 100 evenly spaced values between -3.0 and 3.0 for y-axis
X, Y = np.meshgrid(x, y)  # Generate a grid of x and y values using meshgrid; this creates a 2D grid of coordinates
Z = np.sin(X) ** 10 + np.cos(10 + Y * X) * np.cos(X)  # Z values as a function of X and Y (complex mathematical function)
plt.contour(X, Y, Z, 20, cmap='RdGy')  # Create contour lines with 20 levels, using the 'RdGy' colormap
plt.title("Contour Plot")  # Title for the contour plot
plt.show()  # Show the plot
