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