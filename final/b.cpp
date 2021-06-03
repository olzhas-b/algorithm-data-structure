#include <iostream> 
#include <deque> 

using namespace std; 

int main() { 
deque <int> fir; 
deque <int> sec; 
for(int i=0; i<5; i++){
    int n;
    cin>>n;
    fir.push_back(n);
}
for(int i=0; i<5; i++){
    int n;
    cin>>n;
    sec.push_back(n);
}

int cnt=0;
while(fir.size()!=0 && sec.size()!=0){
    int f,s;
    cnt++;

    f = fir.front();
    s = sec.front();
    if ((f == 0 && s== 9) || (f == 9 && s== 0) ){
        if (f == 0 && s== 9){
            fir.push_back(f);
            fir.push_back(s);
            fir.pop_front();
            sec.pop_front();            
        }
        else{
            sec.push_back(f);
            sec.push_back(s);
            fir.pop_front();
            sec.pop_front();              
        }

    }
    else{

    if (f>s){
        fir.push_back(f);
        fir.push_back(s);
        fir.pop_front();
        sec.pop_front();

    }
    else{
        sec.push_back(f);
        sec.push_back(s);
        fir.pop_front();
        sec.pop_front();        
    }
    }
    if(cnt == 1000000){
        cout << "blin nichya";
        break;
    }
}
if (fir.size()>= sec.size()){
    cout << "Boris" << " "<< cnt;
}
else{cout << "Nursik"<< " "<< cnt;
}


return 0;
}