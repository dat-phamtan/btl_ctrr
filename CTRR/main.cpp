#include "tsm.h"
#include "bellman.h"
#include <iostream>
#include <fstream>
#include <climits>
#include <string.h>
#include <sstream>
using namespace std;
int clone;
string staging;
int main() {
    string test1 ="inMat3.txt";
    string test2 ="inMat1.txt";
    int G[20][20];
    ifstream fin(test1);

    if (!fin) {
        cerr << "Unable to open file inMat1.txt";
        return 1;
    }

    int n = 0;  // Number of rows
    string line;
    while (getline(fin, line) && n < 20) {
        istringstream iss(line);
        int value;
        int m = 0;  // Number of columns
        while (iss >> value && m < 20) {
            G[n][m] = value;
            m++;
        }
        n++;
    }
    fin.close();

    if (n > 20) {
        cerr << "Matrix size exceeds the limit of 20";
        return 1;
    }
    cout << "___________________"<<endl;
    cout << "##Test BF()##"<<endl;
    int BFValue[20];
    int BFPrev[20];
    runTestCases(test1, test2, n, BFValue, BFPrev);
    cout << "___________________"<<endl;
    cout << "##Test BF_Path()##"<<endl;
    runTestCasespath(test1, n);
    cout << "___________________"<<endl;
    cout << "##Test Traveling##"<<endl;
    string output = Traveling(G, n, 'A');
    int cost = pathlength(G, n, output);
    cout << "Shortest Hamiltonian cycle: " << output << endl;
    cout << "Cost of the shortest Hamiltonian cycle: " << cost << endl;
    return 0;
}