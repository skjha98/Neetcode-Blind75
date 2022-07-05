#include <iostream>
#include <vector>

using namespace std;
int maxProfit(vector<int> nums){
	int out=0, minPrice=nums[0];
	for(int i=1; i<nums.size(); i++){
		out = max(out, nums[i]-minPrice);
		minPrice = min(minPrice, nums[i]);
	}
	return out;
}
int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	int out = maxProfit(nums);
	cout << out;
	return 0;
}
