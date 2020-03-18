/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        int temp = 0;
        while(n!=0)
        {
            temp = n%26;
            if(temp==0)
            {
                  res = 'Z' +res;
                 n--;
            }else
                res =(char)(temp+'A'-1) + res;
            n = n/26;
        }
        return res;
    }

};

