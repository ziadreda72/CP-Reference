struct MonotonicQueueMax{
        stack < array < int , 2 > > s1 , s2;

        void add(int x){
                int mx = s1.empty() ? x : max(x , s1.top()[1]);
                s1.push({x , mx});
        }

        void remove(){
                if(s2.empty()){
                        while(!s1.empty()){
                                int x = s1.top()[0];
                                s1.pop();

                                int mx = s2.empty() ? x : max(x , s2.top()[1]);
                                s2.push({x , mx});
                        }
                }
                s2.pop();
        }

        int find_max(){
                if(s1.empty() || s2.empty()){
                        return s1.empty() ? s2.top()[1] : s1.top()[1];
                }else{
                        return max(s1.top()[1] , s2.top()[1]);
                }
        }
};
