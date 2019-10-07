class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        i = 0
        size = len(flowerbed)
        while i < size and n > 0:
            if flowerbed[i]:
                i += 2
                continue
            if i == 0:
                if size == 1 or not flowerbed[i+1]:
                    n -= 1
                    i += 2
                    continue
            elif i == size - 1:
                if not flowerbed[i-1]:
                    n -= 1
                    i += 2
                    continue
            else:
                if flowerbed[i-1] + flowerbed[i+1] == 0:
                    n -= 1
                    i += 2
                    continue
            i += 1 
        return n == 0
