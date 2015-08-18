class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            const int g=target-nums[i];
            if(m.find(g)!=m.end()&&m[g]>i){
                result.push_back(i+1);
                result.push_back(m[g]+1);
                break;
            }
        }
        return result;
    }
};
