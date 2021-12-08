#include<iostream>
#include<set>
#include<cmath>
using namespace std;

set<int> store;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int code,length;
        cin>>code>>length;
        if(code==1){
            if(store.count(length)==1){
                cout<<"Already Exist"<<endl;
                continue;
            }else{
                store.insert(length);
            }
        }else if(code==2){
            if(store.empty()){
                cout<<"Empty"<<endl;
                continue;
            }
            set<int>::iterator p=store.lower_bound(length);
            if(p==store.end()){
                p--;
            }
            if(*p>length){
                if(p!=store.begin()){
                    int a=*p;
                    p--;
                    int b=*p;
                    if(abs(length-a)<abs(length-b)) p++;
                }
            }
            cout<<*p<<endl;
            store.erase(p);
        }
        
    }
    return 0;
}