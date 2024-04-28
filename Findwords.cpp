#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const int ROW = 25;
const int COL = 25;

void bacadata(const string& namaFile, char data[ROW][COL]) {
    ifstream file(namaFile);

    if (!file.is_open()) {
       cout << "Gagal membuka file." <<endl;
        return;
    }

    string line;
    int row = 0;
    while (getline(file, line) && row < ROW) {
        for(int col = 0; col < COL && col < line.size(); col++) {
            data[row][col] = line[col];
        }
        row++;
    }

    file.close();
}

int main() {
   string namaFile = "file.txt"; 
    char data[ROW][COL];
    bacadata(namaFile, data);
return 0;
}
