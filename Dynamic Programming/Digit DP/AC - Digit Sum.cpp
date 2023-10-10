#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = (int) 1e9 + 7 , MAX = (int) 1e4 + 10;

int add(int x , int y){
        x %= MOD;
        y %= MOD;
        return (x + y) % MOD;
}

int N , D;
vector < int > a;
int dp[MAX][2][105];

int solve(int i , int f , int sum){
        if(i >= N){
                return sum == 0;
        }

        auto &ret = dp[i][f][sum];
        if(~ret){
                return ret;
        }

        ret = 0;

        int LIM = f ? 9 : a[i];
        for(int d = 0 ; d <= LIM ; ++d){
                ret = add(ret , solve(i + 1 , f | (d < a[i]) , (sum + d) % D));
        }

        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string K;
        cin >> K >> D;

        for(auto c : K) a.push_back(c - '0');
        N = (int) a.size();

        memset(dp , -1 , sizeof dp);

        cout << ((solve(0 , 0 , 0) - 1 + MOD) % MOD);

        return 0;
}
