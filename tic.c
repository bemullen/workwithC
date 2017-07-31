#include <stdio.h>
// Template comes from CS210 at Boston University

//Our board locations:
char board[3][3] =
  {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
  };
void print_board() { //prints our tic tac toe board
  printf("\n\n");
  printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
  printf("-----------\n");
  printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
  printf("-----------\n");
  printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int test_diagonals(){ //tests to see if there is 3 diagonally 
 
  if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
    return 1;
  }
  else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
    return 1;
  }
  else{
    return 0; 
  }
}

int test_rows_cols(){ // tests to see if there is 3 across or down
  int row;
  int col;

  for(row = 0; row < 3; row++){  //testing rows
    if(board[row][0] == board[row][1] && board[row][1] == board[row][2]){
      return 1;
    }
    for(col = 0; col < 3; col++){  //testing columns
      if (board[0][col] == board[1][col] && board[1][col] == board[2][col]){
	return 1;
      }
    }
  } 
  return 0;
}
 

void main(void) //the main function where our testing functions will be implemented
{
  int i;
  int player;
  int go;
  int row;
  int column;
  int winner = 0;

  for (i = 0; i<9 && winner==0; i++) 
    {
      print_board();
      player = i%2 + 1;

      do
	{
	  printf("\nPlayer %d, please enter the number of the square "
		 "where you want to place your %c: ",player,(player==1)?'X':'O');
	  scanf("%d", &go);

	  row = (go-1)/3;
	  column = (go-1)%3;
	}
      while (go<1 || go>9 || board[row][column] > '9');

      board[row][column] = (player == 1) ? 'X' : 'O';
 
      //testing both diagonals and rows/cols
 
      if (test_diagonals())
	winner = player;
      else
	if (test_rows_cols())
	  winner = player;

    }
  print_board();

  if (winner == 0)
    printf("\nDraw\n");
  else
    printf("\nplayer %d, YOU WON!\n", winner);
}


