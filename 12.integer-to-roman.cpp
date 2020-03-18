/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        vector<int> values={1000,900,500,400,100,90,50,40,10,9,5,4,1}; 
        vector<string> strs={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        for  (int i=0;i<values.size();i++){
            while (num>=values[i]){
                res+=strs[i];
                num-=values[i];
            }
        }
        return res;


    }
};
// @lc code=end

/*将数字和罗马数字一一对应，然后循环解决   符合贪心算法的策略