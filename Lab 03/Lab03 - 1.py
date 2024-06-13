import math

# Функция для вычисления подынтегральной функции
def f(x):
    return x**4 / (21 + x**2)

# Метод прямоугольников
def rectangle_method(a, b, n):
    h = (b - a) / n
    integral = 0
    for i in range(n):
        xi = a + i * h
        integral += f(xi)
    integral *= h
    return integral

# Метод трапеций
def trapezoidal_method(a, b, n):
    h = (b - a) / n
    integral = (f(a) + f(b)) / 2
    for i in range(1, n):
        xi = a + i * h
        integral += f(xi)
    integral *= h
    return integral

# Метод Симпсона
def simpsons_method(a, b, n):
    h = (b - a) / n
    integral = f(a) + f(b)
    for i in range(1, n, 2):
        xi = a + i * h
        integral += 4 * f(xi)
    for i in range(2, n-1, 2):
        xi = a + i * h
        integral += 2 * f(xi)
    integral *= h / 3
    return integral


a = 1
b = 2
n = 1000  # количество разбиений

# Вычисление интеграла методами
integral_rectangle = rectangle_method(a, b, n)
integral_trapezoidal = trapezoidal_method(a, b, n)
integral_simpsons = simpsons_method(a, b, n)

# Вывод результатов
print(f"Integral of x^4 * (21 + x^2)^-1 from {a} to {b}:")
print(f"Rectangle method: {integral_rectangle}")
print(f"Trapezoidal method: {integral_trapezoidal}")
print(f"Simpson's method: {integral_simpsons}")
