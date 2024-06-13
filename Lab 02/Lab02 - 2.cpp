#include <iostream>
#include <cmath>

// Структура для представления вектора
struct Vector {
    double x;
    double y;
    double z;
};

// Функция для нахождения длины вектора
double vectorLength(const Vector& v) {
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Функция для нахождения угла между двумя векторами
double angleBetweenVectors(const Vector& v1, const Vector& v2) {
    double dotProduct = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    double length1 = vectorLength(v1);
    double length2 = vectorLength(v2);
    return std::acos(dotProduct / (length1 * length2));
}

// Функция для нахождения суммы двух векторов
Vector addVectors(const Vector& v1, const Vector& v2) {
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

// Функция для нахождения разности двух векторов
Vector subtractVectors(const Vector& v1, const Vector& v2) {
    return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

// Функция для нахождения векторного произведения двух векторов
Vector crossProduct(const Vector& v1, const Vector& v2) {
    return {
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    };
}

// Функция для проверки, параллельны ли два вектора
bool areParallel(const Vector& v1, const Vector& v2) {
    Vector cross = crossProduct(v1, v2);
    return cross.x == 0 && cross.y == 0 && cross.z == 0;
}

int main() {
    // Заданные вектора
    Vector v1 = {1, 2, 3};
    Vector v2 = {4, 5, 6};

    // Длины векторов
    double length1 = vectorLength(v1);
    double length2 = vectorLength(v2);

    std::cout << "Length of first vector: " << length1 << std::endl;
    std::cout << "Length of second vector: " << length2 << std::endl;

    // Угол между векторами
    double angle = angleBetweenVectors(v1, v2);
    std::cout << "Angle between the vectors: " << angle * (180.0 / M_PI) << " degrees" << std::endl;

    // Сумма векторов
    Vector sum = addVectors(v1, v2);
    std::cout << "Sum of vectors: (" << sum.x << ", " << sum.y << ", " << sum.z << ")" << std::endl;

    // Разность векторов
    Vector diff = subtractVectors(v1, v2);
    std::cout << "Difference of vectors: (" << diff.x << ", " << diff.y << ", " << diff.z << ")" << std::endl;

    // Проверка на параллельность
    bool parallel = areParallel(v1, v2);
    std::cout << "Vectors are " << (parallel ? "parallel" : "not parallel") << std::endl;

    // Векторное произведение
    Vector cross = crossProduct(v1, v2);
    std::cout << "Cross product of vectors: (" << cross.x << ", " << cross.y << ", " << cross.z << ")" << std::endl;

    return 0;
}
