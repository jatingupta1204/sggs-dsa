#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int low, int high, int target){
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid]<target){
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    int target;

    bubbleSort(arr, n);

    cout<<"Sorted Array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;

    cout<<"Enter element to search: ";
    cin>>target;

    int result = binarySearch(arr, 0, n-1, target);

    if(result != -1){
        cout<<"Element found at index: "<<result+1<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}
