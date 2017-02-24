/*************************************************************************
 > File Name: max_sliding_window.cpp
# File Name: max_sliding_window.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月23日 星期四 15时35分00秒
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
using namespace std;
struct Node {
	int val;
	int index;
	Node(int val, int index):val(val),index(index){}
	bool operator < (const Node& r) const {
		if (this->val < r.val) return true;
		else if (this->val == r.val) return this->index < r.index;
		else return false;
	}
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		priority_queue<Node> Q;
		for (int i = 0; i < k && i < nums.size(); ++i) {
			Q.push(Node(nums[i], i));
		}
		vector<int> ret;
		ret.push_back(Q.top().val);
		for (int i = k; i < nums.size(); ++i) {
			Q.push(Node(nums[i], i));
			while (!Q.empty()) {
				Node t = Q.top();
				if (t.index > i - k && t.index <= i) {
					ret.push_back(t.val);
					break;
				} else {
					Q.pop();
				}
			}
		}
		return ret;
    }
};
int main() {
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int a;
        cin>>a;
        nums.push_back(a);
    }
    vector<int> ret = s.maxSlidingWindow(nums, k);
    for (auto ele : ret) {
        cout<<ele<<"-";
    }
    cout<<endl;
    return 0;
}
