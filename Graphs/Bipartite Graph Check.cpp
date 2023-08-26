#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        vector < vector < int > > g(n + 1);
        while(m--){
                int u , v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        vector < int > color(n + 1 , -1);
        bool is_bipartite = true;
        queue < int > q;
        for(int i = 1 ; i <= n ; ++i){
                if(color[i] == -1){
                        q.push(i);
                        color[i] = 0;
                        while(!q.empty()){
                                int u = q.front();
                                q.pop();
                                for(int v : g[u]){
                                        if(color[v] == -1){
                                                color[v] = color[u] ^ 1;
                                                q.push(v);
                                        }
                                        else{
                                                is_bipartite &= color[v] != color[u];
                                        }
                                }
                        }
                }
        }
        if(is_bipartite){
                for(int i = 1 ; i <= n ; ++i){
                        cout << color[i] + 1 << ' ';
                }
        }else{
                cout << "IMPOSSIBLE";
        }
        return 0;
}
