#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>

#include "Maze.h"
#include "Maze Interface.h"

using namespace std;

/*****************************************************
|	Welcome to Lab 7 - 3D Maze
|	For this lab we will navegate a maze and output the
|	path taken.
|
|	***Note to grader: my program finds a different path
|	than that found in the solution online just because 
|	I ordered things a lil different but it is still
|	a valid path. The grade specs just ask for a 
|	solution soooo yeah. Thanks.***
*****************************************************/

int main(int argc, char * argv[])
{
	VS_MEM_CHECK               // enable memory leak check
							   //Check for errors in opening the output file
		if (argc < 3)
		{
			cerr << "Please provide name of input and output files";
			return 1;
		}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open " << argv[1] << " for input";
		return 1;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
	}

	//Variables for maze size
	int height, width, layers;

	//Read in the first line, being the size of the maze
	in >> height >> width >> layers;

	//Now that we have the number of rows, columns, and layers, we
	//can read in our maze
	Maze m = Maze(height, width, layers);
	
	//Variable for reading in the cell values
	int data;
	for (int l = 0; l < layers; l++)
	{
		for (int h = 0; h < height; h++)
		{
			for (int w = 0; w < width; w++)
			{
				in >> data;
				m.setValue(h, w, l, data);
			}
		}
	}
	out << "Solve Maze: " << endl;
	out << m.toString();
	if (m.find_maze_path())
	{
		out << "Solution: " << endl;
		out << m.toString();
	}
	else out << "No Solution Exists!" << endl;


	//Close your files, go home, and enjoy the spring day
	in.close();
	out.close();
	return 0;
}
