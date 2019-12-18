from functools import reduce
class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        def is_mine(cell):
            row, col = cell
            return board[row][col] == 'M'
        def game_over(row, col):
            board[row][col] = 'X'
        def adjacent_cells(row, col):
            return ((row-i, col-j) 
                    for i in [-1, 0, 1] 
                        for j in [-1, 0, 1] 
                            if (row, col) != (row-i, col-j) 
                                and 0 <= row-i < len(board) 
                                and 0 <= col-j < len(board[0]))
        def no_adjacent_mines(row, col):
            return not any(is_mine(adjacent_cell)
                           for adjacent_cell in adjacent_cells(row, col))
        def reveal_blank(row, col):
            board[row][col] = 'B'
        def count_adjacent_mines(row, col):
            return reduce(
                operator.add, 
                filter(
                    lambda mine_cell: mine_cell is True, 
                    map(is_mine, adjacent_cells(row, col))), 
                0)
        def is_unrevealed(row, col):
            return board[row][col] == 'E'
        def reveal(row, col):
            if is_mine((row, col)):
                game_over(row, col)
            elif no_adjacent_mines(row, col):
                reveal_blank(row, col)
                for adjacent_row, adjacent_col in adjacent_cells(row, col):
                    if is_unrevealed(adjacent_row, adjacent_col):
                        reveal(adjacent_row, adjacent_col)
            else:
                adjacent_mines = count_adjacent_mines(row, col)
                board[row][col] = str(adjacent_mines) 
        reveal(*click)
        return board
