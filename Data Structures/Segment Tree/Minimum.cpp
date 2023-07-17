struct segtree {
        int sz;
        vector < int > mn;

        void init(int n){
                sz = 1;
                while (sz < n)
                        sz *= 2;
                mn.assign(2 * sz , INT32_MAX);
        }

        void build(vector < int > &a , int x , int lx , int rx){
                if(rx - lx == 1){
                        if (lx < (int) a.size())
                                mn[x] = a[lx];
                        return;
                }
                int m = (lx + rx) / 2;
                build(a , 2 * x + 1 , lx , m);
                build(a , 2 * x + 2 , m , rx);
                mn[x] = min(mn[2 * x + 1] , mn[2 * x + 2]);
        }

        void build(vector < int > &a){
                build(a , 0 , 0 , sz);
        }

        void update(int i , int v , int x , int lx , int rx){
                if(rx - lx == 1){
                        mn[x] = v;
                        return;
                }
                int m = (lx + rx) / 2;
                if(i < m)
                        update(i, v, 2 * x + 1, lx, m);
                else
                        update(i, v, 2 * x + 2, m, rx);
                mn[x] = min(mn[2 * x + 1] , mn[2 * x + 2]);
        }

        void update(int i , int v){
                update(i, v, 0, 0, sz);
        }

        int get(int l , int r , int x , int lx , int rx){
                if(lx >= r || l >= rx)
                        return INT32_MAX;
                if(l <= lx && rx <= r)
                        return mn[x];
                int m = (lx + rx) / 2;
                return min(get(l , r , 2 * x + 1 , lx , m) , get(l , r , 2 * x + 2 , m , rx));
        }

        int get(int l , int r){
                return get(l , r , 0 , 0 , sz);
        }
};
