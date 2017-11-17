#include<iostream>
using namespace std;
class BinarySearchTree{

    //Struct to store the node data....
    struct node{
        int data;
        node* left;
        node* right;

    };
    node* root;
    node* temp;

    //For deleting the node
    //node*

    //Inserting function 
    node* insert(int x,node* t){
        if(t==NULL){
            t=new node;
            t->data=x;
            t->left=NULL;
            t->right=NULL;
        }
        else if(x>= t->data){
            t->right=insert(x,t->right);
        }
        else if(x< t->data){
            t->left=insert(x,t->left);
        }
        return t;
    } 

    //Inorder Traversing
    void inorderTraverse(node* t){
        if(t==NULL){
            return;
        }
        else{
            inorderTraverse(t->left);
            cout<<t->data<<" ";
            inorderTraverse(t->right);
        }
    }
    void preOrderTraverse(node *t){
        if(t==NULL){
            return;
        }
        else{
            cout<<t->data<<" ";
            preOrderTraverse(t->left);
            preOrderTraverse(t->right);
        }
    }
    node* find(node* t,int x){

        if(t==NULL){
            return NULL;
        }
        else if(x > t->data){
            find(t->right,x);
        }
        else if(x< t->data){
            find(t->left,x);
        }
    
            return t;

    }
    node* findMax(node* t){
        if(t==NULL){
            return NULL;
        }
        else if(t->right==NULL){
            return t;
        }
        else{
            return findMax(t->right);
        }
    }

    node* findMin(node* t){
        if(t==NULL)
        {
            return NULL;
        }
        else if(t->left==NULL){
            return t;
        }
        else{
            return findMin(t->left);
        }
    }
    public:
        BinarySearchTree(){
            root=NULL;
        }
        void insert(int x){
            root=insert(x,root);
        }
        void display(){
            cout<<"Inorder Traversal :"<<endl;
            inorderTraverse(root);
            cout<<endl;
            cout<<"Preorder Traversal :"<<endl;
            preOrderTraverse(root);

        }
        void search(int x){
            temp=root;
            temp=find(temp,x);
            if(temp!=NULL){
                cout<<"Found";
                cout<<temp->data;
            }
            else{
                cout<<"Not found ";
            }
        }

};

int main(){
    BinarySearchTree Tree;
    char quit;
    int how_many,data;
    cout<<"How many nodes you want to insert?"<<endl;
    cin>>how_many;
    for(int i=0;i<how_many;i++){
        cin>>data;
        Tree.insert(data);
    }
    cout<<"Display :"<<endl;
    Tree.display();
    cout<<"Find :"<<endl;
    int fi;
    cin>>fi;
    Tree.search(fi);
    cout<<endl;
    return 0;

}