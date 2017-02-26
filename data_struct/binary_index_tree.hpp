/*************************************************************************
 > File Name: binary_index_tree.hpp
# File Name: binary_index_tree.hpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月26日 星期日 21时06分53秒
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

class BinaryIndexTree {
public:
    BinaryIndexTree(int n) {
        _n = n;
        _c.resize(n + 1);
    }
    void add(int pos, int val) {
        while (pos <= _n) {
            t[pos] += val;
            pos += (pos & (-pos));
        }
    }
    int sum(int n) {
        int ret = 0;
        while (n > 0) {
            ret += t[n];
            n -= (n & (-n));
        }
        return ret;
    }

private:
    int lower_bit(int x) {
        return x & (-x);
    }
    int _n;
    vector<int> _c;
};

