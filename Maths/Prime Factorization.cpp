/*
 * Algorithm: Prime Factorization
 * Time Complexity: O(sqrt(n))
 * Space Complexity: O(log(n))
*/

vector < i64 > getPrFact(i64 n){
        vector < i64 > ret;
        for(int d : {2 , 3 , 5}){
                while (n % d == 0){
                        ret.push_back(d);
                        n /= d;
                }
        }
        static array < int , 8 > inc = {4 , 2 , 4 , 2 , 4 , 6 , 2 , 6};
        int i = 0;
        for (i64 d = 7; d * d <= n; d += inc[i++]) {
                while (n % d == 0){
                        ret.push_back(d);
                        n /= d;
                }
                if(i == 8)
                        i = 0;
        }
        if(n > 1)
                ret.push_back(n);
        return ret;
}
