#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAXN = 2E5 + 5 , LOG = 25;

int st[LOG + 1][MAXN]; // Sparse Table for Range XOR

int RXQ(int L , int R){
        // This function returns Range XOR Query from L to R in O(LOG) 

        int ret = 0;

        for(int i = LOG ; i >= 0 ; --i){
                if((1 << i) <= (R - L + 1)){
                        ret ^= st[i][L];
                        L += (1 << i);
                }
        }

        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n , q;
        cin >> n >> q;

        for(int i = 0 ; i < n ; ++i){
                cin >> st[0][i];
        }

        for(int i = 1 ; i <= LOG ; ++i){
                for(int j = 0 ; j + (1 << i) - 1 < n ; ++j){
                        st[i][j] = st[i - 1][j] ^ st[i - 1][j + (1 << (i - 1))];
                }
        }

        while(q--){
                int l , r;
                cin >> l >> r;
                cout << RXQ(--l , --r) << '\n';
        }

        return 0;
}
