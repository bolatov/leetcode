class Solution:
    # solution from "Cracking the Coding Interview"
    def search(self, nums: List[int], target: int) -> bool:
        lo, hi = 0, len(nums) - 1
        def _search(lo=0, hi=len(nums)-1):
            if lo > hi:
                return -1
            mid = lo + (hi-lo)//2
            if nums[mid] == target:
                return mid
            
            if nums[lo] < nums[mid]:
                if nums[lo] <= target < nums[mid]:
                    return _search(lo, mid-1)
                else:
                    return _search(mid+1, hi)
            elif nums[mid] < nums[lo]:
                if nums[mid] < target <= nums[hi]:
                    return _search(mid+1, hi)
                else:
                    return _search(lo, mid-1)
            elif nums[lo] == nums[mid]:
                if nums[mid] != nums[hi]:
                    return _search(mid+1, hi)
                else:
                    left = _search(lo, mid-1)
                    if left == -1:
                        return _search(mid+1, hi)
                    else:
                        return _search(lo, mid-1)
            return -1
        return True if _search() >= 0 else False
