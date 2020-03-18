#
# @lc app=leetcode id=125 lang=python3
#
# [125] Valid Palindrome
#
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s=s.lower()
        if len(s)<=1:
            return False
        i=0,j=len(s)-1
        while i<j:
            while i<j and not s[i].isalnum():
                i=i+1
            while i<j and not s[j].isalnum():
                j=j+1
            if s[j]!=s[i]:
                return False
        return True


'''解法类似于c++解法 遇到数字和空格就跳过 s.lower 将所有字母都转为小写