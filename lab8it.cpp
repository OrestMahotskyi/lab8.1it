#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція для знаходження індексу четвертої від кінця крапки
int FindFourthLastDot(const char* str) {
    int dotCount = 0; // Лічильник крапок
    int len = strlen(str); // Довжина рядка

    // Ітеруємо з кінця рядка
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '.') { // Якщо поточний символ - крапка
            dotCount++; // Збільшуємо лічильник крапок
            // Якщо знайшли четверту крапку, повертаємо її індекс
            if (dotCount == 4) {
                return i;
            }
        }
    }
    return -1; // Якщо немає чотирьох крапок
}


// Функція для заміни кожної крапки на пару зірочок "**"
char* ReplaceDotsWithAsterisks(const char* str) {
    int len = strlen(str); // Довжина рядка
    int dotCount = 0; // Лічильник крапок

    // Рахуємо кількість крапок
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') { // Якщо поточний символ - крапка
            dotCount++; // Збільшуємо лічильник крапок
        }
    }

    // Розраховуємо нову довжину рядка, враховуючи заміну крапок на зірочки
    int newLen = len + dotCount; // Додаємо місце для кожної пари зірочок
    char* newStr = new char[newLen + 1]; // Виділяємо пам'ять для нового рядка
    int j = 0; // Індекс для нового рядка

    // Проходимо кожен символ оригінального рядка
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') { // Якщо поточний символ - крапка
            newStr[j++] = '*'; // Додаємо першу зірочку
            newStr[j++] = '*'; // Додаємо другу зірочку
        } else {
            newStr[j++] = str[i]; // Якщо не крапка, копіюємо символ
        }
    }
    newStr[j] = '\0'; // Завершуємо рядок

    return newStr; // Повертаємо новий рядок
}

int main() {
    char str[101]; // Масив для вводу рядка
    cout << "Введіть рядок: ";
    cin.getline(str, 100); // Вводимо рядок з консолі

    // Знаходимо індекс четвертої від кінця крапки
    int fourthLastDotIndex = FindFourthLastDot(str);
    if (fourthLastDotIndex != -1) { // Якщо знайдена четверта крапка
        cout << "Індекс четвертої від кінця крапки: " << fourthLastDotIndex << endl;
    } else {
        cout << "У рядку менше чотирьох крапок." << endl; // Якщо крапок менше чотирьох
    }

    // Замінюємо крапки на зірочки
    char* modifiedStr = ReplaceDotsWithAsterisks(str);
    cout << "Змінений рядок: " << modifiedStr << endl;

    delete[] modifiedStr; // Звільняємо пам'ять для нового рядка
    return 0;
}