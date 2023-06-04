/*
************************************************************

	Will Young      CS10C       9/13/22     Harden    A4
	
This assignment helps us get used to using advanced 

recursion methods with a vector.

************************************************************
*/


#include <iostream>
#include <vector>
using namespace std;

// Class representing a Queen chess piece
class Queen {
public:
    // Sets the row for the Queen
    void setRow(int inRow);
    // Returns the row where the Queen is placed
    int getRow() const;
private:
    // The row where the Queen is placed
    int row;
};


// Getter for row
int Queen::getRow() const {

	return row;
}


// Setter for row
void Queen::setRow(int inRow) {

	row = inRow;

}


// Class representing a chess board
class Board {
public:
    // The size of the board (8 for an 8x8 board)
    static const int BOARD_SIZE = 8;
    // Constructor that initializes the board
    Board();
    // Starts solving the 8 Queens problem
    void doQueens();
    // Displays the current state of the board
    void display() const;
private:
    // Tries to place a Queen at a given row and column, and then solve the rest of the board recursively
    bool placeQueens(int row, int col);
    // Finds the next safe square in the given column where a queen can be placed
    bool findNextSafeSquare(int& row, int col);
    // Checks if a square at the given row and column is under attack by any other queen
    bool isUnderAttack(int row, int col);
    // A vector of queens, one for each column
    vector<Queen> queens;
	
};



// Constructor, initializes the queens vector
Board::Board() {

    queens.resize(BOARD_SIZE);
}



// Entry point to start solving the problem
void Board::doQueens() {
    // If a solution is found, display it
    if (placeQueens(0, 0)) {

        display();
    }
    // Otherwise, print that no solution was found
    else {

        cout << "No solution found." << endl;
    }
}



// Recursive function to place queens on the board
bool Board::placeQueens(int row, int col) {

    // Keep trying to find a safe square in the current column
	while (findNextSafeSquare(row, col)) {
        // If found, place the queen
        queens[col].setRow(row);
        // If we've filled the board or can successfully fill the rest of the board, return true
		if (col == BOARD_SIZE - 1 || placeQueens(0, col + 1)) {
			
				return true;
			
		}
        // Otherwise, try the next row in the current column
		else {
            
			row = queens[col].getRow();
			
		}
        
        row++;
		
	}
    // If no safe square can be found in the current column, return false
    return false;

}

// Check if a square is under attack by any other queen
bool Board::isUnderAttack(int testRow, int testCol) {
	
    // Check all columns before the current one
	for (int col = 0; col < testCol; col++) {
        
        
        int row = queens[col].getRow();
        // If there's a queen in the same row or on a diagonal, it's not safe
		if (row == testRow) {
			return true;
		}

		if (abs(row - testRow) == abs(col - testCol)) {
			return true;
		}

	}
    // If no queen can attack this square, it's safe
	return false;

}


// Find the next safe square in the current column
bool Board::findNextSafeSquare(int& row, int col) {
	
     // Check all squares in the current column
     for (int i = row; i < BOARD_SIZE; i++) {
         // If a square is not under attack, it's safe
         if (!isUnderAttack(i, col))
         {
             row = i;
             return true;
         }

     }
     // If no safe square can be found, return false
     return false;
}



// Display the current state of the board
void Board::display() const {
	
    // For each square, print 'X' if there's a queen and '_' if it's empty
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        for (int col = 0; col < BOARD_SIZE; ++col)
        {
            if (queens[col].getRow() == row) { 
				
                cout << 'X' << " ";
            } 
			
            else 
            { 
                cout << '_' << " ";
            }
        }
        cout << endl;
    }
	
}



// Main function
int main() {
    // Create a new board and start solving the problem
    Board board;
    board.doQueens();
}




/*
************************************************************
                    Test Output
X _ _ _ _ _ _ _
_ _ _ _ _ _ X _
_ _ _ _ X _ _ _
_ _ _ _ _ _ _ X
_ X _ _ _ _ _ _
_ _ _ X _ _ _ _
_ _ _ _ _ X _ _
_ _ X _ _ _ _ _


X _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
_ _ _ X _ _ _ _ _ _ _ _ _ _ _ _
_ X _ _ _ _ _ _ _ _ _ _ _ _ _ _
_ _ _ _ _ _ _ _ _ _ _ _ X _ _ _
_ _ X _ _ _ _ _ _ _ _ _ _ _ _ _
_ _ _ _ _ _ _ _ _ X _ _ _ _ _ _
_ _ _ _ _ _ _ _ _ _ _ X _ _ _ _
_ _ _ _ _ _ _ _ _ _ _ _ _ _ X _
_ _ _ _ _ X _ _ _ _ _ _ _ _ _ _
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ X
_ _ _ _ _ _ _ _ _ _ _ _ _ X _ _
_ _ _ _ _ _ _ X _ _ _ _ _ _ _ _
_ _ _ _ X _ _ _ _ _ _ _ _ _ _ _
_ _ _ _ _ _ X _ _ _ _ _ _ _ _ _
_ _ _ _ _ _ _ _ X _ _ _ _ _ _ _
_ _ _ _ _ _ _ _ _ _ X _ _ _ _ _

************************************************************
*/