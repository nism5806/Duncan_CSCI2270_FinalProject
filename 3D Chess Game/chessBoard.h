#include <iostream>

#ifndef chessboard.h
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

class chessBoard
{
protected:
public:
    chessBoard();
    chessBoard(int);
    ~chessBoard();
    void createPiece(); //Implemented later
    void deletePiece();
    void movePiece();
    chessPiece *locatePieces(std::string); //Implemented later
    void p1Attack();    //Unsure of how this should work exactly, may need editing
    void p2Attack();
private:
    int boardSize;
    chessPiece ****board;
    int p1count;    //Pieces left
    int p2count;
    int p1taken;    //Pieces taken from the enemy
    int p2taken;
};
#endif // chessboard
