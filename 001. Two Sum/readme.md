# 题目
配对，给出一个`List`和`target`，找到`a`和`b`，使得`a+b=target`
# 思路
## C++
1. 遍历寻找，两个`for`循环，时间复杂度O(n^2)，空间复杂度O(1)
2. 使用`key-value`的数据结构，先将表的内容保存到`hash`表中，查找在`a`的情况下，`b=target-a`的下标，这里采用`unorderde_map`，因为无需排序，时间复杂度O(n)，空间复杂度O(n)
3. 在`2`的基础上，还可以继续优化，在将数据对插入到`hash`中时，同时查找，这样可以减少一定的空间和时间的使用，但最坏情况相同?
---