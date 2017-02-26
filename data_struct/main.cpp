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
#include"tree.hpp"
#include"segment_tree.hpp"
using namespace std;

int unifind() {
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
int tree() {
    int n;
    cin>>n;
    vector<char> array;
    for (int i = 1; i <= n; ++i) {
        char t;
        cin>>t;
        array.push_back(t);
    }
    Tree t;
    TreeNode* root = t.build_from_array(array);
    //t.visit_pre(root);
    //t.visit_mid(root);
    //t.visit_pos(root);
    t.lca(root);
    //t.visit_level(root);
    return 0;
}
int segment_tree() {
    SegmentTree st(10);
    st.build(0, 10, 1);
    st.insert(2, 4, 1);
    st.insert(2, 4, 1);
    int ret = st.search(3, 4, 1);
    cout<<ret<<endl;
    return 0;
}
int main() {
    int a = 6;
    cout<<(a&(-a))<<endl;
    return 1;
}
