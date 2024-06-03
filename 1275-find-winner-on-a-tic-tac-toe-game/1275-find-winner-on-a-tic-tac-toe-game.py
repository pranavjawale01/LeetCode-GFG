class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        board = [[' ' for _ in range(3)] for _ in range(3)]
        
        for i, move in enumerate(moves):
            row, col = move
            player = 'X' if i % 2 == 0 else 'O'
            board[row][col] = player
            
            if board[row][0] == player and board[row][1] == player and board[row][2] == player:
                return "A" if player == 'X' else "B"
            
            if board[0][col] == player and board[1][col] == player and board[2][col] == player:
                return "A" if player == 'X' else "B"
            
            if row == col and board[0][0] == player and board[1][1] == player and board[2][2] == player:
                return "A" if player == 'X' else "B"
            
            if row + col == 2 and board[0][2] == player and board[1][1] == player and board[2][0] == player:
                return "A" if player == 'X' else "B"
        
        if len(moves) == 9:
            return "Draw"
        
        return "Pending"