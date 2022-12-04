#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int val = 0)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLL
{

    public:
    Node *head;

    DLL()
    {
        head = NULL;
    }

    void insertHead(int val)
    {

        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            Node *last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head = newNode;
        }
    }

    void display()
    {
        Node *temp = head;

        while (temp->next != head)
        {  
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout<<temp->data<<" ";
        cout<<endl;

    }

    void deleteData(int val){
        
        Node *temp = head;

        // Check if the data is at head
        if(head->data == val){

            Node *last = head->prev;

            last->next = head->next;
            head->next->prev = last;

            head = head->next;
            delete temp;

        }else{

            // Traverse till the data is found
            while(temp->next->data != val){
                temp = temp->next;
                if(temp->next == head){
                    break;
                }
            }
            
            if(temp->next->data == val){
                Node *toDelete = temp->next;
                temp->next = toDelete->next;
                toDelete->next->prev = temp;
                delete toDelete;
            }else{
                cout<<"Not found"<<endl;
            }

        }

        

    }

};

int main()
{
    DLL dll;
    dll.insertHead(5);
    dll.insertHead(10);
    dll.insertHead(15);
    dll.insertHead(20);
    dll.display();
    dll.deleteData(5);
    dll.display();

    return 0;
}