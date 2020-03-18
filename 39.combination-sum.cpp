/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (47.18%)
 * Total Accepted:    318.8K
 * Total Submissions: 673.3K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>> res;
        if(candidates.size() == 0) return res;
        vector<int> re;
        DFS(candidates,res,re,target,0,0);
        return res;
    }
    void DFS(vector<int>& candidates,vector<vector<int>>& res,vector<int>& re,int target,int sum,int start){
        // cout<<"当前sum为:  "<<sum<<endl;
        if(sum > target){
            return;
        }else if(sum == target){
            res.push_back(re);
            return;
        }else{
            for(int i = start;i<candidates.size();i++){
                // cout<<"re中push了  "<<candidates[i]<<endl;
                re.push_back(candidates[i]);
                DFS(candidates,res,re,target,sum+candidates[i],i);
                re.pop_back();
            }
        }
    }
};

