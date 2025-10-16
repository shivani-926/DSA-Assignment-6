#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
    CNode* head;
public:
    CircularLinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        CNode* newNode = new CNode;
        newNode->data = val;
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode;
        newNode->data = val;
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int val) {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        CNode* temp = head;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode;
                newNode->data = val;
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        CNode *temp = head, *prev = NULL;
        if (head->data == key) {
            CNode* last = head;
            while (last->next != head)
                last = last->next;
            if (head == last) {
                delete head;
                head = NULL;
            } else {
                last->next = head->next;
                delete head;
                head = last->next;
            }
            return;
        }
        do {
            prev = temp;
            temp = temp->next;
            if (temp->data == key) {
                prev->next = temp->next;
                delete temp;
                return;
            }
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void search(int key) {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        CNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        DNode* newNode = new DNode;
        newNode->data = val;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode;
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        DNode* newNode = new DNode;
        newNode->data = val;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteNode(int key) {
        if (head == NULL) {
            cout << "List empty.\n";
            return;
        }
        DNode* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        delete temp;
    }

    void search(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found.\n";
    }

    void display() {
        DNode* temp = head;
        if (temp == NULL) {
            cout << "List empty.\n";
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    CircularLinkedList clist;
    DoublyLinkedList dlist;
    int choice, listType, val, key;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Circular Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> listType;

        if (listType == 3) break;

        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Delete a Node\n";
        cout << "5. Search a Node\n";
        cout << "6. Display List\n";
        cout << "Enter operation: ";
        cin >> choice;

        switch (listType) {
            case 1:
                switch (choice) {
                    case 1: cout << "Value: "; cin >> val; clist.insertAtBeginning(val); break;
                    case 2: cout << "Value: "; cin >> val; clist.insertAtEnd(val); break;
                    case 3: cout << "After which value: "; cin >> key; cout << "Value: "; cin >> val; clist.insertAfter(key, val); break;
                    case 4: cout << "Value to delete: "; cin >> val; clist.deleteNode(val); break;
                    case 5: cout << "Value to search: "; cin >> val; clist.search(val); break;
                    case 6: clist.display(); break;
                    default: cout << "Invalid choice\n";
                }
                break;

            case 2:
                switch (choice) {
                    case 1: cout << "Value: "; cin >> val; dlist.insertAtBeginning(val); break;
                    case 2: cout << "Value: "; cin >> val; dlist.insertAtEnd(val); break;
                    case 3: cout << "After which value: "; cin >> key; cout << "Value: "; cin >> val; dlist.insertAfter(key, val); break;
                    case 4: cout << "Value to delete: "; cin >> val; dlist.deleteNode(val); break;
                    case 5: cout << "Value to search: "; cin >> val; dlist.search(val); break;
                    case 6: dlist.display(); break;
                    default: cout << "Invalid choice\n";
                }
                break;

            default:
                cout << "Invalid list type.\n";
        }
    }

    cout << "Program terminated.\n";
    return 0;
}
