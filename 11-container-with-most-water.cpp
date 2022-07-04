#include <iostream>
#include <vector>

using namespace std;
int maxArea(vector<int>& nums){
	int n=nums.size();
	int l=0, r=nums.size()-1, area=-1;
	while(l<r){
		area = max(area, min(nums[l], nums[r])*(r-l));
		if(nums[l]<nums[r]) l++;
		else r--;
	}
	return area;
}
int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	int out = maxArea(nums);
	cout << out;
	return 0;
}
