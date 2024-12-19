#include <iostream>
using namespace std;

class queue{
    int q[10],n, front, rear;
public:
    queue(){
        front=0;
        rear=-1;
        cout<<"Enter the size of the queue (max 10): "<<endl;
        cin>>n;
        if(n>10){
            cout<<"Queue can't be more than 10 elements."<<endl;
            exit(0);
        }else{
            cout<<"Enter the elements: "<<endl;
            for(int i=0; i<n; i++){
                rear++;
                cin>>q[rear];
            }
        }
    }

    bool full(){
        return (front == (rear + 1) % n);
    }
    
    bool empty(){
        return (front == -1);
    }

    void insertion(){
        if(full()){
            cout<<"Queue is Full."<<endl;
            return;
        }
        if(front == -1){
            front = 0;
            rear = 0;
            int element;
            cout<<"Enter the Element: "<<endl;
            cin>>element;
            rear++;
            q[rear] = element;
            cout<<"Element Inserted. ";
            traversal();
        }
    };
    void deletion(){
        if(front>rear){
            cout<<"Queue is Empty."<<endl;
        }else{
            front++;
            cout<<"Element Deleted. ";
            traversal();
        }
    };
    void traversal(){
        if(front>rear){
            cout<<"Queue is Empty."<<endl;
        }else{
            cout<<"New Array: "<<endl;
            for(int i=front; i<=rear; i++){
                cout<<q[i]<<endl;
            }
        }
    };
};

int main(){
    int n;
    char choice;
    queue obj1;
    do{
    cout<<"What you want to perform: "<<endl<<"1. Insertion"<<endl<<"2. Deletion"<<endl<<"3. Traversal"<<endl<<"4. Exit"<<endl;
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
        obj1.traversal();
        break;
    case 4:
        cout<<"Exiting Program."<<endl;
        return 0;
    default:
        cout<<"Enter the correct number";
        break;
    }
    cout<<"Do you want to continue(Y/N): "<<endl;
    cin>>choice;
    }while(choice == 'y' || choice == 'Y');
}