/*Department of Computer Engineering has student's club named 'Pinnacle Club' Students of second, third, and final year of department can be granted membership on request. Similarly one may cancel the membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club.
Write a C++ program to maintain club member's information using singly linked list. Store student PRN and Name. Write functions to:
a) Add and Delete the members as well as president or even secretary
b) Compute total Number of members of club
c) Display members 
d) Two linked lists exists for 2 divisions. Concatinate two lists. */

#include<iostream>
using namespace std;

class Node{
    public:
    int PRN;
    Node* next;
};
void display(Node** head){
    int count;
    Node* temp = *head;
    count=1;
    cout<<"Sr. No\tPRN"<<endl;
    while(temp!=NULL){
        cout<<count<<"\t"<<temp->PRN<<endl;
        temp=temp->next;
        count+=1;
    }        
}
/*
void create_club(Node** head){   //this was a extremely stupid way of trying to do lol
    if(*head=NULL){
        Node* head;
        Node* last;

        head = new Node();
        last = new Node();

        cout<<"Enter the PRN of president";
        cin>>head->PRN;
        head->next=last;
        cout<<"Enter the PRN of secretary";
        last->next=NULL; 
    }
    else{
        cout<<"Club Already Exists";
    }
}
*/
int size(Node* temp){
    int n;
    n=1;
    while (temp->next!=NULL){
        temp=temp->next;
        n+=1;
    }
    return n;
}
void insert_president(Node** head){
    Node* newNode;
    newNode = new Node();
    cout<<"Enter the PRN of the new president:- ";
    cin>>newNode->PRN;
    newNode->next=*head;

    *head=newNode;
    cout<<"new president inserted"<<endl;
}

void insert_secretary(Node** head){
    Node* newNode = new Node();
    cout<<"Enter the PRN of new secretary:- ";
    cin>>newNode->PRN;
    newNode->next=NULL;
    Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    cout<<"New Secretary appointed"<<endl;
}

void insert_member(int a, Node** head){
    int n;
    n=size(*head);

    Node* newNode;
    newNode = new Node();
    cout<<"Enter the PRN of member:- ";
    cin>>newNode->PRN;
    newNode->next=NULL;

    Node* temp=*head; 
    while(a>0){
        temp=temp->next;
        a-=1;
    }

    newNode->next = temp->next;
    temp->next=newNode;
    cout<<"Member Inserted"<<endl;
}

void delete_node(Node** head, int d){
    Node* temp = *head;
    Node* prev = *head;
    cout<<"here 1"<<endl;

    while(d>1){
        while(d>2){
        prev=prev->next;
        break;
        }
        temp=temp->next;
        d-=1;
    }
    cout<<"here 2"<<endl;
    cout<<prev->PRN<<"    "<<temp->PRN<<"   "<<temp->next<<endl;
    prev->next=temp->next; 
    cout<<"here 3"<<endl;
    cout<<prev->PRN<<"    "<<prev->next<<endl;
    delete temp;
    cout<<"Member has been removed"<<endl;

}
int main(){
    int a,i,c,d;

    Node* head;
    Node* last;

    head = new Node();
    last = new Node();

    cout<<"Enter the PRN of president:- ";
    cin>>head->PRN;
    head->next=last;
    cout<<"Enter the PRN of secretary:- ";
    cin>>last->PRN;
    last->next=NULL;

    cout<<"\nMenu\n1:Enter New President\n2:Enter New Secretary\n3:Enter New Member\n4:Delete Any Member/President/Secretary\n5:Total Members in Club(inc pres and sec)\n6:Display All Member\n7:Work in Progress\n8:EXIT\n\nEnter your choice:- ";
    
    do{
        cin>>i;
        switch (i)
        {
        case 1:
            insert_president(&head);
            break;
        case 2:
            insert_secretary(&head);
            break;
        case 3:
            a=size(head)-2;
            insert_member(a,&head);
            break;
        case 4:
            cout<<"Enter the Member number to be deleted"<<endl;
            cin>>d;
            delete_node(&head,d);
            break;
        case 5:
            cout<<"The current list size is "<<size(head)<<endl;
            break;
        case 6:
            display(&head);
            break;
        case 8:
            cout<<"EXITING PROGRAM..."<<endl;
            break;
        default:
            break;
        }
    } while(i!=8);
    return 0;
}