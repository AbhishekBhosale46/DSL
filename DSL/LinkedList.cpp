#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next; // Pointer of node type

    // Initially when a new node is created, the next pointer is set to null
    Node(int val){
        data = val;
        next = NULL;
    }

};

class LinkedList{

    // Every linked list has a head(pointer of type node)
    Node *head;

    public:

    LinkedList(){
        // Initially when a new ll is created, its head will point to null
        head = NULL;
    }

    void insertHead(int val){

        // A new node is created at first
        Node *newNode = new Node(val);
        
        if(head == NULL){
            // The head is null (i.e initially), then head will point to newNode.
            head = newNode;
        }else{
            // Point next of newNode to the present head, then shift head to newNode.
            newNode->next = head;
            head = newNode;
        }
    }

    void insertTail(int val){

        // A new node is created at first
        Node *newNode = new Node(val);

        // Temporary node pointer pointing to head, used to determine the last node
        Node *temp = head;

        if(head == NULL){
            // The head is null (i.e initially), then head will point to newNode
            head = newNode;
        }else{
            // Find the last node 
            while(temp->next != NULL){
            temp = temp->next;
            }
            // Then assign last nodes next pointer to newNode
            temp->next = newNode;
        }
    }

    void display(){

        // Temporary node pointer pointing to head
        Node *temp = head;

        // Shift the temp pointer to next unitll its null and print data
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    bool search(int val){
        Node *temp = head;
        while(temp != NULL){
            if(temp->data == val){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void deleteNode(int val){

        // Temporary node pointer pointing to head
        Node *temp = head;

        // If value to delete is at head then shift the head to its next, then delete the temp node.
        if(head->data == val){
            head = head->next;
            delete temp;
        }else{
            // Traverse till we find the value
            while(temp->next->data != val){
                temp = temp->next;
                // To check the end of list
                if(temp->next == NULL){
                    break;
                }
            }

            // If the next of temp is null means that value doesnt exists
            if(temp->next == NULL){
                cout<<"Value doesnt exists"<<endl;;
            }else{
                // New pointer pointing to the node to delete
                Node *toDelete = temp->next;

                // Pointing the next of current to the next of toDelete and then delete
                temp->next = toDelete->next;
                delete toDelete; 
            } 
        }
    }

    void deleteN(int val){
        Node *temp = head;
        if(temp != NULL && temp->data == val){
            head = temp->next;
            delete temp;
            return;
        }else{
            Node *temp2 = head;
            while(temp->data != val && temp!=NULL){
                temp2 = temp;
                temp = temp->next;
            }
            if(temp==NULL){
                cout<<"Value not found"<<endl;
                return;
            }
            temp2->next = temp->next;
            delete temp;
        }
    }

};

int main(){

    LinkedList myLinked;
    myLinked.insertTail(5);
    myLinked.insertTail(10);
    myLinked.insertTail(50);
    myLinked.insertHead(2);
    myLinked.insertHead(1);
    myLinked.display();
    myLinked.deleteNode(1);
    myLinked.deleteNode(50);
    myLinked.deleteNode(2);
    myLinked.display();
    cout<<myLinked.search(10);

    return 0;
}