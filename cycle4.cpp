#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

bool solve(vector<vector<double>>& in, int s){
    if(in.size() == 1){
        for(auto &i : in[0]){
            if(fabs(i - s) < eps){
                return 1;
            }
        }   
    }

    auto cal = [](vector<double> o1, vector<double> o2) -> vector<double>{
        vector<double> res;
        for(auto &i : o1){
            for(auto &j : o2){
                res.emplace_back(i + j);
                res.emplace_back(i - j);
                res.emplace_back(j - i);
                res.emplace_back(i * j);
                res.emplace_back(i / j);
                res.emplace_back(j / i);
            }
        }
        return res;
    };

    for(int u = 0; u < in.size(); u++){
        for(int v = u + 1; v < in.size(); v++){
            vector<double> res = cal(in[u], in[v]);
            vector<vector<double>> newin = in;
            newin.erase(newin.begin() + v);
            newin.erase(newin.begin() + u);
            newin.emplace_back(res);
            if(solve(newin, s)) return 1;       
        }
    }
    return 0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<double>poker(40); int vis = 0;
    for(int i = 1; i <= 10; i++){
        for(int j = 0; j < 4; j++){
            poker[(i - 1) * 4 + j] = i;
        }
    }

    int t = 4;
    vector<vector<double>>in(t, vector<double>(1));

    int ok = 0;
    auto dfs = [&](this auto &&self, int n, int cur, int s) -> void{
        if(cur == n) {
            ok += solve(in, s);
            return;
        }
        for(int i = vis; i < 40; i++){
            in[cur][0] = poker[i];
            int back = vis;
            vis = i + 1;
            self(n, cur + 1, s);
            vis = back;
        }
    };

    for(int i = 0; i <= 100; i++) {
        dfs(t, 0, i);
        cerr << i << " : " << ok << '\n';
        ok = 0;
    }
    return 0;
}