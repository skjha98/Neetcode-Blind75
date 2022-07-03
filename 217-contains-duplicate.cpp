#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
bool containsDuplicate(vector<int>& nums){
	unordered_set<int> s;
	for(int x: nums){
		if(s.count(x)!=0)	return true;
		s.insert(x);
	}
	return false;
}
int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	if(containsDuplicate(arr)) cout << "True";
	else cout << "False";
	return 0;
}
