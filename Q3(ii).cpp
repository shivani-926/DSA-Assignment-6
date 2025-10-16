#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node{10, nullptr};
    Node* second = new Node{20, nullptr};
    Node* third = new Node{30, nullptr};
    head->next = second;
    second->next = third;
    third->next = head;

    int count = 0;
    Node* temp = head;
    if (head != nullptr) {
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
    }

    cout << "Size of Circular Linked List: " << count << endl;
    return 0;
}
