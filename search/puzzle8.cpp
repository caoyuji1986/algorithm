/*************************************************************************
 > File Name: puzzle8.cpp
# File Name: puzzle8.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月25日 星期六 16时11分53秒
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
#include<utility>
using namespace std;
class Solution {
    public:
        int puzzle8(string& ptn, int x, int y) {
            _ptn = ptn;
            _d = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)}; 
            vector<string> ele;
            vector<vector<string> > ret;
            ele.push_back(ptn);
            puzzles(ptn, x, y, 0, ele, ret);
            for (auto ele : ret) {
                if (ele.size() > 1000) {
                    continue;
                }
                for(auto i : ele) {
                    cout<<i<<",";
                }
                cout<<endl;
            }
            return _f[ptn];
        }
        void puzzles(string& ptn, int x, int y, int s, vector<string> elee, vector<vector<string> >& rett) {
            static const string sRESULT = "123405678";
            if (ptn == sRESULT) {
                rett.push_back(elee);
                _f[ptn] = 0;
                return;
            }
            if (s > 50000) {
                _f[ptn] = numeric_limits<int>::max();
                return ;
            }
            int ret = 500001;
            for (auto ele : _d) {
                int c_x = ele.first + x;
                int c_y = ele.second + y;
                if (c_x >=0 && c_x < 3 && c_y >= 0 && c_y <3) {
                    swap(ptn[x * 3 + y], ptn[c_x * 3 + c_y]);
                    if (!_f.count(ptn)) {
                        vector<string> ele_next = elee;
                        ele_next.push_back(ptn);
                        puzzles(ptn, c_x, c_y, s + 1, ele_next, rett);
                    }
                    ret = min(ret, _f[ptn]);
                    swap(ptn[x * 3 + y], ptn[c_x * 3 + c_y]);
                }
            }
            _f[ptn] = ret + 1;
        }
    private:
        string _ptn;
        vector<pair<int, int> > _d;
        unordered_map<string, int> _f;
};

int main() {
    Solution sln;
    string s;
    cin>>s;
    int x, y;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') {
            x = i / 3;
            y = i % 3;
        }
    }
    cout<<x<<","<<y<<endl;
    cout<<s<<endl;
    int ret = sln.puzzle8(s, x, y);
    cout<<ret<<endl;
    return 0;
}
