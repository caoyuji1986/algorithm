/*************************************************************************
 > File Name: prim.cpp
# File Name: prim.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年01月11日 星期三 19时56分49秒
************************************************************************/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include"graph.hpp"
using namespace std;
class MST : public Graph {
public:
    virtual void generate(vector<pair<int,int> >& edges) = 0; 
    virtual ~MST(){}
};

struct Edge {
    int from;
    int to;
    float weight;
    bool operator < (const Edge& right) {
        return weight < right.weight;
    }
    Edge() : from(0),to(0),weight(0.0){}
    Edge(int f, int t, float w) : from(f),to(t),weight(w){}
};

class Prim : public MST {
    virtual void generate(vector<pair<int,int> >& edges) {
        vector<Edge> edges_sort;
        for (auto ele : _GW) {
            for (auto adj : ele.second) {
                edges_sort.push_back(Edge(ele.first, adj.first, adj.second));
            }
        }
        sort(edges_sort.begin(), edges_sort.end());

        unordered_set<int> vertex;
        vertex.insert(1);
        while (vertex.size() != _GW.size()) {
            Edge eRet;
            for (auto e : edges_sort) {
                if (vertex.count(e.from) != 0 && vertex.count(e.to) == 0) {
                    eRet = e;
                    break;
                }
            }
            if (eRet.from == 0) break;
            vertex.insert(eRet.to);
            edges.push_back(make_pair(eRet.from, eRet.to));
        }
    }
};

class Kruskal : public MST {
    virtual void generate(vector<pair<int,int> >& edges) {
        
    }
}

int main() {
    MST* mst = (MST*)new Prim();
    mst->make_weight();
    vector<pair<int,int> > edges;
    mst->generate(edges);
    for (auto e : edges) {
        cout<<e.first<<"->"<<e.second<<endl;
    }
    return 0;
}
