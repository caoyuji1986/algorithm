/*************************************************************************
 > File Name: segment_tree.hpp
# File Name: segment_tree.hpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月26日 星期日 19时29分41秒
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

struct STNode {
    int left, right;
    int num;
    STNode() : left(0), right(0), num(0){}
    STNode(int l, int r, int n) : left(l), right(r), num(n){}
};

class SegmentTree {
public:
    SegmentTree(int m) {
        _data.resize(4 * m);
    }
    void build(int left, int right, int index) {
        if(left == right - 1) {
            _data[index] = STNode(left, left + 1, 0);
            return;
        }
        _data[index] = STNode(left, right, 0);
        int mid = (left + right) / 2;
        build(left, mid, index * 2);
        build(mid, right, index * 2 + 1);
    }
    void insert(int beg, int end, int index) {
        STNode cur = _data[index];
        if (beg == cur.left && end == cur.right) {
            _data[index].num += 1;
            return;
        }
        int mid = (cur.left + cur.right) / 2;
        if (end <= mid) {
            insert(beg, end, index * 2);
        } else if (beg >= mid) {
            insert(beg, end, index * 2 + 1);
        } else {
            insert(beg, mid, index * 2);
            insert(mid, end, index * 2 + 1);
        }
    }
    int search(int beg, int end, int index) {
        STNode cur = _data[index];
        if (beg == cur.left && end == cur.right) {
            return cur.num;
        }
        int mid = (cur.left + cur.right) / 2;
        if (end <= mid) {
            return search(beg, end, index * 2);
        } else if (beg >= mid) {
            return search(beg, end, index * 2 + 1);
        } else {
            int l = search(beg, mid, index * 2);
            int r = search(mid, end, index * 2 + 1);
            return min(l, r);
        }

    }
    void del(int beg, int end, int index) {
        STNode& cur = _data[index];
        if (cur.left == beg && cur.right == end) {
            cur.num = cur.num == 0 ? 0 : cur.num - 1;
            return;
        }
        int mid = (cur.left + cur.right) / 2;
        if (end <= mid) {
            del(beg, end, index * 2);
        } else if (beg >= mid) {
            del(beg, end, index * 2 + 1);
        } else {
            del(beg, mid, index * 2);
            del(mid, end, index * 2 + 1);
        }
    }
private:
    vector<STNode> _data;
};
