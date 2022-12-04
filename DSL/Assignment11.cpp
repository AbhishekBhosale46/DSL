#include <iostream>
using namespace std;

class Queue{
   
    public:
    int arr[50];
    int front;
    int rear;
   
    Queue(){
        front = -1;
        rear = -1;
    }
   
    void enqueue(int val){
        if(rear == 49){
            cout<<"Overflow"<<endl;
        }else{
            if(front == -1){
                front = 0;
            }
            rear = rear+1;
            arr[rear] = val;
        }
    }
   
    int dequeue(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
        }else{
            int del = arr[front];
            if(front == rear){
                front = rear = -1;
            }else{
                front = front+1;
            }
            return del;
        }
    }
   
    void display(){
        if(front==-1 && rear==-1){
            cout<<"Queue is empty"<<endl;
        }else{
            for(int i=front; i<=rear; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
   
   
};

int main() {
   
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(20);
    q.display();
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.display();
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(20);
    q.display();
    return 0;
}