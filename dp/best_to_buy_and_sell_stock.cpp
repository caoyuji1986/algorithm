/*************************************************************************
 > File Name: best_to_buy_and_sell_stock.cpp
# File Name: best_to_buy_and_sell_stock.cpp
# Author :Yuji CAO
# QQ : 1007171627
# Email:1007171627@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年02月23日 星期四 13时45分39秒
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

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> diffs(prices.size(), 0);
        diffs[0] = 0;//just make it readable
        for (int i = 1; i < prices.size(); ++i) {
            diffs[i] = prices[i] - prices[i - 1];
        }
        //count number of available transactions
        int max_num = 0;
        int i = 1;
        while(i<diffs.size()) {
            while(i<diffs.size() && diffs[i]>=0) i++;
            max_num += 1;
            while(i<diffs.size() && diffs[i]<=0) i++;
        }
        cout<<max_num<<endl;
        if (max_num <= k) {
            return so_easy(diffs);
        } else {
            return max_k_subarray_sum(diffs, k);
        }
    }
private:
    int so_easy(vector<int>& diffs) {
        int ret = 0;
        for(auto ele : diffs) {
            ret += ele>0?ele:0;
        }
        return ret;
    }
    int max_k_subarray_sum(vector<int>& diffs, int m) {
        int ret = 0;
        vector<vector<int> > f(diffs.size(), vector<int>(m + 1, 0));
        f[0][1] = diffs[0];
        for (int i = 1; i < diffs.size(); ++i) {
            for (int j = 1; j <= m; ++j) {
                //as other one
                int one = 0;
                for (int k = 0; k < i; ++k) {//loop before i
                    one = max(one, diffs[i] + f[k][j - 1]);
                }
                //merge into previous
                int two = f[i - 1][j] + diffs[i];
                f[i][j] = max(one, two);
            }
            ret = max(ret, f[i][m]);
        }
        return ret;
    }
};
int main() {
    Solution s;
    int num = 0;
    int k = 0;
    cin>>num>>k;
    vector<int> prices;
    for (int i = 1; i <= num; ++i) {
        int a;
        cin >> a;
        prices.push_back(a);
    }
    int ret = s.maxProfit(2, prices);
    cout<<ret<<endl;
    return 0;
}
