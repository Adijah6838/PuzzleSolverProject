import os
import time

def is_valid(board, num, pos):
    for i in range(len(board[0])):
        if board[pos[0]][i] == num and pos[1] != i:
            return False
    for i in range(len(board)):
        if board[i][pos[1]] == num and pos[0] != i:
            return False
    box_x = pos[1] // 3
    box_y = pos[0] // 3
    for i in range(box_y * 3, box_y * 3 + 3):
        for j in range(box_x * 3, box_x * 3 + 3):
            if board[i][j] == num and (i, j) != pos:
                return False
    return True

def find_empty(board):
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 0:
                return (i, j)  
    return None 

def print_board(board, clear_screen=False):
    if clear_screen:
        os.system('cls' if os.name == 'nt' else 'clear')
    for i in range(len(board)):
        if i % 3 == 0 and i != 0:
            print("- - - - - - - - - - - -")
        for j in range(len(board[0])):
            if j % 3 == 0 and j != 0:
                print(" | ", end="")
            if j == 8:
                print(board[i][j])
            else:
                print(str(board[i][j]) + " ", end="")

def solve(board, animate=False):
    find = find_empty(board)
    if not find:
        return True
    else:
        row, col = find
    for i in range(1, 10):
        if is_valid(board, i, (row, col)):
            board[row][col] = i
            if animate:
                print_board(board, clear_screen=True)
                time.sleep(0.05)
            if solve(board, animate):
                return True
            board[row][col] = 0
            if animate:
                print_board(board, clear_screen=True)
                time.sleep(0.05)
    return False

board = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9]
]

print("Here is your unsolved puzzle:")
print_board(board)

print("\nSolving...\n")

# START THE TIMER
start_time = time.time()

solve(board, animate=False)

# END THE TIMER
end_time = time.time()

print("Here is your solved puzzle:")
print_board(board)

# CALCULATE AND PRINT THE DIFFERENCE
time_taken = end_time - start_time
print(f"\nAlgorithm finished in: {time_taken:.4f} seconds")
