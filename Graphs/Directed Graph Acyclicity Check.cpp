/*
 * Checking a directed graph acyclicity
 * Time: O(m)
*/

int n;
vector < vector < int > > g;
vector < int > color , par;
int cycle_start , cycle_end;

bool dfs_directed(int u){
        color[u] = 1;
        for(int v : g[u]){
                if(color[v] == 0){
                        par[v] = u;
                        if(dfs_directed(v))
                                return true;
                }
                else if(color[v] == 1){
                        cycle_start = v;
                        cycle_end = u;
                        return true;
                }
        }
        color[u] = 2;
        return false;
}


void find_cycle(){
        color.assign(n + 5 , 0);
        par.assign(n + 5 , -1);
        cycle_start = -1;
        for(int i = 1 ; i <= n ; ++i){
                if(color[i] == 0 && dfs_directed(i))
                        break;
        }
        if(cycle_start == -1){
                cout << "Acyclic\n";
        }
        else{
                vector < int > cycle;
                for(int i = cycle_end ; i != cycle_start ; i = par[i])
                        cycle.push_back(i);
                cycle.push_back(cycle_start);
                reverse(cycle.begin() , cycle.end());
                for(auto x : cycle)
                        cout << x << ' ';
                cout << '\n';
        }
}
