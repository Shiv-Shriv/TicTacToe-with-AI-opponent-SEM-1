#include<stdio.h>
#include<time.h>
#include<stdlib.h>

char grid[3][3];
int p1 = 2;
int winner = 0;
int win1 = 0;
int win2 = 0;
int AI = 0;
int move1 = 0;

int playAgain();
int AIMove();
int AIEasy();
int AICheckwin();
int printLeaderboard();
void printgrid();
void playermove();
void checkwin();

int AICheckwin(){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if((grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2])&&grid[i][0]!=' '){
                winner = 1;

            }
            else if((grid[0][j]==grid[1][j]&&grid[1][j]==grid[2][j])&&grid[0][j]!=' '){
                winner = 1;

            }
            else if((grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2])&&grid[0][0]!=' '){
                winner = 1;

            }
            else if((grid[0][2]==grid[1][1]&&grid[1][1]==grid[2][0])&&grid[1][1]!=' '){
                winner = 1;

            }
        }
    }

    if(winner == 0){
            int full = 1;

            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(grid[i][j]==' '){
                        full = 0;
                    }
                }
            }

            if(full == 0){
                if(p1==2){
                    AIMove();
                    printf("The AI has made the following move\n");
                }

                else if(p1==1){
                    AIEasy();
                }
    }
            else{
                printf("The match is tied.\n");
                playAgain();
            }
    }

    else{
        if(p1 == 1){
        p1=2;
        win2++;
        printf("\nYou have lost the game!\n");
    }
        else{
        p1=1;
        win1++;
        printf("\nYou have won the game!\n");
    }

        printLeaderboard();

        playAgain();
    }
    return 0;
}

int firstmove(){

    printf("Would the player like to make the first move? (Enter Y/N)\n");
    char c;
    scanf(" %c", &c);

    if(c =='Y'){
        move1 = 1;
    }

    else if(c == 'N'){
        move1 = 0;
        p1=1;
    }

    else{
        printf("Invalid Choice. Try again.\n");
        firstmove();
    }

    return 0;
}

int chooseMode(){
    int a;
    printf("Would you like to play against AI or against friend\n(Enter 1 for AI, 2 for friend)\n");
    scanf("%d", &a);
    if(a == 1){
        AI = 1;
    }
    else if(a==2){
        AI = 0;
    }
    else{
        printf("Invalid Choice. Try again.\n");
        chooseMode();
    }
    return 0;
}

int AIMove(){
    int a1;
    int b1;

    a1 = rand() % 3;
    b1 = rand() % 3;

    if(move1 == 1){
        if(grid[a1][b1]!=' '){
        AIMove();
    }
        else{
        grid[a1][b1] = 'X';
    }
    }
    else{
       if(grid[a1][b1]!=' '){
        AIMove();
    }
        else{
        grid[a1][b1] = 'O';
    }
    }
    printgrid();
    AICheckwin();
    return 0;
}

int AIEasy(){
if(move1==1){

    int a;
    int b;
    printf("\nPlayer, make your move (e.g: for the first row, second column, enter 1 2)\n");
    scanf("%d%d", &a, &b);
    if(grid[a-1][b-1]!=' '){
        printf("Invalid move, try again.\n");
        AIEasy();
    }
    else{
        grid[a-1][b-1] = 'O';
        printgrid();
        AICheckwin();
    }

}
    else{
    if(p1 == 2){
        printf("The AI has made the following move\n");
        AIMove();
    }
    else{

    int a;
    int b;
    printf("\nPlayer, make your move (e.g: for the first row, second column, enter 1 2)\n", p1);
    scanf("%d%d", &a, &b);
    if(grid[a-1][b-1]!=' '){
        printf("Invalid move, try again.\n");
        AIEasy();
    }
    else{
        grid[a-1][b-1] = 'X';
        printgrid();
        AICheckwin();
    }
    }
    }
    return 0;
}


int printLeaderboard(){
    if(AI == 0){


    printf("\n------WINS LEADERBOARD------\n");
    printf("Player 1: %d Win(s) ", win1);
    printf("  Player 1: %d Win(s)\n", win2);
    }

    if(AI == 1){
    printf("\n------WINS LEADERBOARD------\n");
    printf("Player 1: %d Win(s) ", win1);
    printf("AI: %d Win(s)\n", win2);
    }
    return 0;
}

int playAgain(){
    printf("Would you like to play again? (Enter Y/N)\n");
    char c;
    scanf(" %c", &c);
    if(c=='Y'){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    grid[i][j]=' ';
                }
            }
        if(AI==0){
        printgrid();
        printf("Player 1 plays O, Player 2 plays X\nPlayer 1 goes first\n");
        winner = 0;
        playermove();
        }
        else if(AI==1){
            winner = 0;
            p1 = 2;
                firstmove();

                if (move1 == 1){
                    printf("Player plays O, AI plays X, Player makes the first move\n");
                }
                else{
                    printf("Player plays X, AI plays O, AI makes the first move\n");
                }

                printgrid();
                AIEasy();
        }
    }
    else if(c=='N'){
    if(AI == 0){
        if(win1>win2){
            printf("Player 1 has the most wins!\n");
        }
        else if(win2>win1){
            printf("Player 2 has the most wins!\n");
        }
        else{
            printf("Both players tied on the leaderboard!\n");
        }
        printf("Thank you for playing!\n");
        exit(0);
    }
    else{
         if(win1>win2){
            printf("The player has the most wins!\n");
        }
        else if(win2>win1){
            printf("The AI has the most wins!\n");
        }
        else{
            printf("The player and the AI tied on the leaderboard!\n");
        }
        printf("Thank you for playing!\n");
        exit(0);
    }
    }
    else{
        printf("Invalid Choice, try again.\n");
        playAgain();
    }
    return 0;
}

void printgrid(){
    printf("\n");
    int i;
    for(i=0; i<3; i++){
        printf(" %c | %c | %c ", grid[i][0], grid[i][1], grid[i][2]);
        if(i<2){
                printf("\n-----------\n");
        }
    }
    printf("\n");
    if(p1 == 1){
        p1=2;
    }
    else{
        p1=1;
    }
}

void playermove(){
    int a;
    int b;
    printf("\nPlayer %d, make your move (e.g: for the first row, second column, enter 1 2)\n", p1);
    scanf("%d%d", &a, &b);
    if(grid[a-1][b-1]!=' '){
        printf("Invalid move, try again.\n");
        playermove();
    }
    else{
         if(p1==1){
            grid[a-1][b-1] = 'O';
        }
        else{
            grid[a-1][b-1] = 'X';
        }
        printgrid();
        checkwin();
    }
}

void checkwin(){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if((grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2])&&grid[i][0]!=' '){
                winner = 1;
            }
            else if((grid[0][j]==grid[1][j]&&grid[1][j]==grid[2][j])&&grid[0][j]!=' '){
                winner = 1;
            }
            else if((grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2])&&grid[0][0]!=' '){
                winner = 1;
            }
            else if((grid[0][2]==grid[1][1]&&grid[1][1]==grid[2][0])&&grid[1][1]!=' '){
                winner = 1;
            }
        }
    }

    if(winner == 0){
            int full = 1;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(grid[i][j]==' '){
                        full = 0;
                    }
                }
            }
            if(full == 0){
        playermove();
    }
            else{
                printf("The match is tied.\n");
                playAgain();
            }
    }
    else{
        if(p1 == 1){
        p1=2;
        win2++;
    }
    else{
        p1=1;
        win1++;
    }
        printf("\nThe winner is Player %d.\nCongratulations!\n", p1);
        printLeaderboard();
        playAgain();

    }
}


int main(){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            grid[i][j]=' ';
        }
    }

    chooseMode();

    if(AI == 0){
    printgrid();

    printf("Player 1 plays O, Player 2 plays X\nPlayer 1 goes first\n");

    playermove();
    }

    if(AI == 1){
                firstmove();

                if (move1 == 1){
                    printf("Player plays O, AI plays X, Player makes the first move\n");
                }
                else{
                    printf("Player plays X, AI plays O, AI makes the first move\n");
                }

                printgrid();
                AIEasy();

    }


    return 0;
}
