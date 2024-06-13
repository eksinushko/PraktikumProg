#include <iostream>
#include <cmath>

// Функция для вычисления суммы функционального ряда с точностью до eps
double calculateSeriesSum2(double x, double eps) {
    double sum = 0.0;
    double term = 0.0;
    int k = 1;
    do {
        term = std::pow(-1, k) / (std::sin(k * x) + 21 + std::pow(k, 2));
        sum += term;
        k++;
    } while (std::abs(term) >= eps);

    return sum;
}

int main() {
    double eps = 1e-6; // Точность до 10^-6
    double x = 1.0;    // Примерное значение x (можно изменить)

    // Вычисление суммы функционального ряда
    double sum = calculateSeriesSum2(x, eps);

    // Вывод результата
    std::cout << "Sum of the series (-1)^k / (sin(k*x) + 21 + k^2) with precision 10^-6: " << sum << std::endl;

    return 0;
}
