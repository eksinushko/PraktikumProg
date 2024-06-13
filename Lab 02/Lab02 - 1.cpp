#include <iostream>
#include <cmath>

// Структура для представления точки
struct Point {
    double x;
    double y;
};

// Функция для нахождения расстояния от точки до прямой вида Ax + By + C = 0
double distanceToLine(double A, double B, double C, const Point& point) {
    return std::abs(A * point.x + B * point.y + C) / std::sqrt(A * A + B * B);
}

// Функция для нахождения точки пересечения двух прямых
bool intersection(double A1, double B1, double C1, double A2, double B2, double C2, Point& intersect) {
    double det = A1 * B2 - A2 * B1;
    if (det == 0) {
        return false; // Прямые параллельны или совпадают
    } else {
        intersect.x = (B2 * C1 - B1 * C2) / det;
        intersect.y = (A1 * C2 - A2 * C1) / det;
        return true;
    }
}

// Функция для нахождения угла между двумя прямыми
double angleBetweenLines(double A1, double B1, double A2, double B2) {
    double dotProduct = A1 * A2 + B1 * B2;
    double mag1 = std::sqrt(A1 * A1 + B1 * B1);
    double mag2 = std::sqrt(A2 * A2 + B2 * B2);
    return std::acos(dotProduct / (mag1 * mag2));
}

int main() {
    // Заданные прямые Ax + By + C = 0
    double A1 = 1, B1 = -2, C1 = 3;
    double A2 = 2, B2 = 1, C2 = -4;

    // Заданная точка
    Point P = {3, 4};

    // Расстояние от точки до прямых
    double dist1 = distanceToLine(A1, B1, C1, P);
    double dist2 = distanceToLine(A2, B2, C2, P);

    std::cout << "Distance from point to first line: " << dist1 << std::endl;
    std::cout << "Distance from point to second line: " << dist2 << std::endl;

    // Точка пересечения прямых
    Point intersect;
    if (intersection(A1, B1, C1, A2, B2, C2, intersect)) {
        std::cout << "Intersection point: (" << intersect.x << ", " << intersect.y << ")" << std::endl;

        // Расстояние от заданной точки до точки пересечения прямых
        double distToIntersection = std::sqrt(std::pow(P.x - intersect.x, 2) + std::pow(P.y - intersect.y, 2));
        std::cout << "Distance from point to intersection point: " << distToIntersection << std::endl;
    } else {
        std::cout << "The lines do not intersect." << std::endl;
    }

    // Угол между прямыми
    double angle = angleBetweenLines(A1, B1, A2, B2);
    std::cout << "Angle between the lines: " << angle * (180.0 / M_PI) << " degrees" << std::endl;

    return 0;
}
