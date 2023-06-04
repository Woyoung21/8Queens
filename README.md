# 8Queens
8 Queens implementation in C++

/*

Eight Queens Puzzle Solver
This is a solution to the famous Eight Queens puzzle implemented in C++. The code uses recursive backtracking to find a solution where eight queens are placed on a chess board such that no two queens threaten each other. Each queen can move any number of unobstructed squares in any direction: vertically, horizontally, or diagonally.

The solution is represented as an 8x8 grid where 'X' represents a queen and '_' represents an empty square.

How to run
This is a command-line program. You need a C++ compiler (like g++, clang, etc.) installed on your machine to compile and run it, I used Visual Studios. If you're on a Unix-like system, you can usually compile it with a command like: g++ -std=c++11 main.cpp -o queens

Then, you can run it with: ./queens

If a solution is found, it will be printed to the console. If no solution is found, the message "No solution found." will be displayed.

Classes
Queen
The Queen class represents a queen chess piece. It has a single property, row, which represents the row number where the queen is placed. setRow(int inRow) and getRow() methods are used to set and get the row number.

Board
The Board class represents a chessboard and handles the logic for solving the puzzle.

It has the following public methods:

Board(): The constructor initializes the queens vector to be of size BOARD_SIZE (which is 8 in this case).
doQueens(): This is the entry point to start solving the puzzle. It calls placeQueens(0, 0), and if a solution is found, it calls display() to print the board to the console.
display() const: This method prints the current state of the board to the console.
Private methods:

placeQueens(int row, int col): This recursive method tries to place a queen in each row of the given column and calls itself for the next column if successful.
findNextSafeSquare(int& row, int col): This method finds the next safe square in the given column where a queen can be placed without being under attack.
isUnderAttack(int row, int col): This method checks if a square at the given row and column is under attack by any other queen.
Limitations
The current code is built to solve the 8-queens puzzle. To solve an n-queens puzzle for a different n, you'd have to modify the BOARD_SIZE constant and adjust the display method accordingly.

Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

License
MIT


*/
