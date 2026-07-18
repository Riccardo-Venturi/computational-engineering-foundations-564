import numpy as np
from matplotlib import pyplot as plt
#from scipy.integrate import solve
from scipy.special import factorial

x=np.linspace(-10,10,2000)
y=np.sin(x)

plt.plot(x, y, 'k', linewidth=2)
plt.xlim(-10, 10)
plt.ylim(-10, 10)
plt.grid(True)

# First-order Taylor expansion ,
P = [1, 0]  # x + 0
yT1 = np.polyval(P, x)
plt.plot(x, yT1, 'b--', linewidth=1.2)

# Third-order Taylor expansion ,

P = [-1 / factorial(3), 0, 1, 0]  # -(1/3!)x^3 + x + 0
yT3 = np.polyval(P, x)

plt.plot(x, yT3, 'r--', linewidth=1.2)

# Fifth-order Taylor expansion ,
P = [1 / factorial(5), 0, -1 / factorial(3), 0, 1, 0]  # (1/5!)x^5 -(1/3!)x^3 + x + 0;
yT5 = np.polyval(P, x);
plt.plot(x, yT5, 'g--', linewidth=1.2)

#Seventh-order Taylor expansion ,
P = [-1 / factorial(7), 0, 1 / factorial(5), 0, -1 / factorial(3), 0, 1, 0]
yT7 = np.polyval(P, x);
plt.plot(x, yT7, 'm--', linewidth=1.2)

# Ninth-order Taylor expansion ,
P = [1 / factorial(9), 0, -1 / factorial(7), 0, 1 / factorial(5), 0, -1 / factorial(3), 0, 1, 0]

yT9 = np.polyval(P, x);

plt.plot(x, yT9, 'c--', linewidth=1.2)
plt.legend(['sin(x)', '1st order', '3rd order', '5th order', '7th order', '9th order'])
plt.show()
