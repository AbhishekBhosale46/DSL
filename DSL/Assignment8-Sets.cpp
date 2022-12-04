#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    Node(int data=0){
        this->data = data;
        this->next = NULL;
    }

};

class LinkedList{
    
    public:
    Node *head;

    LinkedList(){
        head = NULL;
    }

    void insertTail(int val){
        Node *newNode = new Node(val);
        Node *temp = head;

        if(head == NULL){
            head = newNode;
        }else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }

    }

    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    bool search(int key){
        Node *temp = head;
        while(temp != NULL){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

};


LinkedList findIntersection(LinkedList &ll1, LinkedList &ll2){

    Node *temp1 = ll1.head;
    Node *temp2 = ll2.head;

    LinkedList result;

    while(temp1 != NULL){
        if(ll2.search(temp1->data)){
            result.insertTail(temp1->data);
        }
        temp1 = temp1->next;
    }
    return result;
}

LinkedList findUnion(LinkedList &ll1, LinkedList &ll2){
    Node *temp1 = ll1.head;
    Node *temp2 = ll2.head;

    LinkedList result;

    while(temp1 != NULL){
        result.insertTail(temp1->data);
        temp1 = temp1->next;
    }

    while(temp2 != NULL){
        if(!result.search(temp2->data)){
            result.insertTail(temp2->data);
        }
        temp2 = temp2->next;
    }

    return result;

}

LinkedList symmetricDiff(LinkedList &ll1, LinkedList &ll2){

    LinkedList uni, inter, result;
    uni = findUnion(ll1, ll2);
    inter = findIntersection(ll1, ll2);

    Node *temp1 = uni.head;
    Node *temp2 = inter.head;

    while(temp1 != NULL){
        if(!inter.search(temp1->data)){
            result.insertTail(temp1->data);
        }
        temp1 = temp1->next;
    }

    return result;

}

LinkedList subprob2(LinkedList &unill, LinkedList &inter){

    LinkedList result;

    Node *temp1 = unill.head;

    while(temp1 != NULL){
        if(!inter.search(temp1->data)){
            result.insertTail(temp1->data);
        }
        temp1 = temp1->next;
    }
    return result;
}

int main(){

    LinkedList setA, setB, universal, resultI, resultU, resultSym, resultSub2;
    
    universal.insertTail(5);
    universal.insertTail(10);
    universal.insertTail(20);
    universal.insertTail(22);
    universal.insertTail(32);
    universal.insertTail(16);
    universal.insertTail(17);
    cout<<"UNIVERSAL : ";
    universal.display();

    setA.insertTail(5);
    setA.insertTail(10);
    setA.insertTail(20);
    cout<<"SET A : ";
    setA.display();

    setB.insertTail(5);
    setB.insertTail(10);
    setB.insertTail(22);
    setB.insertTail(32);
    cout<<"SET B : ";
    setB.display();

    resultI = findIntersection(setA, setB);
    cout<<"INTERSECTION : ";
    resultI.display();

    resultU = findUnion(setA, setB);
    cout<<"UNION : ";
    resultU.display();

    resultSym = symmetricDiff(setA, setB);
    cout<<"SYMMETRIC DIFF : ";
    resultSym.display();

    resultSub2 = subprob2(universal, resultI);
    cout<<"EITHER VANILLA OR BUTTER OR NOT BOTH  : ";
    resultSub2.display();

    return 0;
}