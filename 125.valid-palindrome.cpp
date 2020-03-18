/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<=1) return true;
        int i=0,j=s.size()-1;
        while(i<j){
            while(i<j && !isalnum(s[i]))
            i++;
            while(i<j && !isalnum(s[j]))
            j--;
            if(tolower(s[i++])!=tolower(s[j--]))
            return false;

        }
        return true;
    }
};
/*双指针， 如果遇到非字母和数字则跳过，否则判断是否相等，在判断后需要注意将
i++，j--，以便while循环继续进行*/
