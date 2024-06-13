#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для вычисления определителя матрицы методом Гаусса
double determinant(vector<vector<double>>& A) {
    int n = A.size();
    vector<vector<double>> M = A;
    double det = 1;

    for (int i = 0; i < n; ++i) {
        // Поиск максимального элемента в столбце для выбора ведущего элемента
        int max_row = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(M[k][i]) > abs(M[max_row][i])) {
                max_row = k;
            }
        }
        // Обмен строк для выбора ведущего элемента
        if (max_row != i) {
            swap(M[i], M[max_row]);
            det *= -1;
        }
        // Деление текущей строки на ведущий элемент
        double pivot = M[i][i];
        if (pivot == 0) {
            return 0; // Если ведущий элемент нулевой, определитель равен нулю
        }
        det *= pivot;
        for (int k = i + 1; k < n; ++k) {
            double multiplier = M[k][i] / M[i][i];
            for (int j = i; j < n; ++j) {
                M[k][j] -= multiplier * M[i][j];
            }
        }
    }

    return det;
}

// Функция для решения СЛАУ методом Крамера
vector<double> solveByCramer(vector<vector<double>>& A, vector<double>& B) {
    int n = A.size();
    vector<double> X(n);
    double det_A = determinant(A);

    if (det_A == 0) {
        throw runtime_error("Matrix is singular. Cannot solve by Cramer's rule.");
    }

    for (int i = 0; i < n; ++i) {
        vector<vector<double>> A_i = A;
        for (int j = 0; j < n; ++j) {
            A_i[j][i] = B[j];
        }
        double det_A_i = determinant(A_i);
        X[i] = det_A_i / det_A;
    }

    return X;
}


// Функция для решения СЛАУ методом Якоби
vector<double> solveByJacobi(vector<vector<double>>& A, vector<double>& B, double eps, int max_iter) {
    int n = A.size();
    vector<double> X(n, 0);
    vector<double> prev_X(n);
    int iter = 0;

    while (iter < max_iter) {
        prev_X = X;
        for (int i = 0; i < n; ++i) {
            double sum = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum += A[i][j] * prev_X[j];
                }
            }
            X[i] = (B[i] - sum) / A[i][i];
        }

        // Проверка на достижение необходимой точности
        bool converged = true;
        for (int i = 0; i < n; ++i) {
            if (abs(X[i] - prev_X[i]) > eps) {
                converged = false;
                break;
            }
        }
        if (converged) {
            break;
        }

        iter++;
    }

    if (iter == max_iter) {
        throw runtime_error("Maximum number of iterations reached. Solution may not have converged.");
    }

    return X;
}

int main() {
    vector<vector<double>> A = {
        {2, -2, 5},
        {-2, 3, 6},
        {-10, 12, -4}
    };

    vector<double> B = {2, -1, 2};

    try {
        // Решение СЛАУ методом Крамера
        vector<double> X_cramer = solveByCramer(A, B);
        cout << "Solution using Cramer's rule:" << endl;
        cout << "x1 = " << X_cramer[0] << ", x2 = " << X_cramer[1] << ", x3 = " << X_cramer[2] << endl;

        // Решение СЛАУ методом Якоби
        double eps = 1e-6; // Точность
        int max_iter = 100; // Максимальное число итераций
        vector<double> X_jacobi = solveByJacobi(A, B, eps, max_iter);
        cout << "\nSolution using Jacobi method:" << endl;
        cout << "x1 = " << X_jacobi[0] << ", x2 = " << X_jacobi[1] << ", x3 = " << X_jacobi[2] << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
