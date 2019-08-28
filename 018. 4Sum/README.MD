# 题目
* 找出数组中的所有四元对满足其和等于给出的 `target`
# 思路
1. 先对数组进行预处理，按照从小到大排序
2. 可以遍历，找到一个数字 `a` ，然后在数组后面找出3个数字满足等于 `target - a` ，参照 [015. 3Sum](https://github.com/gytBibble/LeetCode/tree/master/015.%203Sum)