Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
    
T(n)=O(n^2)
S(n)=O(1)

#-*-encoding:utf-8-*-
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ls=sorted(nums)#排序保证条件一
        n=len(nums)
        s=set()
        flag=0#标志位
        target=0
        for i in range(n-2):#至少有三个元素
            if flag==1 and target+ls[i]==0:#跳过重复元素,减少不必要的循环
                continue
            if i==0:
                flag=1
            target=-ls[i]#寻找剩下的两个元素之和等于target，从而a+b+c=0
            l=i+1
            h=n-1#使用二分查找
            while(l<h):
                if ls[l]+ls[h]==target:
                    s.add((-target,ls[l],ls[h]))
                    l=l+1
                    h=h-1
                elif ls[l]+ls[h]<target:
                    l=l+1
                else:
                    h=h-1
        lr=[]#返回结果
        for e in s:
            lr.append(list(e))
        return  lr

    def threeSum1(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ls=sorted(nums)#排序保证条件一
        n=len(nums)
        lr=[]
        flag=0#标志位
        target=0
        for i in range(n-2):#至少有三个元素
            if flag==1 and target+ls[i]==0:#跳过重复元素,减少不必要的循环
                continue
            if i==0:
                flag=1
            target=-ls[i]#寻找剩下的两个元素之和等于target，从而a+b+c=0
            l=i+1
            h=n-1#使用二分查找
            while(l<h):
                if ls[l]+ls[h]==target:
                    lr.append((-target,ls[l],ls[h]))
                    l=l+1
                    h=h-1
                    while(l<h and ls[l]==ls[l-1] and ls[h]==ls[h+1]):
                        l=l+1
                        h=h-1
                elif ls[l]+ls[h]<target:
                    l=l+1
                else:
                    h=h-1
        return  lr
    
    def threeSum2(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ls=sorted(nums)#排序保证条件一
        n=len(nums)
        lr=[]
        flag=0#标志位
        target=0
        for i in range(n-2):#至少有三个元素
            if flag==1 and target+ls[i]==0:#跳过重复元素,减少不必要的循环
                continue
            if i==0:
                flag=1
            target=-ls[i]#寻找剩下的两个元素之和等于target，从而a+b+c=0
            l=i+1
            h=n-1#使用二分查找
            while(l<h):
                if ls[l]+ls[h]==target:
                    lr.append((-target,ls[l],ls[h]))
                    l=l+1
                    h=h-1
                    while(l<h and ls[l]==ls[l-1] and ls[h]==ls[h+1]):
                        l=l+1
                        h=h-1
                elif ls[l]+ls[h]<target:
                    l=l+1
                    while(l<h and ls[l]==ls[l-1]):
                        l=l+1
                else:
                    h=h-1
                    while(l<h and ls[h]==ls[h+1]):
                        h=h-1
        return  lr
