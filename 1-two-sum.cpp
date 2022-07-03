#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> twoSum(vector<int>& nums, int target){
	unordered_map<int, int> m; // val, index
	for(int i=0; i<nums.size(); i++){
		if(m.find(target-nums[i])!=m.end()){
			return {m[target-nums[i]], i};
		}
		m[nums[i]]=i;
	}
	cout << "Printing map\n";
	for(pair<int, int> x: m) cout << x.first << " " << x.second << "\n";
	return vector<int> ();

}
int main(){
	int t, n;
	cin >> t >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	vector<int> out = twoSum(arr, t);
	cout << "[";
	for(int i=0; i<out.size(); i++){
		cout << out[i] << " ";
	}
	cout << "]\n";
	return 0;
}
