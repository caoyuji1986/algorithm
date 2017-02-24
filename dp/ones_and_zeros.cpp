/*************************************************************************
 > File Name: ones_and_zeros.cpp
# File Name: ones_and_zeros.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月24日 星期五 16时38分10秒
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
	vector<pair<int, int> > nums;
	int length;
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int> > > f(m + 1, vector<vector<int> >(n + 1, vector<int>(strs.size() + 1, -1)));
		for (int i = 0; i < strs.size(); ++i) {
			pair<int, int> ele = make_pair(0,0);
			for (auto c : strs[i]) {
				ele.first += c == '0';
				ele.second += c == '1';
			}
			nums.push_back(ele);
		}
		length = strs.size();
		find(m, n, 0, f);
		return f[m][n][0];	            
    }
	void find(int m_left, int n_left, int i, vector<vector<vector<int> > >& f) {
		int l = 0;
		int r = 0;
		if (i + 1 < length) {
			if (-1 == f[m_left][n_left][i + 1]) {
				find(m_left, n_left, i + 1, f);
			}
			l = f[m_left][n_left][i + 1];
		}
		if (m_left - nums[i].first >= 0 && n_left - nums[i].second >= 0 && i < length) {
			if (-1 == f[m_left - nums[i].first][n_left - nums[i].second][i + 1]) {
				find(m_left - nums[i].first, n_left - nums[i].second, i + 1, f);
			}
			r = f[m_left - nums[i].first][n_left - nums[i].second][i + 1] + 1;
		}
		f[m_left][n_left][i] = max(l, r);  
	}
};

int main() {
	Solution s;
	int m,n,k;
	cin>>m>>n;
	cin>>k;
	vector<string> strs;
	for (int i = 1; i <= k; ++i) {
		string a;
		cin>>a;
		strs.push_back(a);
	}
	int ret = s.findMaxForm(strs, m, n);
	cout<<ret<<endl;
	return 0;
}
