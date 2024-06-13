#include <iostream>
#include <cmath>

// Функция для вычисления суммы числового ряда с точностью до eps
double calculateSeriesSum1(double eps) {
    double sum = 0.0;
    double term = 0.0;
    int k = 1;
    do {
        term = 21.0 / std::pow(2, k - 1) + std::pow(-1, k - 1) / (2 * std::pow(3, k - 1));
        sum += term;
        k++;
    } while (std::abs(term) >= eps);

    return sum;
}

int main() {
    double eps = 1e-6; // Точность до 10^-6

    // Вычисление суммы числового ряда
    double sum = calculateSeriesSum1(eps);

    // Вывод результата
    std::cout << "Sum of the series 21 / 2^(k-1) + (-1)^(k-1) / (2 * 3^(k-1)) with precision 10^-6: " << sum << std::endl;

    return 0;
}
