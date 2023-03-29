/*
Beginning with an empty binary search tree. Construct a binary search tree by inserting the values in the order given. After constructing a binary tree - 
1 - insert new node 
2 - Find number of nodes in longest path from root
3 - Minimum data value found in the tree 
4 - Change a tree so that the roles of the left and right pointers are swapped at every node
5 - Search a value (with recursion)
*/

#include<iostream>
using namespace std;
#define SPACE 10;

class TreeNode{
public: 
    int value;
    TreeNode *left; 
    TreeNode *right;
 
    TreeNode(){
        value = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int v){
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:
    TreeNode* root; 

    BST(){
        root = NULL;
    }

    bool isEmpty(){
        if (root == NULL)
        return true;
        

        else
        return false;
    }

    void insert(TreeNode *newNode){
        if(root == NULL) {
            root = newNode;
            cout<<"Value Inserted at Root"<<endl;
        }
        else{
            TreeNode *temp=root;
            while(temp!=NULL)
            {
                if(newNode -> value == temp -> value){
                    cout << "value already exist, Insert another value" << endl;
                    return;
                }
                else if ((newNode -> value < temp -> value ) && (temp -> left == NULL) ){
                    temp -> left = newNode;
                    cout<<"value inserted(left)"<<endl;
                    break;

                }
                else if (newNode->value < temp->value){
                    temp = temp->left;
                }

                else if ((newNode -> value > temp -> value ) && (temp -> right == NULL) ){
                    temp -> right = newNode;
                    cout<<"value inserted(right)"<<endl;
                    break;

                }
                else if (newNode->value > temp->value){
                    temp = temp->right;
                }
            }
        }
    }

    int minimum_val(){
            
        TreeNode *temp=root;
        while (temp->left != NULL){
            temp = temp->left;
        }
        return (temp -> value);     
        }

    void print2D(TreeNode *r, int space) {
        int i; 
        if (r == NULL) 
            return;
        space += SPACE; 
        print2D(r -> right, space); 
        cout << endl;
        for (i = 10 ; i < space ; i++) 
            cout << " ";
        cout << r -> value << "\n"; 
        print2D(r -> left, space); 
    }

};


int main(){
int ch,val;
int a; 
BST B; 

do
{
    cout<<"Select the operation you want to perform"<<endl;
    cout<<"1. Insert Node"<<endl;
    cout<<"2. Display"<<endl;
    cout<<"3. Minimum Data Value"<<endl;
    cout<<"4. Swap left and right pointers"<<endl;
    cout<<"5. Clear Screen"<<endl;
    cout<<"0. Exit Program"<<endl;

    cin>>ch;
    TreeNode *newNode = new TreeNode();

    switch (ch)
    {
    case 0:
        cout<<"Exiting Program"<<endl;
        break;
        
    case 1:
        cout<<"Enter the value of tree node to insert in BST"<<endl;
        cin >> val; 
        newNode->value = val;
        B.insert(newNode);
        cout<<endl;
        break;

    case 2: 
        cout << "BST :" << endl;
        B.print2D(B.root, 5);
        cout << endl;
        break;
    case 3:
        a = B.minimum_val();
        cout <<"The minimum data value in the tree is : " << a << endl;
        break; 
    case 5:
        system("clear");
        break;
    
    default:
        cout<<"Invalid Option"<<endl;
        break;
    }

} while (ch != 0);


return 0;
}