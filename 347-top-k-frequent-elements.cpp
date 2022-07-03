#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k){
	unordered_map<int, int> m;
	vector<int> out;
	for(int x: nums) m[x]++;
	vector<vector<int>> buckets(nums.size()+1);
	for(pair<int, int> x: m){
		buckets[x.second].push_back(x.first);
	}
//	for(int i=0; i<buckets.size(); i++){
//		for(int j=0; j<buckets[i].size(); j++){
//			cout << buckets[i][j] << " ";
//		}
//	}
	for(int i=buckets.size()-1; i>0; i--){
		for(int j=0; j<buckets[i].size(); j++){
			out.push_back(buckets[i][j]);
			if(out.size()==k) return out;
		}
	}
	return vector<int> ();
}
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	vector<int> out = topKFrequent(arr, k);
	for(int i=0; i<out.size(); i++){
		cout << out[i] << " ";
	}
	return 0;
}
