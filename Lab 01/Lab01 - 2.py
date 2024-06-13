import math
import numpy as np

# Функция для которой ищем корень
def f(x):
    return 2/(1 + x) - 3 * math.sin(x)

# Метод дихотомии (бисекции)
def bisection_method(a, b, tol):
    if f(a) * f(b) >= 0:
        print("The bisection method fails.")
        return None
    c = a
    while (b - a) / 2.0 > tol:
        c = (a + b) / 2.0
        if f(c) == 0:
            break
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c
    return c

# Метод простой итерации
def iteration_method(x0, tol, max_iter):
    g = lambda x: 2/(3*math.sin(x)) - 1  # Упрощенная итерационная функция
    x_prev = x0
    for _ in range(max_iter):
        x_next = g(x_prev)
        if abs(x_next - x_prev) < tol:
            return x_next
        x_prev = x_next
    print("The iteration method fails.")
    return None

# Метод хорд (секущих)
def secant_method(x0, x1, tol, max_iter):
    for _ in range(max_iter):
        if f(x1) - f(x0) == 0:
            print("Division by zero in secant method.")
            return None
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        if abs(x2 - x1) < tol:
            return x2
        x0, x1 = x1, x2
    print("The secant method fails.")
    return None

# Метод Ньютона
def newton_method(x0, tol, max_iter):
    df = lambda x: -2/(1 + x)**2 - 3*math.cos(x)  # Производная функции f(x)
    x = x0
    for _ in range(max_iter):
        fx = f(x)
        dfx = df(x)
        if dfx == 0:
            print("Derivative is zero in Newton method.")
            return None
        x_next = x - fx / dfx
        if abs(x_next - x) < tol:
            return x_next
        x = x_next
    print("The Newton method fails.")
    return None


tol = 1e-6
max_iter = 1000

a, b = 0, 1  # Интервал для метода дихотомии
x0 = 0.5  # Начальное приближение для остальных методов
x1 = 1.0  # Второе начальное приближение для метода хорд

root_bisection = bisection_method(a, b, tol)
print(f"Bisection method root: {root_bisection}")

root_iteration = iteration_method(x0, tol, max_iter)
print(f"Iteration method root: {root_iteration}")

root_secant = secant_method(x0, x1, tol, max_iter)
print(f"Secant method root: {root_secant}")

root_newton = newton_method(x0, tol, max_iter)
print(f"Newton method root: {root_newton}")
