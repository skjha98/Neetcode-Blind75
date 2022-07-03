#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>

using namespace std;
string sortString(string str){
	char count[26];
	memset(count, 0, sizeof(count));
	for(char c: str){
		count[c-'a']++;
	}
	string out;
	for(int i=0; i<26; i++){
		while(count[i]--){
			out.push_back((char)i+'a');
		}
	}
	return out;
}
vector<vector<string>> groupAnagrams(vector<string>& arr){
	unordered_map<string, vector<string>> m;
	for(int i=0; i<arr.size(); i++){
		m[sortString(arr[i])].push_back(arr[i]);
	}
	vector<vector<string>> out(m.size());
	for(pair<string, vector<string>> x: m) out.push_back(x.second);
	return out;
}
int main(){
	int n;
	cin >> n;
	vector<string> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	vector<vector<string>> out = groupAnagrams(arr);
	for(vector<string>& x: out){
		for(string& y: x){
			cout << y << " ";
		}
		cout << "\n";
	}
	return 0;
}
