/*************************************************************************
 > File Name: contains_duplication.cpp
# File Name: contains_duplication.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月18日 星期六 16时38分42秒
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
#include<limits.h>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0) return false;
        this->_k = k;
        this->_k = min(this->_k, (int)nums.size());
        this->_t = t;
        this->_nums = nums;
        return containsNearbyAlmostDuplicate(0, nums.size());
    }
private:
    bool containsNearbyAlmostDuplicate(int beg, int end) {
        if (beg == end - 1) {
            return false;
        }
        bool l = containsNearbyAlmostDuplicate(beg, (beg + end) / 2);
        if (l == true) return true;
        bool r = containsNearbyAlmostDuplicate((beg + end) / 2, end);
        if (r == true) return true;
        
        int mid = (beg + end) / 2;
        for (int i = 1; i <= this->_k; ++i) {
            int left = max(beg, mid - i);
            for (int j = mid; j <= min(left + this->_k, end - 1); ++j) {
                if (abs(this->_nums[j] - this->_nums[left]) <= this->_t) {
                    return true;
                }
            }
        }
        return false;
    }
    int _k;
    int _t;
    vector<int> _nums;
};
int main() {
    Solution s;
    int a[]={-1,4};
    vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
    cout<<numeric_limits<int>::max()<<endl;
    bool ret = s.containsNearbyAlmostDuplicate(nums, 1, 4);
    cout<<ret<<endl;
    return 0;
}
