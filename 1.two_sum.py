#---coding:utf-8---
__author__ = 'hxlcj'
"""
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target,
where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Two Sum My Submissions Question Solution
O(n^2) runtime, O(1) space – Brute force:
The brute force approach is simple. Loop through each element x and find if there is another value
that equals to target – x. As finding another value requires looping through the rest of array,
its runtime complexity is O(n^2).

O(n) runtime, O(n) space – Hash table:
We could reduce the runtime complexity of looking up a value to O(1) using a hash map that maps
a value to its index.
"""
class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        s=sorted(nums)
        index=[]
        i=0
        j=len(nums)-1
        while i<j:
            if(s[i]+s[j]==target):
                i=nums.index(s[i])+1
                j=nums.index(s[j])+1
                if(i==j):
                    j=nums.index(s[j],i)+1
                if(i>j):
                    temp=i
                    i=j
                    j=temp
                index.append(i)
                index.append(j)
                break
            elif(s[i]+s[j]<target):
                i=i+1
            else:
                j=j-1
        return index

    def twoSum1(self, nums, target):
        dic = {}
        for i, num in enumerate(nums):
            if target-num in dic:
                return [dic[target-num]+1, i+1]
            dic[num] = i

if __name__=="__main__":
    s=Solution()
    nums=[2,3,4,5,8,0,9]
    target=9
    print s.twoSum1(nums,target)

