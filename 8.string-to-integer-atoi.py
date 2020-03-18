#
# @lc app=leetcode id=8 lang=python3
#
# [8] String to Integer (atoi)
#

# @lc code=start
class Solution:
    def myAtoi(self, str: str) -> int:
        #去掉左边字符
        str=str.lstrip()
        #如果字符串空，返回
        if len(str)==0:
            return 0
        #设置默认输出为0
        last=0
        #如果有符号设置起始位置2，其余的为1
        i=2 if str[0]=='-'or str[0]=='+'  else 1
        #循环，直到无法强转成int，跳出循环
        while i <= len(str):
            try:
                last=int(str[:i])
                i+=1
            except:
                break
        #如果数字超出范围，返回范围最大值
        if last<-2147483648 :
            return -2147483648
        if last>2147483647:
            return 2147483647
        return last
'''首先将所有的左边字符全部都去掉 本题的问题在于：只需要识别出字符串中的第一段
连续的数字作为我们要转换为数字的部分，这样就可以使用这种强制转换的方法去解决，对所有
可以转换为int的强制转换，其余的则直接舍弃
# @lc code=end

