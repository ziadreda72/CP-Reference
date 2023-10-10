#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int MOD = (int) 1e9 + 7;

        int N;
        cin >> N;
        
        vector a(N , vector < int > (N));
        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j < N ; ++j){
                        cin >> a[i][j];
                }
        }

        vector < i64 > dp(1 << N);
        dp[0] = 1;
        for(int msk = 0 ; msk < (1 << N) ; ++msk){
                int i = __builtin_popcount(msk);
                for(int j = 0 ; j < N ; ++j){
                        if((msk >> j) & 1 || a[i][j] == 0) continue;
                        int new_msk = msk | (1 << j);
                        dp[new_msk] += dp[msk];
                        dp[new_msk] %= MOD;
                }
        }

        cout << dp.back();

        return 0;
}
