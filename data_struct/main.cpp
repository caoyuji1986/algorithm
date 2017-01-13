/*************************************************************************
 > File Name: main.cpp
# File Name: main.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年01月12日 星期四 20时12分21秒
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
#include"union_find.hpp"
using namespace std;

int main() {
    int n = 0;
    cin>>n;
    UnionFind uf(n);
    int type = 0;
    while (type != 3) {
        cin>>type;
        if (type == 1) {//find
            int key = 0;
            cin>>key;
            cout<<uf.find(key)<<endl;
        } else if (type == 2) {
            int left = 0, right = 0;
            cin>>left>>right;
            uf.combine(left, right);
        }
    }
    return 0;
}

