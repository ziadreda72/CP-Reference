#include <bits/stdc++.h>

using std::cout;
using std::vector;
using std::reverse;

const int N = (int) 2e5 + 5; // Maximum number of vertices in our graph

int n; // number of vertices
int m; // number of edges
vector < int > g[N]; // adjacency list
vector < int > color(N , 0); // 0: not visited yet , 1: visited but not exit , 2: visited and exit
vector < int > par(N , -1); // to keep track the parent of each vertex
int st; // the vertex where the cycle starts
int en; // the vertex where the cycle ends

// checking acyclicity using a single dfs call for each component in the graph
bool dfs(int u){
        color[u] = 1; // entering the vertex
        for(auto v : g[u]){
                if(color[v] == 0){ // the neighboring vertex is not visited yet
                        par[v] = u; // parent of vertex v is u
                        if(dfs(v)){ // the next recursive calls found a cycle, no need to continue
                                return true;
                        }
                }else if(color[v] == 1){ // the neighboring is visited but not exit, means it forms a cycle
                        st = v; // the cycle starting vertex is v, as we started dfs from it and returned back
                        en = u; // the cycle ending vertex is u, as it returns to the starting vertex again
                        return true; // cycle found, no need to continue the search
                }
        }
        // we exit the vertex, it means there is no cycle from this path
        color[u] = 2;
        return false;
}

void find_cycle(){
        st = -1;
        for (int v = 1; v <= n; ++v) {
                if(color[v] == 0 && dfs(v)){ // the component that contains v is cyclic
                        break; // cycle found, no need to continue
                }
        }
        if(st == -1){ // no cycle found in the graph
                cout << "Acyclic Graph";
        }else{ // cycle found, and we will print the cycle using the parent array
                vector < int > cycle; // the array where we will store the cycle
                for (int v = en;; v = par[v]) { // iterate from the ending vertex until we reach the starting vertex
                        cycle.push_back(v);
                        if(v == st){
                                break;
                        }
                }
                reverse(cycle.begin(), cycle.end()); // // we need to reverse the cycle array, as we added vertices from end to start
                cout << "Cycle Found: " << '\n';
                for(auto v : cycle){ // print the cycle
                        cout << v << ' ';
                }
        }
}
