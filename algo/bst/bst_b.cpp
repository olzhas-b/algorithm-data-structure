#include <bits/stdc++.h>
using namespace std;
int ans = 0;
struct Node {
    int value = -1;
    int cnt = 1;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int val, int count) {
        value = val;
        cnt = count;
    }
};
struct bst {
    int sz = 0;
    void insert(Node* root, int val, int cnt) {
       
        if(root->value == -1) {
            root->value = val;
            root->cnt = cnt;
            sz++;
        } else {
            if(root->value == val) {
                return;
            }
            else if(root->value > val) {
                if(root->left == nullptr) {
                    Node *node = new Node(val, cnt + 1);
                    root->left = node;
                    sz++;
                    return;
                } else {
                    insert(root->left, val, cnt + 1);
                }
            } else {
                if(root->right == nullptr) {
                    Node *node = new Node(val, cnt + 1);
                    root->right = node;
                    sz++;
                    return;
                } else {
                    insert(root->right, val, cnt + 1);
                }
            }
        }   
    }
    void print(Node *root) {
        if(root == nullptr) return;
        print(root->left);
        ans = max(ans, root->cnt);
        print(root->right);
    }
    int size() {
        return sz;
    }
}; 
int main(){
    Node *root = new Node(-1, 0);
    bst b;
    while(true) {
        int x; cin >> x;
        if(x == 0) break;
        b.insert(root, x, 1);
    }
    b.print(root);
    cout << b.size() << endl;
    return 0;
}