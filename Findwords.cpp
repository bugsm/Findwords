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

bool searchWord(char data[ROW][COL], string word) {
    int len = word.length();

    if (len > ROW && len > COL) {
        return false;
    }

    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            if (tolower(data[row][col]) == tolower(word[0])) {
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int k, rd = row + x, cd = col + y;
                        for (k = 1; k < len; k++) {
                            if (rd >= ROW || rd < 0 || cd >= COL || cd < 0)
                                break;
                            if (tolower(data[rd][cd]) != tolower(word[k]))
                                break;
                            rd += x, cd += y;
                        }
                        if (k == len)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
   string namaFile = "file.txt"; 
    char data[ROW][COL];
    bacadata(namaFile, data);

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    for (const auto &word : words) {
        if (searchWord(data, word))
            cout <<word << " Ada \n";
        else
            cout<< word << " Tidak Ada\n";
    }

    return 0;
}
