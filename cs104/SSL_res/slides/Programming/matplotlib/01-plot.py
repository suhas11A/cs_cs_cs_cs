import numpy as np
import matplotlib.pyplot as plt


# List all markers
print("\nMarkers:", plt.Line2D.markers)

# List all line styles
print("\nLine Styles:", plt.Line2D.lineStyles)


# 1. Basic Line Plot with Markers
xpoints = np.array([1, 2, 6, 8])
ypoints = np.array([3, 8, 1, 10])

plt.plot(xpoints, ypoints, marker='o')  
plt.show()

# 2. Using Marker, Line, and Color in a Short Format (color marker style) for format string
plt.plot(xpoints, ypoints, 'r*:')  
plt.show()

# 3. Customizing Markers (Size, Edge Color, Line Style, Face Color)
#Notice I am not using xpoints. It will plot ypoints assuming xpoints [0,1,2,3]
plt.plot(ypoints, marker='o', ms=20, mec='g', ls='-.', mfc='hotpink')
plt.show()

# 4. Multiple Line Plots on the Same Graph
x1 = np.array([0, 1, 2, 3])
y1 = np.array([3, 8, 1, 10])
x2 = np.array([0, 1, 2, 3])
y2 = np.array([6, 2, 7, 11])

#Can also be split into two seperate plots
#plt.plot(x1, y1, 'bo-')  # Blue circles with solid line
#plt.plot(x2, y2, 'rs--')  # Red squares with dashed line
plt.plot(x1, y1, 'bo-', x2, y2, 'rs--')
plt.show()

# 5. More Complex Line Plots Using NumPy-generated Data
x = np.linspace(0, 10, 100)  
y1 = np.sin(x)
y2 = np.cos(x)
y3 = np.sin(x) * np.cos(x)

plt.plot(x, y1, 'bo-', x, y2, 'rs--', x, y3, 'gx-.')
plt.show()

