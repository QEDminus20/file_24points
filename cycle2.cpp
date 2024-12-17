#include<bits/stdc++.h>
using namespace std;

const double eps = 0.04;

bool solve(vector<double>& in){
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            vector<double>res1;
            res1.emplace_back(in[i] + in[j]);
            res1.emplace_back(in[i] - in[j]);
            res1.emplace_back(in[j] - in[i]);
            res1.emplace_back(in[i] * in[j]);
            res1.emplace_back(in[i] / in[j]);
            res1.emplace_back(in[j] / in[i]);

            // res1 与 剩下的其中一个数 先运算
            {
                for(int u = 0; u < 4; u++){
                    if(u == i || u == j) continue;
                    for(int k = 0; k < 6; k++){
                        vector<double>res2;
                        res2.emplace_back(res1[k] + in[u]);
                        res2.emplace_back(res1[k] - in[u]);
                        res2.emplace_back(in[u] - res1[k]);
                        res2.emplace_back(res1[k] * in[u]);
                        res2.emplace_back(res1[k] / in[u]);
                        res2.emplace_back(in[u] / res1[k]);
                    
                        for(int v = 0; v < 4; v++){
                            if(v == i || v == j || v == u) continue;
                            for(int h = 0; h < 6; h++){
                                vector<double>res3;
                                res3.emplace_back(res2[h] + in[v]);
                                res3.emplace_back(res2[h] - in[v]);
                                res3.emplace_back(in[v] - res2[h]);
                                res3.emplace_back(res2[h] * in[v]);
                                res3.emplace_back(res2[h] / in[v]);
                                res3.emplace_back(in[v] / res2[h]);

                                for(int g = 0; g < 6; g++){
                                    if(fabs(res3[g] - 24) < eps){
                                        return 1;
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
                        res2.emplace_back(in[u] + in[v]);
                        res2.emplace_back(in[u] - in[v]);
                        res2.emplace_back(in[v] - in[u]);
                        res2.emplace_back(in[u] * in[v]);
                        res2.emplace_back(in[u] / in[v]);
                        res2.emplace_back(in[v] / in[u]);

                        for(int k = 0; k < 6; k++){
                            for(int h = 0; h < 6; h++){
                                vector<double>res3;
                                res3.emplace_back(res1[k] + res2[h]);
                                res3.emplace_back(res1[k] - res2[h]);
                                res3.emplace_back(res2[h] - res1[k]);
                                res3.emplace_back(res1[k] * res2[h]);
                                res3.emplace_back(res1[k] / res2[h]);
                                res3.emplace_back(res2[h] / res1[k]);

                                for(int g = 0; g < 6; g++){
                                    if(fabs(res3[g] - 24) < eps){
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<double>poker(40);
    for(int i = 1; i <= 10; i++){
        for(int j = 0; j < 4; j++){
            poker[(i - 1) * 4 + j] = i;
        }
    }

    int ok = 0;
    vector<double>in(4);
    for(int i = 0; i < 40; i++){
        in[0] = poker[i];
        for(int j = i + 1; j < 40; j++){
            in[1] = poker[j];
            for(int k = j + 1; k < 40; k++){
                in[2] = poker[k];
                for(int l = k + 1; l < 40; l++){
                    in[3] = poker[l];
                    ok += solve(in);
                }
            }
        }
    }
    cout << ok;
    return 0;
}