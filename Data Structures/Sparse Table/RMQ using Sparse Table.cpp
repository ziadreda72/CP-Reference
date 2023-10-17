#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAXN = 2E5 , LOG = 25;

int st[LOG + 1][MAXN + 5] , lg[MAXN + 5];

int RMQ(int L , int R){
        int i = lg[R - L + 1];
        return min(st[i][L] , st[i][R - (1 << i) + 1]);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        lg[1] = 0;
        for(int i = 2 ; i <= MAXN ; ++i){
                lg[i] = lg[i / 2] + 1;
        }

        int n , q;
        cin >> n >> q;

        for(int i = 0 ; i < n ; ++i){
                cin >> st[0][i];
        }

        for(int i = 1 ; i <= LOG ; ++i){
                for(int j = 0 ; j + (1 << i) - 1 < n ; ++j){
                        st[i][j] = min(st[i - 1][j] , st[i - 1][j + (1 << (i - 1))]);
                }
        }

        while(q--){
                int l , r;
                cin >> l >> r;
                cout << RMQ(--l , --r) << '\n';
        }

        return 0;
}
