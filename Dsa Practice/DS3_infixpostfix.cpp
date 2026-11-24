#include <iostream>
#include <cctype>
using namespace std;

char stack[100];
int top = -1;

void push(char x){
    stack[++top] = x;

}

char pop(){
    return stack[top--];
}

int priority(char x){
    if(x == '*' || x == '/'){
        return 2;
    }
    else if(x == '+' || x == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
char infix[100],postfix[100];
int j=0;
cout << "Enter the infix expression: ";
cin >> infix;

for(int i =0; infix[i] != '\0';i++){
    char x = infix[i];
    if(isalnum(x)){
        postfix[j++] = x;
    }
    else if(x == '('){
        push(x);
    }
    else if( x ==')'){
        while(top != -1 && stack[top] != '('){
            postfix[j++] = pop();
        }
        if(top!= -1){
            pop();
        }
        
    }
    else{
        while(top !=-1 && priority(stack[top]) >= priority(x)){
            postfix[j++] = pop();
        }
        push(x);
    }


}
while(top != -1){
    postfix[j++] = pop();
}
postfix[j] = '\0';

cout<<"Postfix expression" << postfix << endl;

int value[100];
int t = -1;

cout<<"Enter the digits values for operands if any: ";

for(int i = 0; postfix[i] != '\0'; i++){
    char x = postfix[i];

    if(isdigit(x)){
        value[++t] = x - '0';
    }
    else if(isalpha(x)){
        int v;
        cout << x << " ";
        cin >> v;
        value[++t] = v;
    }
    else{
        int b = value[t--];
        int a = value[t--];

        switch(x){
            case '+': value[++t] = a+b; break;
            case '-': value[++t] = a-b; break;
            case '*': value[++t] = a*b; break;
            case '/':
            if(b==0){
                cout << "Invalid Input for B";
                return 0;
            }
            value[++t] = a/b; break;
            
        }
    }
}
cout << "Result: " << value[t] << endl;
return 0;
}