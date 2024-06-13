import numpy as np

# Определение функции и её градиента
def f(x):
    x1, x2 = x
    return x1**2 + np.exp(x1**2 + x2**2) + 4*x1 + 3*x2

def grad_f(x):
    x1, x2 = x
    df_dx1 = 2*x1 + 2*x1*np.exp(x1**2 + x2**2) + 4
    df_dx2 = 2*x2*np.exp(x1**2 + x2**2) + 3
    return np.array([df_dx1, df_dx2])

# Метод наискорейшего спуска
def gradient_descent(x0, epsilon=1e-6, max_iterations=1000):
    x = x0.copy()
    iter_count = 0
    step = 0.1  # Начальный размер шага
    
    while np.linalg.norm(grad_f(x)) > epsilon and iter_count < max_iterations:
        # Вычисление градиента
        gradient = grad_f(x)
        
        # Шаг спуска
        x = x - step * gradient
        
        iter_count += 1
    
    return x, f(x)

# Начальное приближение
x0 = np.array([1.0, 1.0])

# Применение метода наискорейшего спуска
optimum, min_value = gradient_descent(x0)

print(f"Минимум функции достигается в точке {optimum}")
print(f"Значение функции в минимуме: {min_value}")
