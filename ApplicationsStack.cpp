#include <iostream>
#include <string>
#include <stack>
using namespace std;

class stackApp
{
public:
    void reverse()
    {
        string str, rev;
        cout << "Enter the String: " << endl;
        cin >> str;
        for (int i = str.length() - 1; i >= 0; i--)
        {
            rev += str[i];
        }
        cout << "Reversed String: " << rev << endl;
    }

    int precedence(char ch)
    {
        if (ch == '+' || ch == '-')
        {
            return 1;
        }
        if (ch == '*' || ch == '/')
        {
            return 2;
        }
        return 0;
    }

    bool isOperand(char ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }

    void InToPost()
    {
        string infix, postfix;
        stack<char> st;
        int n = 100, top = -1;
        cout << "Enter the infix expression: " << endl;
        cin >> infix;
        st.push('(');
        infix += ')';

        for (int i = 0; i < infix.length(); i++)
        {
            char ch = infix[i];

            if (isOperand(ch))
            {
                postfix += ch;
            }
            else if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && precedence(ch) <= precedence(st.top()))
                {
                    postfix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        cout << "Postfix Expression: " << postfix << endl;
    }

    void evaluating()
    {
        string postfix;
        cout << "Enter the postfix expression: " << endl;
        cin >> postfix;
        stack<int> st;
        for (int i = 0; i < postfix.length(); i++)
        {
            char ch = postfix[i];
            if (isdigit(ch))
            {
                st.push(ch - '0');
            }
            else
            {
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                switch (ch)
                {
                case '+':
                    st.push(val1 + val2);
                    break;
                case '-':
                    st.push(val1 - val2);
                    break;
                case '*':
                    st.push(val1 * val2);
                    break;
                case '/':
                    st.push(val1 / val2);
                    break;
                }
            }
        }
        cout << "Result of postfix evaluation: " << st.top() << endl;
    }

    void delimiter(){
        string expression;
        cout<<"Enter the Expression with Delimiters: "<<endl;
        cin>>expression;
        stack<char> st;
        bool isValid = true;
        for (int i = 0; i < expression.length(); i++){
            char ch = expression[i];
            if (ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }else if (ch == ')' || ch == '}' || ch == ']'){
                if (st.empty()){
                    isValid = false;
                    break;
                }
                char top = st.top();
                st.pop();
                if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')){
                    isValid = false;
                    break;
                }
            }
        }
        if (!st.empty()){
            isValid = false;
        }
        if (isValid){
            cout << "The expression has matching delimiters." << endl;
        }else{
            cout << "The expression has unmatched delimiters." << endl;
        }
    }

    int factorial(int n){
        if(n<=1){
            return 1;
        }
        return n * factorial(n -1);
    }
    
    void recursion(){
        int num;
        cout<<"Enter the number to calculate its factorial: "<<endl;
        cin>>num;
        int result = factorial(num);
        cout<<"Factorial of "<<num<<" is: "<<result<<endl;
    }
};

    int main()
    {
        int n;
        char choice;
        stackApp obj1;
        do{
        cout << "What you want to perform: " << endl
             << "1. Reverse a String" << endl
             << "2. Converting an Infix Expression to Postfix" << endl
             << "3. Evaluating a Postfix Operations" << endl
             << "4. Delimiter Matching" << endl
             << "5. Recursion" << endl;   
        cin >> n;
        switch (n)
        {
        case 1:
            obj1.reverse();
            break;
        case 2:
            obj1.InToPost();
            break;
        case 3:
            obj1.evaluating();
            break;
        case 4:
            obj1.delimiter();
            break;
        case 5:
            obj1.recursion();
            break;
        default:
            cout<<"Please enter the correct number."<<endl;
            break;
        }
        cout<<"Do you want to continue(Y/N): "<<endl;
        cin>>choice;
        }while(choice == 'y' || choice == 'Y');
    }