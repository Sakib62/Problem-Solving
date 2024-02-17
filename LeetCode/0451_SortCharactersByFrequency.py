class Solution:
    def frequencySort(self, s: str) -> str:
        freq = {}
        for x in s:
            if x in freq:
                freq[x] += 1
            else:
                freq[x] = 1
        a = sorted(freq.items(), key=lambda x : x[1], reverse = True)
        b = dict(a)
        ans = ""
        for x in b:
            while b[x] > 0:
                ans += x
                b[x] -= 1
        return ans
