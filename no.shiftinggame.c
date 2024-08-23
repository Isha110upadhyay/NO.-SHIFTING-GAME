#include<stdio.h>
#include<string.h>
#include<stdlib.h>      // library for using rand () function for generating random numbers
#include<time.h>        // header file for passing time as the seed value for the formula that will be used by the rand function
void gameRules()
{
    int i , j , k=1 ;
    char start;
    printf("\t\t\t  RULE OF THIS GAME  \n");
    printf(" 1.you can move only 1 step at a time by arrow key\n\t Move Up : by Up arrow key \n\t Move Down : by Down arrow key\n\t Move Left : by Left arrow key\n\t Move Right : by Right arrow key\n\n");
    printf(" 2.You can move number at empty position\n\n");
    printf(" 3.For each valid move : your total number of move will be decreased by 1\n\n");
    printf(" 4.Winning Situation : number in a 4X4 matrix should be in order from 1 to 15\nWinning Situation : ");
    printf("\n--------------------------\n");
    for(i=0 ; i<4 ; i++)
    {
        printf("| ");
        for(j=0 ; j<4 ; j++,k++)
        {
            if(k<=15)
              printf("%2d |",k);
            if(k==16)
                printf("%2c |",32);
        }
        printf("\n");
    }
    printf("--------------------------\n");
    printf(" 5.you can exit the game at any time by pressing 'E' or 'e'... ,\n So try to win in minimum no of move");
    printf("\n\n\t\t\t HAPPY GAMING , GOOD LUCK!\n\n");
    printf("Enter any key to start....");
    scanf("%c",&start);
}

void fillMatrix(int a[][4])
{
   int  i , j ;
    int num[15];
    for(i=0 ; i<15 ; i++)
    {
        num[i] = i+1;

    }
    int index , last_index = 14 ;
    // srand is a function which will provide the seed vale to the rand() function
    srand(time(NULL));      // time(NULL) (//null should be in capital letter )is the seed value that is generating or providing seconds , microseconds since the 1 january 1971 till this second of the day
    for(i=0 ; i<4 ; i++)
    {
        for(j=0 ; j<4 ; j++)
        {
            if(last_index >= 0)
            {
                index = rand() % (last_index+1);  // by performing modulus with 15 of any random number we can only get remainder between 0 to 14
                a[i][j] = num[index];
                num[index] = num[last_index--];
            }
        }
    }
    a[i-1][j-1] = 0 ;
}

void showMatrix(int a[][4])
{
    printf("\n--------------------------\n");
    int  i , j ;
    for(i=0 ; i<4 ; i++)
    {
        for(j=0 ; j<4 ; j++)
        {
            printf("| ");
            if(a[i][j] != 0)
                printf("%2d |",a[i][j]);    //%2d in C language pads the number with an empty space. The number should take less than 2 characters to display .In other words, in %10d , the 10 means that the field is ten characters wide, so for any numbers that take less than 10 characters (let suppose string is of length 4 , 5 , 6, etc) to display, it will be padded with a space to complete that length(i.e. of 6, 5 ,4) of 10 characers.
            else
                printf("   |");
        }
        printf("\n");
    }
    printf("--------------------------\n");
}

int win(int a[][4])
{
   int i , j , k , count = 0 ;
   int num[15];
    for(i=0 ; i<15 ; i++)
    {
        num[i] = i+1;

    }
   for(i=0 , k=0 ; i<4 ; i++)
   {
       for(j=0  ; j<4 ; j++ , k++)
       {
           if(a[i][j] == num[k])
                count++;
       }
   }
   if(a[i-1][j-1] == 0)
    count++;
   if(count == 16)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int readEnteredKey()
{
    int c ;
    c=getch();
    return c;
}


int shiftUp(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 3) // shifting not possible
        return 0;

    // Successfully swapped two numbers !
    swap(&arr[i][j], &arr[i + 1][j]);
    return 1; // Success
}

int shiftDown(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 0) // shifting not possible
        return 0;
    swap(&arr[i][j], &arr[i - 1][j]); // swap numbers

    return 1; // shift up success
}

int shiftRight(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (j == 0) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j - 1]);

    return 1; // shift up success
}

int shiftLeft(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }

    if (j == 3) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j + 1]);
    return 1; // shift up success
}
void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    printf("");
}


int main()
{
    int name[30] , a[4][4] , moves = 7 , key ;
    printf("\n\n\n player name : ");
    gets(name);
    while(1)
    {
        system("cls"); // 1. it's work is to clear the screen as clrscr(); was supported by turbo C++ not by codeblocks  \n 2. #include<windows.h> is not the header file for system("cls") function
        gameRules();
        system("cls");
        printf("player name : %s , moves remaining : %d ", name , moves);
        fillMatrix(a);
        showMatrix(a);
        while(!win(a))
        {
            int flag = 1 ;
            system("cls");
            printf("player name : %s , moves remaining : %d ", name , moves);
            showMatrix(a);
            key = readEnteredKey();
            if(moves >0)
            {
                switch(key)
                {
                    case 69: //ascii code of 'E' =69
                    case 101 ://ascii code of 'e' =101
                        printf("\n\t\t\t\tThanks for playing!");
                        printf("\nplease hit \"ENTER\" to exit the game..");
                        getch();
                        return 0;
                        //break;
                        // break;  is not needful here as after the execution of return 0 ;  control will be out of the loop ( return to the main() function) and program will end itself
                    case 87 : //scan code for arrow up 72 W
                        if(shiftUp(a))
                            moves-- ;
                        break;
                    case 65 : //scan code for arrow left 75 A
                        printf("entered key = %c ",key);
                        if(shiftLeft(a))
                            moves-- ;
                        break;
                    case 68 : //scan code for arrow right 77 D
                        if(shiftRight(a))
                            moves-- ;
                        break;
                    case 83 : //scan code for arrow down 80 S
                        if(shiftDown(a))
                            moves-- ;
                        break;
                    default:
                        printf("\nInvalid key press..\n\t\t\tNOT ALLOWED to move");
                }
            }
            else    //if(moves == 0)
            {
                printf("\n\t\t\t YOU LOSE the Game!");
                flag =0 ;
            }
            if(flag == 0)
                break;

        }
        if(win(a) == 1)
        {
            printf("\n\n\t\t\t Congratulations! , you WIN the game");
        }
        printf("\n\t\tDo you want to play again? ");
        printf("press 'Y' or 'y' to play again : ");
        moves = 7 ;
        key = readEnteredKey();
        if(key != 89 && key != 121 )    // if(key != 'Y' || key != 'y')  ASCII Code : Y = 89 and y = 121
            break;
    }
    return 0;
}

