#include <iostream>
using namespace std;

class Sorting {
private:
    int* arr; // Array for sorting
    int n;    // Size of the array

public:
    // Constructor to initialize the array and size
    Sorting(int size) {
        n = size;
        arr = new int[n];
    }

    // Destructor to free up memory
    ~Sorting() {
        delete[] arr;
    }

    // Function to take array input from the user
    void inputArray() {
        cout << "Enter the elements of the array:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    // Function to display the array
    void displayArray() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to swap two elements
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Bubble Sort
    void bubbleSort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Selection Sort
    void selectionSort() {
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    // Insertion Sort
    void insertionSort() {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Quick Sort: Partition function
    int partition(int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    // Quick Sort
    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    // Merge Sort: Merge function
    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }
        for (int i = 0; i < n2; i++) {
            R[i] = arr[mid + 1 + i];
        }

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }

    // Merge Sort
    void mergeSort(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }

    // Function to make a copy of the array
    void copyArray(int original[]) {
        for (int i = 0; i < n; i++) {
            arr[i] = original[i];
        }
    }
};

// Menu-driven program
int main() {
    int choice, n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    Sorting sorter(n); // Create Sorting class object
    int originalArr[n]; // Store original array

    // Input the array
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> originalArr[i];
    }

    do {
        cout << "\n--- Sorting Menu ---\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Merge Sort\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Copy the original array to the sorter for each sort operation
        sorter.copyArray(originalArr);

        switch (choice) {
            case 1:
                sorter.bubbleSort();
                cout << "Sorted array using Bubble Sort: ";
                sorter.displayArray();
                break;
            case 2:
                sorter.selectionSort();
                cout << "Sorted array using Selection Sort: ";
                sorter.displayArray();
                break;
            case 3:
                sorter.insertionSort();
                cout << "Sorted array using Insertion Sort: ";
                sorter.displayArray();
                break;
            case 4:
                sorter.quickSort(0, n - 1);
                cout << "Sorted array using Quick Sort: ";
                sorter.displayArray();
                break;
            case 5:
                sorter.mergeSort(0, n - 1);
                cout << "Sorted array using Merge Sort: ";
                sorter.displayArray();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
