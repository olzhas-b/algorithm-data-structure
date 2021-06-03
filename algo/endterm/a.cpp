#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<bool> vb;

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define pb push_back

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)

#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MID = 1e5 + 3;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;
#define PI 3.14159265358979323846264338327950L
int i, n;
int cnt = 0;
class Node{

    public:

        int data;
        Node *left, *right;
        Node(int x){
            data = x;
            left = right = NULL;
        }
};

struct Tree{

    Node *root;
    Tree(){
        root = NULL;
    }
    void insert(int n){
        insert(root,n);
    }
    void insert(Node *&tree, int n){
        if (tree == NULL){
            tree = new Node(n);
            return;
        }
        if (tree->data == n) return;
        if (n < tree->data)
            insert(tree->left,n);
        else
            insert(tree->right,n);

    }
    void InOrder(void){
        InOrder(root);
    }
    void InOrder(Node *tree){

        if (tree == NULL) return;

        InOrder(tree->left);
        if((tree->left != NULL) && (tree->right != NULL)){
            cnt++;
        }
        InOrder(tree->right);
    }

};


int main(){
    int q;
    cin >> q;
    Tree t;
    while(q--){
        cin >> n;
        t.insert(n);
    }
    t.InOrder();
    cout << cnt;
    return 0;
}