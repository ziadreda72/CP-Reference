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
