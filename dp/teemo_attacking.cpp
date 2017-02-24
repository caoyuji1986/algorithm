/*************************************************************************
 > File Name: teemo_attacking.cpp
# File Name: teemo_attacking.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月24日 星期五 17时32分39秒
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
	vector<int> time;
    int duration;
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int last_covered_pos = -1;
        int ret = 0;
		for (int i = 0; i < timeSeries.size(); ++i) {
		    if (timeSeries[i] > last_covered_pos) {
		        ret += duration;
		        last_covered_pos = timeSeries[i] - 1 + duration;
		    } else {
		        if (timeSeries[i] + duration - 1 - last_covered_pos > 0) {
		            ret += timeSeries[i] + duration - 1 - last_covered_pos;
		            last_covered_pos = timeSeries[i] - 1 + duration;
		        }
		    }
		}
		return ret;
    }
};

int main() {
	Solution s;
	vector<int> ts;
	int d;
	int k;
	cin>>d>>k;
	for(int i = 1; i <= k; ++i) {
		int a;
		cin>>a;
		ts.push_back(a);
	}
	int ret = s.findPoisonedDuration(ts, d);
	cout<<ret<<endl;
	return 0;
}
