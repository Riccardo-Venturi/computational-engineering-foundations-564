import numpy as np
import matplotlib.pyplot as plt

# Matrice di transizione (righe: oggi, colonne: domani)
A = np.array([
    [0.25, 0.5, 0.25],   # Prob. da Pioggia a [Pioggia, Nuvole, Sole]
    [0.5,  0.5, 0.25],   # Prob. da Nuvole
    [0.25, 0.0, 0.5 ]    # Prob. da Sole
])

# Stato iniziale: [Pioggia, Nuvole, Sole] come vettore riga
x = np.array([[1, 0, 0]])   # forma (1,3) per prodotto comodo

# Numero di giorni
giorni = 10

# Lista per salvare l'andamento di ogni giorno
storico = [x.flatten()]   # appiattisco per avere tre valori separati

print("Stato iniziale:")
print(x)

for giorno in range(1, giorni+1):
    x = x @ A          # prodotto matriciale (1x3) @ (3x3) = (1x3)
    storico.append(x.flatten())
    # stampa formattata (opzionale)
    print(f"Giorno {giorno}: Pioggia={x[0,0]:.3f}  Nuvole={x[0,1]:.3f}  Sole={x[0,2]:.3f}")

# Converti lo storico in un array 2D: ogni riga un giorno, colonna = condizione meteo
storico = np.array(storico)   # shape (11, 3) compreso il giorno 0

# ---------- GRAFICO ----------
giorni_asse = range(giorni+1)   # 0,1,...,10

plt.figure(figsize=(10, 6))
plt.plot(giorni_asse, storico[:, 0], 'b-o', label='Pioggia')
plt.plot(giorni_asse, storico[:, 1], 'gray', linestyle='--', marker='s', label='Nuvole')
plt.plot(giorni_asse, storico[:, 2], 'orange', linestyle='-.', marker='^', label='Sole')

plt.title("Previsione meteo: probabilità a 10 giorni")
plt.xlabel("Giorno")
plt.ylabel("Probabilità")
plt.ylim(0, 1)
plt.xticks(giorni_asse)
plt.legend()
plt.grid(True, alpha=0.3)
plt.show()
