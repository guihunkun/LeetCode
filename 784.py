#!/usr/bin/env python 
# -*- coding:utf-8 -*-
class Solution:
    def __init__(self,s):
        self.S=s
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        # 记录当前所有的分支
        cur_s =[S]
        # print(cur_s)
        # 每次都从上一轮记录的位置的下一位开始计算
        for i in range(len(S)):
            next_s = []
            for s in cur_s:
                # 如果是数字，则当前分支直接加入下轮的分支
                if s[i].isdigit():
                    next_s.append(s)
                    # print(next_s)
                # 如果是字母，则当前分支分为大小写两种加入下轮的分支
                else:
                    next_s.append(s[0:i] + s[i].lower() + s[i + 1:])
                    next_s.append(s[0:i] + s[i].upper() + s[i + 1:])
            cur_s = next_s
            # print(next_s)
        return cur_s
ss='asd123'
res=Solution(ss)
sss='gfd23'
ress=res.letterCasePermutation(sss)
print(ress)