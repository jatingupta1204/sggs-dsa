#include <iostream>
using namespace std;

class matrix{
    int a[10][10], b[10][10], c[10][10], rows, cols;
public:
    matrix(){
        cout<<"Enter the number of rows: "<<endl;
        cin>>rows;
        cout<<"Enter the number of cols: "<<endl;
        cin>>cols;
        cout<<"Enter the data of the First Matrix: "<<endl;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cin>>a[i][j];
            }
        }
        cout<<"Enter the data of the Second Matrix: "<<endl;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cin>>b[i][j];
            }
        }
    }

    void addition(){
        cout<<"Addition of Two Given Matrix: "<<endl;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                c[i][j] = a[i][j] + b[i][j];
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void subtraction(){
        cout<<"Subtraction of Two Given Matrix: "<<endl;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                c[i][j] = a[i][j] - b[i][j];
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void multiplication(){
        cout<<"Multiplication of Two Given Matrix: "<<endl;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                c[i][j] = 0;
                for(int k=0; k<cols; k++){
                    c[i][j] += a[i][k] * b[k][j];
                }
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void transpose(){
        cout<<"Transpose of First Matrix: "<<endl;
        for(int i=0; i<cols; i++){
            for(int j=0; j<rows; j++){
                cout<<a[j][i]<<" ";
            }
            cout<<endl;
        }
        cout<<"Transpose of Second Matrix: "<<endl;
        for(int i=0; i<cols; i++){
            for(int j=0; j<rows; j++){
                cout<<b[j][i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    char choice;
    matrix obj1;
    do{
    cout<<"What you want to perform: "<<endl<<"1. Addition"<<endl<<"2. Subtraction"<<endl<<"3. Multiplication"<<endl<<"4. Transpose of Array"<<endl;
    cin>>n;
    switch (n)
    {
    case 1:
        obj1.addition();
        break;
    case 2:
        obj1.subtraction();
        break;
    case 3:
        obj1.multiplication();
        break;
    case 4:
        obj1.transpose();
        break;
    default:
        cout<<"Invalid Number";
        break;
    }
    cout<<"Do you want to Continue(Y/N): "<<endl;
    cin>>choice;
    }while(choice == 'y' || choice == 'Y');
}