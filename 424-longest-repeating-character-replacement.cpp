#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int characterReplacement(string s, int k){
	unordered_map<char, int> m;
	int l=0, maxFreq=0, maxLen=0;
	for(int i=0; i<s.size(); i++){
		m[s[i]]++;
		maxFreq = max(maxFreq, m[s[i]]);
		while((i-l+1)-maxFreq > k){
			m[s[l]]--;
			l++;
			// cout << i << " " << l << "\n";
		}
		maxLen = max(maxLen, i-l+1);
	}
	return maxLen;
}
int main(){
	int k;
	cin >> k;
	string s;
	cin >> s;
	int out = characterReplacement(s, k);
	cout << out;
	return 0;
}
