#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

bool solve(vector<vector<double>>& in){
    if(in.size() == 1){
    	for(auto &i : in[0]){
    		if(fabs(i - 24) < eps){
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
			if(solve(newin)) return 1;    	
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

    vector<vector<double>>in;

    int ok = 0;
    auto dfs = [&](this auto &&self, int n, int cur) -> void{
    	if(cur == n) {
    		ok += solve(in);
    		return;
    	}
    	for(int i = vis; i < 40; i++){
			in[cur][0] = poker[i];
			int back = vis;
			vis = i + 1;
			self(n, cur + 1);
			vis = back;
    	}
    };

    for(int t = 3; t <= 6; t++){
        ok = 0;
        in.assign(t, vector<double>(1));
        dfs(t, 0);
        cerr << t << " : " << ok << '\n';
    }

    return 0;
}
