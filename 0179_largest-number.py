class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def merge(a, b):
            i, j = 0, 0
            arr = []
            while i < len(a) and j < len(b):
                ai, bj = str(a[i]), str(b[j])
                if ai + bj >= bj + ai:
                    arr.append(a[i])
                    i += 1
                else:
                    arr.append(b[j])
                    j += 1
            if i < len(a):
                arr.extend(a[i:])
            if j < len(b):
                arr.extend(b[j:])
            return arr
        def mergesort(arr):
            if len(arr) <= 1:
                return arr
            mid = len(arr) // 2
            left = mergesort(arr[:mid])
            right = mergesort(arr[mid:])
            return merge(left, right)
        ans = ''.join([str(num) for num in mergesort(nums)])
        while len(ans) > 1 and ans[0] == '0':
            ans = ans[1:]
        return ans
