#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void insert(int value);
    void display() const;
    void removeSingleDigit();
    void duplicatePalindromes();
    bool isSortedByFirstOrLastDigit() const;
    void sortByFirstDigit();

private:
    Node* head;
    int firstDigit(int num) const;
    int lastDigit(int num) const;
    bool isPalindrome(int num) const;
};

#endif // FUNCTIONS_HPP
