#include <iostream>
#include <string>
#include <stdlib.h>
#include "chessBoardRob.h"

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
                p1Pieces.push_back(p1piece);
                cout<<"Player 1 piece created at: "<<x<<", "<<y<<", "<<z<<endl;

                chessPiece *p2piece = new chessPiece;
                p2piece->pieceType = "Pawn";
                p2piece->team = 2;
                p2piece->xMoves = 1;
                p2piece->yMoves = 1;
                p2piece->zMoves = 1;
                board[x][boardSize-y-1][z] = p2piece;
                p2Pieces.push_back(p2piece);
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
                p1Pieces.push_back(p1piece);
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
                p2Pieces.push_back(p2piece);
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

void chessBoard::createPiece()
{
    //This method will be implemented at a later time
}

void chessBoard::deletePiece()
{
    //This method will be used to delete a piece either at the end of the game or during an attack move
}

void chessBoard::movePiece(chessPiece* piece)
{
    //This method is for moving a piece during the game
    //It will check for piece encounters and it will act accordingly
    //Wait until the player has moved a piece
    bool moved = false;
    while(!moved){


        //First print out the locations that the piece can normal move to
        cout<<"Available locations to move:"<<endl;
        int x,y,z,poss;
        string;
        bool exist;
        string possIndex [26];
        for(int i = 0; i < 25; i ++){
            possIndex[i] = "";
        }
        poss = 0;

        //Print out the locations a piece can move to
        cout<<"Available locations to attack:"<<endl;
        for(int i = 1; i < 3; i++){
            for(int j = 1; j < 3; j++){
                for(int k = 1; k < 3; k++){

                    //Check to see if the location is a move or attack location
                    int zeros = 0;
                    if(i == 2){
                        zeros ++;
                    }
                    if(j == 2){
                        zeros ++;
                    }
                    if(k == 2){
                        zeros ++;
                    }

                    //Check if it is a move location, attack location, or original spot
                    if(zeros == 2){
                        //Move array to be implemented later
                        x = piece->xPosition + (-2+i);
                        y = piece->yPosition + (-2+j);
                        z = piece->zPosition + (-2+k);
                        exist = isPiece(x,y,z);
                        if(!exist){
                            index = to_string[x]+to_string[y]+to_string[z]+"m";
                            possIndex[poss] = index;
                            cout<<"Move location "<<poss<<" : "<<x<<":"<<y<<":"<<z<<endl;
                            poss ++;
                        }
                    }
                    if(zeros != 2 && zeros != 3){
                        x = piece->xPosition + (-2+i);
                        y = piece->yPosition + (-2+j);
                        z = piece->zPosition + (-2+k);
                        exist = isPiece(x,y,z);
                        chessPiece *current = getPiece(x,y,z);
                        if(current.team != piece.team){
                            index = to_string[x]+to_string[y]+to_string[z]+"a";
                            possIndex[poss] = index;
                            cout<<"Attack location "<<poss<<" : "<<x<<":"<<y<<":"<<z<<endl;
                            poss ++;
                        }
                    }
                }
            }
        }

        //Ask user which indexed location they would like to move to
        while(true){
           cout<<"Which location would you like to move your piece to? (Please enter an index)"<<endl;
            int input;
            cin>>input;
            if(input > 0 && input < poss){
                break;
            }else{
                cout<<"Not a valid index"<<endl;
            }
        }

        string location = possIndex[input];
        board[piece->xPosition][piece->yPosition][piece->zPosition] = NULL;
        if(location[4] == "a"){
            for(int a = 0; a < 3; a++){
                if(location[a] == "1"){
                    if(a == 0){
                        x = piece->xPosition-1;
                    }
                    if(a == 1){
                        y = piece->yPosition-1;
                    }
                    if(a == 2){
                        z = piece->zPosition-1;
                    }
                }else if(location[a] == "2"){
                    if(a == 0){
                        x = piece->xPosition;
                    }
                    if(a == 1){
                        y = piece->yPosition;
                    }
                    if(a == 2){
                        z = piece->zPosition;
                    }
                }else{
                    if(a == 0){
                        x = piece->xPosition+1;
                    }
                    if(a == 1){
                        y = piece->yPosition+1;
                    }
                    if(a == 2){
                        z = piece->zPosition+1;
                    }
                }
            }
            piece->xPosition = x;
            piece->yPosition = y;
            piece->zPosition = z;
            chessPiece *piece2 = getPiece(x,y,z);
            deletePiece(piece2);
        }else{
            for(int a = 0; a < 3; a++){
                if(location[a] == "1"){
                    if(a == 0){
                        x = piece->xPosition-1;
                    }
                    if(a == 1){
                        y = piece->yPosition-1;
                    }
                    if(a == 2){
                        z = piece->zPosition-1;
                    }
                }else if(location[a] == "2"){
                    if(a == 0){
                        x = piece->xPosition;
                    }
                    if(a == 1){
                        y = piece->yPosition;
                    }
                    if(a == 2){
                        z = piece->zPosition;
                    }
                }else{
                    if(a == 0){
                        x = piece->xPosition+1;
                    }
                    if(a == 1){
                        y = piece->yPosition+1;
                    }
                    if(a == 2){
                        z = piece->zPosition+1;
                    }
                }
            }
        piece->xPosition = x;
        piece->yPosition = y;
        piece->zPosition = z;
        }
        moved = true;
    }
}

chessPiece *chessBoard::locatePieces(std::string)
{
    //This function will be implemented at a later time
}

void chessBoard::p1Attack()
{

}

void chessBoard::p2Attack()
{
    //This function is like p1Attack and may be absorbed into that method
}

void chessBoard::isPiece(int x, int y, int z)
{
    if(board[x][y][z] != NULL){
        return true;
    }
    else{
        return false;
    }
}
