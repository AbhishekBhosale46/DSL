#include <iostream>
using namespace std;

class Dqueue{
    public:
    int arr[50];
    int rear, front;
    
    Dqueue(){
        front = rear = -1;
    }
    
    void enqueueFront(int val){
        
        if( (front == rear+1) || (front == 0 && rear==49)){
            cout<<"Overflow"<<endl;
        }else if(front==-1 && rear==-1){
            front = rear = 0;
            arr[front] = val;
        }else if(front==0){
            front = 49;
            arr[front] = val;
        }else{
            front--;
            arr[front] = val;
        }
        
    }
    
    void enqueueRear(int val){
        
        if((front == rear+1) || (front==0 && rear==49)){
            cout<<"Overflow"<<endl;
        }else if(front==-1 && rear==-1){
            front = rear = 0;
            arr[rear] = val;
        }else if(rear==49){
            rear = 0;
            arr[rear] = val;
        }else{
            rear++;
            arr[rear] = val;
        }
        
    }
    
    int dequeueFront(){
        int del;
        if(front==-1 && rear==-1){
            cout<<"Empty"<<endl;
            return -1;
        }else if(front==rear){
            del = arr[front];
            front = rear = -1;
            return del;
        }else if(front == 49){
            del = arr[front];
            front = 0;
            return del;
        }else{
            del = arr[front];
            front++;
            return del;
        }
    }
    
    int dequeueRear(){
        int del;
        if(front==-1 && rear==-1){
            cout<<"Empty"<<endl;
            return -1;
        }else if(front==rear){
            del = arr[rear];
            front = rear = -1;
            return del;
        }else if(rear==0){
            del = arr[rear];
            rear = 49;
            return del;
        }else{
            del = arr[rear];
            rear--;
            return del;
        }
    }
    
    void display(){
        int i=front;
        while(i!=rear){
            cout<<arr[i]<<" ";
            i = (i+1)%50;
        }
        cout<<arr[rear]<<endl;
    }
    
    int getFront(){
        if(front==-1 && rear==-1){
            cout<<"Empty"<<endl;
        }else{
            return arr[front];
        }
    }
    
    int getRear(){
        if(front==-1 && rear == -1){
            cout<<"Empty"<<endl;
        }else{
            return arr[rear];
        }
    }
    
};

int main() {
    Dqueue dq;
    
    dq.enqueueFront(5);
    dq.enqueueFront(10);
    dq.enqueueFront(20);
    dq.enqueueRear(30);
    dq.display();
    
    dq.dequeueFront();
    dq.dequeueRear();
    dq.display();
    
    
    return 0;
}