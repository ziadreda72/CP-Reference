#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int N;
vector < int > L , R;
i64 dp[20][2][2][5];

i64 solve(int i , int f1 , int f2 , int cnt){
        if(i >= N){
                return 1;
        }

        auto &ret = dp[i][f1][f2][cnt];
        if(ret != -1){
                return ret;
        }

        ret = 0;
        int lo = f1 ? 0 : L[i] , hi = f2 ? 9 : R[i];
        for(int d = lo ; d <= hi ; ++d){
                if(cnt + (d > 0) <= 3){
                        ret += solve(i + 1 , f1 | (d > L[i]) , f2 | (d < R[i]) , cnt + (d > 0));
                }
        }

        return ret;
}

void solveTC(){
        L.clear();
        R.clear();
        memset(dp , -1 , sizeof dp);

        i64 l , r;
        cin >> l >> r;

        while(r){
                R.push_back(r % 10);
                r /= 10;
        }

        while(l){
                L.push_back(l % 10);
                l /= 10;
        }

        while(L.size() < R.size()) L.push_back(0);

        reverse(L.begin() , L.end());
        reverse(R.begin() , R.end());
        N = (int) L.size();

        cout << solve(0 , 0 , 0 , 0);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
