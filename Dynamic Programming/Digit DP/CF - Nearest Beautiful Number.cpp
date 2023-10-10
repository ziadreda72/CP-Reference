#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = 10;
const i64 INF = (i64) 1e14;

int n , k;
vector < int > a;
i64 dp[MAX][2][1 << MAX] , pw[15] , cnt[1 << MAX];
int vis[MAX][2][1 << MAX] , id;
int idx;

i64 solve(int i , bool f , int msk){
        if(i >= MAX || cnt[msk] > k){
                return 1LL * INF * (cnt[msk] > k);
        }

        auto &ret = dp[i][f][msk];
        if(vis[i][f][msk] == id){
                return ret;
        }
        vis[i][f][msk] = id;

        ret = INF;
        for(int d = (f ? 0 : a[i]) ; d <= 9 ; ++d){
                i64 x = 1LL * d * pw[MAX - 1 - i];
                bool new_f = f | (d > a[i]);
                int new_msk = msk | (1 << d);
                if(d == 0 && i < idx){
                        new_msk = msk;
                }
                ret = min(ret , solve(i + 1 , new_f , new_msk) + x);
                if(ret < INF) break;
        }

        return ret;
}

void solveTC(){
        a.clear();

        cin >> n >> k;

        while(n){
                a.push_back(n % 10);
                n /= 10;
        }

        while(a.size() < MAX) a.push_back(0);
        reverse(a.begin() , a.end());

        idx = -1;
        for(int i = 0 ; i < MAX ; ++i){
                if(a[i] > 0){
                        idx = i;
                        break;
                }
        }

        id++;
        cout << solve(0 , 0 , 0);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        for(int msk = 0 ; msk < (1 << MAX) ; ++msk){
                cnt[msk] = __builtin_popcount(msk);
        }

        pw[0] = 1;
        for(int i = 1 ; i < 15 ; ++i) pw[i] = 1LL * pw[i - 1] * 10;

        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
