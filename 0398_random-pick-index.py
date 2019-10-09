import random
class Solution:

    def __init__(self, nums: List[int]):
        self.dct = {}
        for i, num in enumerate(nums):
            if num not in self.dct:
                self.dct[num] = []
            self.dct[num].append(i)

    def pick(self, target: int) -> int:
        indices = self.dct[target]
        return random.choice(indices)
