#include <iostream>
#include <cmath>

// Функция f(x1, x2, x3)
double f(double x1, double x2, double x3) {
    return exp(x1 * x1 + x2 * x2) + log(4 + x2 * x2 + 2 * x3 * x3);
}

// Метод покоординатного спуска
void coordinate_descent(double& x1, double& x2, double& x3, double epsilon, int max_iterations) {
    double step = 0.1; // Начальный шаг
    int iter = 0;
    while (iter < max_iterations) {
        double x1_old = x1, x2_old = x2, x3_old = x3;

        // Обновление каждой координаты по очереди
        x1 = x1_old - step * (2 * x1_old * exp(x1_old * x1_old + x2_old * x2_old));
        x2 = x2_old - step * (2 * x2_old * exp(x1_old * x1_old + x2_old * x2_old) + 
                             (2 * x2_old) / (4 + x2_old * x2_old + 2 * x3_old * x3_old));
        x3 = x3_old - step * ((4 * x3_old) / (4 + x2_old * x2_old + 2 * x3_old * x3_old));

        // Проверка на достижение необходимой точности
        if (fabs(x1 - x1_old) < epsilon && fabs(x2 - x2_old) < epsilon && fabs(x3 - x3_old) < epsilon) {
            break;
        }
        
        iter++;
    }
}

int main() {
    double x1 = 1.0, x2 = 1.0, x3 = 1.0; // Начальные значения переменных
    double epsilon = 1e-6; // Точность
    int max_iterations = 1000; // Максимальное количество итераций

    coordinate_descent(x1, x2, x3, epsilon, max_iterations);

    std::cout << "Минимум функции достигается в точке (x1, x2, x3) = (" << x1 << ", " << x2 << ", " << x3 << ")" << std::endl;
    std::cout << "Значение функции в минимуме: " << f(x1, x2, x3) << std::endl;

    return 0;
}
