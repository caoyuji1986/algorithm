/*************************************************************************
 > File Name: permutations_II.cpp
# File Name: permutations_II.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月24日 星期五 19时42分54秒
************************************************************************/
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<queue>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		this->nums = nums;
		vector<int> ele;
		vector<vector<int> > ret;
		permuteUnique(0, ret, ele);
		return ret;
    }
	void permuteUnique(int beg, vector<vector<int> >& ret, vector<int> ele) {
		if (ele.size() == nums.size()) {
			ret.push_back(ele);
			return;
		}
		unordered_set<int> used;
		for (int i = beg; i < nums.size(); ++i) {
			if (used.count(nums[i]) == 0 ) {
				swap(nums[i], nums[beg]);
				used.insert(nums[beg]);
				vector<int> next = ele;
				next.push_back(nums[beg]);
				permuteUnique(beg + 1, ret, next);
				swap(nums[i], nums[beg]);
			}
		}
	}
private:
	vector<int> nums;
};

int main() {
	Solution s;
	int n = 0;
	cin>>n;
	vector<int> nums;
	for (int i = 1; i <= n; ++i) {
		int e;
		cin>>e;
		nums.push_back(e);
	}
	auto ret = s.permuteUnique(nums);
	for (auto x : ret) {
		for (auto y : x) {
			cout<<y<<",";
		}
		cout<<endl;
	}
	return 0;
}

