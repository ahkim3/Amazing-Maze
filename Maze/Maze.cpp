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
#include <fstream>

using namespace std;

const enum Entrance { BEGIN_X = 0, BEGIN_Y = 2 }; // Position of entrance to maze
enum class Direction {DOWN, RIGHT, UP, LEFT};

void fill(char[12][12], int, string);
void mazeTraverse(char[12][12], int, int, int, Direction);
bool validMove(char[12][12], int, int);
bool isSolved(int, int, int);
void printMaze(char[12][12], int);


int main()
{
    char maze[12][12];

    fill(maze, 12, "Maze.txt");

    Direction nextDirection = Direction::DOWN; // Initial direction attempt

    mazeTraverse(maze, 12, BEGIN_X, BEGIN_Y, nextDirection);
    //printMaze(maze, 12);
}


// Fill array with maze from a file
void fill(char maze[12][12], int size, string inputFileName)
{
    string name;
    ifstream input;

    // Reads file and stores each character in an array element
    input.open(inputFileName, ios::in);
    if (input.is_open())
    {
        for (int j = 0; j < size; j++)
        {
            for (int i = 0; i < size; i++)
                input >> maze[i][j];
        }
        input.close();
    }
}


// Executes tasks for each step in maze
void mazeTraverse(char maze[12][12], int size, int xCurrent, int yCurrent, 
    Direction nextDirection)
{
    bool directionFound;
    int directionCount = 0;

    maze[xCurrent][yCurrent] = 'X'; // Places an X at current position

    system("pause");
    system("cls");
    printMaze(maze, size);

    // Continues onto next position if maze is neither solved nor unsolvable
    if (!(isSolved(size, xCurrent, yCurrent) 
        && (xCurrent == BEGIN_X && yCurrent == BEGIN_Y)))
    {
        directionFound = false;

        // Cycle through direction possibilities to find a valid direction
        while (!directionFound)
        {
            directionCount = 0;

            // Tests a single direction
            switch (nextDirection)
            {
            case Direction::DOWN:
                if (validMove(maze, xCurrent, yCurrent + 1))
                    directionFound = true;
                break;
            case Direction::RIGHT:
                if (validMove(maze, xCurrent + 1, yCurrent))
                    directionFound = true;
                break;
            case Direction::UP:
                if (validMove(maze, xCurrent, yCurrent - 1))
                    directionFound = true;
                break;
            case Direction::LEFT:
                if (validMove(maze, xCurrent - 1, yCurrent))
                    directionFound = true;
                break;
            }

            // Moves onto a different direction if original wasn't valid
            if (!directionFound)
            {
                directionCount++;

                switch (nextDirection)
                {
                case Direction::DOWN:
                    nextDirection = Direction::RIGHT;
                    break;
                case Direction::RIGHT:
                    nextDirection = Direction::UP;
                    break;
                case Direction::UP:
                    nextDirection = Direction::LEFT;
                    break;
                case Direction::LEFT:
                    nextDirection = Direction::DOWN;
                    break;
                }
            }
        }
        
        // Move onto next step in maze
        switch (nextDirection)
        {
        case Direction::DOWN:
            mazeTraverse(maze, size, xCurrent, yCurrent + 1, Direction::LEFT);
            break;
        case Direction::RIGHT:
            mazeTraverse(maze, size, xCurrent + 1, yCurrent, Direction::DOWN);
            break;
        case Direction::UP:
            mazeTraverse(maze, size, xCurrent, yCurrent - 1, Direction::RIGHT);
            break;
        case Direction::LEFT:
            mazeTraverse(maze, size, xCurrent - 1, yCurrent, Direction::UP);
            break;
        }
    }
}


// Determine if moving to a specified position in a maze is allowed
bool validMove(char maze[12][12], int xCoord, int yCoord)
{
    if (maze[xCoord][yCoord] == '#') // Specified position is a border
        return false;
    return true;
}


// Determines if exit of maze has been found
bool isSolved(int size, int xCurrent, int yCurrent)
{
    // Edge of array (exit) has been reached AND it's not the entrance
    if ((xCurrent != BEGIN_X && yCurrent != BEGIN_Y)
        && (xCurrent == 0 || xCurrent == size 
            || yCurrent == 0 || yCurrent == size))
        return true;
    return false;
}


// Prints the maze
void printMaze(char maze[12][12], int size)
{
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
            cout << maze[i][j] << ' ';
        cout << endl;
    }
}
