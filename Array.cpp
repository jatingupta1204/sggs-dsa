#include <iostream>
using namespace std;

class Myarray{
    int data[10], n, loc, element;
public:
    Myarray(){
        cout<<"Enter the number of elements you want to enter into the array: ";
        cin>>n;
        cout<<"Enter the data: "<<endl;
        for(int i=0; i<n; i++){
            cin>>data[i];
        }
    }

    void insertion(){
        cout<<"Where you want to insert an element: "<<endl;
        cin>>loc;
        for(int i=n; i>=loc; i--){
            data[i] = data[i-1];
        }
        cout<<"Enter the element you want to insert: ";
        cin>>element;
        data[loc-1] = element;
        n++;
        cout<<"Element Inserted. New Array: "<<endl;
        for(int i=0; i<n; i++){
            cout<<data[i]<<endl;
        }
    }

    void deletion(){
        cout<<"Which element you want to delete: "<<endl;
        cin>>loc;
        for (int i=loc-1; i<n; i++){
            data[i] = data[i+1];
        }
        n--;
        cout<<"Element Deleted. New Array: "<<endl;
        for(int i=0; i<n; i++){
            cout<<data[i]<<endl;
        }
    }

    void sorting(){
        int choice;
        cout<<"In which order do you want to sort: "<<endl<<"1. Ascending Order"<<endl<<"2. Descending Order"<<endl;
        cin>>choice;
        if(choice == 1){
            for(int i=0; i<n; i++){
                for(int j=0; j<n-i-1; j++){
                    if(data[j]>data[j+1]){
                        int temp=data[j];
                        data[j]=data[j+1];
                        data[j+1]=temp;
                    }
                }
            }
        }else if(choice == 2){
            for(int i=0; i<n; i++){
                for(int j=0; j<n-i-1; j++){
                    if(data[j]<data[j+1]){
                        int temp=data[j];
                        data[j]=data[j+1];
                        data[j+1]=temp;
                    }
                }
            }
        }
        cout<<"Sorted Array: "<<endl;
        for(int i=0; i<n; i++){
            cout<<data[i]<<endl;
        }
    }

    void searching(){
        bool found=false;
        cout<<"Enter the element you want to search: "<<endl;
        cin>>element;
        for(int i=0; i<n; i++){
            if(data[i] == element){
                cout<<"Element "<<element<<" found at position "<<i+1<<"."<<endl;
                found=true;
                break;
            }
        }
        if(!found){
            cout<<"Element "<<element<<" not found in the array."<<endl;
        }
    }

    void merge(){
        int data2[10], mergedArr[20], size;
        cout<<"Enter the number of elements you want in the new array: "<<endl;
        cin>>size;
        cout<<"Enter the data: "<<endl;
        for(int i=0; i<size; i++){
            cin>>data2[i];
        }
        for(int i=0; i<n; i++){
            mergedArr[i]=data[i];
        }
        for(int j=0; j<size; j++){
            mergedArr[n + j]=data2[j];
        }
        n += size;
        for(int i=0; i<n; i++){
            data[i]=mergedArr[i];
        }
        cout << "Arrays Merged. New Array: " << endl;
        for(int i = 0; i < n; i++){
            cout << data[i] << endl;
        }
    }

    void traversal(){
        cout<<"Array Elements: "<<endl;
        for(int i=0; i<n; i++){
            cout<<data[i]<<endl;
        }
    }
};

int main(){
    int n;
    char choice;
    Myarray obj1;
    do{
    cout<<"What you want to perform: "<<endl<<"1. Insertion"<<endl<<"2. Deletion"<<endl<<"3. Sorting"<<endl<<"4. Searching"<<endl<<"5. Merging"<<endl<<"6. Traversal"<<endl;
    cin>>n;
    switch (n)
    {
    case 1:
        obj1.insertion();
        break;
    case 2:
        obj1.deletion();
        break;
    case 3:
        obj1.sorting();
        break;
    case 4:
        obj1.searching();
        break;
    case 5:
        obj1.merge();
        break;
    case 6:
        obj1.traversal();
        break;
    default:
        cout<<"Enter the correct number";
        break;
    }
    cout<<"Do you want to continue(Y/N): "<<endl;
    cin>>choice;
    }while(choice == 'y'|| choice == 'Y');
}