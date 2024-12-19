#include <iostream>
using namespace std;

int stack[100], n=100, top=-1;

void push(){
    int val;
    cout<<"Enter the Value you want to push: "<<endl;
    cin>>val;
    if(top>=n-1){
        cout<<"Stack Overflow."<<endl;
    }else{
        top++;
        stack[top] = val;
    }
}

void pop(){
    if(top<=-1){
        cout<<"Stack Underflow"<<endl;
    }else{
        cout<<"The Poped element is: "<<stack[top]<<endl;
        top--;
    }
}

void traversal(){
    if(top>=0){
        cout<<"Stack Elements are: "<<endl;
        for(int i=top; i>=0; i--){
            cout<<stack[i];
        }
        cout<<endl;
    }else{
        cout<<"Stack is empty"<<endl;
    }
}

int main(){
    int g;
    char choice;
    do{
    cout<<"What do you want to perform: "<<endl<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Traversal"<<endl<<"4. Exit"<<endl;
    cin>>g;
    switch (g)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        traversal();
        break;
    case 4:
        cout<<"Exiting Program."<<endl;
        return 0;
    
    default:
        break;
    }
    cout<<"Do you want to continue(Y/N): "<<endl;
    cin>>choice;
    }while(choice == 'y' || choice == 'Y');
}