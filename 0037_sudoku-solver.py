class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        N = 9
        DOT = '.'
        dots = []
        rows, cols, boxes = {}, {}, {}
        def boxid(row, col):
            return row // 3 * 3 + col // 3
        for i, row in enumerate(board):
            if i not in rows:
                rows[i] = set()
            for j, char in enumerate(row):
                if j not in cols:
                    cols[j] = set()
                if boxid(i, j) not in boxes:
                    boxes[boxid(i, j)] = set()
                if char == DOT:
                    dots.append((i, j))
                else:
                    rows[i].add(char)
                    cols[j].add(char)
                    boxes[boxid(i, j)].add(char)
        def is_valid(row, col, num):
            return (num not in rows[row]
                    and num not in cols[col]
                    and num not in boxes[boxid(row, col)])
        def place(row, col, num):
            board[row][col] = num
            rows[row].add(num)
            cols[col].add(num)
            boxes[boxid(row, col)].add(num)
        def remove(row, col, num):
            board[row][col] = DOT
            rows[row].remove(num)
            cols[col].remove(num)
            boxes[boxid(row, col)].remove(num)
        def backtrack(idx=0):
            if idx == len(dots):
                return True
            row, col = dots[idx]
            for i in range(1, N+1):
                nxt_candidate = str(i)
                if is_valid(row, col, nxt_candidate):
                    place(row, col, nxt_candidate)
                    if backtrack(idx + 1):
                        return True
                    remove(row, col, nxt_candidate)
            return False
        backtrack()
