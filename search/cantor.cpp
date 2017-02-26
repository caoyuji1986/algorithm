/*************************************************************************
 > File Name: cantor.cpp
# File Name: cantor.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月25日 星期六 17时34分09秒
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
class Cantor {
public:
    int encode(string& code) {
        vector<int> code_vec;
        for (auto ele : code) {
            code_vec.push_back(ele - '0');
        }
        unordered_set<int> s;
        int ret = 0;
        for (int i = 0; i < code_vec.size(); ++i) {
            int b = 0;
            for (int j = 0; j < code_vec[i]; ++j) {
                if (s.count(j) == 0) {
                    b += 1;
                }
            }

            s.insert(code_vec[i]);
            ret += b * factorial(code_vec.size() - i - 1);
        }
        return ret;
    }
    string decode(int code, int length) {
        string ret;
        int i = 1;
        unordered_set<int> s;
        while (i <= length) {
            int base = factorial(length - i);
            int b = code / base;
            int k = 0;
            int r = 0;
            for (int j = 0; j < length; ++j) {
                if (s.count(j) == 0) {
                    k++;
                }
                if (k == b + 1) {
                    r = j;
                    break;
                }
            }
            ret.push_back(r + '0');
            s.insert(r);
            i++;
            code %= base;
        }
        return ret;
    }
private:
    int factorial(int n) {
        if (n == 0) return 1;
        return factorial(n-1) * n;
    }
};
int main() {
    while (true) {
    string code;
    cin>>code;
    Cantor c;
    int r = c.encode(code);
    cout<<r<<endl;
    string rr = c.decode(r, code.size());
    cout<<rr<<endl;
    }
    return 0;
}
