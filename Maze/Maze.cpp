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

const enum ENTRANCE { beginX = 0, beginY = 2 }; // Position of entrance to maze

void mazeTraverse(char[12][12], int, int, int, int);
bool validMove(char[12][12], int, int);
bool isSolved(int, int, int);
void printMaze(char[12][12], int);


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

    printMaze(maze, 12);
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


// Prints the maze
void printMaze(char maze[12][12], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << maze[i][j] << ' ';
        cout << endl;
    }
}
