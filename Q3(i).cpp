#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    Node* head = new Node{10, nullptr, nullptr};
    Node* second = new Node{20, nullptr, head};
    Node* third = new Node{30, nullptr, second};
    head->next = second;
    second->next = third;

    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    cout << "Size of Doubly Linked List: " << count << endl;
    return 0;
}
