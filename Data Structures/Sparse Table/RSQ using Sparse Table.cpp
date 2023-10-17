#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAXN = 2E5 , LOG = 25;

i64 st[LOG + 1][MAXN]; // Sparse Table for Range Sum

i64 RSQ(int L , int R){
        // This function returns range sum query from L to R in O(LOG)

        i64 ret = 0;

        for(int i = LOG ; i >= 0 ; --i){
                if((1 << i) <= (R - L + 1)){
                        ret += st[i][L]; // sum of interval of length 2^i starting from L
                        L += 1 << i; // decrease the length of the interval by 2^i
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
                cin >> st[0][i]; // a[i] is the sum of range of length 2^0 starting from i
        }

        for(int i = 1 ; i <= LOG ; ++i){
                for(int j = 0 ; j + (1 << i) <= n ; ++j){
                        st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
                }
        }

        while(q--){
                int l , r;
                cin >> l >> r;
                cout << RSQ(--l , --r) << '\n';
        }

        return 0;
}
