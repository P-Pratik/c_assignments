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
    int lheight = 0 , rheight = 0;

    BST(){
        root = NULL;
    }


    bool isEmpty(){
        if (root == NULL)
        return true;

        else
        return false;
    }
    
    void insert(TreeNode *newNode){             //Insertion Operation 
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

    void deleteNode(int d_val){
        if(root == NULL)
        return;
        else{
            
        }
    }

    TreeNode* search(int s_value){ 
        if(root == NULL){
            return root;
        }
        else{
            TreeNode *temp = root;
            while (temp!=NULL){
                if(s_value == temp->value){
                    return temp;
                }
                else if(s_value < temp->value){
                    temp = temp -> left;
                }
                else{
                    temp = temp -> right;
                }
            }
            cout<<"Value is not present in the tree"<<endl;
            return NULL;
        }
    }
    
    int height(TreeNode *heightNode){
        if (heightNode == NULL){
            return -1;
        }   
        else{
            lheight = height(heightNode->left);
            rheight = height(heightNode->right);
            if(lheight > rheight){
                return lheight + 1; 
            }
            else
                return rheight + 1;
        }
    }

    //Printing Functions
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

    void preOrder(TreeNode *r){
        if(r == NULL )
        return;

        cout<<r->value<<" ,";
        preOrder(r->left);
        preOrder(r->right);
    }
    
    void inOrder(TreeNode *r){
        if (r == NULL)
        return;

        inOrder(r->left);
        cout<<r->value<<" ,";
        inOrder(r->right);
    }

    void postOrder(TreeNode *r){
        if (r == NULL)
        return;

        inOrder(r->left);
        inOrder(r->right);
        cout<<r->value<<" ,";
    }
};

int main(){
int ch,val;
int searched_val;
BST B; 

do
{
    cout<<"Select the operation you want to perform"<<endl;
    cout<<"1. Insert Node"<<endl;
    cout<<"2. Delete Node"<<endl;
    cout<<"3. Search Node"<<endl;
    cout<<"4. Print 2D representation of BST"<<endl;
    cout<<"5. Print  Representation of BST"<<endl;
    cout<<"6. Display the height of the tree"<<endl;
    cout<<"9. Clear Screen"<<endl;
    cout<<"0. Exit Program"<<endl;

    cin>>ch;    

    switch (ch)
    {
    case 0:
        cout<<"Exiting Program"<<endl;
        break;
        
    case 1:
        do{
            TreeNode *newNode = new TreeNode();
            cout<<"Enter the value of tree node to insert in BST (enter -1 to stop entering) :- "<<endl;
            cin >> val;
            if (val != -1){
            newNode->value = val;
            B.insert(newNode);
            cout<<endl;
        }
        }
        while (val != -1);
        break;
    
    case 3:
        TreeNode *return_s;
        cout<<"Enter the value to be searched :"<<endl;
        cin>>searched_val;
        return_s = B.search(searched_val);
        if ( return_s != NULL ){

            cout<<"The Searched Value is "<<return_s ->value << endl;
            if (return_s ->left != NULL)
            cout<<"left node - :"<<return_s->left->value<<endl;

            if (return_s->right != NULL)
            cout<<"right node - :"<<return_s->right->value <<endl;
        }
        else{
            cout<<"Searched Value is not present in the tree"<<endl;
        }

        break;

    case 4:
        cout<<"2D figure: "<<endl;
        B.print2D(B.root , 5);
        cout<<endl;
        break;

    case 5:
        cout<<"PreOrder BST form"<<endl;
        B.preOrder(B.root);
        cout<<endl;
        cout<<"InOrder BST form"<<endl;
        B.inOrder(B.root);
        cout<<endl;
        cout<<"PostOrder BST form"<<endl;
        B.postOrder(B.root);
        cout<<endl;
        break;

    case 6:
        int height;
        height = B.height(B.root);
        cout << "The height of the tree is :- " << height << endl;
        break;
                
    case 9:
        system("clear");
        break;
    
    default:
        cout<<"Invalid Option"<<endl;
        break;
    }

} while (ch != 0);


return 0;
}