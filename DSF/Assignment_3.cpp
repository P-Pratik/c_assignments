#include<iostream>
#include<string.h>
#include<utility>
using namespace std;

struct node
{
	pair<long,string> value;
	node* next;
}*HashTable[10];

class hashing
{
	public:
	hashing()
	{
		for(int i=0 ; i<10 ; i++)
		{
			HashTable[i]=NULL;
		}
	}

	int HashFunction(long value)
	{
		return (value%10);
	}
	node* create_node(long x, string s)
	{
		node* temp=new node;
		temp->next=NULL;
		temp->value.first=x;
		temp->value.second=s;
		return temp;
	}

	void display()
	{
		for(int i=0 ; i< 10; i++)
		{
			node * temp=new node;
			temp=HashTable[i];
			cout<<"a["<<i<<"] : ";
			while(temp !=NULL)
			{
				cout<<" --> |"<<temp->value.second<<"   "<<temp->value.first<<"|";
				temp=temp->next;
			}
			cout<<"\n";
		}
	}

	int searchElement(long value)
	{
		bool flag = false;
		long hash_val = HashFunction(value);
		node* entry = HashTable[hash_val];

		cout<<"\nElement found at : ";
		while (entry != NULL)
		{
			if (entry->value.first==value)
			{
				cout<<hash_val<<" : "<<entry->value.first<<"\t"<<entry->value.second<<endl;
				flag = true;
			}
			entry = entry->next;
		}
			if (!flag)
				return -1;
	}

	void deleteElement(long value)
	{
		long hash_val = HashFunction(value);
		node* entry = HashTable[hash_val];
		if (entry == NULL)
		{
			cout<<"No Element found ";
			return;
		}

		if(entry->value.first==value)
		{
			HashTable[hash_val]=entry->next;

			return;
		}
		while ((entry->next)->value.first != value)
		{
			entry = entry->next;
		}
		entry->next=(entry->next)->next;
	}

	void insertElement(long value,string name)
	{
		int hash_val = HashFunction(value);

		node* temp=new node;
		node* head=new node;
		head = create_node(value,name);
		temp=HashTable[hash_val];
		if (temp == NULL)
		{
			HashTable[hash_val]=head;
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next=head;
		}
	}
};
int main()
{
	int ch;
	string s;
	long pn,search,del;
	hashing h;
	do
	{
		cout<<"\n------MENU------\n1.Insert \n2.Display \n3.Search \n4.Delete\n5.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"\nEnter Name : ";
			cin>>s;
			cout<<"\nEnter phone no: ";
			cin>>pn;
			h.insertElement(pn,s);
			break;
			
			case 2:
			h.display();
			break;
			
			case 3:
			cout<<"\nEnter the phone no. to be searched : ";
			cin>>search;

			if (h.searchElement(search) == -1)
			{

				cout<<"No element found at key ";
				continue;
			}
			break;
			case 4:cout<<"\nEnter the phno. to be deleted : ";
			cin>>del;
			h.deleteElement(del);
			cout<<"Phno. Deleted"<<endl;
			break;
		}
	}while(ch!=5);
	return 0;

}