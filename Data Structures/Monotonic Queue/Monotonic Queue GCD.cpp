struct MonotonicQueueGCD{
        stack < array < int , 2 > > s1 , s2;

        bool empty(){
                return s1.empty() && s2.empty();
        }

        void add(int x){
                int g = s1.empty() ? x : gcd(x , s1.top()[1]);
                s1.push({x , g});
        }

        int remove(){
                if(s2.empty()){
                        while(!s1.empty()){
                                int x = s1.top()[0];
                                s1.pop();

                                int g = s2.empty() ? x : gcd(x , s2.top()[1]);
                                s2.push({x , g});
                        }
                }
                int x = s2.top()[0];
                s2.pop();
                return x;
        }

        int find_gcd(){
                if(s1.empty() || s2.empty()){
                        return s1.empty() ? s2.top()[1] : s1.top()[1];
                }else{
                        return gcd(s1.top()[1] , s2.top()[1]);
                }
        }
};
