

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
Enter your choice:9
 List elements: 21 -> 22 -> NULL

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
Enter your choice:10
 Exiting program...

Process finished with exit code 0

```

---

### **2. Count & Delete Occurrences of a Key**

This program traverses the linked list, counts how many times a key appears, and deletes all occurrences. It highlights how traversal and node manipulation can be combined.

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

**Sample Output:**

```
List: 1->2->3->4->5
Middle element: 3

Process finished with exit code 0

```

---

### **4. Reverse a Linked List**

Reversing is achieved by changing the direction of `next` pointers for all nodes. This operation is crucial in many algorithms, including palindrome detection and memory optimization.

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

