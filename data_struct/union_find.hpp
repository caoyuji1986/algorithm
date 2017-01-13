/*************************************************************************
 > File Name: union_find.hpp
# File Name: union_find.hpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年01月12日 星期四 19时44分15秒
************************************************************************/
#ifndef _UNION_FIND_HPP_
#define _UNION_FIND_HPP_

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
class UnionFind {
public:
    UnionFind(int n) {
        _n = n;
        _data.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            _data[i] = i;
        }
    }
    int find(int cur) {
        if (cur > _n) return 0;
        if (_data[cur] != cur) {
            _data[cur] = find(_data[cur]);
        }
        return _data[cur];
    }
    void combine(int left, int right) {
        if (left > _n || right > _n) return;
        if (find(left) == find(right)) {
            return;    
        }
        int r_root = find(right);
        _data[r_root] = find(left);
    }
private:
    vector<int> _data;
    int _n;
};
#endif//~
