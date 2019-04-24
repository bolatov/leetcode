class Solution:
    def matrixScore(self, A: List[List[int]]) -> int:
        def get_sum(A):
            val = 0
            for arr in A:
                v = 0
                for ai in arr:
                    v = (v << 1) | ai
                val += v
            return val
        def p(*s):
            print(s)
            for i in range(len(A)):
                print(A[i], '=', int(''.join([str(ai) for ai in A[i]]), base=2))
            print('-'*10)
        rlen, clen = len(A), len(A[0])
        def flip_column(j):
            for i in range(rlen):
                A[i][j] = 1 - A[i][j]
        def flip_row(i):
            for j in range(clen):
                A[i][j] = 1 - A[i][j]
        ans = get_sum(A)
        # p('Initial', 'max_sum', ans)
        changed = True
        while changed:
            changed = False
            row_id, row_val = -1, -1
            for i in range(rlen):
                flip_row(i)
                cur = get_sum(A)
                flip_row(i)
                if row_val < cur:
                    row_val = cur
                    row_id = i
            col_id, col_val = -1, -1
            for j in range(clen):
                flip_column(j)
                cur = get_sum(A)
                flip_column(j)
                if col_val < cur:
                    col_val = cur
                    col_id = j
            # print('row_val', row_val)
            # print('col_val', col_val)
            if row_val >= col_val and row_val > ans:
                flip_row(row_id)
                # p('Flip row', row_id, 'row_val', row_val)
                ans = row_val
                changed = True
            elif col_val >= row_val and col_val > ans:
                flip_column(col_id)
                # p('Flip col', col_id, 'col_val', col_val)
                ans = col_val
                changed = True
        return ans
