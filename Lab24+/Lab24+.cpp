#include <iostream>
#include <iomanip>

using namespace std;

// 1. Опис рекурсивної підпрограми згідно з варіантом 8 (табл. 25):
// обчислення суми спадної геометричної прогресії
// current - поточний елемент прогресії
// endVal  - кінцеве (граничне) значення (1.0)
// ratio   - знаменник прогресії (0.5 — зменшення у 2 рази на кожному кроці)
double geomSeriesSumRecursive(double current, double endVal, double ratio = 0.5) {
    // Базовий випадок рекурсії: якщо поточний елемент менший за кінцеве значення,
    // далі не додаємо
    if (current < endVal) {
        return 0.0;
    }

    // Рекурсивний крок: додаємо поточний елемент і переходимо до наступного (current * ratio)
    return current + geomSeriesSumRecursive(current * ratio, endVal, ratio);
}

// 2. Опис головної програми, що містить виклик рекурсивної підпрограми
int main() {
    // Початкове значення, кінцеве значення та знаменник прогресії згідно з варіантом 8
    const double startVal = 50.0;
    const double endVal = 1.0;
    const double ratio = 0.5;

    // Виклик рекурсивної підпрограми з п. 1
    double sum = geomSeriesSumRecursive(startVal, endVal, ratio);

    // Виведення параметрів прогресії та обчисленої суми
    cout << "Початкове значення: " << startVal << "\n";
    cout << "Кінцеве значення: " << endVal << "\n";
    cout << "Знаменник прогресії (q): " << ratio << "\n";
    cout << "Сума елементів прогресії: " << fixed << setprecision(6) << sum << "\n";

    return 0;
}