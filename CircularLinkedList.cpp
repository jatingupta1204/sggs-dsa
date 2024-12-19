#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// CircularLinkedList class to manage operations
class CircularLinkedList {
private:
    Node* last;

public:
    // Constructor to initialize the last pointer
    CircularLinkedList() {
        last = nullptr;
    }

    // Insert a node at the end of the circular linked list
    void insert(int value) {
        Node* newNode = new Node(value);

        if (last == nullptr) {  // If list is empty
            last = newNode;
            last->next = last;  // Point to itself
        } else {
            newNode->next = last->next;  // Link new node to first node
            last->next = newNode;        // Update last node's next
            last = newNode;              // Update last to the new node
        }
        cout << "Inserted " << value << endl;
    }

    // Delete a node with a given value
    void deleteNode(int value) {
        if (last == nullptr) {  // List is empty
            cout << "List is empty. Cannot delete " << value << endl;
            return;
        }

        Node* temp = last->next;  // Start from the first node
        Node* prev = last;

        // If there is only one node in the list
        if (last == last->next && last->data == value) {
            delete last;
            last = nullptr;
            cout << "Deleted " << value << endl;
            return;
        }

        // If the node to be deleted is the first node
        if (temp->data == value) {
            prev->next = temp->next;  // Update the last's next to the second node
            delete temp;
            cout << "Deleted " << value << endl;
            return;
        }

        // Traverse the list to find the node to delete
        do {
            prev = temp;
            temp = temp->next;
            if (temp->data == value) {
                prev->next = temp->next;
                if (temp == last) {
                    last = prev;  // Update last if we're deleting the last node
                }
                delete temp;
                cout << "Deleted " << value << endl;
                return;
            }
        } while (temp != last->next);

        // Node not found
        cout << "Value " << value << " not found in the list." << endl;
    }

    // Display the circular linked list
    void display() {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = last->next;  // Start from the first node
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "Back to start (Circular)" << endl;
    }
};

// Menu-driven program
int main() {
    CircularLinkedList list;
    int choice, value;

    do {
        // Menu
        cout << "\n--- Circular Linked List Operations ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 3:
                list.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
