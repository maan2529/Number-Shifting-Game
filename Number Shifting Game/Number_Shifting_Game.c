#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INFINITE_LOOP 1

void displayRule();
int getNum();
void unique_number(int arr[]);
void set_Matrix(int arr[], int u_num[][4]);
void displayMatrix(int u_num[][4]);
int winning(int arr[]);
int uparrow(int u_num[][4], int);
int downarrow(int u_num[][4], int);
int rightarrow(int u_num[][4], int);
int leftarrow(int u_num[][4], int);
void swap(int *a, int *b);
void winSituation();

void displayRule()
{
    printf("\n");
    printf("\t\t\t***RULE OF THIS GAME***\t\n");

    printf("1. You can move only 1 step at a time by arrow key\n");
    printf("Move Up     :  By Up Arrow Key\n");
    printf("Move Down   :  By Down Arrow Key\n");
    printf("Move Left   :  By Left Arrow Key\n");
    printf("Move Right  :  By Right Arrow Key\n\n");

    printf("2. You can move number at empty position only\n\n");

    printf("3. For each valid move : Your total number of move will decreased by 1\n\n");
    printf("4. Winning Situation   : Number in a 4 * 4 matrix should be in order from 1 to 15\n\n");
    printf("\t\tWinning Situation\n");
    winSituation();
    printf("\n");
    printf("5. You can exit the game at any time by pressing E or e\n");
    printf("So try to win in minimum no of moves\n\n");

    printf("\t\t***Happy Gaming , Good Luck***\n");
}
int getNum()
{
    char arrowNum;
    arrowNum = _getch();
    if (arrowNum == -32)
        arrowNum = _getch();

    return arrowNum;
}
void unique_number(int arr[])
{

    int store;
    int i, j;

    srand(time(NULL));
    for (i = 0; i < 15; i++)
    {
        store = (rand() % 15) + 1; // generating randum number
        for (j = 0; j < i; j++)
        {
            if (arr[j] == store)
            {
                break;
            }
        }
        (i == j) ? arr[i] = store : i--;
    }
    arr[15] = 0;
}

void set_Matrix(int arr[], int u_num[][4])
{
    int u = 0;
    //########Assigning value in array#######
    for (int n = 0; n < 4; n++)
    {
        for (int m = 0; m < 4; m++)
        {
            u_num[n][m] = arr[u++];
        }
    }
}

void displayMatrix(int u_num[][4])
{
    // ######## printing matrix ##########

    printf(" ---------------------\n"); // Output for matrix star
    for (int k = 0; k < 4; k++)
    {
        for (int l = 0; l < 4; l++)
        {
            if (u_num[k][l] == 0)
            {
                printf(" | %2c ", 0);
                if (l == 3)
                {
                    printf(" |");
                }
            }
            else
            {
                printf(" | %2d", u_num[k][l]);
                if (l == 3)
                {
                    printf(" |");
                }
            }
        }
        printf("\n");
    }
    printf(" ---------------------\n"); // Output for matrix end
}

int winning(int arr[])
{
    int i, matNum = 1;
    for (i = 0; i < 15; i++)
    {
        if (arr[i] != matNum)
        {
            return 0;
        }
        matNum++;
    }
    if (i == 15) // condition not require
        return 1;
}

int uparrow(int u_num[][4], int key)
{

    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (u_num[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (i < 3)
    {
        swap(&u_num[i][j], &u_num[i + 1][j]);
        return key;
    }
    else if (i == 3)
    {
        return key + 1;
    }
}

int downarrow(int u_num[][4], int key)
{

    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (u_num[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (i > 0)
    {
        swap(&u_num[i][j], &u_num[i - 1][j]);
        return key;
    }
    else if (i == 0)
    {
        return key + 1;
    }
}

int rightarrow(int u_num[][4], int key)
{

    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (u_num[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (j > 0)
    {
        swap(&u_num[i][j], &u_num[i][j - 1]);
        return key;
    }
    else if (j == 0)
    {
        return key + 1;
    }
}

int leftarrow(int u_num[][4], int key)
{

    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (u_num[i][j] == 0)
                break;
        }
        if (j < 4)
            break;
    }
    if (j < 3)
    {
        swap(&u_num[i][j], &u_num[i][j + 1]);
        return key;
    }
    else if (j == 3)
    {
        return key + 1;
    }
}

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void winSituation()
{
    int count = 1;
    int winSituation[4][4];
    printf(" ---------------------\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            winSituation[i][j] = count;
            if (count == 16)
            {
                winSituation[i][j] = 0;
            }
            if (winSituation[i][j] == 0)
            {
                printf(" | %2c", winSituation[i][j]);
                printf("  |");
            }
            else
            {
                printf(" | %2d", winSituation[i][j]);
                if (j == 3)
                {
                    printf(" |");
                }
                count++;
            }
        }
        printf("\n");
    }
    printf(" ---------------------\n");
}
int main()
{

    int arrow;
    int move;
    int level;
    char name[30];
    char surname[30];
    int u_num[4][4];
    int arr[16];
    while (INFINITE_LOOP)
    {
        printf("\n Enter Your Name : ");
        scanf("%s", name);

        printf("\n Enter Your Surname Name : ");
        scanf("%s", surname);

        while (INFINITE_LOOP)
        {
            printf(" \n Enter 1 : For level 1 (Easy)\n");
            printf(" Enter 2 : For level 2 (Medium)\n");
            printf(" Enter 3 : For level 3 (Hard)\n");
            level = getNum();

            if (level == 49)
            {
                move = 100;
                break;
            }
            else if (level == 50)
            {
                move = 50;
                break;
            }
            else if (level == 51)
            {
                move = 30;
                break;
            }
            else
            {
                printf("Enter Valid Input \n");
            }
        }
        int M_remain = move;

        displayRule();
        unique_number(arr);
        set_Matrix(arr, u_num);

        void displayRule();
        printf("\n Enter Any key to start.... \n");
        getch();
        // printf(" Enter Moves : ");
        // scanf("%d", &M_remain);

        while (!winning(arr))
        {

            system("cls");
            printf(" Hello %s %s, Move remaining : %d \n", name, surname, M_remain);
            if (M_remain < 1)
                break;
            displayMatrix(u_num);
            arrow = getNum();

            switch (arrow)
            {
            case 72: // up arrow
                M_remain = uparrow(u_num, M_remain);
                M_remain--;
                break;
            case 80: // down arrow
                M_remain = downarrow(u_num, M_remain);
                M_remain--;
                break;
            case 77: // right arrow
                M_remain = rightarrow(u_num, M_remain);
                M_remain--;
                break;
            case 75: // left arrow
                M_remain = leftarrow(u_num, M_remain);
                M_remain--;
                break;
            case 69: // For Exit
                printf(" Game End\n\n ThankYou For Playing \n");
                return 0;
                break;
            case 101: // For Exit
                printf(" Game End\n\n ThankYou For Playing \n");
                return 0;
                break;
            }
        }
        printf("\n");
        if (winning(arr) == 1)
        {
            printf(" Congratulations You Win\n\n");
        }
        else if (winning(arr) == 1 && M_remain == 0)
        {
            printf(" Congratulations You Win\n");
        }
        else if (M_remain == 0)
        {
            printf(" You Lose , You Can Try Again\n\n");
        }
        int choice;

        while (INFINITE_LOOP)
        {
            printf("\n If You Want To Play Again Press (Y/y) For Exit Press (E/e)");
            choice = getNum();
            if (choice == 69 || choice == 101)
            {
                printf("\n Game End...\n ThankYou For Playing \n\n");
                return 0;
            }
            else if (choice == 89 || choice == 121)
            {
                printf(" \n Continue\n");
                system("cls");
                break;
            }
            else
            {
                printf("\n Enter Valid Input\n");
            }
        }
    }
    getch();
    return 0;
}
