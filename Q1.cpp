#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = NULL;
    }

    // Destructor
    ~SinglyLinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // (a) Insertion at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at the beginning" << endl;
    }

    // (b) Insertion at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << value << " inserted at the end" << endl;
    }

    // (c) Insertion before a specific value
    void insertBefore(int value, int beforeValue) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        // If inserting before head
        if (head->data == beforeValue) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->data != beforeValue) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node with value " << beforeValue << " not found!" << endl;
        } else {
            Node* newNode = new Node(value);
            prev->next = newNode;
            newNode->next = temp;
            cout << value << " inserted before " << beforeValue << endl;
        }
    }

    // (c) Insertion after a specific value
    void insertAfter(int value, int afterValue) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != afterValue) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node with value " << afterValue << " not found!" << endl;
        } else {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            cout << value << " inserted after " << afterValue << endl;
        }
    }

    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from the beginning" << endl;
        delete temp;
    }

    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        // If only one node
        if (head->next == NULL) {
            cout << head->data << " deleted from the end" << endl;
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        cout << temp->next->data << " deleted from the end" << endl;
        delete temp->next;
        temp->next = NULL;
    }

    // (f) Deletion of a specific node
    void deleteSpecificNode(int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        // If deleting head
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node with value " << value << " not found!" << endl;
        } else {
            prev->next = temp->next;
            cout << "Node with value " << value << " deleted" << endl;
            delete temp;
        }
    }

    // (g) Search for a node and display its position
    void searchNode(int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Node with value " << value << " found at position " << position << " from head" << endl;
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "Node with value " << value << " not found!" << endl;
    }

    // (h) Display all node values
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "List elements: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, targetValue;

    do {
        cout << "\n----- SINGLY LINKED LIST OPERATIONS -----" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert before a specific value" << endl;
        cout << "4. Insert after a specific value" << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete specific node" << endl;
        cout << "8. Search for a node" << endl;
        cout << "9. Display list" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter the value before which to insert: ";
                cin >> targetValue;
                list.insertBefore(value, targetValue);
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter the value after which to insert: ";
                cin >> targetValue;
                list.insertAfter(value, targetValue);
                break;

            case 5:
                list.deleteFromBeginning();
                break;

            case 6:
                list.deleteFromEnd();
                break;

            case 7:
                cout << "Enter value of node to delete: ";
                cin >> value;
                list.deleteSpecificNode(value);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                list.searchNode(value);
                break;

            case 9:
                list.display();
                break;

            case 10:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 10);
    
    return 0;
}