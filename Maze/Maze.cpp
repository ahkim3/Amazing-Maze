/*
Name: Andrew Kim
Date: February 18, 2021
Program: It's A-Mazing

I hereby certify that this program represents my
work and that the design and logic was completed
without outside assistance.

Signature: Andrew Kim
*/

#include <iostream>

using namespace std;

const enum ENTRANCE { X = 0, Y = 2 };

void mazeTraverse(char[12][12], int, int, int, int);
bool validMove(char[12][12], int, int);
bool isSolved(int, int, int);


int main()
{
    // Initializes maze
    char maze[12][12] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',

    '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',

    '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#',

    '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#',

    '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.',

    '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#',

    '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',

    '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',

    '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#',

    '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#',

    '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#',

    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
    };

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
            cout << maze[i][j] << ' ';
        cout << endl;
    }
}


// Executes tasks for each step in maze
void mazeTraverse(char maze[12][12], int size, int xCurrent, int yCurrent, 
    int nextDirection)
{
    maze[xCurrent][yCurrent] = 'X'; // Places an X at current position

    // Decide if maze has been solved

    // Check if current position is start position (meaning unsolvable)

    // Cycle through direction possibilities
        // NTS: For each that would give a valid move, make a recursive call 
        // which will involve taking a step in that direction
}


// Determine if moving to a specified position in a maze is allowed
bool validMove(char maze[12][12], int xCoord, int yCoord)
{
    return false;
}


// Determines if exit of maze has been found
bool isSolved(int size, int xCoord, int yCoord)
{
    return false;
}
