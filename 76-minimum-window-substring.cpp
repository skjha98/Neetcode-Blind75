#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t){
	unordered_map<char, int> required, window;
	for(int i=0; i<t.size(); i++) required[t[i]]++;
	int mct=0, dmct=t.size(), i=0, j=0;
	string out;
	bool acquired, released;
	while(1){
		acquired=false; released=false;
		// acquire phase
		while(i<s.size() && mct<dmct){
			window[s[i]]++;
			if(window[s[i]]<=required[s[i]]) mct++;
			// cout << i << " " << mct << "\n";
			i++;
			acquired=true;
		}
		// store and release phase
		while(j<i && mct==dmct){
			if(out.size()==0||i-j<out.size()) out=s.substr(j, i-j);
			// cout << out << " " << j << " " << i << "\n";
			window[s[j]]--;
			if(window[s[j]]<required[s[j]]) mct--;
			j++;
			released=true;
		}
		if(!acquired && !released) break;
	}
	return out;
}

int main(){
	string s, t, out;
	cin >> s >> t;
	out = minWindow(s, t);
	cout << out;
	return 0;
}
