#ifndef TSM_H
#define TSM_H

//#include "main.h"
#include <string>
#include <iostream>
#include <string>
#include <climits>
#include <fstream>

using namespace std;

const int INF = 9999;

void tspRec(int matrix[][20], bool visited[], int n, int currentpos, int count, int cost, int &mincost, int path[], int minpath[], int start);
string Traveling(int matrix[][20], int n, char startver);
int pathlength(int matrix[][20], int n, string path_str);
void removeSpaces(string &str);

#endif