/*
Write C++ program for storing appointment schedule for day. Appointments
are booked randomly using linked list. Set start and end time and min and
max duration for visit slot. Write functions for- a) Display free slots b) Book
appointment c) Cancel appointment (check validity, time bounds,
availability) d) Sort list based on time e) Sort list based on time using
pointer manipulation
*/
#include<iostream>
#include <iomanip>
using namespace std;

class Node{
  public:
  int start, end, max, min;
  bool isBooked;
  Node *next;

  Node(int start=0, int end=0, int max=0, int min=0, bool booked=false){
      this->start = start;
      this->end = end;
      this->max = max;
      this->min = min;
      this->isBooked = booked;
  }

};


class LinkedList{

    public:
    Node *head;

    LinkedList(){
        head = NULL;
    }


    void makeSlot(){

        Node *newNode = new Node();

        cout<<"Enter start time : ";
        cin>>newNode->start;
        cout<<"Enter end time : ";
        cin>>newNode->end;
        cout<<"Enter max duration : ";
        cin>>newNode->max;
        cout<<"Enter min duration : ";
        cin>>newNode->min;

        if(head==NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }

        cout<<"\n"<<endl;

    }

    void bookAppointment(){
        Node *temp = head;

        int start;
        char choice;

        cout<<"Enter the start time of the appointment : ";
        cin>>start;

        while(temp->start != start){
            temp = temp->next;
            if(temp == NULL){
                break;
            }
        }

        if(temp == NULL){
            cout<<"Appointment not found "<<endl;
        }else{
            cout<<"Appointment details : "<<endl;
            cout<<temp->start<<setw(10)<<temp->end<<setw(10)<<temp->max<<setw(10)<<temp->min<<setw(10)<<std::boolalpha<<temp->isBooked<<endl;
    
            cout<<"Do you want to book this appointment [y/n] : ";
            cin>>choice;
    
            if(choice=='y'){
                temp->isBooked = true;
            }
            else{
                cout<<"Not booked "<<endl;
            }
        }
    }

    void cancelAppointment(){
        Node *temp = head;

        int start;
        char choice;

        cout<<"Enter the start time of the appointment : ";
        cin>>start;

        while(temp != NULL && temp->start != start){
            temp = temp->next;
        }

        cout<<"Appointment details : "<<endl;
        cout<<temp->start<<setw(10)<<temp->end<<setw(10)<<temp->max<<setw(10)<<temp->min<<setw(10)<<std::boolalpha<<temp->isBooked<<endl;

        cout<<"Do you want to book this appointment [y/n] : ";
        cin>>choice;

        if(choice=='y'){
            temp->isBooked = false;
        }
        else{
            return;
        }

    }

    void displayFreeSlots(){

        Node *temp = head;

        cout<<"Start"<<setw(10)<<"End"<<setw(10)<<"Max"<<setw(10)<<"Min"<<setw(10)<<"Booked"<<endl;
        
        while(temp != NULL){
            if(temp->isBooked == 1){
                temp = temp->next;
            }else{
                cout<<temp->start<<setw(10)<<temp->end<<setw(10)<<temp->max<<setw(10)<<temp->min<<setw(10)<<std::boolalpha<<temp->isBooked<<endl;
                temp = temp->next;
            }
        }

        cout<<endl;

    }

    void deleteSlot(){
       
        Node *temp = head;
   
        int start;
       
        cout<<"Enter the start time : ";
        cin>>start;
       
        while(temp->next->start != start){
            temp = temp->next;
            if(temp == NULL){
                break;
            }
        }
       
        if(temp == NULL){
            cout<<"Appointment doesnt exists "<<endl;
        }else{
            Node *toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            return;
        }
       
    }

    void sort(){

    Node *temp1 = head;
    Node *temp2 = temp1->next;

    while(temp1 != NULL){

        while(temp2 != NULL){

            Node *min = temp2;
            Node *temp3 = temp2->next;

            while(temp3 != NULL){
                if(temp3->start < min->start){
                    min = temp3;
                }
                temp3 = temp3->next;
            }

            if(min->start < temp1->start){
                //Swap the values

                int tstart, tend, tmin, tmax;

                tstart = temp1->start;
                tend = temp1->end;
                tmax = temp1->max;
                tmin = temp1->min;

                temp1->start = min->start;
                temp1->end = min->end;
                temp1->max = min->max;
                temp1->min = min->min;

                min->start = tstart;
                min->end = tend;
                min->max = tmax;
                min->min = tmin;
            }            

            temp2 = temp2->next;
        }

        temp1 = temp1->next;

    }

   }



};


int main(){

    LinkedList myList;
    myList.makeSlot();
    myList.makeSlot();
    myList.displayFreeSlots();
    myList.bookAppointment();
    myList.displayFreeSlots();
    // myList.deleteSlot();
    // myList.displayFreeSlots();

    return 0;
}