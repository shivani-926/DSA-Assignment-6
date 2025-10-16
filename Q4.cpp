#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

int main() {
    Node* head = new Node{'l', nullptr, nullptr};
    Node* second = new Node{'e', nullptr, head};
    Node* third = new Node{'v', nullptr, second};
    Node* fourth = new Node{'e', nullptr, third};
    Node* fifth = new Node{'l', nullptr, fourth};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node* left = head;
    Node* right = head;
    while (right->next != nullptr)
        right = right->next;

    bool isPalindrome = true;
    while (left != right && right->next != left) {
        if (left->data != right->data) {
            isPalindrome = false;
            break;
        }
        left = left->next;
        right = right->prev;
    }

    if (isPalindrome)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}
