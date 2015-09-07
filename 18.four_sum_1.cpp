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
