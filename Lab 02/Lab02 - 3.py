import random
import math

# Параметры эллипса: (x/a)^2 + (y/b)^2 = 1
a = random.uniform(1, 10)
b = random.uniform(1, 10)

# Координаты случайной точки
x = random.uniform(-10, 10)
y = random.uniform(-10, 10)

# Проверка принадлежности точки эллипсу
def is_point_on_ellipse(x, y, a, b):
    return (x / a)**2 + (y / b)**2 <= 1

# Нахождение координат фокусов эллипса
def ellipse_foci(a, b):
    c = math.sqrt(abs(a**2 - b**2))
    if a > b:
        return (c, 0), (-c, 0)
    else:
        return (0, c), (0, -c)

# Длины полуосей эллипса
def ellipse_axes(a, b):
    return a, b

# Нахождение эксцентриситета эллипса
def ellipse_eccentricity(a, b):
    c = math.sqrt(abs(a**2 - b**2))
    return c / max(a, b)

# Расстояние от директрис эллипса до его центра
def ellipse_directrix_distance(a, b):
    e = ellipse_eccentricity(a, b)
    return a / e if a > b else b / e

# Основной блок программы
print(f"Parameters of the ellipse: a = {a}, b = {b}")
print(f"Coordinates of the point: x = {x}, y = {y}")

# Проверка принадлежности точки эллипсу
on_ellipse = is_point_on_ellipse(x, y, a, b)
print(f"Point ({x}, {y}) is {'on' if on_ellipse else 'not on'} the ellipse.")

# Координаты фокусов эллипса
foci = ellipse_foci(a, b)
print(f"Foci of the ellipse: {foci}")

# Длины полуосей эллипса
axes = ellipse_axes(a, b)
print(f"Lengths of the semi-axes: a = {axes[0]}, b = {axes[1]}")

# Эксцентриситет эллипса
eccentricity = ellipse_eccentricity(a, b)
print(f"Eccentricity of the ellipse: {eccentricity}")

# Расстояние от директрис эллипса до его центра
directrix_distance = ellipse_directrix_distance(a, b)
print(f"Distance from the directrices to the center: {directrix_distance}")
