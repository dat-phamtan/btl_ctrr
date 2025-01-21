#include "tsm.h"
#include <iostream>


// Hàm đệ quy nhánh và cận để tìm chu trình Hamilton ngắn nhất
void tspRec(int matrix[][20], bool visited[], int n, int currentpos, int count, int cost, int &mincost, int path[], int minpath[], int start) {
    if (count == n && matrix[currentpos][start] != 0) { // Kiểm tra điều kiện dừng của đệ quy
        int sum = cost + matrix[currentpos][start];
        if (sum < mincost) {
            mincost = sum;
            copy(path, path + n, minpath);
        }
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && matrix[currentpos][i] != 0 && matrix[currentpos][i] != INF) {
            visited[i] = true;
            path[count] = i;

            int newcost = cost + matrix[currentpos][i];
            if (newcost < mincost) {
                tspRec(matrix, visited, n, i, count + 1, newcost, mincost, path, minpath, start);
            }

            visited[i] = false; // Quay lui: bỏ đánh dấu đỉnh đã thăm
        }
    }
}


// Hàm tìm chu trình Hamilton ngắn nhất
string Traveling(int matrix[][20], int n, char startver) {
    int mincost = INF;
    int minpath[20];
    bool visited[20] = { false };
    int path[20];

    // Chuyển đổi đỉnh bắt đầu từ ký tự thành chỉ số
    int start = startver - 'A';

    // Khởi tạo mảng
    for (int i = 0; i < 20; ++i) {
        path[i] = -1;
        minpath[i] = -1;
    }

    visited[start] = true;
    path[0] = start;

    tspRec(matrix, visited, n, start, 1, 0, mincost, path, minpath, start);

    if (mincost == INF) {
        return "";
    }

    string result;
    for (int i = 0; i < n; ++i) {
        result += char('A' + minpath[i]);
        result += " ";
    }
    result += char('A' + start);
    return result;
}




// Hàm loại bỏ các khoảng trắng từ chuỗi
void removeSpaces(string &str){
    int n = str.length();
    int count = 0; // Biến đếm số lượng ký tự không phải khoảng trắng

    // Duyệt qua từng ký tự trong chuỗi
    for (int i = 0; i < n; i++) {
        if (str[i] != ' ') {
            str[count++] = str[i]; // Ghi lại ký tự không phải khoảng trắng
        }
    }

    str.erase(count); // Loại bỏ các ký tự sau vị trí cuối cùng của chuỗi không phải khoảng trắng
}



//Hàm tính độ dài của đường đi
int pathlength(int matrix[][20], int n, string path_str) {
    int length = 0;

    // Loại bỏ các khoảng trắng trong chuỗi path_str
    removeSpaces(path_str);

    // Kiểm tra xem có đường đi hay không
    if (path_str.empty()) {
        return INF; // Trả về INF nếu không có đường đi
    }

    // Duyệt qua chuỗi path_str để tính tổng chi phí
    for (int i = 0; i < n - 1; ++i) {
        int from = path_str[i] - 'A';
        int to = path_str[i + 1] - 'A';
        length += matrix[from][to];
    }

    // Tính chi phí cuối cùng từ điểm cuối trở lại điểm đầu tiên
    int last = path_str[n - 1] - 'A';
    int start = path_str[0] - 'A';
    length += matrix[last][start];

    return length;
}