#include <iostream>
#include <stdlib.h>
#include "chessBoard.h"

using namespace std;

void displayMenu()
{
    cout<<"==========Menu=========="<<endl;
    cout<<"1) Play"<<endl;
    cout<<"2) Quit"<<endl;
}

int main()
{
    chessBoard board;

    //board.printBoard();

    int playerTurn = 1;
    string input;
    bool turn;
    while(true){
        //Game is still going, both players still have pieces
        turn = false;
        cout<<"========================"<<endl;
        cout<<"Player "<<playerTurn<<"'s Turn"<<endl;
        displayMenu();

        getline(cin, input);
        if(atoi(input.c_str()) == 1){
            //Display the available pieces
            //Display piece menu
            board.pieceFunctions(playerTurn);
            turn = true;
        }
        else if(atoi(input.c_str()) == 2){
            board.gameStandings();
            break;
            //Display current game standings and then quit
        }
        else{
            cout<<"Invalid Input"<<endl;
        }

        if(turn){
            if(playerTurn == 1){
                playerTurn++;
            }
            else{
                playerTurn--;
            }
        }
    }
}
