class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        even_sum = sum(i for i in A if i%2 == 0)
        ans = []
        for q in queries:
            val, idx = q
            old_val, new_val = A[idx], A[idx]+val
            A[idx] = new_val
            if old_val % 2 == 0:
                even_sum -= old_val
            if new_val % 2 == 0:
                even_sum += new_val
            ans.append(even_sum)
        return ans

    
