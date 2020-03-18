/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set <char> temp;
        int b=s.size();
        int c=0,max=0;
        int i=0;
        while(i<b){
            if (temp.count(s[i])==0){
                temp.insert(s[i]);
                c++;
                i++;
            }
            else {
                if (c>max)  max=c;
                temp.clear();
                i=i-c+1;
                c=0;
            }
        }
        if (c>max)  max=c;
        return max;
                
          
    }
};
/*方法一 滑动窗口法 这种原始的滑动窗口法的问题在于每一次遇到重复元素以后都需要清空temp 
但实际上不需要清空 只需要将最左边的元素删去  具体实现见方法二 */
if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
    }
        return maxStr;

