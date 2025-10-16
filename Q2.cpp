#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node{20, nullptr};
    Node* second = new Node{100, nullptr};
    Node* third = new Node{40, nullptr};
    Node* fourth = new Node{80, nullptr};
    Node* fifth = new Node{60, nullptr};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;

    Node* temp = head;

    if (head != nullptr) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data;
    }

    cout << endl;
    return 0;
}
