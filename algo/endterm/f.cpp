#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
struct BST{
    private:
        struct node
        {
            int key;
            node* left;
            node* right;
        };

        node* root;
        void AddleafPrivate(int key, node* Ptr);
        void PrintInOrderPrivate(node* Ptr);
        void CntChildPrivate(node* Ptr);

    public:
        BST();
        node* CreateLeaf(int key);
        void Addleaf(int key);  
        void PrintInOrder();
        void CntChild();
BST(){
    root = NULL;
}
node CreateLeaf(int key){
    node* n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}
void Addleaf(int key)
{
    AddleafPrivate(key, root);
}
void AddleafPrivate(int key, node* Ptr)
{
    if(root == NULL){
        root = CreateLeaf(key);
    }
    else if(key < Ptr->key){
        if(Ptr->left != NULL)
        {
            AddleafPrivate(key, Ptr->left);
        }
        else{
            Ptr->left = CreateLeaf(key);
        }
    }
    else if(key > Ptr->key){
        if(Ptr->right != NULL)
        {
            AddleafPrivate(key, Ptr->right);
        }
        else{
            Ptr->right = CreateLeaf(key);
        }
    }
}

void PrintInOrder(){
    PrintInOrderPrivate(root);
}
void BST::PrintInOrderPrivate(node* Ptr){
    if(root != NULL){
        if(Ptr->left != NULL){
            PrintInOrderPrivate(Ptr->left);
        }
        cout<<Ptr->key<<" ";
        if(Ptr->right != NULL){
            PrintInOrderPrivate(Ptr->right);
        }
    }
}
void CntChild(){
    CntChildPrivate(root);
}
void CntChildPrivate(node* Ptr){
    if(Ptr->left!=NULL&&Ptr->right!=NULL)cnt++;
    if(Ptr->right!=NULL){
        CntChildPrivate(Ptr->right);
    }
    if(Ptr->left!=NULL){
        CntChildPrivate(Ptr->left);
    }
}
}
int main(){
    int n;
    BST myTree;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        myTree.Addleaf(x);
    }
    myTree.CntChild();
    cout<<cnt;

    return 0;
}