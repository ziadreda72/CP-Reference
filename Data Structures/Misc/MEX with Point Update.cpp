#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Mex{
        private:
                map < int , int > freq;
                set < int > missing;
                vector < int > A;

        public:
                Mex(vector < int > &A): A(A){
                        for(int i = 0 ; i <= (int) A.size() ; ++i){
                                missing.insert(i);
                        }

                        for(auto x : A){
                                ++freq[x];

                                if(missing.count(x)){
                                        missing.erase(x);
                                }
                        }
                }

                int get_mex(){
                        return *missing.begin();
                }        

                void update(int idx , int new_val){
                        if(--freq[A[idx]] == 0){
                                missing.insert(A[idx]);
                        }

                        A[idx] = new_val;
                        ++freq[new_val];

                        if(missing.count(new_val)){
                                missing.erase(new_val);
                        }
                }
};

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , Q;
        cin >> N >> Q;

        vector < int > A(N);
        for(int i = 0 ; i < N ; ++i) cin >> A[i];

        Mex mex(A);

        while(Q--){
                int idx , new_val;
                cin >> idx >> new_val;

                mex.update(--idx , new_val);

                cout << mex.get_mex() << '\n';
        }

        return 0;
}
