#include <stdio.h>
#include <conio.h>
char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void draw()
{
    /*To draw the game design representing positions*/
    system("cls");
    printf("\t\t***************** || Welcome to TIC TAC TOE || *******************\n\t\t\t\t\t\t X-O");
    printf("\n\n\n---------------------------------------------------------------------------------");
    printf("\nRules:-\n1.It is a two player game\n2.Player1 is X and Player2 is O\n3.Enter the positions number to insert 'X and O'");
    printf("\n4.The first one to make pair of three X or O up,down,across or diagonal wins");
    printf("\n---------------------------------------------------------------------------------");
    printf("\n\n\n\t\t%c | %c | %c", a[0], a[1], a[2]);
    printf("\n\t\t--|---|--");
    printf("\n\t\t%c | %c | %c", a[3], a[4], a[5]);
    printf("\n\t\t--|---|--");
    printf("\n\t\t%c | %c | %c", a[6], a[7], a[8]);
}

int gamecondi()
{
    /*return
    type 1=game finished with result
    type 0 means draw
    type -1 means still checking conditions*/
    if (a[0] == a[1] && a[1] == a[2])
        return 1;
    else if (a[0] == a[3] && a[3] == a[6])
        return 1;
    else if (a[0] == a[4] && a[4] == a[8])
        return 1;
    else if (a[1] == a[4] && a[4] == a[7])
        return 1;
    else if (a[2] == a[5] && a[5] == a[8])
        return 1;
    else if (a[2] == a[4] && a[4] == a[6])
        return 1;
    else if (a[3] == a[4] && a[4] == a[5])
        return 1;
    else if (a[6] == a[7] && a[7] == a[8])
        return 1;

    else if (a[0] != '1' && a[1] != '2' && a[2] != '3' && a[3] != '4' && a[4] != '5' && a[5] != '6' && a[6] != '7' && a[7] != '8' && a[8] != '9')
        return 0;

    else
        return -1;
}

int main()
{
    int player = 1, ch, i;
    char mark;
    char ans;
label:
    do
    {
        draw();
        player = (player % 2) ? 1 : 2;
        printf("\nPlayer %d enter the position number:", player);
        scanf("%d", &ch);
        mark = (player == 1) ? 'X' : 'O';

        if (ch == 1 && a[0] == '1')
            a[0] = mark;
        else if (ch == 2 && a[1] == '2')
            a[1] = mark;
        else if (ch == 3 && a[2] == '3')
            a[2] = mark;
        else if (ch == 4 && a[3] == '4')
            a[3] = mark;
        else if (ch == 5 && a[4] == '5')
            a[4] = mark;
        else if (ch == 6 && a[5] == '6')
            a[5] = mark;
        else if (ch == 7 && a[6] == '7')
            a[6] = mark;
        else if (ch == 8 && a[7] == '8')
            a[7] = mark;
        else if (ch == 9 && a[8] == '9')
            a[8] = mark;

        else
        {
            printf("\nInvalid move");
            player--;
            getch();
        }
        i = gamecondi();
        player++;
    } while (i == -1);

    if (i == 1)
    {
        printf("\n*****Congratulations :-)*****\nPlayer %d won the game", --player);
    }
    else
    {
        printf("\nGAME DRAW.");
    }
    printf("\nWant to play more?\nPress Y or N:");
    fflush(stdin);
    scanf("%c", &ans);
    if (ans == 'Y')
    {
        a[0] = '1';
        a[1] = '2';
        a[2] = '3';
        a[3] = '4';
        a[4] = '5';
        a[5] = '6';
        a[6] = '7';
        a[7] = '8';
        a[8] = '9';
        player = --player;
        goto label;
    }
    printf("\n\n\t\t********THANK YOU...HOPE YOU ENJOYED :-)********");
    getch();
    return 0;
}