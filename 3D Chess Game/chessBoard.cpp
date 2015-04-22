#include <iostream>
#include "chessBoard.h"

using namespace std;

chessBoard::chessBoard()
{
    //This is the default constructor for the chess board class
    //It sets the board size as 6x6x6 initially, and gives each player 18 pieces

    boardSize = 6;
    //First create the board
    board = new chessPiece ***[boardSize];
    for(int x = 0; x < boardSize; x++){
        board[x] = new chessPiece **[boardSize];
        for(int y = 0; y < boardSize; y++){
            board[x][y] = new chessPiece *[boardSize];
            for(int z = 0; z < boardSize; z++){
                //board[x][y][z] = new chessPiece;
                cout<<"Place created at: ";
                cout<<x<<", "<<y<<", "<<z<<endl;
                board[x][y][y] = NULL;
            }
        }
    }

    //Create pieces for player 1 and player 2
    int pieceCount = 0;
    for(int x = 0; x < boardSize; x++){
        for(int y = 0; y < boardSize/4; y++){
            //Frontmost pieces on the board
            for(int z = boardSize/4; z < 3*boardSize/4; z++){
                chessPiece *p1piece = new chessPiece;
                p1piece->pieceType = "Pawn";
                p1piece->team = 1;
                p1piece->xMoves = 1;
                p1piece->yMoves = 1;
                p1piece->zMoves = 1;
                board[x][y][z] = p1piece;
                cout<<"Player 1 piece created at: "<<x<<", "<<y<<", "<<z<<endl;

                chessPiece *p2piece = new chessPiece;
                p2piece->pieceType = "Pawn";
                p2piece->team = 2;
                p2piece->xMoves = 1;
                p2piece->yMoves = 1;
                p2piece->zMoves = 1;
                board[x][boardSize-y-1][z] = p2piece;
                cout<<"Player 2 piece created at: "<<x<<", "<<boardSize-y-1<<", "<<z<<endl<<endl;

                pieceCount++;
            }
        }
    }

    //Set initial piece counters;
    p1count = pieceCount;
    p2count = pieceCount;
    cout<<"p1count and p2count set to: "<<pieceCount<<endl;
    p1taken = 0;
    p2taken = 0;
    cout<<"p1taken and p2taken set to: "<<0<<endl;
}

chessBoard::chessBoard(int limit)
{
    //This is the variable board constructor
    //It can be used to create a cube shaped board with side length limit

    boardSize = limit;
    //First create the board
    board = new chessPiece ***[boardSize];
    for(int x = 0; x < boardSize; x++){
        board[x] = new chessPiece **[boardSize];
        for(int y = 0; y < boardSize; y++){
            board[x][y] = new chessPiece *[boardSize];
            for(int z = 0; z < boardSize; z++){
                //board[x][y][z] = new chessPiece;
                cout<<"Place created at: ";
                cout<<x<<", "<<y<<", "<<z<<endl;
                board[x][y][y] = NULL;
            }
        }
    }

    //Create pieces for player 1 and player 2
    int pieceCount = 0;
    for(int x = 0; x < boardSize; x++){
        for(int y = 0; y < boardSize/4; y++){
            //Frontmost pieces on the board
            for(int z = boardSize/4; z < 3*boardSize/4; z++){
                chessPiece *p1piece = new chessPiece;
                p1piece->pieceType = "Pawn";
                p1piece->team = 1;
                p1piece->xMoves = 1;
                p1piece->yMoves = 1;
                p1piece->zMoves = 1;
                p1piece->xPosition = x;
                p1piece->yPosition = y;
                p1piece->zPosition = z;
                board[x][y][z] = p1piece;
                cout<<"Player 1 piece created at: "<<x<<", "<<y<<", "<<z<<endl;

                chessPiece *p2piece = new chessPiece;
                p2piece->pieceType = "Pawn";
                p2piece->team = 2;
                p2piece->xMoves = 1;
                p2piece->yMoves = 1;
                p2piece->zMoves = 1;
                p2piece->xPosition = x;
                p2piece->yPosition = boardSize-y-1;
                p2piece->zPosition = z;
                board[x][boardSize-y-1][z] = p2piece;
                cout<<"Player 2 piece created at: "<<x<<", "<<boardSize-y-1<<", "<<z<<endl<<endl;

                pieceCount++;
            }
        }
    }

    //Set initial piece counters;
    p1count = pieceCount;
    p2count = pieceCount;
    cout<<"p1count and p2count set to: "<<pieceCount<<endl;
    p1taken = 0;
    p2taken = 0;
    cout<<"p1taken and p2taken set to: "<<0<<endl;
}

chessBoard::~chessBoard()
{
    //Destructor

    //Delete all of the pointers in the array
    /*
    for(int x = 0; x < boardSize; x++){
        for(int y = 0; y < boardSize; y++){
            cout<<"Deleting array: ("<<x<<", "<<y<<")"<<endl;
            delete [] board[x][y];
            /*for(int z = 0; z < boardSize; z++){
                //board[x][y][z] = new chessPiece;
                cout<<"Place created at: ";
                cout<<x<<", "<<y<<", "<<z<<endl;
                board[x][y][y] = NULL;
            }
        }
    }*/
    delete [] board;
}

void createPiece()
{
    //This method will be implemented at a later time
}

void deletePiece()
{
    //This method will be used to delete a piece either at the end of the game or during an attack move
}

void movePiece()
{
    //This method is for moving a piece during the game
    //It will check for piece encounters and it will act accordingly
}

chessPiece *locatePieces(std::string)
{
    //This function will be implemented at a later time
}

void p1Attack()
{
    //This function will need some thought about functionality before coding
}

void p2Attack()
{
    //This function is like p1Attack and may be absorbed into that method
}
