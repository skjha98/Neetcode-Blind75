#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
int longestConsecutive(vector<int>& nums){
	unordered_set<int> s;
	int maxOut=0;
	for(int& x: nums) s.insert(x);
	for(int& x: nums){
		if(!s.count(x+1)){
			int count=1, n=x;
			while(s.count(n-1)){
				count++;
				n=n-1;
			}
			maxOut = count>maxOut?count:maxOut;
		}
	}
	return maxOut;
}
int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	int out = longestConsecutive(arr);
	cout << out;
	return 0;
}
