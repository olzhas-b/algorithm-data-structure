#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define forn(b) for(int i = 0; i < b; i++)
#define rforn(b) for(int i = b - 1 ;i >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
    
int main(){
    speed;
    int n; cin >> n;
    vi v(n);
    vector<bool> m1(1000001);
    vector<bool> m2(1000001);
    forn(n) {
        cin >> v[i];
        m1[v[i]] = true;
    }
    queue<int> q;
    queue<int> data;
    for(int i = 0; i < 1000000; i++) {
        if(m1[i] == false) data.push(i);
    }
    vector<int> answer(n);
    bool yes = true;
    int current = 0;
    int previous = 0;
    for(int i = 0; i < n; i++) {
        current = v[i] - 1;
        if(!q.empty()) {
            if(q.front() != v[i]) q.push(v[i]);
        }
        else {
            q.push(v[i]);
        }
        if(v[i] == 0) {
            int k = data.front();
            if(m2[k] == true) data.pop();
            k = data.front();
            data.pop();
            //cout << i << "-- >1\n";
            m2[k] = true;
            answer[i] = k;
        }
        else if(m2[v[i] - 1] == false) {
            m2[v[i] - 1] = true;
            int k = data.front();
            if(m2[k] == true) data.pop();
            //cout << i << "-- >2\n";
            answer[i] = v[i] - 1;
        }
        else {
            if(q.empty()) {
                //cout << i << "-- >3\n";
                int k = data.front();
                if(m2[k] == true) data.pop();
                k = data.front();
                data.pop();
                m2[k] = true;
                answer[i] = k;
            }
            else {
                int k = q.front();
                if(k == v[i]) {
                    //cout << i << "-- >4\n";
                    if(m2[k] == true) data.pop();
                    k = data.front();
                    k = data.front();
                    data.pop();
                    m2[k] = true;
                    answer[i] = k;
                }
                else {
                    cout << i << "-- >5\n";
                    k = q.front();
                    
                    m2[k] = true;
                    answer[i] = k;
                }
            }
        }
        // if(previous >= 0) {
        //     for(int j = current; j >= previous; j--) {
        //         if(m2[j] == false) yes = false;
        //     }
        // }
        // previous = current;
    }
    if(yes) {
        for(int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
        }
    }
    else {
        cout << -1;
    }
 
 
    return 0;
}