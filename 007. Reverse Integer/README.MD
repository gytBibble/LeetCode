# 题目
* 翻转整数
# 思路
1. 输入为`32`位有符号型整数，翻转整数符号不变，去掉翻转后的前置`0`，注意整数的范围，如果超过`10`位则一定溢出`int`，可以与`0x80000000`和`0x7fffffff`比较
2. 题目要求使用的机器只支持32位的情况，即不使用`long`等类型
---