/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.07%)
 * Total Accepted:    539.5K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        bool flag=true;
        while(s.size()!=0 && flag)
        {
            int pos;
            if((pos=s.find("()"))!=string::npos || 
               (pos=s.find("{}"))!=string::npos || 
               (pos=s.find("[]"))!=string::npos)
                s.erase(s.begin()+pos,s.begin()+pos+2);
            else
                flag=false;
        }
        return flag;
    }
};

/* npos是find函数寻找失败后返回的值 下面贴出一个find函数的实例
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s = "helllo";
    if (s.find("e") == string::npos)  //yes
        cout << "no" << endl;
    else
        cout << "yes" << endl;

    if (s.find("z") == string::npos)  //no
        cout << "no" << endl;
    else
        cout << "yes" << endl;
}