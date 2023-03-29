#include<iostream> 
#define SPACE 10;
using namespace std;

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

};





int main(){
int ch,val;
BST B; 

do
{
    cout<<"Select the operation you want to perform"<<endl;
    cout<<"1. Insert Node"<<endl;
    cout<<"2. Delete Node"<<endl;
    cout<<"3. Search Node"<<endl;
    cout<<"4. Print BST values"<<endl;
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
        cout<<"Enter the value of tree node to insert in BST";
        cin >> val; 
        newNode->value = val;
        B.insert(newNode);
        cout<<endl;

    case 5:
        system("cls");
        break;
    
    default:
        cout<<"Invalid Option"<<endl;
        break;
    }

} while (ch != 0);


return 0;
}