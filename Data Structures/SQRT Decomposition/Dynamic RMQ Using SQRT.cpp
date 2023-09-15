#include "bits/stdc++.h"

using namespace std;

const int INF = INT_MAX;

int SQRT(int x){
        int lo = 0 , hi = 1;
        while(hi * hi <= x) hi <<= 1;

        while(hi - lo > 1){
                int mid = (lo + hi) >> 1;
                if(mid * mid >= x){
                        hi = mid;
                }else{
                        lo = mid;
                }
        }

        return hi;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n , q;
        cin >> n >> q;

        int B = SQRT(n);
        vector < int > a(n) , b(B , INF);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                b[i / B] = min(b[i / B] , a[i]);
        }

        while(q--){
                int t;
                cin >> t;

                if(t == 1){
                        int i , x;
                        cin >> i >> x;
                        --i;
                        int k = i / B;
                        a[i] = x;
                        b[k] = INF;
                        for(int i = k * B ; i < (k + 1) * B ; ++i){
                                b[k] = min(b[k] , a[i]);
                        }
                }else{
                        int l , r;
                        cin >> l >> r;
                        --l , --r;
                        int ans = INF;
                        for(int i = l ; i <= r ;){
                                if(i % B == 0 && i + B - 1 <= r){
                                        ans = min(ans , b[i / B]);
                                        i += B;
                                }else{
                                        ans = min(ans , a[i++]);
                                }
                        }
                        cout << ans << '\n';
                }
        }
}
