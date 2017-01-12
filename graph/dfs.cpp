/*************************************************************************
 > File Name: dfs.cpp
# File Name: dfs.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年01月11日 星期三 11时46分13秒
************************************************************************/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include"graph.hpp"
using namespace std;
class Dfs : public Graph {
public:
    vector<int> dfs(vector<int>& result,
        unordered_map<string, int>& edge_classified) {
        _timer = 0;
        unordered_set<int> visited;
        _touch_time.resize(_G.size() + 1, 0);
        _finish_time.resize(_G.size() + 1, 0);
        _parent.resize(_G.size() + 1, 0);

        for (int i = 1; i <= _G.size(); ++i) {
            if (visited.count(i) == 0) {
                _parent[i] = -1 * i;
                dfs_inner(i, visited, edge_classified, result);
            }
        }
    }

    void dfs_inner(int s, unordered_set<int>& visited,
            unordered_map<string, int>& edge_classified, vector<int>& result) {
        _timer += 1;
        _touch_time[s] = _timer;
        visited.insert(s);
        result.push_back(s);
        list<int> adjs = _G[s];
        for (auto adj : adjs) {
            int edge_type = 0;
            if (visited.count(adj) == 0) {
                //tree edge
                _parent[adj] = s;
                edge_type = 0;
                dfs_inner(adj, visited, edge_classified, result);
            } else {
                if (_parent[adj] == _parent[s]) {
                    //cross edge
                    edge_type = 1;
                } else {
                    if (_finish_time[s] == 0) {
                        //forword edge
                        edge_type = 2;
                    } else {
                        //backword edge
                        edge_type = 3;
                    }
                }
            }
            stringstream ss;
            ss<<s<<"->"<<adj;
            edge_classified[ss.str()] = edge_type;
        }
        _timer += 1;
        _finish_time[s] = _timer;
    }

private:
    int _timer;
    vector<int> _touch_time;
    vector<int> _finish_time;
    vector<int> _parent;
};

int main() {
    Dfs dfs;
    dfs.make();
    vector<int> result;
    unordered_map<string, int> edge_classified;
    dfs.dfs(result, edge_classified);
    dfs.visit(result);
    for (auto ele : edge_classified) {
        cout<<ele.first<<":"<<ele.second<<endl;
    }
    return 0;
}
