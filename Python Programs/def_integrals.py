import matplotlib.pyplot as plt
import numpy as np
import sympy as sy


def f(x):
	return x**2

x = sy.Symbol("x")
print(sy.integrate(f(x), (x, 0, 2)))

x = np.linspace(0, 2, 1000)
plt.plot(x, f(x))
plt.axhline(color="black")
plt.fill_between(x, f(x), where=[(x > 0) and (x < 2) for x in x])
plt.show()
