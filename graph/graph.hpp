/*************************************************************************
 > File Name: graph.cpp
# File Name: graph.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007272627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: Tue 10 Jan 2017 07:29:17 PM CST
************************************************************************/
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<utility>

using namespace std;

class Graph {
public:
    ~Graph(){}
    void visit(vector<int>& vertex) {
        for (auto ele : vertex) {
            cout<<ele<<",";
        }
        cout<<endl;
    }

    void make() {
        int num_ver = 0;
        cin>>num_ver;
        for (int i = 0; i < num_ver; ++i) {
            int cur = 0;
            cin>>cur;
            int num_adj = 0;
            cin>>num_adj;
            list<int> adjs;
            for (int j = 0; j < num_adj; ++j) {
                int adj = 0;
                cin>>adj;
                adjs.push_back(adj);
            }
            _G[cur] = adjs;
            cout<<cur<<"->";
            for (auto ele : adjs) {
                cout<<ele<<",";
            }
            cout<<endl;
        }
    }
    void make_weight() {
        int num_vertex = 0;
        cin>>num_vertex;
        for (int i = 1; i <= num_vertex; ++i) {
            _GW[i] = list<pair<int,float> >();
        }
        int num_edge = 0;
        cin>>num_edge;
        for (int i = 0; i < num_edge; ++i) {
            int from=0,to=0;
            float weight = 0.0;
            cin>>from>>to>>weight;
            _GW[from].push_back(make_pair(to, weight));
        }
    }
    
protected:
    unordered_map<int, list<int> > _G;
    unordered_map<int, list<pair<int,float> > > _GW;
};

#endif//~
