/*
 * Algorithm: Sieve of Eratosthenes
 * Time Complexity: O(nloglogn)
 * Space Complexity: O(n)
 * Upper Bound: ~115e6 works in (982ms & 14MB)
*/

const int N = 115e6;

vector < bool > is_prime(N , 1);
vector < int > pr;

void sieve(){
          is_prime[0] = is_prime[1] = 0;
          for (int i = 4; i <= N; i += 2) {
                    is_prime[i] = 0;
          }
          pr.push_back(2);
          for (int i = 3; i * i <= N; i += 2) {
                    if(is_prime[i]){
                              pr.push_back(i);
                              for (int j = i * i; j <= N; j += i) {
                                        is_prime[j] = 0;
                              }
                    }
          }
}
