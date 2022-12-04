#include <iostream>
#include<cstring>
using namespace std;

class Stack{

    public:
    char s[50];
    int top;

    Stack(){
        top = -1;
    }

    void push(char ch){
        if(top <50 ){
            //push the elements
            top += 1;
            s[top] = ch;
        }else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    char pop(){
        if(top == -1){
            cout<<"Stack is empty "<< endl;
        }else{
            char c = s[top];
            top--;
            return c;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){
        if(top < 49){
            return false;
        }else{
            return true;
        }
    }

    char topEle(){
        return s[top];
    }

};

int main() {

    Stack myStack;
    bool isValid = false;

    // INPUT STRING
    string expr;
    cin>>expr;

    // CONVERT TO CHAR ARRAY   
    int len = expr.length();
    char ex[len];
    strcpy(ex, expr.c_str());

    // CHECK IF VALID
    for(int i=0; i<len; i++){

        if(ex[i]=='(' || ex[i]=='{' || ex[i]=='['){
            myStack.push(ex[i]);
        }else if(ex[i]==')'){
            char p = myStack.pop();
            if(p == '('){
                isValid = true;
            }else{
                isValid = false;
            }
        }else if(ex[i]=='}'){
            char p = myStack.pop();
            if(p == '{'){
                isValid = true;
            }else{
                isValid = false;
            }
        }else if(ex[i]==']'){
            char p = myStack.pop();
            if(p == '['){
                isValid = true;
            }else{
                isValid = false;
            }
        }

        if(myStack.isEmpty()){
            isValid = true;
        }else{
            isValid = false;
        }

    }

    if(isValid == true){
        cout<<"Expression is valid";
    }else{
        cout<<"Expression is not valid";
    }


    return 0;
}