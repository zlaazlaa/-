#include<bits/stdc++.h>
using namespace std;

int lenth;
char s[10000];
stack <char> k;
queue <char> ans;

int compare(char x,char y) {
	if(y == '(')	return 0;
	if(x == '+' || x == '-')	return 1;
	if(x == '*' || x == '/')	return 0;
}

int main() {
	scanf("%s",s);
	lenth = strlen(s);	
	for(int i = 0;i < lenth;i ++) {		
		if('0' <= s[i] && s[i] <= '9')     
			ans.push(s[i]);
		else if(s[i] == '(')
			k.push(s[i]);
		else {
			if(k.empty())
				k.push(s[i]);
			else {
				char kk = s[i];
				if(kk == ')') {
					while(!k.empty() && k.top() != '(') {
						ans.push(k.top());
						k.pop();
					}
					if(k.empty()) {
						printf("rammar mistakes");//语法检查 
						return 0; 
					}
					k.pop(); 
				}
				else if( compare(kk,k.top()) ) {
					while(!k.empty() && k.top() != '(') {
						ans.push(k.top());
						k.pop();
					}
					k.push(kk);
				}
				else if( !compare(kk,k.top()) )
					k.push(kk);
			}
		}
	} 
	while(!k.empty()) {
		ans.push(k.top());
		k.pop();
	}
	while(!ans.empty()) {
		printf("%c",ans.front());
		ans.pop();
	}
	return 0;
} 
