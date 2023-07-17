struct segtree {
        int sz;
        vector < i64 > sums;

        void init(int n){
                sz = 1;
                while (sz < n)
                        sz *= 2;
                sums.assign(2 * sz , 0LL);
        }

        void build(vector < int > &a , int x , int lx , int rx){
                if(rx - lx == 1){
                        if (lx < (int) a.size())
                                sums[x] = a[lx];
                        return;
                }
                int m = (lx + rx) / 2;
                build(a , 2 * x + 1 , lx , m);
                build(a , 2 * x + 2 , m , rx);
                sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        }

        void build(vector < int > &a){
                build(a , 0 , 0 , sz);
        }

        void update(int i , int v , int x , int lx , int rx){
                if(rx - lx == 1){
                        sums[x] = v;
                        return;
                }
                int m = (lx + rx) / 2;
                if(i < m)
                        update(i, v, 2 * x + 1, lx, m);
                else
                        update(i, v, 2 * x + 2, m, rx);
                sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        }

        void update(int i , int v){
                update(i, v, 0, 0, sz);
        }

        i64 get(int l , int r , int x , int lx , int rx){
                if(lx >= r || l >= rx)
                        return 0;
                if(l <= lx && rx <= r)
                        return sums[x];
                int m = (lx + rx) / 2;
                return get(l , r , 2 * x + 1 , lx , m) + get(l , r , 2 * x + 2 , m , rx);
        }

        i64 get(int l , int r){
                return get(l , r , 0 , 0 , sz);
        }
};
