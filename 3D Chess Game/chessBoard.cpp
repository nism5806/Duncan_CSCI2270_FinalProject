#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdlib>
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
            for(int z = 0; z < boardSize; z++){
                //board[x][y][z] = new chessPiece;
                cout<<"Place created at: ";
                cout<<x<<", "<<y<<", "<<z<<endl;
                board[x][y][y] = NULL;
            }
        }
    }*/
    delete []board;
}

void chessBoard::createPiece()
{
    //This method will be implemented at a later time
}

void chessBoard::deletePiece(chessPiece *piece)
{
    //This method will be used to delete a piece either at the end of the game or during an attack move
    //This maybe also used by the move function

    //The placement on the board needs to be cleared and the pointer in the respective array removed
    //First the placement
    board[piece->xPosition][piece->yPosition][piece->zPosition] = NULL;

    //Now the array
    int index;
    if(piece->team == 1){
        //player 1 piece
        for(unsigned int i = 0; i < p1Pieces.size(); i++){
            if(piece == p1Pieces[i]){
                index = i;
                cout<<"Deletion index set"<<endl;
                p1count--;
                p2taken++;
                break;
            }
        }
        p1Pieces.erase(p1Pieces.begin()+index);
    }
    else{
        for(unsigned int i = 0; i < p2Pieces.size(); i++){
            if(piece == p2Pieces[i]){
                index = i;
                cout<<"Deletion index set"<<endl;
                p2count--;
                p1taken++;
                break;
            }
        }
        p2Pieces.erase(p2Pieces.begin()+index);
    }
}

/*void chessBoard::movePiece()
{
    //This method is for moving a piece during the game
    //It will check for piece encounters and it will act accordingly
}*/
void chessBoard::movePiece(chessPiece* piece)
{
    //This method is for moving a piece during the game
    //It will check for piece encounters and it will act accordingly
    int xPos = piece->xPosition;
    int yPos = piece->yPosition;
    int zPos = piece->yPosition;
    vector<string> moves;
    vector<string> attacks;

    /*bool possibleMoves[27];
    //Set all the possible locations to zero
    for(int i = 0; i < 27; i++){
        possibleMoves[i] = false;
    }*/
    if(xPos-piece->xMoves>=0){
        if(isPiece(xPos-piece->xMoves,yPos,zPos)&&getPiece(xPos-piece->xMoves,yPos,zPos)->team!=piece->team){
            attacks.push_back(to_string(xPos-piece->xMoves)+to_string(yPos)+to_string(zPos));
        }else{
            moves.push_back(to_string(xPos-piece->xMoves)+to_string(yPos)+to_string(zPos));
        }
    }
    if(xPos+piece->xMoves<boardSize){
        if(isPiece(xPos+piece->xMoves,yPos,zPos)&&getPiece(xPos+piece->xMoves,yPos,zPos)->team!=piece->team){
            attacks.push_back(to_string(xPos+piece->xMoves)+to_string(yPos)+to_string(zPos));
        }else{
            moves.push_back(to_string(xPos+piece->xMoves)+to_string(yPos)+to_string(zPos));
        }
    }
    if(yPos-piece->yMoves>=0){
        if(isPiece(xPos,yPos-piece->yMoves,zPos)&&getPiece(xPos,yPos-piece->yMoves,zPos)->team!=piece->team){
            attacks.push_back(to_string(xPos)+to_string(yPos-piece->yMoves)+to_string(zPos));
        }else{
            moves.push_back(to_string(xPos)+to_string(yPos-piece->yMoves)+to_string(zPos));
        }
    }
    if(yPos+piece->yMoves<boardSize){
        if(isPiece(xPos,yPos+piece->yMoves,zPos)&&getPiece(xPos,yPos+piece->yMoves,zPos)->team!=piece->team){
            attacks.push_back(to_string(xPos)+to_string(yPos+piece->yMoves)+to_string(zPos));
        }else{
            moves.push_back(to_string(xPos)+to_string(yPos+piece->yMoves)+to_string(zPos));
        }
    }
    if(zPos-piece->zMoves>=0){
        if(isPiece(xPos,yPos,zPos-piece->zMoves)&&getPiece(xPos,yPos,zPos-piece->zMoves)->team!=piece->team){
            attacks.push_back(to_string(xPos)+to_string(yPos)+to_string(zPos-piece->zMoves));
        }else{
            moves.push_back(to_string(xPos)+to_string(yPos)+to_string(zPos-piece->zMoves));
        }
    }
    if(zPos+piece->zMoves<boardSize){
        if(isPiece(xPos,yPos,zPos+piece->zMoves)&&getPiece(xPos,yPos,zPos+piece->zMoves)->team!=piece->team){
            attacks.push_back(to_string(xPos)+to_string(yPos)+to_string(zPos+piece->zMoves));
        }else{
            moves.push_back(to_string(xPos)+to_string(yPos)+to_string(zPos+piece->zMoves));
        }
    }
    /**
    int possIndex = 0;
    //Display possible move and attack locations
    for(int i = -1; i <= 1; i++){
        //Check the previous and next x position
        for(int j = -1; j <= 1; j++){
            //Check the previous and next y position
            for(int k = -1; k <= 1; k++){
                //Check the previous and next z position
                if(xPos+i >= 0 && xPos+i < boardSize && yPos+j >= 0 && yPos+j < boardSize && zPos+k >= 0 && zPos+k < boardSize){
                    if((i+j+k == 1 || i+j+k == -1) && (i == 0 || j == 0 || k == 0)){
                        //This is a move location
                        if(!isPiece(xPos+i,yPos+j,zPos+k)){
                            //The move location is valid
                            moves.push_back(to_string(i+xPos)+to_string(j+yPos)+to_string(k+zPos));
                        }
                    }
                    else if(i == 0 && j == 0 && k == 0){
                        //This is the piece location. Do nothing
                    }
                    else{
                        //This is an attack location
                        chessPiece *tempPiece = getPiece(xPos+i,yPos+j,zPos+k);
                        if(tempPiece != NULL){
                            if(tempPiece->team != piece->team){
                                //Opposite teams
                                attacks.push_back(to_string(i+xPos)+to_string(j+yPos)+to_string(k+zPos));
                            }
                        }
                    }
                    possIndex++;
                }
            }
        }
    }
    **/
    cout<<"Possible moves"<<endl;
    for(int i = 0; i < moves.size(); i++){
        if(i == 0){
            cout<<moves[i];
        }
        else{
            cout<<", "<<moves[i];
        }
    }
    cout<<endl<<"Possible attacks"<<endl;
    for(int i = 0; i < attacks.size(); i++){
        if(attacks[i] != ""){
            if(i == 0){
                cout<<attacks[i];
            }
            else{
                cout<<", "<<attacks[i];
            }
        }
    }
    cout<<endl;

    //Now ask for a movement location
    string input;
    string moveto;
    int x,y,z;
    bool attack = false;
    while(true){
        bool choice = false;
        cout<<"Where would you like to move?"<<endl;
        getline(cin,input,'\n');
        for(int i = 0; i < moves.size(); i++){
            if(input == moves[i]){
                moveto = moves[i];
                x = moveto[0]-'0';
                y = moveto[1]-'0';
                z = moveto[2]-'0';
                choice = true;
            }
        }
        for(int i = 0; i < attacks.size(); i++){
            if(input == attacks[i]){
                moveto = attacks[i];
                x = moveto[0]-'0';
                y = moveto[1]-'0';
                z = moveto[2]-'0';
                attack = true;
                choice = true;
            }
        }
        if(!choice){
            cout<<"Not a valid move"<<endl;
        }else{
            break;
        }
    }

    if(attack){
        deletePiece(getPiece(x,y,z));
        if(piece->team == 1){
            p1taken ++;
        }else{
            p2taken ++;
        }
    }else{
        piece->xPosition = x;
        piece->yPosition = y;
        piece->zPosition = z;
    }
}
/**
    Function Prototype:
    vector<chessPiece*> locatePieces(std::string name)

    Function description:
    returns a vector containing all pieces of the type name


**/
vector<chessPiece*> chessBoard::locatePieces(std::string name)
{
    vector<chessPiece*> pieces;
    for(int x = 0; x < boardSize; x++){
        for(int y = 0; y < boardSize; y++){
            for(int z = 0; z < boardSize; z++){
                if(board[x][y][z]->pieceType ==name){
                    pieces.push_back(board[x][y][z]);
                }
            }
        }
    }
    return pieces;
}

void chessBoard::printBoard()
{
    //Print the contents of the board
    for(int x = 0; x < boardSize; x++){
        for(int y = 0; y < boardSize; y++){
            for(int z = 0; z < boardSize; z++){
                if(board[x][y][z] != NULL){
                    //There is a piece here
                    cout<<"Player "<<board[x][y][z]->team<<" "<<board[x][y][z]->pieceType<<endl;
                    cout<<"Located at: ("<<x<<","<<y<<","<<z<<")"<<endl<<endl;
                }
            }
        }
    }
}

bool chessBoard::isPiece(int x, int y, int z)
{
    //Is it within the boundaries of the board?
    if(x >= 0 && x < boardSize && y >= 0 && y < boardSize && z >= 0 && z < boardSize){
        //Is there a game piece at this location?
        if(board[x][y][z] != NULL){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

chessPiece *chessBoard::getPiece(int x, int y, int z)
{
    //This method should return a pointer to a piece
    if(isPiece(x,y,z)){
        return board[x][y][z];
    }
    else{
        //cout<<"There is no piece there"<<endl;
        return NULL;
    }
}

void chessBoard::pieceFunctions(int player)
{
    //Piece function stuff
    vector<chessPiece*> temp;
    if(player == 1){
        //Player one pieces
        temp = p1Pieces;
    }
    else{
        //Player two pieces
        temp = p2Pieces;
    }



    //Display menu of possible actions;
    string input;
    chessPiece *tempPiece;
    while(true){
        cout<<"What will you do?"<<endl;
        cout<<"1) Print Board"<<endl;
        cout<<"2) Move Piece"<<endl;

        getline(cin, input);
        if(atoi(input.c_str()) == 1){
            //Print all the pieces on the board
            printBoard();
        }
        else if(atoi(input.c_str()) == 2){
            //Display player pieces
            cout<<"Available pieces and locations"<<endl;
            for(int i = 0; i < temp.size(); i++){
                cout<<i<<": "<<temp[i]->pieceType<<" ("<<temp[i]->xPosition<<","<<temp[i]->yPosition<<","<<temp[i]->zPosition<<")"<<endl;
            }

            //Select a piece and them move it
            cout<<"Select a piece to move"<<endl;
            getline(cin, input);
            if(atoi(input.c_str()) >= 0 && atoi(input.c_str()) < temp.size()){
                int x,y,z;
                tempPiece = temp[atoi(input.c_str())];
                cout<<"Selected: "<<tempPiece->pieceType<<endl<<endl;
                cout<<"Enter x, y and z moves separated by a space"<<endl;
                //cin>>x>>y>>z;
                movePiece(tempPiece);
                break;
            }
            else{
                cout<<"Invalid Input"<<endl;
            }
        }
        else{
            cout<<"Invalid Input"<<endl;
        }
    }

}

void chessBoard::gameStandings()
{
    cout<<"Player 1 had: "<<p1count<<" pieces left"<<endl;
    cout<<"              taken "<<p1taken<<" pieces"<<endl<<endl;
    cout<<"Player 1 had: "<<p2count<<" pieces left"<<endl;
    cout<<"              taken "<<p2taken<<" pieces"<<endl<<endl;
    cout<<"Thanks for playing! Goodbye!"<<endl;
}
