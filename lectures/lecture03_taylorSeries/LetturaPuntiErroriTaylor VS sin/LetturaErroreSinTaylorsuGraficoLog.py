import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# ================== PARAMETRI ==================
num_points = 2000
x = np.linspace(-10, 10, num_points)

# Calcolo sin(x) reale
y_true = np.sin(x)

# ================== POLINOMI DI TAYLOR ==================
def taylor_sin(x, order):
    """Calcola polinomio di Taylor di sin(x) di ordine 'order'"""
    y = np.zeros_like(x)
    term = x.copy()
    factorial = 1.0
    sign = 1.0
    
    for n in range(1, order + 1, 2):        # solo termini dispari
        y += sign * term / factorial
        # prepara termine successivo
        term *= x * x
        factorial *= (n+1) * (n+2)
        sign = -sign
    return y

# Calcoliamo vari ordini
orders = [1, 3, 5, 7, 9]
errors = {}

for order in orders:
    y_approx = taylor_sin(x, order)
    error = np.abs(y_true - y_approx)          # Errore assoluto
    errors[f'Taylor_{order}'] = error

# ================== GRAFICO ==================
plt.figure(figsize=(12, 8))

# Plot errore su scala logaritmica
for order in orders:
    plt.plot(x, errors[f'Taylor_{order}'], label=f'Taylor ordine {order}')

plt.yscale('log')                    # <--- Scala logaritmica sull'asse Y
plt.xlabel('x')
plt.ylabel('Errore assoluto |sin(x) - Taylor(x)| (scala log)')
plt.title('Confronto Errori dei Polinomi di Taylor per sin(x) - Scala Log')
plt.grid(True, which='both', linestyle='--')
plt.legend()
plt.axhline(y=1e-10, color='gray', linestyle=':', alpha=0.7)  # riferimento

plt.show()

# ================== SALVA DATI SU CSV (opzionale) ==================
df = pd.DataFrame({'x': x, 'sin(x)': y_true})
for order in orders:
    df[f'Taylor_{order}'] = taylor_sin(x, order)
    df[f'Error_{order}'] = errors[f'Taylor_{order}']

df.to_csv('taylor_error_analysis.csv', index=False)
print("File 'taylor_error_analysis.csv' salvato!")
