import math

# Функция для вычисления подынтегральной функции
def f(x):
    return math.exp(-2 * x) * math.sin(21 * x)

# Метод прямоугольников для интеграла от 0 до +бесконечности
def rectangle_method_inf(a, n):
    integral = 0
    h = a / n
    for i in range(n):
        xi = i * h
        integral += f(xi)
    integral *= h
    return integral

# Метод трапеций для интеграла от 0 до +бесконечности
def trapezoidal_method_inf(a, n):
    integral = 0
    h = a / n
    for i in range(n):
        xi = i * h
        integral += f(xi)
    integral = (h / 2) * (f(0) + f(a)) + h * integral
    return integral

# Метод Симпсона для интеграла от 0 до +бесконечности
def simpsons_method_inf(a, n):
    integral = 0
    h = a / n
    for i in range(n):
        xi = i * h
        integral += f(xi)
    integral = (h / 3) * (f(0) + f(a)) + 2 * h * integral / 3
    return integral


a = 1000  # верхний предел интегрирования (бесконечность)
n = 1000  # количество разбиений

# Вычисление интеграла методами
integral_rectangle_inf = rectangle_method_inf(a, n)
integral_trapezoidal_inf = trapezoidal_method_inf(a, n)
integral_simpsons_inf = simpsons_method_inf(a, n)

# Вывод результатов
print(f"Integral of e^(-2*x) * sin(21*x) from 0 to +infinity:")
print(f"Rectangle method: {integral_rectangle_inf}")
print(f"Trapezoidal method: {integral_trapezoidal_inf}")
print(f"Simpson's method: {integral_simpsons_inf}")
