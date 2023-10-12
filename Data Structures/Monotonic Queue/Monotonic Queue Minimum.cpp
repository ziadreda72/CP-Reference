struct MonotonicQueueMin{
        stack < array < int , 2 > > s1 , s2;

        void add(int x){
                int mn = s1.empty() ? x : min(x , s1.top()[1]);
                s1.push({x , mn});
        }

        void remove(){
                if(s2.empty()){
                        while(!s1.empty()){
                                int x = s1.top()[0];
                                s1.pop();

                                int mn = s2.empty() ? x : min(x , s2.top()[1]);
                                s2.push({x , mn});
                        }
                }
                s2.pop();
        }

        int find_min(){
                if(s1.empty() || s2.empty()){
                        return s1.empty() ? s2.top()[1] : s1.top()[1];
                }else{
                        return min(s1.top()[1] , s2.top()[1]);
                }
        }
};
