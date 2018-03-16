#include "Maze.h"
#include <string>
#include <iostream>
using namespace std;

enum CellValue { OPEN, BLOCKED, PATH, EXIT, TEMPORARY, DOWN, UP, LEFT, RIGHT, OUT, IN };

void Maze::setValue(int height, int width, int layer, int value)
{
	maze_[height][width][layer] = value;
}


/** Solve maze - to be called in the main function
@return true if solveable, else false
*/
bool Maze::find_maze_path()
{
	if (find_maze_path(0, 0, 0)) return true;
	else return false;
}
//Other form of the maze - to be called recursively
bool Maze::find_maze_path(int h, int w, int l)
{
	// check boundary
	if ((h < 0) || (h >= height_) ||
		(w < 0) || (w >= width_) ||
		(l < 0) || (l >= layer_)) return false;

	// check to see if it's blocked
	if (maze_[h][w][l] != OPEN) return false;

	// check to see if it's at the end
	if ((h == height_ - 1) && (w == width_ - 1) && (l == layer_ - 1))
	{
		maze_[h][w][l] = EXIT;
		return true;
	}


	// This is the recursive part. I also have included the 
	// different directions for the BONUS section.
	maze_[h][w][l] = PATH;
	if (find_maze_path(h - 1, w, l))		//UP
	{
		maze_[h][w][l] = UP;
		return true;
	}
	else if (find_maze_path(h + 1, w, l))	//DOWN
	{
		maze_[h][w][l] = DOWN;
		return true;
	}
	else if (find_maze_path(h, w - 1, l))	//LEFT
	{
		maze_[h][w][l] = LEFT;
		return true;
	}
	else if (find_maze_path(h, w + 1, l))	//RIGHT
	{
		maze_[h][w][l] = RIGHT;
		return true;
	}
	else if (find_maze_path(h, w, l + 1))	//IN
	{
		maze_[h][w][l] = IN;
		return true;
	}
	else if (find_maze_path(h, w, l - 1))	//OUT
	{
		maze_[h][w][l] = OUT;
		return true;
	}
	maze_[h][w][l] = TEMPORARY;
	return false;

}


/** Output maze (same order as input maze)
@return string of 2D layers
*/
string Maze::toString() const
{
	stringstream out;
	for (int l = 0; l < layer_; l++)
	{
		out << "Layer " << l + 1 << endl;
		for (int h = 0; h < height_; h++)
		{
			for (int w = 0; w < width_; w++)
			{
				switch (maze_[h][w][l])
				{
					case OPEN: 
						out << "_ ";
						break;
					case BLOCKED: 
						out << "X ";
						break;
					case PATH: 
						out << "2 ";
						break;
					case EXIT: 
						out << "E ";
						break;
					case TEMPORARY: 
						out << "_ ";
						break;
						//DOWN, UP, LEFT, RIGHT, OUT, IN 
					case DOWN:
						out << "D ";
						break;
					case UP:
						out << "U ";
						break;
					case LEFT:
						out << "L ";
						break;
					case RIGHT:
						out << "R ";
						break;
					case OUT: 
						out << "O ";
						break;
					case IN:
						out << "I ";
						break;
				}
			}
			out << endl;
		}
		out << endl;
	}
	string output;
	output = out.str();
	return output;
}
