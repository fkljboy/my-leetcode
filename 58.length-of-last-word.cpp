/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.18%)
 * Total Accepted:    253.1K
 * Total Submissions: 786.3K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        bool flag = false;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                flag = true;
                ret++;
            } else {
                if (flag) {
                    break;
                }
            }
        }
        return ret;
    }
};
/* 这道题有很多种解决方法 简单一点的可以考虑用相关的函数吧整个的字符串用空格分割为字符串数组
也可以考虑先删除尾部的所有空格 然后通过倒序找到第一个字符串就好
string word;
        stringstream ss(s);
        while(ss>>word){}
        return word.size();
        这种方法极为简洁 重点是要懂得如何使用stringstream函数
        一下是一段stringstream的用法实例展示
        string s;
    getline(cin,s);          //输入字符串s，可带空格because of(getline);
    stringstream ss(s);  //定义一个字符串流ss，并用字符串s去初始化；
    string res=" ", tmp;  
    while (ss>>tmp)     //ss>>tmp，从字符串流读出一个字符串到tmp中，tmp遇到空格停止。比如输入 "xiao  yan",此时                                   //tmp中为"xiao",第二次循环读出时为"yan".

    {
        if (res==" ")
            res=tmp;
        else
            res=tmp+" "+res;

    }

程序实现的功能为：输入：girl a am i

                                输出：i am a girl