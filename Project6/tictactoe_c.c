// A signature Nick Alvarez program, produced for Project 6, due October 30, 2018
/* This program will simulate a game of tic tac toe, with you playing against the computer.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3
#define O 'O'
#define X 'X'
#define _ '_'

//Displays the entire table
void display_table(char board[3][3])
{
  int r=0, c=0;
  printf("The current state of the game is:\n");
  //Displays the table by running a loop
  for (r=0; r<3; r++)
  {
    for (c=0; c<3; c++)
    {
      printf("%c ", board[r][c]);
    }
    printf("\n");
  }
}

//Replaces the entire table with underscores
void clear_table(char board[3][3])
{
  int r=0, c=0;
  //Sets board to underscores
  for (r=0; r<3; r++)
  {
    for (c=0; c<3; c++)
    {
      board[r][c]=_;
    }
  }
}

//Checks whether or not the table has any more underscores
_Bool check_table_full(char board[3][3])
{
  //Checks for underscores
  int r=0, c=0, i=0;
  for (r=0; r<3; r++)
  {
    for (c=0; c<3; c++)
    {
      if (board[r][c] == _)
      {
        i++;
      }
    }
  }
  if (i>=1)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

//Adds the specified token (X or O) to the table in the specified location
void update_table(char board[3][3], int r, int c, char token)
{
  board[r][c]=token;
}

/*Checks if the entered value is legal, by seeing if the values are contained
within the array and if so, that location is empty*/
_Bool check_legal_option(char board[3][3], int r, int c)
{
  if (r < 3 && c < 3)
  {
    if (board[r][c]==_)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }
}

//Checks if a win has occurred
int check_three_in_a_row(char board[3][3])
{
  int r=0, c=0;
  int counterO=0, counterX=0;

  //Checks across columns
  for (r=0; r<3; r++)
  {
    for(c=0; c<3; c++)
    {
      if (board[r][c]==O)
      {
        counterO++;
      }
      if (board[r][c]==X)
      {
        counterX++;
      }
    }
    if (counterO==3)
    {
      return 1;
    }
    if (counterX==3)
    {
      return 2;
    }
    counterO=0;
    counterX=0;
  }

  //Checks down columns
  for (c=0; c<3; c++)
  {
    for (r=0; r<3; r++)
    {
      if (board[r][c]==O)
      {
        counterO++;
      }
      if (board[r][c]==X)
      {
        counterX++;
      }
    }
    if (counterO==3)
    {
      return 1;
    }
    if (counterX==3)
    {
      return 2;
    }
    counterO=0;
    counterX=0;
  }

  //Checks diagonally
  if ((board[0][0]==O && board[1][1]==O && board[2][2]==O) || (board[2][0]==O && board[1][1]==O && board[0][2]==O))
    return 1;
  else if ((board[0][0]==X && board[1][1]==X && board[2][2]==X) || (board[2][0]==X && board[1][1]==X && board[0][2]==X))
    return 2;

  else
    return 0;
}

/*Checks if the game is over by testing if the table is full or three in a row
has been achieved*/
_Bool check_end_of_game(char board[3][3])
{
  if (check_table_full(board)==1 || check_three_in_a_row(board)>0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

/*Generates a move for player two, using a random value between 0 and 2, and
then checking if it is legal*/
void generate_player2_move(char board[3][3], int r, int c)
{
//  int randint_r=0, randint_c=0;
  srand(time(0));
  if (check_end_of_game(board)==0)
  {
    while (check_legal_option(board, r, c)==0)
    {
      r = rand() % 3;
      c = rand() % 3;
      check_legal_option(board, r, c);
    }
    update_table(board, r, c, X);
    printf("Player 2 has entered [row, col]: %d, %d\n", r+1, c+1);
    display_table(board);
  }
}

//Gets user input and checks if the input is legal
void get_player1_move(char board[3][3], int r, int c)
{
  if (check_end_of_game(board)==0)
  {
    do
    {
      printf("Player 1 enter your selection [row, col]: ");
      scanf("%d,%d", &r, &c);
      r-=1;
      c-=1;
      check_legal_option(board, r, c);
      if (check_legal_option(board, r, c)==0)
      {
        printf("Please enter a valid selection.\n");
      }
    } while (check_legal_option(board, r, c)==0);
    update_table(board, r, c, O);
    display_table(board);
  }
}

//Checks if the game is over, and prints the appropriate winner
void print_winner(char board[3][3])
{
  if (check_end_of_game(board)==1)
  {
    if (check_three_in_a_row(board)==1)
    {
      printf("Congratulations, Player 1 wins!\n");
    }
    else if (check_three_in_a_row(board)==2)
    {
      printf("Congratulations, Player 2 wins!\n");
    }
    else
    {
      printf("Game over, no player wins.\n");
    }
  }
}

int main()
{
  //Declare the tic-tac-toe board
  char board[SIZE][SIZE];

  //The row and column of the move for either player 1 or 2
  int row, col;
  char replay;

  do
  {
    //Clear the table
    clear_table(board);

    //Display the table
    display_table(board);

    do {
      //Have player 1 enter their move
      get_player1_move(board, row, col);

      //Generate player 2 move
      generate_player2_move(board, row, col);

      //Do this while the game hasn't ended
    } while(check_end_of_game(board) == 0);

    //After the game is over, print who won
    print_winner(board);

    //Asks user if they would want to replay the game
    printf("Would you like to play again (Y/N): ");
    scanf(" %c", &replay);
  } while (replay=='Y');
  return 0;
}
