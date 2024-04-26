#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Constants for board dimensions
const int BOARD_SIZE = 8;

// Enum to represent piece types
enum PieceType { Pawn, Rook, Knight, Bishop, Queen, King };

// Struct to represent a chess piece
struct Piece {
    PieceType type;
    char symbol;
    string color;
};

// Function to initialize the chess board with pieces in their initial positions
vector< vector < Piece > > initializeBoard() {
    vector<vector <Piece> > board(BOARD_SIZE, vector<Piece>(BOARD_SIZE));
    // Initialize pawns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        board[1][i] = {Pawn, 'P', "Black"};
        board[6][i] = {Pawn, 'P', "White"};

    }
    // Initialize rooks
    board[0][0] = {Rook, 'R', "Black"};
    board[0][7] = {Rook, 'R', "Black"};
    board[7][0] = {Rook, 'R', "White"};
    board[7][7] = {Rook, 'R', "White"};
    // Initialize knights
    board[0][1] = {Knight, 'N', "Black"};
    board[0][6] = {Knight, 'N', "Black"};
    board[7][1] = {Knight, 'N', "White"};
    board[7][6] = {Knight, 'N', "White"};
    // Initialize bishops
    board[0][2] = {Bishop, 'B', "Black"};
    board[0][5] = {Bishop, 'B', "Black"};
    board[7][2] = {Bishop, 'B', "White"};
    board[7][5] = {Bishop, 'B', "White"};
    // Initialize queens
    board[0][3] = {Queen, 'Q', "Black"};
    board[7][3] = {Queen, 'Q', "White"};
    // Initialize kings
    board[0][4] = {King, 'K', "Black"};
    board[7][4] = {King, 'K', "White"};

    return board;
}


// Function to display the chess board
void displayBoard(const vector<vector<Piece>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j].type == Pawn)
                cout << 'P';
            else if (board[i][j].type == Rook)
                cout << 'R';
            else if (board[i][j].type == Knight)
                cout << 'N';
            else if (board[i][j].type == Bishop)
                cout << 'B';
            else if (board[i][j].type == Queen)
                cout << 'Q';
            else if (board[i][j].type == King)
                cout << 'K';
            cout << board[i][j].color[0] << ' ';
        }
        cout << endl;
    }
}

// Function to check if the move is within the bounds of the board
bool isValidMove(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

// Function to move a piece on the board
void movePiece(vector<vector<Piece>>& board, int fromX, int fromY, int toX, int toY) {
    if (isValidMove(toX, toY)) {
        board[toX][toY] = board[fromX][fromY];
        board[fromX][fromY] = {PieceType(), ' ', ""};
    } else {
        cout << "Invalid move!" << endl;
    }
}

int main() {
    // Initialize the board
    vector<vector<Piece>> board = initializeBoard();

    // Display the initial board
    displayBoard(board);

    // Sample move: Move a pawn
    movePiece(board, 1, 0, 3, 0); // Moving the pawn from (1,0) to (3,0)

    // Display the board after the move
    cout << endl;
    displayBoard(board);

    return 0;
}
