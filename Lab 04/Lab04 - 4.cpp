#include <iostream>
#include <vector>

using namespace std;

// Функция для решения СЛАУ методом прогонки
vector<double> solveByTridiagonal(vector<vector<double>>& A, vector<double>& B) {
    int n = A.size();
    vector<double> alpha(n); // Прогоночные коэффициенты alpha
    vector<double> beta(n);  // Прогоночные коэффициенты beta
    vector<double> X(n);     // Вектор решения

    // Прямая прогонка
    alpha[1] = -A[0][1] / A[0][0];
    beta[1] = B[0] / A[0][0];

    for (int i = 1; i < n - 1; ++i) {
        double denom = A[i][i] + A[i][i-1] * alpha[i];
        alpha[i+1] = -A[i][i+1] / denom;
        beta[i+1] = (B[i] - A[i][i-1] * beta[i]) / denom;
    }

    // Обратная прогонка
    X[n-1] = beta[n-1];
    for (int i = n - 2; i >= 0; --i) {
        X[i] = alpha[i+1] * X[i+1] + beta[i+1];
    }

    return X;
}

int main() {
    vector<vector<double>> A = {
        {-12, -7, 0, 0, 0},
        {-7, -11, -3, 0, 0},
        {0, -7, 21, -8, 0},
        {0, 0, 4, -13, 5},
        {0, 0, 0, -6, 14}
    };

    vector<double> B = {-102, -92, -65, 38, -12};

    try {
        vector<double> X = solveByTridiagonal(A, B);
        cout << "Solution using tridiagonal method:" << endl;
        for (int i = 0; i < X.size(); ++i) {
            cout << "x" << i + 1 << " = " << X[i] << endl;
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
