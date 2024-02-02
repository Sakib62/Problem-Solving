class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        pre = []
        pre.append(1)
        ln = len(nums)
        for i in range(ln):
            pre.append(pre[i] * nums[i])
        suf = []
        suf.append(1)
        for i in range(ln-1, -1, -1):
            suf.append(suf[ln-i-1] * nums[i])
        ans = []
        for i in range(ln):
            ans.append(pre[i] * suf[ln-i-1])
        return ans
