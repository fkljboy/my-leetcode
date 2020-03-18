#
# @lc app=leetcode id=155 lang=python3
#
# [155] Min Stack
#
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data=[]
        self.helper=[]

    def push(self, x: int) -> None:
        self.data.append(x)
        if len(self.helper)==0 or x<=self.helper[-1]:
            self.helper.append(x)

    def pop(self) -> None:
        if self.data[-1]==self.helper[-1] and self.helper:
            self.helper.pop()
        return self.data.pop()

    def top(self) -> int:
        if self.data:
            return self.data[-1]

    def getMin(self) -> int:
        if self.helper:
            return self.helper[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

'''此题的问题在于如何直接弹出最小值，很显然如果只有一个堆栈的话那么根据
先进后出的原则 我们无法将最小值直接弹出 所以我们需要一个辅助栈 这个栈
的作用就是辅助储存较小的值，具体操作为：在首次压入时，同时向主栈和辅助栈
压入数据，后面的压入，则主栈都压入，辅助站则和首次压入的值进行比较，如果改值
小于首次压入的数，则进行压入，否则不压，这样就可以保证一个较小的数永远处于
辅助栈的栈顶，这样在所有元素都入栈以后，只需要将辅助站的栈顶元素弹出即可得到
需要的最小值，该题也可以用哈希表做