#include "functions.hpp"

// Конструктор
LinkedList::LinkedList() : head(nullptr) {}

// Деструктор
LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Вставка элемента в список
void LinkedList::insert(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

// Вывод списка
void LinkedList::display() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Удаление однозначных чисел
void LinkedList::removeSingleDigit() {
    Node* current = head;
    Node* previous = nullptr;

    while (current) {
        if (current->data < 10) {
            if (previous) {
                previous->next = current->next;
                delete current;
                current = previous->next;
            } else {
                head = current->next;
                delete current;
                current = head;
            }
        } else {
            previous = current;
            current = current->next;
        }
    }
}

// Дублирование палиндромов
void LinkedList::duplicatePalindromes() {
    Node* current = head;

    while (current) {
        if (isPalindrome(current->data)) {
            Node* newNode = new Node{current->data, current->next};
            current->next = newNode;
            current = newNode->next; // Пропускаем только что добавленный узел
        } else {
            current = current->next;
        }
    }
}

// Проверка, упорядочен ли список по первой или последней цифре
bool LinkedList::isSortedByFirstOrLastDigit() const {
    if (!head) return true;

    Node* current = head;
    bool isSortedByFirst = true;
    bool isSortedByLast = true;

    while (current && current->next) {
        if (firstDigit(current->data) < firstDigit(current->next->data)) {
            isSortedByFirst = false;
        }
        if (lastDigit(current->data) < lastDigit(current->next->data)) {
            isSortedByLast = false;
        }
        current = current->next;
    }

    return isSortedByFirst || isSortedByLast;
}

// Упорядочивание по первой цифре
void LinkedList::sortByFirstDigit() {
    if (!head) return;

    std::vector<Node*> nodes;
    Node* current = head;

    while (current) {
        nodes.push_back(current);
        current = current->next;
    }

    std::sort(nodes.begin(), nodes.end(), [this](Node* a, Node* b) {
        return firstDigit(a->data) < firstDigit(b->data);
    });

    for (size_t i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes.back()->next = nullptr;
    head = nodes.front();
}

// Получение первой цифры числа
int LinkedList::firstDigit(int num) const {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

// Получение последней цифры числа
int LinkedList::lastDigit(int num) const {
    return num % 10;
}

// Проверка, является ли число палиндромом
bool LinkedList::isPalindrome(int num) const {
    int reversed = 0, original = num;
    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return original == reversed && original >= 10; // Палиндром должен быть длиной более 1 цифры
}
