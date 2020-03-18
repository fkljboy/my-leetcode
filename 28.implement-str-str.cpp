/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.44%)
 * Total Accepted:    396.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
         if (needle=="")
        return 0;
        if (haystack.find(needle) == string::npos) 
        return -1;
        else
        return haystack.find(needle); 
        
    }
};
/* 以下的方法是kmp法 
public static int[] getNext(String ps) {

    char[] p = ps.toCharArray();

    int[] next = new int[p.length];

    next[0] = -1;

    int j = 0;

    int k = -1;

    while (j < p.length - 1) {

       if (k == -1 || p[j] == p[k]) {

           if (p[++j] == p[++k]) { // 当两个字符相等时要跳过

              next[j] = next[k];

           } else {

              next[j] = k;

           }

       } else {

           k = next[k];

       }

    }

    return next;

} 
public static int KMP(String ts, String ps) {

    char[] t = ts.toCharArray();

    char[] p = ps.toCharArray();

    int i = 0; // 主串的位置

    int j = 0; // 模式串的位置

    int[] next = getNext(ps);

    while (i < t.length && j < p.length) {

       if (j == -1 || t[i] == p[j]) { // 当j为-1时，要移动的是i，当然j也要归0

           i++;

           j++;

       } else {

           // i不需要回溯了

           // i = i - j + 1;

           j = next[j]; // j回到指定位置

       }

    }

    if (j == p.length) {

       return i - j;

    } else {

       return -1;

    }

}