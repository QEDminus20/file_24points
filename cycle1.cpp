#include<bits/stdc++.h>
using namespace std;

void solve(){
    vector<double>a(4);
    for(auto &i : a) cin >> i;
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            vector<double>res1;
            res1.emplace_back(a[i] + a[j]);
            res1.emplace_back(a[i] - a[j]);
            res1.emplace_back(a[j] - a[i]);
            res1.emplace_back(a[i] * a[j]);
            if(fabs(a[j]) > 1e-5)
                res1.emplace_back(a[i] / a[j]);
            if(fabs(a[i]) > 1e-5)
                res1.emplace_back(a[j] / a[i]);

            // res1 与 剩下的其中一个数 先运算
            {
                for(int u = 0; u < 4; u++){
                    if(u == i || u == j) continue;
                    for(int k = 0; k < 6; k++){
                        vector<double>res2;
                        res2.emplace_back(res1[k] + a[u]);
                        res2.emplace_back(res1[k] - a[u]);
                        res2.emplace_back(a[u] - res1[k]);
                        res2.emplace_back(res1[k] * a[u]);
                        if(fabs(a[u]) > 1e-5)
                            res2.emplace_back(res1[k] / a[u]);
                        if(fabs(res1[k]) > 1e-5)
                            res2.emplace_back(a[u] / res1[k]);
                    
                        for(int v = 0; v < 4; v++){
                            if(v == i || v == j || v == u) continue;
                            for(int h = 0; h < 6; h++){
                                vector<double>res3;
                                res3.emplace_back(res2[h] + a[v]);
                                res3.emplace_back(res2[h] - a[v]);
                                res3.emplace_back(a[v] - res2[h]);
                                res3.emplace_back(res2[h] * a[v]);
                                if(fabs(a[v]) > 1e-5)
                                    res3.emplace_back(res2[h] / a[v]);
                                if(fabs(res2[h]) > 1e-5)
                                    res3.emplace_back(a[v] / res2[h]);

                                for(int g = 0; g < 6; g++){
                                    if(fabs(res3[g] - 24) < 1e-4){

                                        auto show_op = [](string x, string y, int op) -> string{
                                            string res;
                                            res += "(";
                                            if(op == 0) res += x + " + " + y;
                                            if(op == 1) res += x + " - " + y;
                                            if(op == 2) res += y + " - " + x;
                                            if(op == 3) res += x + " * " + y;
                                            if(op == 4) res += x + " / " + y;
                                            if(op == 5) res += y + " / " + x;
                                            res += ")";
                                            return res;
                                        };

                                        string o1 = to_string((int)a[i]), o2 = to_string((int)a[j]),
                                                 o3 = to_string((int)a[u]), o4 = to_string((int)a[v]);

                                        cout << show_op(show_op(show_op(o1, o2, k), o3, h), o4, g) << '\n';
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            // 剩下的两个数先运算
            {
                for(int u = 0; u < 4; u++){
                    if(u == i || u == j) continue;
                    for(int v = 0; v < 4; v++){
                        if(v == i || v == j || v == u) continue;
                        vector<double>res2;
                        res2.emplace_back(a[u] + a[v]);
                        res2.emplace_back(a[u] - a[v]);
                        res2.emplace_back(a[v] - a[u]);
                        res2.emplace_back(a[u] * a[v]);
                        if(fabs(a[v]) > 1e-5)
                            res2.emplace_back(a[u] / a[v]);
                        if(fabs(a[u]) > 1e-5)
                            res2.emplace_back(a[v] / a[u]);

                        for(int k = 0; k < 6; k++){
                            for(int h = 0; h < 6; h++){
                                vector<double>res3;
                                res3.emplace_back(res1[k] + res2[h]);
                                res3.emplace_back(res1[k] - res2[h]);
                                res3.emplace_back(res2[h] - res1[k]);
                                res3.emplace_back(res1[k] * res2[h]);
                                if(fabs(res2[h]) > 1e-5)
                                    res3.emplace_back(res1[k] / res2[h]);
                                if(fabs(res1[k]) > 1e-5)
                                    res3.emplace_back(res2[h] / res1[k]);

                                for(int g = 0; g < 6; g++){
                                    if(fabs(res3[g] - 24) < 1e-4){

                                        auto show_op = [](string x, string y, int op) -> string{
                                            string res;
                                            res += "(";
                                            if(op == 0) res += x + " + " + y;
                                            if(op == 1) res += x + " - " + y;
                                            if(op == 2) res += y + " - " + x;
                                            if(op == 3) res += x + " * " + y;
                                            if(op == 4) res += x + " / " + y;
                                            if(op == 5) res += y + " / " + x;
                                            res += ")";
                                            return res;
                                        };

                                        string o1 = to_string((int)a[i]), o2 = to_string((int)a[j]),
                                                 o3 = to_string((int)a[u]), o4 = to_string((int)a[v]);
                                                 
                                        cout << show_op(show_op(o1, o2, k), show_op(o3, o4, h), g) << '\n';
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << -1 << '\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}