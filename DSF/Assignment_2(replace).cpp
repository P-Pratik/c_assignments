#include <iostream>
using namespace std;

class hash1
{
    public:
        int n=10;
        void insert(int arr[]);
        void display(int arr[]);
        int hashf(int x);
};

int hash1 :: hashf(int x)
{
    return (x%10);
}

void hash1::insert(int arr[])
{
    int key, hf, i;
    cout << "Enter key value: ";
    cin >> key;
    hf = hashf(key);
    if (arr[hf] == -1) {
        arr[hf] = key;
    } else {
        i = (hf + 1) % n;
        while (i != hf && arr[i] != -1) {
            i = (i + 1) % n;
        }
        if (i == hf) {
            cout << "Hash table overflow!" << endl;
        } else {
            if (arr[i] != -1) {
                cout << "Replacing " << arr[i] << " at index " << i << endl;
            }
            arr[i] = key;
        }
    }
}


void hash1::insert(int arr[])
{
    int key, hf;
    cout << "Enter key value: ";
    cin >> key;
    hf = hashf(key);
    if (arr[hf] == -1)
    {
        arr[hf] = key;
    }
    else
    {
        int i = hf;
        int replacementIndex = -1;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                // Key already exists, no need for replacement
                return;
            }
            if (arr[i] == -2 && replacementIndex == -1)
            {
                // Found a previously deleted slot, mark it as a potential replacement
                replacementIndex = i;
            }
            i = (i + 1) % n; // Move to the next slot
        }
        if (replacementIndex != -1)
        {
            arr[replacementIndex] = key; // Replace the deleted slot with the new key
        }
        else
        {
            arr[i] = key; // Insert the key in the next available slot
        }
    }
}

void hash1 :: display(int arr[])
{
    cout<<"Index\tKey"<<endl;
    for(int i=0;i<n;i++)
        cout<<i<<"\t"<<arr[i]<<endl;
}

int main()
{
    hash1 h;
    int ch, a[h.n];
    for(int i=0;i<h.n;i++){a[i]=-1;}
    int check=1;
    while(check==1)
    {
        cout<<"------MENU------\n1.Insert\n2.Display\n3.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                h.insert(a);
            break;

            case 2:
                h.display(a);
            break;

            case 3:
                cout<<"Terminated"<<endl;
                check=0;
            break;
        }
    }
    return 0;
}