#ifndef MAZE_H
#define MAZE_H

#include "Maze Interface.h"

#include <string>
#include <sstream>
using namespace std;

class Maze : public MazeInterface
{
public:
	//Two Maze constructors for the main function
	Maze() {};

	Maze(int height, int width, int layer)
	{
		//Declare the size of the maze
		height_ = height;
		width_ = width;
		layer_ = layer;

		//Dynamically allocate array of ints
		int*** val = new int **[height_]();
		for (int i = 0; i < height_; i++)
		{
			val[i] = new int *[width_]();
			for (int j = 0; j < width_; j++)
				val[i][j] = new int[layer_]();
		}

		maze_ = val;
	};

	//Maze destructor
	~Maze()
	{
		for (int i = 0; i < height_; i++)
		{
			for (int j = 0; j < width_; j++)
			{
				delete [] maze_[i][j];
			}
			delete[] maze_[i];
		}
		delete[] maze_;
	}

//See cpp file for function descriptions

	void setValue(int height, int width, int layer, int value);

	bool find_maze_path();

	bool find_maze_path(int h, int w, int l);

	string toString() const;

private:
	//Variables for working in the maze
	int height_;
	int width_;
	int layer_;
	int value_;
	int*** maze_;

};
#endif // !MAZE_H
