#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = 20;

int n;
vector < int > a , b;
i64 dp[MAX][2][2];
int dif;

i64 solve(int i , bool f1 , bool f2){
        if(i >= n){
                return 1;
        }

        auto &ret = dp[i][f1][f2];
        if(ret != -1){
                return ret;
        }

        ret = -1;

        int lo = f1 ? 0 : a[i] , hi = f2 ? 9 : b[i];
        for(int d = lo ; d <= hi ; ++d){
                int x = (d == 0 && i < dif ? 1 : d);
                ret = max(ret , 1LL * solve(i + 1 , f1 | (d > a[i]) , f2 | (d < b[i])) * x);
        }

        return ret;
}

void trace(int i , bool f1 , bool f2){
        if(i >= n){
                return;
        }

        auto opt = solve(i , f1 , f2);

        int lo = f1 ? 0 : a[i] , hi = f2 ? 9 : b[i];
        for(int d = lo ; d <= hi ; ++d){
                int x = (d == 0 && i < dif ? 1 : d);
                if((1LL * solve(i + 1 , f1 | (d > a[i]) , f2 | (d < b[i])) * x) == opt){
                        if(i >= dif || d > 0){
                                cout << d;
                        }
                        trace(i + 1 , f1 | (d > a[i]) , f2 | (d < b[i]));
                        return;
                }
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 x , y;
        cin >> x >> y;

        while(x){
                a.push_back(x % 10);
                x /= 10;
        }

        while(y){
                b.push_back(y % 10);
                y /= 10;
        }

        dif = b.size() - a.size();
        while(a.size() < b.size()) a.push_back(0);
        n = (int) a.size();
        
        reverse(a.begin() , a.end());
        reverse(b.begin() , b.end());

        memset(dp , -1 , sizeof dp);

        solve(0 , 0 , 0);
        trace(0 , 0 , 0);

        return 0;
}
