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
        int full=0;

        HashTable();
        
        void remove();
        void display();
        int hashFunction(int key);
        
        int space(){
            cout<<full<<"/10"<<endl;
        }

        void insert(){
        
            int phone,hkey,full=0; 
            char name[20];


            cout<<"enter the phone number and then insert the name of the person";
            cin>>phone>>name;

            hkey = hashFunction(phone);
            
            if(h[hkey].key == -1){

                h[hkey].key = phone;
                strcpy(h[hkey].name, name);
                full++;
            }
            else{
                while(hkey!=-1){
                    hkey+=1;
                }
                h[hkey].key = phone;
                strcpy(h[hkey].name,name);
                full++;
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
        cout<<"5. Spaces Filled"<<endl;

        cin>>ch;

        switch (ch)
        {
        case 1:
            HT.insert();
            break;
        
        case 4:
            HT.display();
            break;
        
        case 5:
            HT.space();
            break;

        default:
            break;
        }
    } while (ch != 0);
    
    return 0;
}

