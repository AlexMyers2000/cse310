# Overview

{This project was to work in C++ and I chose to build a chess game that is able to be ran through a termial window. I was able to achive this goal and do hope to expand upon this in the future.}

{I wanted to test my skills in C++ and see what i was able to create. I was able to create the board and pieces and make them have the ability to move and have restictions where they cant move just anywhere on the board}



[Software Demo Video](Still uploading to youtube will post in comments section when its up)

# Development Environment

Standard Libraries: The code includes several standard C++ libraries:

<iostream>: Provides input/output streams, used for console output.
<vector>: Implements dynamic arrays, used for representing the chess board and pieces.
<string>: Provides string manipulation functionalities, used for representing colors of the chess pieces.
Structs and Enums: The code utilizes structs and enums to represent chess pieces and their types:

PieceType: An enum representing different types of chess pieces like Pawn, Rook, Knight, etc.
Piece: A struct representing a chess piece, containing its type, symbol, and color.
Functions: Several functions are defined to handle different aspects of the chess game:

initializeBoard(): Initializes the chess board with pieces in their initial positions.
displayBoard(): Displays the current state of the chess board.
isSquareOccupied(): Checks if a square on the board is occupied by a piece.
isValidMove(): Checks if a move is within the bounds of the chess board.
isValidMoveForPiece(): Placeholder function to check if a move is valid for a specific piece type.
capturePiece(): Placeholder function to handle capturing opponent's pieces.
movePiece(): Moves a piece on the board, handling capturing and validity checks.
Main Function: The main() function serves as the entry point of the program. It initializes the chess board and currently doesn't contain the game loop or user input handling logic.

# Useful Websites

- [W3 Schools](https://www.w3schools.com/cpp/)
- [Cplusplus](https://cplusplus.com/reference/stl/)

# Future Work

- I hope that i will be able to add graphics and actual images of each piece
- I hope to implement an ai side that will play against the user and have different levels for beginners to experts 
- I hope to implement a better board as well as just overal looks and possibly have the options for changing if you wanted to. 

Chat gpt was used to generate answers