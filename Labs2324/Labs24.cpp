#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// 1. Опис підпрограми, що обчислює функцію згідно з варіантом 8 (табл. 24)
double calcY(double x, bool& divisionByZero) {
    divisionByZero = false;

    // Перша гілка системи: умова x > 4
    if (x > 4.0) {
        double sum = 0.0;
        // Обчислення суми від i = 0 до 4
        for (int i = 0; i <= 4; ++i) {
            double denom = x - i;
            // Перевірка ділення на нуль (з урахуванням похибки дійсних чисел)
            if (fabs(denom) < 1e-12) {
                divisionByZero = true;
                return 0.0;
            }
            sum += (x + 2.0 * i) / denom;
        }
        return x * x + sum;
    }
    // Друга гілка системи: умова x <= 4
    else {
        return 3.0 * x * x + 5.0 * x - 1.0;
    }
}

// 2. Опис головної програми, що табулює функцію
int main() {
    // Задання меж інтервалу та кроку табулювання згідно з варіантом 8: x ∈ [0, 8], h = 0.4
    const double xStart = 0.0;
    const double xEnd = 8.0;
    const double h = 0.4;

    // Обчислення точної кількості кроків для уникнення накопичення похибки типу double
    int steps = static_cast<int>(llround((xEnd - xStart) / h));

    // Виведення заголовка таблиці значень
    cout << left << setw(12) << "x" << setw(18) << "y(x)" << "\n";
    cout << string(30, '-') << "\n";

    // Цикл табулювання функції на заданому проміжку
    for (int k = 0; k <= steps; ++k) {
        double x = xStart + k * h;
        bool divZero = false;

        // Виклик підпрограми з п.1 для обчислення чергового значення функції
        double y = calcY(x, divZero);

        // Виведення аргументу x та відповідного значення y(x) у вигляді таблиці
        cout << left << setw(12) << fixed << setprecision(2) << x;
        if (divZero) {
            cout << "ділення на 0\n";
        }
        else {
            cout << setprecision(6) << y << "\n";
        }
    }

    return 0;
}