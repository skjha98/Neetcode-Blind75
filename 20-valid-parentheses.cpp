#include <iostream>
#include <string>
#include <stack>

using namespace std;
bool isValid(string s){
	stack<char> st;
	for(char c: s){
		if(c=='(' || c=='{' || c=='[') st.push(c);
		else if(st.empty()) return false;
		else if(c==')' && st.top()=='(') st.pop();
		else if(c=='}' && st.top()=='{') st.pop();
		else if(c==']' && st.top()=='[') st.pop();
		else return false;
	}
	return true;
}
int main(){
	string s;
	cin >> s;
	bool out = isValid(s);
	if(out) cout << "True";
	else cout << "False";
	return 0;
}
