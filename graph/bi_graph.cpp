/*************************************************************************
 > File Name: bi_graph.cpp
# File Name: bi_graph.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年01月18日 星期三 14时12分21秒
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
class BiGraph {
public:
    void make() {
        cin>>_m>>_n;
        int num_edges = 0;
        cin>>num_edges;
        for (int i = 0; i < num_edges; ++i) {
            int left, right;
            cin>>left>>right;
            if (_G.find(left) == _G.end()) {
                _G[left] = list<int>();
            }
            if (_G.find(right) == _G.end()) {
                _G[right] = list<int>();
            }
            _G[left].push_back(right);
            _G[right].push_back(left);
        }
    }
    virtual int match(unordered_map<int, int>& edges) = 0;
    virtual ~BiGraph(){}
protected:
    unordered_map<int, list<int> > _G;
    int _m;
    int _n;
};

class HungryBFS : public BiGraph {
public:
    virtual int match(unordered_map<int, int>& m) {
        int ret = 0;
        for (int i = 1; i <= _m; ++i) {
            if (m.count(i) == 0) {
                queue<int> Q;
                Q.push(i);
                unordered_map<int, int> pre;
                pre[i] = 0;
                unordered_set<int> visit;
                visit.clear();
                while (!Q.empty()) {
                    int u = Q.front();
                    Q.pop();
                    bool b = false;
                    for (int v : _G[u]) {
                        if (visit.count(v) == 0) {
                            visit.insert(v);
                            if (m.count(v) == 0) {
                                int s = u;
                                int e = v;
                                while (s!=0) {
                                    int ts = pre[s];
                                    int te = m[u];
                                    m[e] = s;
                                    m[s] = e;
                                    s = ts;
                                    e = te;
                                }
                                ret += 1;
                                b = true;
                                break;
                            } else {
                                pre[m[v]] = u;
                                Q.push(m[v]);
                            }
                        }
                    }
                    if (b) break;
                }
            }
        }
        return ret;
    }

};

class Hungry : public BiGraph {
public:
    virtual int match(unordered_map<int, int>& m) {
        int ret = 0;
        for (int i = 1; i <= _m; ++i) {
            _used.clear();
            if (find_augment(i, m)) {
                ret += 1;
            }
        }
        return ret;
    }
private:
    bool find_augment(int beg, unordered_map<int, int>& m) {
        // No edges from beg
        if (_G.find(beg) == _G.end()) return false;
        //dsf search
        for (auto y : _G[beg]) {
            if (_used.count(y) == 0) {
                _used.insert(y);
                if (m.find(y) == m.end() || find_augment(m[y], m)) {
                    m[y] = beg;
                    return true; 
                }
            }
        }
        return false;
    }
    //record if y \in Y
    unordered_set<int> _used;
};

class HopcroftKarp : public BiGraph {
public:
    virtual int match(unordered_map<int, int>& m) {
        int ret = 0;
        while(true) {
            unordered_map<int, int> d;
            int dis = bfs(m, d);
            if (dis == 0) break;
            for (int i = 1; i <= _m; ++i) {
                unordered_set<int> visit;
                ret += hungryBFS(i, m, d, visit, dis);
            }
        }
        return ret;
    }
private:
    int hungryBFS(int u, unordered_map<int, int>& m,
            unordered_map<int, int>& d, unordered_set<int>& visit, int dis) {
        if (_G.count(u) == 0) return 0;
        for (int v : _G[u]) {
            if (d[v] == d[u] + 1 && visit.count(v) == 0) {
                visit.insert(v);
                if (m.count(v) != 0 && d[v] == dis) continue;
                if (m.count(v) == 0 || hungryBFS(m[v], m, d, visit, dis)) {
                    m[v] = u;
                    m[u] = v;
                    return 1;
                }
            }
        }
        return 0;
    }
    int bfs(unordered_map<int, int>& m, unordered_map<int, int>& d) {
        d.clear();
        queue<int> Q;
        for (int i = 1; i <= _m; ++i) {
            if (m.count(i) == 0) {
                Q.push(i);
                d[i] = 0;
            }
        }
        int dis = numeric_limits<int>::max();
        unordered_set<int> visited;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int v : _G[u]) {
                if (visited.count(v) == 0) {
                    visited.insert(v);
                    d[v] = d[u] + 1;
                    if (d[v] > dis) break;

                    if (m.count(v) == 0) {
                        dis = d[v]; 
                    } else {
                        d[m[v]] = d[v] + 1;//the element that will be pushed in queue must have dist value
                        Q.push(m[v]);
                    }
                }
            }
        }
        return dis == numeric_limits<int>::max() ? 0 : dis;
    }
};

int main() {
    BiGraph* bg = (BiGraph*)new HopcroftKarp();
    bg->make();
    unordered_map<int, int> m;
    int num = bg->match(m);
    for (auto ele : m) {
        cout<<ele.first<<"--"<<ele.second<<endl;
    }
    cout<<num<<endl;
    return 0;
}
