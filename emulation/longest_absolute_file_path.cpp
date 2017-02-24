/*************************************************************************
 > File Name: longest_absolute_file_path.cpp
# File Name: longest_absolute_file_path.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月24日 星期五 21时10分00秒
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
    int lengthLongestPath(string input) {
        vector<int> pathLength(input.size(), 0);
        int cur = 1;
        int ret = 0;
        int i = 0;
        bool file = false;
        int pos = 0;
        for (; pos < input.size();) {
            auto ele = input[pos];
            if (ele == '\n') {
                if (file) {
                    ret = max(i, ret);
                } else {
                    pathLength[cur + 1] = i + 1;
                    cout<<cur + 1<<":"<<i + 1<<endl;
                }
                pos++;
            } else if (ele == '\t') {
                cur = 1;
                int j = pos;
                while (input[j] == '\t') {
                    cur += 1;
                    j++;
                }
                pos = j;
                i = pathLength[cur];
                file = false;
            } else {
                if (ele == '.') {
                    file = true;
                }
                i++;
                pos++;
            }
        }
        if (file) {
            ret = max(i, ret);
        }
        return ret;
    }
};
int main() {
	Solution s;
	string input;
	cin>>input;
	int ret = s.lengthLongestPath(input);
	cout<<ret<<endl;
	return 0;
}
