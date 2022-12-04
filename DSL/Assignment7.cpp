#include <iostream>
using namespace std;

class Node{

    public:
    bool isBooked;
    Node *next;
    Node *prev;

    Node(bool book = false)
    {
        this->isBooked = book;
        this->next = NULL;
        this->prev = NULL;
    }

};


class DLL{

    public:
    Node *head;

    DLL()
    {
        head = NULL;
    }

    void insertHead(bool val=false)
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

    void display(){
        Node *temp = head;

        while (temp->next != head)
        {  
            cout << temp->isBooked <<" ";
            temp = temp->next;
        }
        cout<<temp->isBooked<<" ";
        cout<<endl;
    }

    void bookSeat(int seatNo)
    {
        Node *temp = head;
        int counter = 1;

        if(seatNo > 7){
            cout<<"Seat doesnt exists"<<endl;
        }else{

            while(counter != seatNo){
                temp = temp->next;
                if(temp->next == head){
                    break;
                }
                counter++;
            }
            if(temp->isBooked == true){
                cout<<"Seat already booked"<<endl;
            }else{
                temp->isBooked = true;
                cout<<"Seat booked"<<endl;
            }
            
        }
    }

    void cancelSeat(int seatNo){
        Node *temp = head;
        int counter = 1;

        if(seatNo > 7){
            cout<<"Seat doesnt exists"<<endl;
        }else{

            while(counter != seatNo){
                temp = temp->next;
                if(temp->next == head){
                    break;
                }
                counter++;
            }
            if(temp->isBooked == false){
                cout<<"Seat already cancelled"<<endl;
            }else{
                temp->isBooked = false;
                cout<<"Seat cancelled"<<endl;
            }
            
        }
    }

};


class Theatre{

    public:
    
    DLL r1, r2;

    Theatre(){
        r1.insertHead(true);
        r1.insertHead(true);
        r1.insertHead();

        r2.insertHead();
        r2.insertHead();
        r2.insertHead();
    }

    Node *row[2] = { r1.head, r2.head};

    void display(){
        cout<<row[0]->next;
    }
    
    

};


int main()
{
    // DLL dll;
    // dll.insertHead();
    // dll.insertHead();
    // dll.insertHead();
    // dll.insertHead();
    // dll.display();

    // dll.bookSeat(2);
    // dll.bookSeat(4);
    // dll.display();

    // dll.cancelSeat(2);
    // dll.cancelSeat(4);
    // dll.cancelSeat(1);
    // dll.display();

    Theatre myt;
    myt.display();

    return 0;
}