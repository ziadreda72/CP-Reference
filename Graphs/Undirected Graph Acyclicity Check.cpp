/*
 * Checking a undirected graph acyclicity
 * Time: O(m)
*/

vector < bool > vis;

bool dfs_undirected(int u , int p){
        vis[u] = 1;
        for(int v : g[u]){
                if(v == p)
                        continue;
                if(vis[v]){
                        cycle_start = v;
                        cycle_end = u;
                        return true;
                }
                par[v] = u;
                if(dfs_undirected(v , u))
                        return true;
        }
        return false;
}
