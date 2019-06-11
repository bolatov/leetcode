class NumArray:

    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.tree = [0] * (self.n * 4)
        def build(pos, lo, hi):
            if lo == hi:
                self.tree[pos] = nums[lo]
            else:
                mid = lo + (hi-lo) // 2
                build(pos*2+1, lo, mid)
                build(pos*2+2, mid+1, hi)
                self.tree[pos] = self.tree[pos*2+1] + self.tree[pos*2+2]
        if nums:
            build(0, 0, self.n-1)

    def update(self, i: int, val: int) -> None:
        def traverse(pos, lo, hi):
            if lo == hi:
                self.tree[pos] = val
                return
            mid = lo + (hi-lo) // 2
            if i <= mid:
                traverse(pos*2+1, lo, mid)
            else:
                traverse(pos*2+2, mid+1, hi)
            self.tree[pos] = self.tree[pos*2+1] + self.tree[pos*2+2]
        if self.n > 0:
            traverse(0, 0, self.n-1)

    def sumRange(self, i: int, j: int) -> int:
        def rsq(pos, lo, hi):
            if j < lo or hi < i:
                return 0
            if i <= lo and hi <= j:
                return self.tree[pos]
            mid = lo + (hi-lo) // 2
            if j <= mid:
                return rsq(pos*2+1, lo, mid)
            elif mid < i:
                return rsq(pos*2+2, mid+1, hi)
            return rsq(pos*2+1, lo, mid) + rsq(pos*2+2, mid+1, hi)
        return rsq(0, 0, self.n-1) if self.n > 0 else 0


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
