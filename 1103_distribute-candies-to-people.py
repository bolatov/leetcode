class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0] * num_people
        i = 1
        while candies > 0:
            ans[(i-1) % num_people] += min(i, candies)
            candies -= i
            i += 1
        return ans
