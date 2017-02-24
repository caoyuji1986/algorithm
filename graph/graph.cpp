/*************************************************************************
 > File Name: graph.cpp
# File Name: graph.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年01月24日 星期二 13时10分04秒
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
using namespace std;
class GraphImp : public Graph {
public:
    int match(unordered_map<int, int>& match) {
        queue<int> Q;
        for (int i = 1; i <= _G.size(); ++i) {
            if (match.count(i) == 0) {

            }
        }
    }
private:
    bool dfs(int u, unordered_set<int> visit, stack<int> path) {
        visit.insert(u);
        path.push(u);
        vector<int> candidates;
        int i = 0;
        while (i < _G[u].size()) {
            int v = _G[u][i];
            if (_map.count(v) == 0) {
                candidates.push_back(v);
            } else {
                for (int vv : _map[v]) {
                    candidates.push_back(vv);
                }
            }
            i++;
        }
        int i = 0;
        while (i < candidates.size()) {
            int v = candidates[i];
            if (match[v] == -1) {
                return true;
            } else {
                int vv = match[v];
                if (visit.count(v) != 0) {
                    constract(v, path);
                } else {
                    visit.push(v);
                    path.push(v);
                    dfs(vv, visit, path);
                    i++;
                }
            }
        }
        visit.erase(u);
        return false;
    }
    void constract(int u, stack<int> path) {
        vector<int> tmp;
        while (true) {
            int uu = path.top();
            path.pop();
            tmp.push_back(uu);
            if (uu == u) break;
        }
        _map[u] = tmp;
    }
    map<int, vector<int> > _map;
};
