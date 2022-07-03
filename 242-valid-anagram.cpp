#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool isAnagram(string str1, string str2){
	unordered_map<char, int> m1, m2;
	for(char c: str1){
		m1[c]++;
	}
	for(char c: str2){
		m2[c]++;
	}
	for(pair<char, int> x: m1){
		if(x.second != m2[x.first]) return false;
	}
	for(pair<char, int> x: m2){
		if(x.second != m1[x.first]) return false;
	}
	return true;
}

int main(){
	string string1, string2;
	cin >> string1 >> string2;
	if(isAnagram(string1, string2)) cout << "True";
	else cout << "False";
	return 0;
}
