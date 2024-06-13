#include <iostream>
#include <cmath>

// Функция для вычисления интерполяционного многочлена Ньютона
double newton_interpolation(double x, double xi[], double yi[], int n) {
    // Инициализация массива разделенных разностей
    double f[n][n];
    for (int i = 0; i < n; ++i) {
        f[i][0] = yi[i];
    }

    // Вычисление разделенных разностей
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            f[i][j] = (f[i+1][j-1] - f[i][j-1]) / (xi[i+j] - xi[i]);
        }
    }

    // Вычисление значения интерполяционного многочлена в точке x
    double result = f[0][0];
    double term = 1.0;
    for (int j = 1; j < n; ++j) {
        term *= (x - xi[j-1]);
        result += f[0][j] * term;
    }

    return result;
}

int main() {
    const int n = 4; // количество точек
    double xi[n] = {0.1 * M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI};
    double yi[n];
    
    // Заполнение значений yi = cos(xi)
    for (int i = 0; i < n; ++i) {
        yi[i] = cos(xi[i]);
    }

    // Вычисление интерполяционного многочлена Ньютона в точке x = 0.25 * pi
    double x = 0.25 * M_PI;
    double interpolated_value = newton_interpolation(x, xi, yi, n);
    double exact_value = cos(x);

    // Вычисление погрешности интерполяции
    double interpolation_error = std::abs(exact_value - interpolated_value);

    // Вывод результатов
    std::cout << "Значение интерполяционного многочлена в x = 0.25pi: " << interpolated_value << std::endl;
    std::cout << "Точное значение функции в x = 0.25pi: " << exact_value << std::endl;
    std::cout << "Погрешность интерполяции в x = 0.25pi: " << interpolation_error << std::endl;

    return 0;
}
