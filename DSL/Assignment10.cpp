#include <iostream>
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

int prec(char c){
    if(c == '+' || c== '-'){
        return 2;
    }else if(c == '*' || c == '/'){
        return 1;
    }else{
        return -1;
    }
}

bool isOperand(char c){
    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
         return true;
    }else{
        return false;
    }
}

string inToPost(string st){
    
    Stack s;
    string post;
    
    for(int i=0; i<=st.length(); i++){
        char c = st[i];
        
        // If operand add to postfix
        if(isOperand(c)){
            post += c;
        }
        // If ( push in stack
        else if(c=='('){
            s.push(c);
        }
        // Pop unitll (
        else if( c==')'){
            while(s.topEle() != '('){
                post += s.topEle();
                s.pop();
            }
            s.pop();
        }
        // If operator is encountered
        else{
            while( !s.isEmpty() && (prec(c) <= prec(s.topEle())) ){
                post += s.topEle();
                s.pop();
            }
            s.push(c);
        }
        
    }
    
    return post;
    
}

int main() {

    string in;
    cin>>in;
    cout<<in<<endl;
    cout<<inToPost(in);
    
    

    return 0;
}