const int MOD = (int) 1e9 + 7 , MAX = 2e6 + 5;

i64 POW(i64 a , i64 b){
        i64 ret = 1;
        while(b){
                if(b & 1){
                        ret = (ret * a) % MOD;
                }

                a = (a * a) % MOD;

                b >>= 1;
        }
        return ret;
}

i64 mod_inv(i64 a){
        return POW(a , MOD - 2);
}

i64 fact[MAX] , fact_inv[MAX];

void pre(){
        fact[0] = fact_inv[0] = 1;
        for(int i = 1 ; i < MAX ; ++i){
                fact[i] = (fact[i - 1] * i) % MOD;
                fact_inv[i] = mod_inv(fact[i]);
        }
}

i64 P(i64 n , i64 r){
        if(r > n) return 0;
        return fact[n] * fact_inv[n - r] % MOD;
}

i64 C(i64 n , i64 r){
        if(n == 0) return r == 0;
        if(r > n) return 0;
        return fact[n] * (fact_inv[n - r] * fact_inv[r] % MOD) % MOD;
}
