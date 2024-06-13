import numpy as np

# Задаем матрицу коэффициентов A и вектор правой части B
A = np.array([
    [-2, -9, -3, 7],
    [-7, 8, 2, 5],
    [-6, 2, 0, 0],
    [0, -3, 8, -3]
], dtype=float)

B = np.array([-26, -25, -16, -5], dtype=float)

# Функция для решения СЛАУ методом Гаусса
def gauss_elimination(A, B):
    n = len(A)
    # Прямой ход метода Гаусса
    for i in range(n):
        # Поиск максимального элемента в текущем столбце для выбора ведущего элемента
        max_row = i
        for k in range(i+1, n):
            if abs(A[k, i]) > abs(A[max_row, i]):
                max_row = k
        # Обмен строк для выбора ведущего элемента
        A[[i, max_row]] = A[[max_row, i]]
        B[[i, max_row]] = B[[max_row, i]]
        
        # Деление текущей строки на ведущий элемент
        pivot = A[i, i]
        if pivot == 0:
            raise ValueError("Matrix is singular.")
        A[i] /= pivot
        B[i] /= pivot
        
        # Вычитание текущей строки из всех нижележащих строк
        for k in range(i+1, n):
            multiplier = A[k, i]
            A[k] -= multiplier * A[i]
            B[k] -= multiplier * B[i]
    
    # Обратный ход метода Гаусса
    X = np.zeros(n)
    for i in range(n-1, -1, -1):
        X[i] = B[i] - np.dot(A[i, i+1:], X[i+1:])
    
    return X

# Решение СЛАУ методом Гаусса
try:
    X_gauss = gauss_elimination(A.copy(), B.copy())
    print("Solution using Gauss method:")
    print(f"x1 = {X_gauss[0]}, x2 = {X_gauss[1]}, x3 = {X_gauss[2]}, x4 = {X_gauss[3]}")
except ValueError as e:
    print(f"Error: {e}")

# Решение СЛАУ с использованием обратной матрицы (для проверки)
try:
    A_inv = np.linalg.inv(A)
    X_inv = np.dot(A_inv, B)
    print("\nSolution using inverse matrix method (NumPy):")
    print(f"x1 = {X_inv[0]}, x2 = {X_inv[1]}, x3 = {X_inv[2]}, x4 = {X_inv[3]}")
except np.linalg.LinAlgError:
    print("Matrix is singular. Unable to compute inverse.")
