#include<iostream>
#include<stack>
#include<queue>
using namespace std;

stack<int> s;
queue<int> pushed,poped;

int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            pushed.push(t);
        }   
        bool ans=true; 
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            if(!ans) continue;//we should read all the numbers

            //search t.first in she stack
            if(!s.empty()){
                if(s.top()==t){
                    s.pop();
                    continue;
                }
            }
            //second in the queue
            if(pushed.empty()){//fail
                ans=false;
                continue;
            }
            bool flag=false;
            while(!pushed.empty()){//search!
                if(pushed.front()==t){
                    flag=true;
                    pushed.pop();
                    break;
                }else{
                    s.push(pushed.front());
                    pushed.pop();
                }
            }
            if(!flag) ans=false;
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        while(!s.empty()) s.pop();
        while(!pushed.empty()) pushed.pop();
    }
    return 0;
}