class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates,int target){
    vector<vector<int>> result;
    if(candidates.size()==0)//empty
        return  result;
    for(auto i:candidates)
        if(i<=0) return result;//has negative integer
    sort(candidates.begin(),candidates.end());
    if(target<candidates[0])
        return result;
    int h=upper_bound(candidates.begin(),candidates.end(),target)-candidates.begin()-1;
    vector<int> tempResult;
    findSolution2(target,candidates,tempResult,result,0,h);
}

void findSolution2(int target,const vector<int>& candidates,vector<int>&tempResult,vector<vector<int>>&result,int l,int h){
    if(target==0){result.push_back(tempResult); return;}
    if(target<0||l>h) return;
    for(int i=l;i<=h;){
        tempResult.push_back(candidates[i]);
        int newTarget=target-candidates[i];
        int l=i+1;
        int h=upper_bound(candidates.begin(),candidates.end(),newTarget)-candidates.begin()-1;
        findSolution2(newTarget,candidates,tempResult,result,l,h);
        tempResult.pop_back();
        i=upper_bound(candidates.begin(),candidates.end(),candidates[i])-candidates.begin();
    }
}
};

/*
vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);//递归，找到和为target的所有组合
        //auto end_unique = unique(res.begin(),res.end());
        //res.erase(end_unique,res.end());
        return res;
}
private:
    void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
        if  (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i];++i) {//每循环一次结束，combination置0
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i+1);
            combination.pop_back();
            while(candidates[i]==candidates[i+1]) i++;
        }
    }
*/
