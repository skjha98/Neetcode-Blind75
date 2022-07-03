#include <iostream>
#include <vector>

using namespace std;
vector<int> productExceptSelf(vector<int>& nums){
	vector<int> preProd(nums.size());
	preProd[0] = nums[0];
	for(int i=1; i<nums.size(); i++){
		preProd[i]=preProd[i-1]*nums[i];
	}
	int postProd=1;
	vector<int> out(nums.size());
	for(int i=nums.size()-1; i>0; i--){
		out[i]=preProd[i-1]*postProd;
		postProd*=nums[i];
	}
	out[0]=postProd;
	return out;
}
int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<nums.size(); i++) cin >> nums[i];
	vector<int> out = productExceptSelf(nums);
	for(int& x: out) cout << x << " ";
	return 0;
}
