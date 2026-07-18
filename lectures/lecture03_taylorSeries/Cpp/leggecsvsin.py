import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("taylor_series.csv")

plt.figure(figsize=(10, 6))
plt.plot(df['x'], df['sin(x)'], label='sin(x)', linewidth=2.5)
plt.plot(df['x'], df['Taylor_1'], label='Taylor 1°')
plt.plot(df['x'], df['Taylor_3'], label='Taylor 3°')
plt.plot(df['x'], df['Taylor_5'], label='Taylor 5°')
plt.plot(df['x'], df['Taylor_9'], label='Taylor 9°', linestyle='--')

plt.legend()
plt.grid(True)
plt.title('Confronto sin(x) vs Polinomi di Taylor')
plt.xlabel('x')
plt.ylabel('y')
plt.show()
