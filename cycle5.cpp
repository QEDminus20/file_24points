#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

void solve(vector<vector<double>>& in, int k, vector<int>& ok, vector<bool>& vis){
    if(in.size() == 1){
    	for(auto &i : in[0]){
    		for(int res = 0; res <= 100; res++){
                if(!vis[res] && fabs(res - i) < eps){
                    vis[res] = 1;
                    ok[res] += k;
                }
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
			solve(newin, k, ok, vis);
		}
    }
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

    vector<int>C4 = {1, 4, 6, 4, 1, 0, 0};

    vector<vector<double>>in;

    vector<int>ok(101);

    auto dfs = [&](this auto &&self, int n, int cur = 0, int u = 1) -> void{
        if(cur == n){
            vector<int>cnt(11, 0);
            int k = 1;
            for(int i = 0; i < n; i++){
                cnt[(signed)in[i][0]]++;
            }
            for(int i = 0; i <= 10; i++){
                k *= C4[cnt[i]];
            }
            vector<bool>vis(101, 0);
            solve(in, k, ok, vis);
            return;
        }
        for(int v = u; v <= 10; v++){
            in[cur][0] = v;
            self(n, cur + 1, v);
        }
    };

    for(int t = 3; t <= 5; t++){
        ok.assign(101, 0);
        in.assign(t, vector<double>(1));
        dfs(t);
        for(int i = 0; i <= 100; i++){
            cerr << t << " : " << i << " : " << ok[i] << '\n';
        }
        cerr << '\n';
    }

    return 0;
}