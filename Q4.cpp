#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr) {
            next = curr->next;    // Store next node
            curr->next = prev;    // Reverse the link
            prev = curr;          // Move prev forward
            curr = next;          // Move curr forward
        }

        head = prev;  // Update head
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    // Create list: 1->2->3->4
    for (int i = 1; i <= 4; i++) {
        list.insert(i);
    }

    cout << "Original: ";
    list.display();

    list.reverse();

    cout << "Reversed: ";
    list.display();

    return 0;
}