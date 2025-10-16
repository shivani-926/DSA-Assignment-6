#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (head == NULL)
        return false;

    Node* temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;

    return (temp == head);
}

int main() {
    Node* head = new Node{2, nullptr};
    Node* second = new Node{4, nullptr};
    Node* third = new Node{6, nullptr};
    Node* fourth = new Node{7, nullptr};
    Node* fifth = new Node{5, nullptr};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;   // make circular; remove this line to test non-circular

    if (isCircular(head))
        cout << "Linked list is circular";
    else
        cout << "Linked list is not circular";

    return 0;
}
