/*************************************************************************
 > File Name: tree.hpp
# File Name: tree.hpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月26日 星期日 10时53分33秒
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

struct TreeNode {
    TreeNode* left, *right;
    int val;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr){}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r){}
    string to_str() {
        stringstream ss;
        ss<<val;
        string ret;
        ss>>ret;
        return ret;
    }
};

class Tree {
private:
    TreeNode* build_from_array_with_level(vector<char>& array, int beg) {
        if (array[beg] == '#') return nullptr;
        int l = 2 * beg;
        int r = 2 * beg + 1;
        TreeNode* l_node = nullptr;
        TreeNode* r_node = nullptr;
        if (l < array.size()) {
            l_node = build_from_array_with_level(array, l);
        }
        if (r < array.size()) {
            r_node = build_from_array_with_level(array, r);
        }
        TreeNode* cur = new TreeNode(array[beg] - '0', l_node, r_node);
        return cur;
    }
    void lca(TreeNode* root, vector<TreeNode*>& v, unordered_map<string, int>& ret) {
        if (root == nullptr) return;
        vector<TreeNode*> vl, vr;
        if (root->left) lca(root->left, vl, ret);
        if (root->right) lca(root->right, vr, ret);
        for (auto l : vl) {
            for (auto r : vr) {
                stringstream ss;
                vector<string> tmp = {l->to_str(), r->to_str()};
                sort(tmp.begin(), tmp.end());
                ss<<tmp[0]<<"_"<<tmp[1];
                string key;
                ss>>key;
                ret[key] = root->val;
            }
        }
        for (auto l : vl) v.push_back(l);
        v.push_back(root);
        for (auto r : vr) v.push_back(r);
    }
    void visit_level(queue<TreeNode*>& Q) {
        queue<TreeNode*> Q1;
        while (!Q.empty()) {
            TreeNode* f = Q.front();Q.pop();
            cout<<f->to_str()<<endl;
            if (f->left) Q1.push(f->left);
            if (f->right) Q1.push(f->right);
        }
        if (!Q1.empty()) {
            visit_level(Q1);
        }
    }
public:
    /**
     * build tree form array
     **/
    TreeNode* build_from_array(vector<char>& array) {
        vector<char> tmp;
        tmp.push_back('#');
        for (auto ele : array) tmp.push_back(ele);
        return build_from_array_with_level(tmp, 1);
    }
    /**
     * using robert tarjan algorithm to solve lca problem
     **/
    void lca(TreeNode* root) {
        vector<TreeNode*> v;
        unordered_map<string, int> ret;
        lca(root, v, ret);
        for (auto kv : ret) {
            cout<<kv.first<<":"<<kv.second<<endl;
        }
    }
    /**
     * visiting
     **/
    void visit_level(TreeNode* root) {
        if (root == nullptr) return;
        queue<TreeNode*> Q;
        Q.push(root);
        visit_level(Q);
    }
    void visit_pre(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> s;
        while (cur != nullptr || !s.empty()) {
            while(cur != nullptr) {
                s.push(cur);
                cout<<cur->to_str()<<endl;
                cur = cur->left;
            }
            auto root_now = s.top();s.pop();
            cur = root_now->right;
        }
    }

    void visit_mid(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> s;
        while (cur != nullptr || !s.empty()) {
            while(cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            auto root_now = s.top();s.pop();
            cout<<root_now->to_str()<<endl;
            cur = root_now->right;
        }
    }

    void visit_pos(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        stack<TreeNode*> s;
        while (cur != nullptr || !s.empty()) {
            while(cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            
            auto root_now = s.top();
            if (root_now->right == nullptr || root_now->right == pre) {
                cout<<root_now->to_str()<<endl;
                pre = root_now;
                s.pop();
                cur = nullptr;// return to parent
            } else {
                cur = root_now->right;// goto right
            }
        }
    }
};

