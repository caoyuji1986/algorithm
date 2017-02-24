/*************************************************************************
 > File Name: elimination_game.cpp
# File Name: elimination_game.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月23日 星期四 18时11分58秒
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
    int lastRemaining(int n) {
        vector<int> data;
        for (int i = 1; i <= n; ++i) {
            data.push_back(i);
        }
		return last_remain(data);
    }
    int lastRemainingV2(int n) {
        if (n == 1) return 1;
        return last_remain_v2(n/2, 1, 2);
    }
    int last_remain_v2(int n, int map_method, int l) {
        if (n == 1) return map_method == 1 ? 2 : 1;
        int v = 0;
        if (l % 2 == 0) {
            int method = n % 2 == 0 ? 2 : 1;
            v = last_remain_v2(n / 2, method, l + 1);
        } else {
            v = last_remain_v2(n / 2, 1, l + 1);
        }
        return map_method == 1 ?  (2 * v) : (2 * v - 1);
    }
    int last_remain(vector<int>& data) {
		if (data.size() == 1) return data[0];
		stack<int> tmp;
		for (int i = 0; i < data.size(); ++i) {
			if (i % 2 != 0) {
				tmp.push(data[i]);
			}
		}
        
		data.clear();
		while(!tmp.empty()) {
			data.push_back(tmp.top());
			tmp.pop();
		}
		return last_remain(data);
	}
};

int main() {
	Solution s;
	while (true) {
		int tmp;
		cin>>tmp;
		if (tmp < 0) break;
		int ret = s.lastRemainingV2(tmp);
		cout<<ret<<endl;
	}
	return 0;
}
