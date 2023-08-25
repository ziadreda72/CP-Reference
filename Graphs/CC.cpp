/*
 * Finding connected components using dfs
 * Time: O(n + m)
*/

const int N = 5005;

int n;
vector < int > g[N];
bool vis[N];
vector < int > comp;

void dfs(int u){
        vis[u] = 1;
        comp.push_back(u);
        for(int v : g[u]){
                if(vis[v])
                        continue;
                dfs(v);
        }
}

void CC(){
        int cnt = 0;
        for(int i = 1 ; i <= n ; ++i){
                if(vis[i])
                        continue;
                comp.clear();
                dfs(i);
                cout << "Component #" << ++cnt << ":\n";
                for(auto x : comp)
                        cout << x << ' ';
                cout << '\n';
        }
}
