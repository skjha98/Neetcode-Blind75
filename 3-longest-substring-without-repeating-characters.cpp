#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int lengthOfLongestSubstring(string s){
	unordered_map<char, int> m;
	int prev=0, maxLen=0, len=0;
	for(int i=0; i<s.size(); i++){
		if(m.find(s[i])!=m.end()){
			prev = m[s[i]]+1;
		}
		m[s[i]]=i;
		maxLen = max(maxLen, i-prev+1);
	}
	return maxLen;
}



int main(){
	string s;
	cin >> s;
	int out = lengthOfLongestSubstring(s);
	cout << out;
	return 0;
}
