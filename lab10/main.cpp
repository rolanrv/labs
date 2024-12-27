#include "functions.hpp"

int main() {
    LinkedList list;
    int number;

    std::cout << "Введите последовательность натуральных чисел (введите 0 для завершения ввода):" << std::endl;
    while (true) {
        std::cin >> number;
        if (number == 0) break; // Завершение ввода
        list.insert(number);
    }

    if (list.isSortedByFirstOrLastDigit()) {
        list.removeSingleDigit();
        list.duplicatePalindromes();
    } else {
        list.sortByFirstDigit();
    }

    std::cout << "Результирующая последовательность:" << std::endl;
    list.display();

    return 0;
}
