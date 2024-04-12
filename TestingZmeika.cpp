#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;//this function is used tofalse;
int width = 200;//this function is used to draw the game
int height = 200;// this function is used to draw the game
int x, y, fruitX, fruitY, score;//this function is used to draw the game
int tailX[1000], tailY[1000];//this function is used to draw the game
int nTail;//this function is used to draw the game

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir; set up the game
void Setup()
{
    gameOver = 
//this function is used tofalse;
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
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "|";
    cout << endl;
    //for loop is used to draw the game
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "|";
            if (i == y && j == x)
                cout << "@";     // head
            else if (i == fruitY && j == fruitX)
                cout << "$";         // apple
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "^"; print = true; // body
                    }
                }
                if (!print) cout << " ";

            }

            if (j == width - 1)
                cout << "|";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "|";
    cout << endl;
    cout << "Score:" << score << endl;
}
//this function is used to take input from the user
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
//this function is used to move the snake
void algorithm()
{
    int prevX = tailX[0];//this is used to move the snake
    int prevY = tailY[0];//this is used to move the snake
    int prev2X, prev2Y;//this is used to move the snake
    tailX[0] = x;//this is used to move the snake
    tailY[0] = y;//this is used to move the snake
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    //this switch case is used to move the snake
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
int main()//this is used to draw the game
{
    Setup();//this is used to set up the game
    while (!gameOver)//this is used to draw the game
    {
        Draw();//this is used to draw the game
        Input();//this is used to take input from the user
        algorithm();//this is used to move the snake
        Sleep(40); // Adding a delay to slow down the snake's movement
        return 0;//this is used to exit the game
    }
