/*************************************************************************
 > File Name: bfs.cpp
# File Name: bfs.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年01月12日 星期四 12时28分49秒
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
#include"graph.hpp"
using namespace std;
class Bfs : public Graph {
public:
    vector<int> bfs(int s, vector<int>& result) {
        unordered_set<int> visited;
        visited.insert(s);
        
        vector<int> parent(_G.size());
        parent[s] = 0;

        vector<int> dist(_G.size());
        dist[s] = 0;

        queue<int> Q;
        Q.push(s);

        result.push_back(s);
        while (!Q.empty()) {
            int root = Q.front();
            Q.pop();
            list<int> adjs = _G[root];
            for (auto adj : adjs) {
                if (visited.count(adj) == 0) {
                    Q.push(adj);
                    parent[adj] = root;
                    dist[adj] = dist[root] + 1;
                    visited.insert(adj);
                    result.push_back(adj);
                }
            }
        }
        return dist;
    }
    void visit(const vector<int>& dist) {
        for (int i = 0; i <= dist.size(); ++i) {
            cout<<i<<":\t"<<dist[i]<<endl;
        }
    }
};

int main() {
    Bfs bfs;
    bfs.make();
    vector<int> result;
    vector<int> dist = bfs.bfs(1, result); 
    cout<<"visit order:"<<endl;
    bfs.visit(result);
    cout<<"tree level"<<endl;
    bfs.visit(dist);
    return 0;
}
