#include <iostream>
#define MAX 5
using namespace std;

class CircularQueue {
    int arr[MAX], front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1));
    }

    bool isEmpty() {
        return front == -1;
    }

    bool insert(int value) {
        if (isFull()) {
            cout << "Queue is overflow\n";
            return false;
        } else if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    bool deletion() {
        if (isEmpty()) {
            cout << "Queue is underflow\n";
            return false;
        }
        cout << "Deleted: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
        return true;
    }

    void traversal() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << "\t";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

void menu() {
    cout << "\n\n ---Menu---\n";
    cout << "\n Press 1: Insertion";
    cout << "\n Press 2: Deletion";
    cout << "\n Press 3: Traversal";
}

int main() {
    CircularQueue q;
    int n, num, choice;
    char cont;
    cout << "Size of queue is " << MAX << endl;
    cout << "Enter the number of elements (up to " << MAX << "): ";
    cin >> n;
    cout << "Enter the Elements: \n";
    for (int i = 0; i < n; i++) {
        cin >> num;
        q.insert(num);
    }
    do {
        menu();
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> num;
                q.insert(num);
                q.traversal();
                break;
            case 2:
                q.deletion();
                q.traversal();
                break;
            case 3:
                q.traversal();
                break;
            default:
                cout << "Invalid choice\nTry again\n";
                continue;
        }
        cout << "\nDo you want to continue (Y/N): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    return 0;
}
