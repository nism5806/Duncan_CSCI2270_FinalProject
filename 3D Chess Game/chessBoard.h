#ifndef CHESSBOARD_INCLUDED
#define CHESSBOARD_INCLUDED
#include <iostream>
#include <vector>


struct chessPiece
{
    std::string pieceType;
    int team;
    int xMoves;
    int yMoves;
    int zMoves;

    int xPosition;
    int yPosition;
    int zPosition;
};

struct boardInfo
{
    void printBoard(){};
};

class chessBoard
{
protected:
public:
    chessBoard();
    chessBoard(int);
    ~chessBoard();
    void createPiece(); //Implemented later
    void deletePiece(chessPiece*);
    void movePiece(chessPiece*);
    std::vector<chessPiece*> locatePieces(std::string); //Implemented later
    void printBoard();
    bool isPiece(int, int, int);
    chessPiece *getPiece(int, int, int);
    void pieceFunctions(int);
    void gameStandings();
private:
    int boardSize;
    chessPiece ****board;
    int p1count;    //Pieces left
    int p2count;
    int p1taken;    //Pieces taken from the enemy
    int p2taken;

    std::vector<chessPiece*> p1Pieces;   //Used for quick access of pieces
    std::vector<chessPiece*> p2Pieces;
};
#endif // CHESSBOARD_INCLUDED
