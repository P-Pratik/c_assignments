#include<iostream>
#include<string.h>
using namespace std;

class HashTable {
    typedef struct hash {
        int key;
        char name[20];
    }hash;

    hash h[10];
    public:
        HashTable();
        
        void remove();
        void display();
        int hashFunction(int key);

        void insert(){
        
            int phone,Hkey; 
            char name[20];

            cout<<"enter the phone number and then insert the name of the person";
            cin>>phone>>name;

            Hkey = hashFunction(phone);
            if(h[Hkey].key == -1){

                h[Hkey].key = phone;
                strcpy(h[Hkey].name, name);
            }

        }


        int search();

};



HashTable :: HashTable(){                       //contructor basically used to acquire empty spaces so that there are no errors when searching in the code
    int i; 
    for(i = 0 ; i < 10 ; i++){
        h[i].key = -1;
        strcpy(h[i].name,"NULL");
    }
}

int HashTable :: hashFunction(int key){
    return key % 10;
}



void HashTable :: display(){
    int i; 
    cout<<"Key"<<"\t"<<"Phone"<<"\t"<<"Value"<<endl;

    for(i=0 ; i<10; i++){
        cout<< i <<"\t"<<h[i].key<<"\t"<<h[i].name<<endl;
    }
}


int main(){
    int ch;
    HashTable HT;

    do
    {
        cout<<"Select the operation you want to perform"<<endl;
        cout<<"1. Insert Data"<<endl;
        cout<<"2. Delete Data"<<endl;
        cout<<"3. Search Data"<<endl;
        cout<<"4. Display Data"<<endl;

        cin>>ch;

        switch (ch)
        {
        case 1:
            HT.insert();
            break;
        
        case 4:
            HT.display();
            break;

        default:
            break;
        }
    } while (ch != 0);
    
    return 0;
}

