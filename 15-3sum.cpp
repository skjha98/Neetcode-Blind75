#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> nums){
	sort(nums.begin(), nums.end());
	int n=nums.size();
	int l=0, r=n-1, sum;
	vector<vector<int>> out;
	for(int i=0; i<n; i++){
		l=i+1; r=n-1;
		while(l<r){
			sum = nums[i]+nums[l]+nums[r];
			if(sum<0) l++;
			else if(sum>0) r--;
			else if(sum==0){
				out.push_back({nums[i], nums[l], nums[r]});
				while(l<r && nums[l]==nums[l+1]) l++;
				while(l<r && nums[r]==nums[r-1]) r--;
				l++; r--;
			}
		}
		while(i<n && nums[i]==nums[i+1]) i++;
	}
	return out;
}

int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	vector<vector<int>> out = threeSum(nums);
	for(vector<int>& x: out){
		cout << "[ ";
		for(int y: x){
			cout << y << " ";
		}
		cout << " ]";
	}
	return 0;
}
