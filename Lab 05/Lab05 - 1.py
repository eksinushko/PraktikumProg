import numpy as np
import matplotlib.pyplot as plt

# Заданные данные
data = np.array([
    [-1.0, -0.5],
    [0.0, 0.0],
    [1.0, 0.5],
    [2.0, 0.86603],
    [3.0, 1.0],
    [4.0, 0.86603]
])

x = data[:, 0]
y = data[:, 1]

# Метод наименьших квадратов для многочлена 1 степени (линейный)
A1 = np.vstack([x, np.ones_like(x)]).T
coeffs1 = np.linalg.lstsq(A1, y, rcond=None)[0]

# Метод наименьших квадратов для многочлена 2 степени
A2 = np.vstack([x**2, x, np.ones_like(x)]).T
coeffs2 = np.linalg.lstsq(A2, y, rcond=None)[0]

# Генерация значений для построения графиков
x_range = np.linspace(-1.5, 4.5, 400)
y_pred1 = coeffs1[0] * x_range + coeffs1[1]
y_pred2 = coeffs2[0] * x_range**2 + coeffs2[1] * x_range + coeffs2[2]

# Вывод результатов
plt.figure(figsize=(10, 6))
plt.plot(x_range, y_pred1, label=f'Линейный многочлен: y = {coeffs1[0]:.4f}x + {coeffs1[1]:.4f}', color='r')
plt.plot(x_range, y_pred2, label=f'Квадратичный многочлен: y = {coeffs2[0]:.4f}x^2 + {coeffs2[1]:.4f}x + {coeffs2[2]:.4f}', color='b')
plt.scatter(x, y, color='k', label='Табличные данные')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Приближающие многочлены методом наименьших квадратов')
plt.legend()
plt.grid(True)
plt.show()
