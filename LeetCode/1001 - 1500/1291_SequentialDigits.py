class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        for i in range(1, 10):
            tmp = i
            for j in range(i+1, 10):
                tmp = tmp * 10 + j
                if tmp >= low and tmp <= high:
                    ans.append(tmp)
                if tmp > high:
                    break
        ans.sort()
        return ans
