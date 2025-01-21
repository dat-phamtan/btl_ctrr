#include "bellman.h"
#include <iostream>
void BF(int matrix[20][20], int numver, char startver, int dist[], int prev[]) {
    int startIndex = startver - 'A';
    if(dist[startIndex]==-1){
        for (int i = 0; i < numver; ++i) {
            dist[i] = -1;
            prev[i] = -1;
        }
        dist[startIndex] = 0;
    }
    int tempDist[numver];
    for (int i = 0; i < numver; ++i) {
        tempDist[i] = dist[i];
    }
    for (int u = 0; u < numver; ++u) {
        for (int v = 0; v < numver; ++v) {
            if (matrix[u][v] != 0 && tempDist[u] != -1 && (dist[v] == -1 || tempDist[u] + matrix[u][v] < dist[v])) {
                dist[v] = tempDist[u] + matrix[u][v];
                prev[v] = u;
            }
        }
    }
    for (int u = 0; u < numver; u++) {
        for (int v = 0; v < numver; v++) {
            if (matrix[u][v] != 0 && tempDist[u] != 1e9 && tempDist[u] + matrix[u][v] < tempDist[v]) {
                return;
            }
        }
    }
}
// Hàm thực hiện thuật toán Bellman-Ford và tìm đường đi ngắn nhất từ start đến goal
string BF_Path(int matrix[20][20], int numver, char start, char goal) {
    int dist[20];
    int prev[20];
    char startver = start;
    for (int i = 0; i < numver; ++i) {
        dist[i] = -1;
        prev[i] = -1;
    }
    int start_index = start - 'A';
    int goal_index = goal - 'A';
    dist[start_index] = 0;

    while (true) {
        bool updated = false;
        int tempDist[20];
        for (int i = 0; i < numver; ++i) {
            tempDist[i] = dist[i];
        }
        for (int u = 0; u < numver; ++u) {
            for (int v = 0; v < numver; ++v) {
                if (matrix[u][v] != 0 && tempDist[u] != -1 && (dist[v] == -1 || tempDist[u] + matrix[u][v] < dist[v])) {
                    dist[v] = tempDist[u] + matrix[u][v];
                    prev[v] = u;
                    updated = true;
                }
            }
        }
        if (!updated) {
            break; // Nếu không có cập nhật nào, thoát khỏi vòng lặp
        }
    }

    int path[20];
    int count = 0;
    for (int i = goal_index; i != -1; i = prev[i]) {
        path[count++] = i;
    }
    if (count == 0 || path[count - 1] != start_index) {
        return ""; // Không có đường đi từ đỉnh bắt đầu đến đỉnh đích
    }
    for (int i = 0; i < count / 2; ++i) {
        swap(path[i], path[count - i - 1]);
    }
    string path_ver;
    for (int i = 0; i < count; ++i) {
        path_ver += (char)(path[i] + 'A');
        if (i < count - 1) {
            path_ver += ' ';
        }
    }

    return path_ver;
}

void runTestCases(string inputFile1, string inputFile2, int n, int (&BFValue)[20], int (&BFPrev)[20]) {
    int G[20][20];
    int G2[20][20];
    
    ifstream fin;
    
    // Đọc ma trận từ file inputMat16_1.txt
    fin.open(inputFile1);
    for(int i = 0; i < n; i++) {
        BFValue[i] = -1;
        BFPrev[i] = -1;
        for(int j = 0; j < n; j++) {
            fin >> G[i][j];
        }
    }
    fin.close();
    
    // Đọc ma trận từ file inputMat16_2.txt
    fin.open(inputFile2);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            fin >> G2[i][j];
        }
    }
    fin.close();
    
    // Chạy test cases
    for(int i = 0; i < n; i++) {
        if(i % 2)
            BF(G, n, 'A', BFValue, BFPrev);
        else
            BF(G2, n, 'A', BFValue, BFPrev);
        
        cout << "step " << i + 1 << ":" << endl;
        for(int j = 0; j < n; j++) {
            cout << BFValue[j] << " ";
        }
        cout << endl;
        for(int j = 0; j < n; j++) {
            cout << BFPrev[j] << " ";
        }
        cout << endl;
    }
}
void runTestCasespath(string inputFile, int n) {
    int G[20][20];
    int BFValue[20];
    int BFPrev[20];
    
    ifstream fin(inputFile);
    
    // Đọc ma trận từ file inputMat16_2.txt
    for(int i = 0; i < n; i++) {
        BFValue[i] = -1;
        BFPrev[i] = -1;
        for(int j = 0; j < n; j++) {
            fin >> G[i][j];
        }
    }
    fin.close();
    
    // Chạy test cases
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << BF_Path(G, n, char(i + 'A'), char(j + 'A')) << endl;
        }
    }
}