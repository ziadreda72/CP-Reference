const int N = 5005 , INF = (int) 1e8;

int n;
vector < int > g[N];

void bfs(int src){
        queue < int > q;
        vector < int > d(n + 1 , INF);
        vector < int > par(n + 1 , -1);

        q.push(src);
        d[src] = 0;
        while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v : g[u]){
                        if(d[u] + 1 < d[v]){
                                q.push(v);
                                d[v] = d[u] + 1;
                                par[v] = u;
                        }
                }
        }
}
