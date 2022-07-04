#include <iostream>
#include <vector>

using namespace std;
bool isPalindrome(string s){
	string str;
	for(char c: s){
		if(c>='A' && c<='Z') str.push_back(c+32);
		else if(c>='a' && c<='z') str.push_back(c);
	}
	int n=str.size();
	int i=0, j=n-1;
	for(int i=0; i<n/2; i++){
		if(str[i]!=str[n-1-i]) return false;
	}
	return true;
}
int main(){
	string s;
	cin >> s;
	bool out = isPalindrome(s);
	if(out) cout << "True";
	else cout << "False";
	return 0;
}
