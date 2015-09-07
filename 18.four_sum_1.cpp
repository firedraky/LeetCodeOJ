vector<vector<int>> fourSum(vector<int>&num,int target){
    vector<vector<int>> result;
    if (num.size()<4) return result;
    sort(num.begin(),num.end());
    unordered_multimap<int,pair<int,int>> cache;
    for (int i = 0; i < num.size(); ++i) {
        for (int j = i+1; j < num.size(); ++j) {
            cache.insert(make_pair(num[i]+num[j],make_pair(i,j)));
        }
    }

    for(auto i=cache.begin();i!=cache.end();++i){
        int x=target - i->first;
        auto range=cache.equal_range(x);
        for (auto j = range.first;j!=range.second; ++j) {
            auto a=i->second.first;
            auto b=i->second.second;
            auto c=j->second.first;
            auto d=j->second.second;
            if(a!=c&&a!=d&&b!=c&&b!=d){
                vector<int> vec{num[a],num[b],num[c],num[d]};
                sort(vec.begin(),vec.end());
                result.push_back(vec);
            }
        }
    }
    sort(result.begin(),result.end());
    result.erase(unique(result.begin(),result.end()),result.end());
    return result;
}
/*
vector<vector<int>> fourSum(vector<int>&num,int target){
    vector<vector<int>> result;
    if(num.size()<4)return result;

    sort(num.begin(),num.end());
    unordered_map<int,vector<pair<int,int>>>cache;
    for (int i = 0; i <num.size()-1; ++i) {
        for (int j = i+1; j <num.size() ; ++j) {
            cache[num[i]+num[j]].push_back(make_pair(i,j));
        }
    }
    for (int i = 0; i <num.size()-1; ++i) {
        for (int j = i+1; j <num.size() ; ++j) {
            const int key=target-num[i]-num[j];
            if(cache.find(key)==cache.end())
                continue;
            const auto& vec=cache[key];
            for(int k=0;k<vec.size();++k){
                if(i<=vec[k].second)
                    continue;
                result.push_back({num[vec[k].first],num[vec[k].second],num[i],num[j]});
            }
        }
    }
    sort(result.begin(),result.end());
    result.erase(unique(result.begin(),result.end()),result.end());
    return result;
}

vector<vector<int>> fourSum(vector<int>&num,int target){
    vector<vector<int>> result;
    if (num.size()<4) return result;
    sort(num.begin(),num.end());
    unordered_multimap<int,pair<int,int>> cache;
    for (int i = 0; i < num.size()-1; ++i) {
        for (int j = i+1; j < num.size(); ++j) {
            cache.insert(make_pair(num[i]+num[j],make_pair(i,j)));
        }
    }

    for(auto i=cache.begin();i!=cache.end();++i){
        int x=target - i->first;
        auto range=cache.equal_range(x);
        for (auto j = range.first;j!=range.second; ++j) {
            auto a=i->second.first;
            auto b=i->second.second;
            //a<b => num[a]<=num[b]
            auto c=j->second.first;
            auto d=j->second.second;
            //c<d
            if(c<=b) continue;
            vector<int> vec{num[a],num[b],num[c],num[d]};
            result.push_back(vec);
        }
    }
    sort(result.begin(),result.end());
    result.erase(unique(result.begin(),result.end()),result.end());
    return result;
}*/
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>  result;
        if(nums.size() < 4) return result;

        vector<int> solution(4,0);
        std::sort(nums.begin(),nums.end());
        int sum,a,b,c,d,Max_d_when_a_increase = nums.size() - 1,Max_d_when_b_increase;

        //a,b,c,d are the four index
        //Max_d_when_a_increase is the max possible d when a increase. To have the same sum, when a increase, d can only decrease
        //Max_d_when_b_increase is the max possible d when b increase

        for( a = 0; a < Max_d_when_a_increase - 2;a++ )
        {
            //remove dupilcate & do pruning if a too small or too big
            if((a>0 && nums[a] == nums[a-1])
            || nums[a] + nums[Max_d_when_a_increase] + nums[Max_d_when_a_increase-1] + nums[Max_d_when_a_increase-2] < target) continue;
            if(nums[a]+nums[a+1]+nums[a+2]+nums[a+3] > target) break;            

            //update Max_d_when_a_increase
            sum = nums[a]+nums[a+1]+nums[a+2];
            while(sum+nums[Max_d_when_a_increase] > target)Max_d_when_a_increase--;
            Max_d_when_b_increase = Max_d_when_a_increase;

            solution[0] = nums[a];
            for( b=a+1; b < Max_d_when_b_increase - 1;b++)
            {
                //remove dupilcate & do pruning if b too small or too big
                if((b>a+1 && nums[b] == nums[b-1])
                || nums[a] + nums[b] + nums[Max_d_when_b_increase-1] + nums[Max_d_when_b_increase] < target) continue;
                sum = nums[a] + nums[b]+nums[b+1];
                if(sum + nums[b+2] > target) break;

                //update Max_d_when_b_increase
                while(sum+nums[Max_d_when_b_increase]>target) Max_d_when_b_increase--;

                solution[1] = nums[b];
                c = b+1;
                d = Max_d_when_b_increase;
                sum = nums[a] + nums[b];
                while(c < d)//this are the same as two sum
                    if(sum + nums[c] + nums[d] == target)
                    {
                        solution[2]=nums[c];
                        solution[3]=nums[d];
                        result.push_back(solution);

                        do{c++;}while(c < d && nums[c] == nums[c-1]);
                        do{d--;}while(c < d && nums[d] == nums[d+1]);
                    }
                    else if(sum + nums[c] + nums[d] < target) 
                        do{c++;}while(c < d && nums[c] == nums[c-1]);
                    else do{d--;}while(c < d && nums[d] == nums[d+1]);
            }
        }
        return result;
    }
