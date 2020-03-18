/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (51.81%)
 * Total Accepted:    380.3K
 * Total Submissions: 734.1K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
class Solution {
public:
    int romanToInt(string s) {
        int m = 0, d = 0, c = 0, l = 0, x = 0, v = 0, i = 0, j = 0, sum = 0;
	while (s[j] == 'M')
	{
		m++;
		j++;
	}
	if (s[j] == 'C' && s[j + 1] == 'D')
	{
		c = 4;
		j += 2;
	}
	if (s[j] == 'C' && s[j + 1] == 'M')
	{
		c = 9;
		j += 2;
	}
	if (s[j] == 'D')
	{
		d = 1;
		j++;
	}
	while (s[j] == 'C')
	{
		c++;
		j++;
	}
	if (s[j] == 'X' && s[j + 1] == 'L')
	{
		x = 4;
		j += 2;
	}
	if (s[j] == 'X' && s[j + 1] == 'C')
	{
		x = 9;
		j += 2;
	}
	if (s[j] == 'L')
	{
		l = 1;
		j++;
	}
	while (s[j] == 'X')
	{
		x++;
		j++;
	}
	if (s[j] == 'I' && s[j + 1] == 'V')
	{
		i = 4;
		j += 2;
	}
	if (s[j] == 'I' && s[j + 1] == 'X')
	{
		i = 9;
		j += 2;
	}
	if (s[j] == 'V')
	{
		v = 1;
		j++;
	}
	while (s[j] == 'I')
	{
		i++;
		j++;
	}
	sum = m * 1000 + d * 500 + c * 100 + l * 50 + x * 10 + v * 5 + i;
        return sum;
    }
};

