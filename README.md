

# UCS301 Data Structures

## Lab Assignment 5: Single Linked List

---

## **Explanations**

### **1. Operations on a Singly Linked List**

A **singly linked list** is a linear data structure where each node contains data and a reference (pointer) to the next node. Unlike arrays, linked lists allow **dynamic memory allocation** and efficient **insertions/deletions** at arbitrary positions.

Key operations demonstrated in this lab:

* **Insertion:** at beginning, at end, or before/after a node.
* **Deletion:** from beginning, from end, or a specific node.
* **Search:** traversing the list to find a node and return its position.
* **Traversal:** displaying all node values.

**Code:**
```cpp
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
```

**Sample Output:**

```

----- SINGLY LINKED LIST OPERATIONS -----
1. Insert at beginning
2. Insert at end
3. Insert before a specific value
4. Insert after a specific value
5. Delete from beginning
6. Delete from end
7. Delete specific node
8. Search for a node
9. Display list
10. Exit
Enter your choice:1
 Enter value to insert at beginning:21
 21 inserted at the beginning

----- SINGLY LINKED LIST OPERATIONS -----
1. Insert at beginning
2. Insert at end
3. Insert before a specific value
4. Insert after a specific value
5. Delete from beginning
6. Delete from end
7. Delete specific node
8. Search for a node
9. Display list
10. Exit
Enter your choice:2
 Enter value to insert at end:22
 22 inserted at the end

----- SINGLY LINKED LIST OPERATIONS -----
1. Insert at beginning
2. Insert at end
3. Insert before a specific value
4. Insert after a specific value
5. Delete from beginning
6. Delete from end
7. Delete specific node
8. Search for a node
9. Display list
10. Exit
Enter your choice:3
 Enter value to insert:21
 Enter the value before which to insert:21
 21 inserted at the beginning

----- SINGLY LINKED LIST OPERATIONS -----
1. Insert at beginning
2. Insert at end
3. Insert before a specific value
4. Insert after a specific value
5. Delete from beginning
6. Delete from end
7. Delete specific node
8. Search for a node
9. Display list
10. Exit
Enter your choice:4
 Enter value to insert:32
 Enter the value after which to insert:22
 32 inserted after 22

----- SINGLY LINKED LIST OPERATIONS -----
1. Insert at beginning
2. Insert at end
3. Insert before a specific value
4. Insert after a specific value
5. Delete from beginning
6. Delete from end
7. Delete specific node
8. Search for a node
9. Display list
10. Exit
Enter your choice:5
 21 deleted from the beginning

----- SINGLY LINKED LIST OPERATIONS -----
1. Insert at beginning
2. Insert at end
3. Insert before a specific value
4. Insert after a specific value
5. Delete from beginning
6. Delete from end
7. Delete specific node
8. Search for a node
9. Display list
10. Exit
Enter your choice:6
 32 deleted from the end

Process finished with exit code 0

```

---

### **2. Count & Delete Occurrences of a Key**

This program traverses the linked list, counts how many times a key appears, and deletes all occurrences. It highlights how traversal and node manipulation can be combined.

**Code:**
```cpp
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
    
    int countAndDelete(int key) {
        int count = 0;
        
        // Handle deletion from head
        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        
        // Handle deletion from middle/end
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                count++;
            } else {
                curr = curr->next;
            }
        }
        
        return count;
    }
    
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    
    // Create list: 1->2->1->2->1->3->1
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(1);
    
    cout << "Original List: ";
    list.display();
    
    int key = 1;
    int count = list.countAndDelete(key);
    
    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    list.display();
    
    return 0;
}
```

**Sample Output:**

```
Original List: 1->2->1->2->1->3->1
Count: 4
Updated List: 2->2->3

Process finished with exit code 0

```

---

### **3. Find the Middle of a Linked List**

The **slow and fast pointer technique** is used:

* The slow pointer moves one step at a time.
* The fast pointer moves two steps at a time.
  When the fast pointer reaches the end, the slow pointer will be at the middle.

**Code:**
```cpp
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
    
    int findMiddle() {
        if (!head) return -1;
        
        Node* slow = head;
        Node* fast = head;
        
        // Fast moves 2 steps, slow moves 1 step
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->data;
    }
    
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    
    // Create list: 1->2->3->4->5
    for (int i = 1; i <= 5; i++) {
        list.insert(i);
    }
    
    cout << "List: ";
    list.display();
    
    cout << "Middle element: " << list.findMiddle() << endl;
    
    return 0;
}
```

**Sample Output:**

```
List: 1->2->3->4->5
Middle element: 3

Process finished with exit code 0

```

---

### **4. Reverse a Linked List**

Reversing is achieved by changing the direction of `next` pointers for all nodes. This operation is crucial in many algorithms, including palindrome detection and memory optimization.

**Code:**
```cpp
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
```

**Sample Output:**

```
Original: 1->2->3->4->NULL
Reversed: 4->3->2->1->NULL

Process finished with exit code 0

```

---

## **Conclusion**

This Assignment provided a **hands-on exploration of singly linked lists**, with focusing on fundamental dynamic data structure.
Key takeaways:

* **Insertion and Deletion** demonstrate memory flexibility compared to arrays.
* **Counting and Removing Keys** shows how traversal logic can be extended to solve application-specific problems.
* **Middle Element Retrieval** emphasizes efficient algorithms using pointer manipulation.
* **Reversal of a List** is a classic transformation problem highlighting pointer re-linking.

Overall, the assignment reinforced **pointer-based data handling**, efficient traversal, and manipulation of linked lists, which are critical for advanced data structure design and memory management.

---

