import numpy as np

# Задаем матрицу коэффициентов A и вектор правой части B
A = np.array([
    [18, 0, -2, 7],
    [-1, 14, -3, 2],
    [5, 5, 26, 7],
    [-2, -6, 9, 24]
], dtype=float)

B = np.array([50, 2, 273, 111], dtype=float)

# Функция для решения СЛАУ методом Зейделя
def solveBySeidel(A, B, eps, max_iter):
    n = len(A)
    X = np.zeros(n)  # Начальное приближение X = [0, 0, ..., 0]
    iter_count = 0
    converged = False
    
    while iter_count < max_iter:
        X_prev = X.copy()
        for i in range(n):
            sum1 = np.dot(A[i, :i], X[:i])  # Сумма от первого элемента до диагонального элемента
            sum2 = np.dot(A[i, i+1:], X[i+1:])  # Сумма после диагонального элемента
            X[i] = (B[i] - sum1 - sum2) / A[i, i]

        # Проверка на достижение необходимой точности
        if np.linalg.norm(X - X_prev) < eps:
            converged = True
            break
        
        iter_count += 1
    
    if not converged:
        raise RuntimeError("Maximum number of iterations reached. Solution may not have converged.")
    
    return X

# Параметры метода Зейделя
eps = 1e-6  # Точность
max_iter = 1000  # Максимальное число итераций

try:
    X_seidel = solveBySeidel(A, B, eps, max_iter)
    print("Solution using Seidel method:")
    for i in range(len(X_seidel)):
        print(f"x{i+1} = {X_seidel[i]}")
except RuntimeError as e:
    print(f"Error: {e}")
