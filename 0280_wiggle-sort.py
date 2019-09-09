# Solution from "Cracking the Coding Interview"
class Solution:
    """
    @param: nums: A list of integers
    @return: nothing
    """
    def wiggleSort(self, nums):
        # write your code here
        if len(nums) < 2:
            return
        def max_index(i, j, k):
            get_val = lambda idx: nums[idx] if 0 <= idx < len(nums) else float('-inf')
            ival, jval, kval = get_val(i), get_val(j), get_val(k)
            max_val = max(ival, max(jval, kval))
            if max_val == ival:
                return i
            elif max_val == jval:
                return j
            return k
            
        for i in range(1, len(nums), 2):
            biggest_index = max_index(i-1, i, i+1)
            if i != biggest_index:
                nums[i], nums[biggest_index] = nums[biggest_index], nums[i]
