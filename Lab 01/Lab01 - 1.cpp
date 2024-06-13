#include <iostream>
#include <cmath>

struct Complex {
    double real;
    double imag;

    Complex(double r, double i) : real(r), imag(i) {}
};

Complex add(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex subtract(const Complex& a, const Complex& b) {
    return Complex(a.real - b.real, a.imag - b.imag);
}

Complex multiply(const Complex& a, const Complex& b) {
    return Complex(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);
}

Complex divide(const Complex& a, const Complex& b) {
    double denominator = b.real * b.real + b.imag * b.imag;
    return Complex((a.real * b.real + a.imag * b.imag) / denominator, (a.imag * b.real - a.real * b.imag) / denominator);
}

Complex pow(const Complex& a, int n) {
    double r = std::sqrt(a.real * a.real + a.imag * a.imag);
    double theta = std::atan2(a.imag, a.real);
    double r_n = std::pow(r, n);
    double theta_n = theta * n;
    return Complex(r_n * std::cos(theta_n), r_n * std::sin(theta_n));
}

Complex root(const Complex& a, int n, int k) {
    double r = std::sqrt(a.real * a.real + a.imag * a.imag);
    double theta = std::atan2(a.imag, a.real);
    double r_n = std::pow(r, 1.0 / n);
    double theta_n = (theta + 2 * M_PI * k) / n;
    return Complex(r_n * std::cos(theta_n), r_n * std::sin(theta_n));
}

void print(const Complex& c) {
    std::cout << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << "i\n";
}

int main() {
    Complex a(1, 1);
    Complex b(1, 2);

    std::cout << "a = ";
    print(a);
    std::cout << "b = ";
    print(b);

    Complex sum = add(a, b);
    Complex difference = subtract(a, b);
    Complex product = multiply(a, b);
    Complex quotient = divide(a, b);

    std::cout << "Sum: ";
    print(sum);
    std::cout << "Difference: ";
    print(difference);
    std::cout << "Product: ";
    print(product);
    std::cout << "Quotient: ";
    print(quotient);

    Complex c(1, 1);
    Complex c_pow_4 = pow(c, 4);
    std::cout << "c^4: ";
    print(c_pow_4);

    for (int k = 0; k < 3; ++k) {
        Complex c_root_3 = root(c, 3, k);
        std::cout << "c^(1/3), root " << k << ": ";
        print(c_root_3);
    }

    return 0;
}
