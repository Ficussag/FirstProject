#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;//this variable is used to check if the game is over
const int width = 20;//width and height of the game
const int height = 20;//width and height of the game
int x, y, fruitX, fruitY, score;//x and y are the coordinates of the head of the snake
int tailX[100], tailY[100];//tailX and tailY are the coordinates of the tail of the snake
int nTail;//length of the tail

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;
//this function is used to set up the game
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
//this function is used to draw the game
void Draw()
{
    system("cls");//cls is used to clear the screen
    for (int i = 0; i < width + 2; i++)
        cout << "#";//# is used to print the game
    cout << endl;//endl is used to move the cursor to the next line
    //for loop is used to print the game
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)//this if statement is used to print the game
                cout << "#";
            if (i == y && j == x)//this if statement is used to print the game
                cout << "@";     // head
            else if (i == fruitY && j == fruitX)//this if statement is used to print the game
                cout << "$";         // apple
            else
            {
                bool print = false;//this variable is used to print the game
                for (int k = 0; k < nTail; k++)//for loop is used to print the game
                {
                    if (tailX[k] == j && tailY[k] == i)//this if statement is used to print the game
                    {
                        cout << "^"; print = true; // body
                    }
                }
                if (!print) cout << " ";//this if statement is used to print the game

            }

            if (j == width - 1)//this if statement is used to print the game
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)//this for loop is used to print the game
        cout << "#";//# is used to print the game
    cout << endl;
    cout << "Score:" << score << endl;//this cout statement is used to print the game
}
//this function is used to take input from the user
void Input()
{
    if (_kbhit())
    {
        switch (_getch())//this switch statement is used to take input from the user
        {
        case 'a' ://this case statement is used to take input from the user
            dir = LEFT;
            break;
        case 'd'://this case statement is used to take input from the user
            dir = RIGHT;
            break;
        case 'w'://this case statement is used to take input from the user
            dir = UP;
            break;
        case 's'://this case statement is used to take input from the user
            dir = DOWN;
            break;
        case 'x'://this case statement is used to take input from the user
            gameOver = true;
            break;
        }
    }
}
//this function is used to move the snake
void algorithm()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x >= width)
        x = 0; else if (x < 0) x = width - 1;
    if (y >= height)
        y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
//pragrammin in start
int main()
{
    Setup();//this function is used to set up the game
    while (!gameOver)
    {
        Draw();//this function is used to draw the game
        Input();//this function is used to take input from the user
        algorithm();//this function is used to move the snake
        Sleep(40); // Adding a delay to slow down the snake's movement
    return 0;
}
