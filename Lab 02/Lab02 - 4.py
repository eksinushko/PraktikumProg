import random
import math

# Параметры эллипсоида: (x/a)^2 + (y/b)^2 + (z/c)^2 = 1
a = random.uniform(1, 10)
b = random.uniform(1, 10)
c = random.uniform(1, 10)

# Параметры плоскости: Ax + By + Cz + D = 0
A = random.uniform(-10, 10)
B = random.uniform(-10, 10)
C = random.uniform(-10, 10)
D = random.uniform(-10, 10)

# Параметры прямой: (x - x0)/l = (y - y0)/m = (z - z0)/n
x0 = random.uniform(-10, 10)
y0 = random.uniform(-10, 10)
z0 = random.uniform(-10, 10)
l = random.uniform(-10, 10)
m = random.uniform(-10, 10)
n = random.uniform(-10, 10)

# Координаты случайной точки
px = random.uniform(-10, 10)
py = random.uniform(-10, 10)
pz = random.uniform(-10, 10)

# Проверка принадлежности точки эллипсоиду
def is_point_on_ellipsoid(x, y, z, a, b, c):
    return (x / a)**2 + (y / b)**2 + (z / c)**2 <= 1

# Проверка пересечения плоскости и эллипсоида
def does_plane_intersect_ellipsoid(A, B, C, D, a, b, c):
    delta = (A/a)**2 + (B/b)**2 + (C/c)**2
    return delta <= D**2

# Проверка пересечения прямой и эллипсоида
def does_line_intersect_ellipsoid(x0, y0, z0, l, m, n, a, b, c):
    A = (l/a)**2 + (m/b)**2 + (n/c)**2
    B = 2 * (x0*l/a**2 + y0*m/b**2 + z0*n/c**2)
    C = (x0/a)**2 + (y0/b)**2 + (z0/c)**2 - 1
    delta = B**2 - 4*A*C
    return delta >= 0

# Основной блок программы
print(f"Parameters of the ellipsoid: a = {a}, b = {b}, c = {c}")
print(f"Parameters of the plane: A = {A}, B = {B}, C = {C}, D = {D}")
print(f"Parameters of the line: x0 = {x0}, y0 = {y0}, z0 = {z0}, l = {l}, m = {m}, n = {n}")
print(f"Coordinates of the point: px = {px}, py = {py}, pz = {pz}")

# Проверка принадлежности точки эллипсоиду
on_ellipsoid = is_point_on_ellipsoid(px, py, pz, a, b, c)
print(f"Point ({px}, {py}, {pz}) is {'on' if on_ellipsoid else 'not on'} the ellipsoid.")

# Проверка пересечения плоскости и эллипсоида
plane_intersects = does_plane_intersect_ellipsoid(A, B, C, D, a, b, c)
print(f"The plane {'intersects' if plane_intersects else 'does not intersect'} the ellipsoid.")

# Проверка пересечения прямой и эллипсоида
line_intersects = does_line_intersect_ellipsoid(x0, y0, z0, l, m, n, a, b, c)
print(f"The line {'intersects' if line_intersects else 'does not intersect'} the ellipsoid.")
