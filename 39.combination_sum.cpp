void combinationSumHelper(vector<vector<int>>& result, vector<int>& candidates, 
                          int right, int target, vector<int>& partResult)
{
    int upperBound = upper_bound(candidates.begin(), candidates.begin() + right, target) - candidates.begin() - 1;
    if (upperBound < 0) return;

    for (int i = upperBound; i >= 0; i--)  // upper bound is to prevent duplicate solution && less computation
    {
        int newTarget = target - candidates.at(i);
        partResult.push_back(candidates.at(i));
        if (newTarget == 0)
        {
            result.push_back(partResult);
            partResult.pop_back();
            continue;
        }
        combinationSumHelper(result, candidates, i+1, newTarget, partResult);
        partResult.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> result;
    if (candidates.empty()) return result;

    sort(candidates.begin(), candidates.end());

    vector<int> partResult;
    combinationSumHelper(result, candidates, candidates.size(), target, partResult);
    for (auto& r : result)
        reverse(r.begin(), r.end());  // I didn't backtrack but recursed straightly. so I have to reverse.
    return result;
}

/*
void findSolution(int target,const vector<int>& candidates,vector<int>& temp,vector<vector<int>>& result,int l,int h){
    if(target==0){result.push_back(temp);return;}
    if(l>h||target<0){ return;}
    for (int i = l; i <=h ; ++i) {
        temp.push_back(candidates[i]);
        findSolution(target-candidates[i],candidates,temp,result,i,h);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> result;
    if(candidates.size()==0)//empty
        return  result;
    for(auto i:candidates)
        if(i<=0) return result;//has negative integer
    sort(candidates.begin(),candidates.end());
    candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());//delete the duplicate nums
    if(target<candidates[0])//too small
        return  result;
    vector<int> tempResult;
    findSolution(target,candidates,tempResult,result,0,candidates.size()-1);
    return result;
}
*/
