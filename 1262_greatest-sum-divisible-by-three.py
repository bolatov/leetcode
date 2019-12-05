class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        """
        The intuition behind this solution is as follows:
        Split the numbers into 3 groups according to the modulo 3 values.
        Group 0 (modulo 3 == 0): those numbers that maximize the result.
        Group 1 (modulo 3 == 1) and Group 2 (modulo 3 == 2).
        Numbers from other two groups can be combined as to be added to the result.
        
        Having the above hints, do the reverse engineering. Sum up all the values
        and check whether it is divisible by 3. If yes, the result is found. Otherwise,
        try to remove the remainder value.
        e.g. If `total_sum` % 3 == 1, then either remove one smallest value from Group 1
        or two smallest values from Group 2.
        """
        total_sum = sum(nums)
        if total_sum % 3 == 0:
            return total_sum
        rem1 = sorted((num for num in nums if num % 3 == 1))
        rem2 = sorted((num for num in nums if num % 3 == 2))
        cand1, cand2 = 0, 0
        if total_sum % 3 == 1:
            if rem1:
                cand1 = total_sum - rem1[0]
            if len(rem2) >= 2:
                cand2 = total_sum - rem2[0] - rem2[1]
        else:
            if rem2:
                cand2 = total_sum - rem2[0]
            if len(rem1) >= 2:
                cand1 = total_sum - rem1[0] - rem1[1]
        return max(cand1, cand2)
