#include <bits/stdc++.h>
using namespace std;

struct Node {
    int item;
    Node *next;
    Node(int n) {
        item = n;
        next = nullptr;
    }
};
struct Queue {
    private:
        int cnt = 0;
        Node *last = nullptr;
        Node *first = nullptr;
    public:
        void push(int input) {
            Node *node = new Node(input);
            if(cnt == 0) {
                first = node;
            }
            else {
                last->next = node;
            }
            last = node;
            cnt++;
        }
        void pop() {
            first = first->next;
            cnt--;
        }
        int front() {
            return first->item;
        }
        void clear() {
            last = nullptr;
            first = nullptr;
            cnt = 0;
        }
        bool empty() { return cnt == 0; }
        int size() { return cnt; }
};
int main(){
    Queue q;
    while(true) {
        string s; cin >> s;
        if(s == "size") {
            cout << q.size() << endl;
        }
        else if(s == "push") {
            int n; cin >> n;
            cout << "ok" << endl;
            q.push(n); 
        }
        else if(s == "clear") {
            q.clear();
            cout << "ok" << endl;
        }
        else if(s == "pop") {
            if(q.empty()) cout << "error" << endl;
            else { cout << q.front() << endl; q.pop(); }
        }
        else if( s == "front") {
            if(q.empty()) cout << "error" << endl;
            else cout << q.front() << endl;
        }
        else if(s == "exit") {
            cout << "bye" << endl;
            break;
        }
    }
    return 0;
}