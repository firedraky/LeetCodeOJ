#-*-encoding:utf-8-*-

class Solution(object):
    def threeSumClosest1(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        ls=sorted(nums)
        n=len(ls)
        ts=[] #保存每轮结束后最接近的结果
        for i in range(n-2):
            if i>0 and ls[i-1]==ls[i]: #跳过重复的元素
                continue
            l=i+1
            h=n-1
            s=ls[i]+ls[l]+ls[h]
            minTemp=abs(target-s)
            sumTemp=s
            while l<h:
                if l+1==h:
                    ts.append(sumTemp)

                if s==target:
                    return target
                elif s<target:
                    l=l+1
                else:
                    h=h-1

                if(l<h):
                    s=ls[i]+ls[l]+ls[h]
                    if minTemp>abs(target-s):
                        minTemp=abs(target-s)
                        sumTemp=s
        #若是没有三个元素之和等于target，返回最近的三个元素之和（可能有多个元素符合）
        ts.sort()
        k=len(ts)
        if target<ts[0]:
            return ts[0]
        if target>ts[k-1]:
            return ts[k-1]
        for i in range(1,k):
            if target<ts[i]:
                if (target-ts[i-1])<=(ts[i]-target):
                    return ts[i-1]
                else :
                    return ts[i]

    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        ls=sorted(nums)
        n=len(ls)
        minTemp=sys.maxint
        sumTemp=0
        for i in range(n-2):
            if i>0 and ls[i-1]==ls[i]: #跳过重复的元素
                continue
            l=i+1
            h=n-1
            while l<h:
                s=ls[i]+ls[l]+ls[h]
                if minTemp>abs(target-s):
                    minTemp=abs(target-s)
                    sumTemp=s
                if s==target:
                    return target
                elif s<target:
                    l=l+1
                else:
                    h=h-1
        return  sumTemp