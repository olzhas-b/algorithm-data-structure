#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, b) for(int i = 0; i < b; i++)
#define repr(i, b) for(int i = b - 1 ;i >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node {
    int cnt;
    int value;
    node *left = nullptr;
    node *right = nullptr;
    node(int val) {
        value = val;
        cnt = 1;
    } 
};
struct BST {

    node* insert(node *start, int val) {
        if(!start) {
            return new node(val);
        }
        if(start->value == val) {
            start->cnt++;
        }
        else if(start->value > val) {
            start->left = insert(start->left, val);
        } else {
            start->right = insert(start->right, val);
        } 
        return start;
    }
    void inorder(node *root) {
        if(root != NULL) 
        { 
            inorder(root->left); 
            cout << root->value << " " << root->cnt <<  endl; 
            inorder(root->right);
        } 
    }
    void search(int val) {

    }
};
int main(){
    speed;
    int k; cin >> k;
    node *root;
    BST b;
    root = b.insert(root, 5);
    rep(i, k) {
        int x; cin >> x;
        b.insert(root, x);
    }
    b.inorder(root);
    return 0;
}