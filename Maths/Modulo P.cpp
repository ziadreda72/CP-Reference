const int P = (int) 1e9 + 7;

int add(int a , int b){
          return (1LL * ((a % P) + (b % P))) % P;
}

int mul(int a , int b){
          return (1LL * ((a % P) * (b % P))) % P;
}

int sub(int a , int b){
          return ((a % P) - (b % P) + P) % P;
}

int POW(int a , int b){
          int ret = 1;
          while (b){
                    if(b & 1)
                              ret = mul(ret , a);
                    a = mul(a , a);
                    b >>= 1;
          }
          return ret;
}

int divide(int a , int b){
          return mul(a , POW(b , P - 2));
}
