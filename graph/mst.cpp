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
#include"../data_struct/union_find.hpp"
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
    bool operator < (const Edge& right) const {
        return weight < right.weight;
    }
    string str() {
        stringstream ss;
        ss<<from<<"->"<<to<<":\t"<<weight;
        return ss.str();
    }
    Edge() : from(0),to(0),weight(0.0){}
    Edge(int f, int t, float w) : from(f),to(t),weight(w){}
};

struct cmp {
    bool operator()(const Edge& left, const Edge& right) const {
        return left.weight > right.weight;
    }
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

class PrimHeap : public MST {
    virtual void generate(vector<pair<int,int> >& edges) {
        unordered_set<int> visited;
        priority_queue<Edge,vector<Edge>, cmp> Q;
        Q.push(Edge(1,1,0.0f));
        while (visited.size() != _GW.size() ) {
            Edge e = Q.top();
            cout<<e.from<<"-"<<e.to<<endl;
            Q.pop();
            if (visited.count(e.to)) continue;
            int from = e.to;
            edges.push_back(make_pair(e.from, e.to));
            visited.insert(from);
            list<pair<int, float> > adjs = _GW[from];
            for (auto adj : adjs) {
                if (visited.count(adj.first))continue;
                int to = adj.first;
                int weight = adj.second;
                Q.push(Edge(from, to, weight));
            }
        }
    }
};

class Kruskal : public MST {
    virtual void generate(vector<pair<int,int> >& edges) {
        vector<Edge> edge_sort;
        for (auto ele : _GW) {
            list<pair<int,float> > adjs = ele.second;
            int from = ele.first;
            for (auto to : adjs) {
                edge_sort.push_back(Edge(from, to.first, to.second));
            }
        }
        sort(edge_sort.begin(), edge_sort.end());
        UnionFind uf(_GW.size() + 1);
        for (auto edge : edge_sort) {
            if (uf.find(edge.from) != uf.find(edge.to)) {
                edges.push_back(make_pair(edge.from, edge.to));
                uf.combine(edge.from, edge.to);
            }
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout<<argv[0]<<" [prim|prim_heap|kruskal]"<<endl;
        return -1;
    }
    cout<<argv[1]<<endl;
    MST* mst = (MST*)new Kruskal();

    mst->make_weight();
    cout<<"bingo"<<endl;
    vector<pair<int,int> > edges;
    mst->generate(edges);
    for (auto e : edges) {
        cout<<e.first<<"->"<<e.second<<endl;
    }
    return 0;
}
