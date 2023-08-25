/*
 * Simple dfs implementation using only visited array
*/

const int N = 5005;

vector < int > g[N];
bool vis[N];

void dfs(int u){
        vis[u] = 1;
        for(int v : g[u]){
                if(vis[v])
                        continue;
                dfs(v);
        }
}

-----------------------------------------------------

/*
 * More general implementation using color array and entry-exit time arrays
*/

const int N = 5005;

vector < int > g[N];
int color[N] , time_in[N] , time_out[N];
int dfs_timer = 0;

void dfs(int u){
        time_in[u] = dfs_timer++;
        color[u] = 1;
        for(int v : g[u]){
                if(color[v] == 0)
                        dfs(v);
        }
        color[u] = 2;
        time_out[u] = dfs_timer++;
}
