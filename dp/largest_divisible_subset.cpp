/*************************************************************************
 > File Name: d.cpp
# File Name: d.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月18日 星期六 12时17分48秒
************************************************************************/
#include<iostream>
#include<unordered_map>
#include<set>
#include<list>
#include<queue>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
struct Node {
    int index;
    vector<int> subset;
    Node(int index, vector<int> subset) {
        this->index = index;
        this->subset = subset;
    }
    bool operator < (const Node& r) const {
        return this->subset.size() < r.subset.size();
    }
};
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        sort(nums.begin(), nums.end());
        Node first(0, vector<int>(1, nums[0]));
        multiset<Node> s;
        s.insert(first);
        for (int i = 1; i < nums.size(); ++i) {
            int tmp = nums[i];
            bool tag = false;
            for (set<Node>::reverse_iterator ritr = s.rbegin(); ritr != s.rend(); ++ritr) {
                if (tmp % nums[ritr->index] == 0) {
                    //cout<<tmp<<"***"<<nums[ritr->index]<<endl;
                    Node cur(i, ritr->subset);
                    cur.subset.push_back(tmp);
                    s.insert(cur);
                    //cout<<s.size()<<endl;
                    tag = true;
                    break;
                }
            }
            if (tag == false) {
                s.insert(Node(i, vector<int>(1, tmp)));
            }
        }
        return s.rbegin()->subset;
    }
};
int main() {
	Solution s;
	int a[] = {1,2,3};
	vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
	auto ret = s.largestDivisibleSubset(nums);
    for (auto ele : ret) {
        cout<<ele<<endl;
    }
	return 0;
}
