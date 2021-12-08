#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

stack<int> s;
struct Ch{
	char c;
    string st;
	bool hide,astr;
} arr[101];

int main(){
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		char tmp=str[i];
		char hide=false;
		
		if(tmp=='('||tmp=='['){
			s.push(i);
		}else{
			if(!s.empty()){
				char tmp_=arr[s.top()].c;
				if((tmp==')'&&tmp_=='(')||(tmp==']'&&tmp_=='[')) hide=true,arr[s.top()].hide=true,s.pop();
			}
		}
        
		arr[i].hide=hide;
        arr[i].c=tmp;
	}
	
	for(int i=0;i<str.size();i++){
		Ch tmp=arr[i];
		if(!tmp.hide){
			if(tmp.c=='('||tmp.c==')') tmp.astr=true,tmp.st="()";
			if(tmp.c=='['||tmp.c==']') tmp.astr=true,tmp.st="[]";
		}
        if(tmp.astr) cout<<tmp.st;
        else cout<<tmp.c;
		//cout<<tmp.c;
        //([(])
	}
	return 0;
}