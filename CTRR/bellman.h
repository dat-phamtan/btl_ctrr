
//#include "main.h"
#include <iostream>
#include <string>
#include <climits>
#include <fstream>

using namespace std;

void BF(int matrix[20][20], int numver, char startver, int dist[], int prev[]);
string BF_Path(int matrix[20][20], int numver, char start, char goal);
void runTestCases(string inputFile1, string inputFile2, int n, int (&BFValue)[20], int (&BFPrev)[20]);
void runTestCasespath(string inputFile, int n);