class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge_sort(arr):
            if len(arr) <= 1:
                return arr
            mid = len(arr) // 2
            l = merge_sort(arr[:mid])
            r = merge_sort(arr[mid:])
            i, j = 0, 0
            for k in range(len(arr)):
                if i >= len(l):
                    arr[k] = r[j]
                    j += 1
                elif j >= len(r):
                    arr[k] = l[i]
                    i += 1
                elif l[i] < r[j]:
                    arr[k] = l[i]
                    i += 1
                else:
                    arr[k] = r[j]
                    j += 1
            return arr
        return merge_sort(nums)
