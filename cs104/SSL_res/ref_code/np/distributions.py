'''
    Distributions
'''

import numpy as np
from matplotlib import pyplot as plt

# Seeding for reproducibility
np.random.seed(42)
S=1000000
# sampling from each of the six distributions
beta = 100*np.random.beta(a=4, b=20, size=S)
exponential = 100*np.random.exponential(scale=0.1, size=S)
gamma = 100*np.random.gamma(shape=2.0, scale=0.1, size=S)
laplace = 100*np.random.laplace(loc=0.0, scale=0.5, size=S)
normal = np.random.normal(loc=0.0, scale=3.0, size=S)
poisson = np.random.poisson(lam=3, size=S)


# plotting histograms for each of the distributions
plt.subplot(3,2,1)
plt.hist(beta, bins=55, range = (-5,50), color='red')
plt.title("Beta")
plt.subplot(3,2,2)
plt.hist(exponential, bins=51, range = (-1,50), color='green', alpha=0.5)
plt.title("Exponential")
plt.subplot(3,2,3)
plt.hist(gamma, bins=51, range = (-1,50), color='black', alpha=0.8, orientation='horizontal')
plt.title("Gamma")
plt.subplot(3,2,4)
plt.hist(laplace, bins=51, range = (-1,50), color='orange')
plt.title("Laplace")
plt.subplot(3,2,5)
plt.hist(normal, bins=21, range = (-10,11))
plt.title("Normal")
plt.subplot(3,2,6)
plt.hist(poisson, bins=12, range = (-1,11))
plt.title("Poisson")

# adjust the sub-plots to fit the titles and labels
plt.tight_layout()
# save the plot as plot.png
plt.savefig('plot.png')
'''
    Distributions
'''

import numpy as np
from matplotlib import pyplot as plt

# Seeding for reproducibility
np.random.seed(42)
S=1000000
# sampling from each of the six distributions
beta = 100*np.random.beta(a=4, b=20, size=S)
exponential = 100*np.random.exponential(scale=0.1, size=S)
gamma = 100*np.random.gamma(shape=2.0, scale=0.1, size=S)
laplace = 100*np.random.laplace(loc=0.0, scale=0.5, size=S)
normal = np.random.normal(loc=0.0, scale=3.0, size=S)
poisson = np.random.poisson(lam=3, size=S)


# plotting histograms for each of the distributions
plt.subplot(3,2,1)
plt.hist(beta, bins=55, range = (-5,50), color='red')
plt.title("Beta")
plt.subplot(3,2,2)
plt.hist(exponential, bins=51, range = (-1,50), color='green', alpha=0.5)
plt.title("Exponential")
plt.subplot(3,2,3)
plt.hist(gamma, bins=51, range = (-1,50), color='black', alpha=0.8, orientation='horizontal')
plt.title("Gamma")
plt.subplot(3,2,4)
plt.hist(laplace, bins=51, range = (-1,50), color='orange')
plt.title("Laplace")
plt.subplot(3,2,5)
plt.hist(normal, bins=21, range = (-10,11))
plt.title("Normal")
plt.subplot(3,2,6)
plt.hist(poisson, bins=12, range = (-1,11))
plt.title("Poisson")

# adjust the sub-plots to fit the titles and labels
plt.tight_layout()
# save the plot as plot.png
plt.savefig('plot.png')