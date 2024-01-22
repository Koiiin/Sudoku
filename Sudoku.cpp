#include <iostream>
#include <vector>

using namespace std;

const int N = 9;

// Hàm kiểm tra xem giá trị num có thể được đặt vào ô (row, col) hay không
bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
    // Kiểm tra cùng hàng
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // Kiểm tra cùng cột
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // Kiểm tra cùng ô 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Hàm giải bài toán Sudoku sử dụng đệ quy
bool solveSudoku(vector<vector<char>>& board) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            // Tìm ô chưa điền (chưa điền được biểu diễn bằng ký tự 'X')
            if (board[row][col] == 'X') {
                // Thử đặt các giá trị từ '1' đến '9'
                for (char num = '1'; num <= '9'; num++) {
                    if (isSafe(board, row, col, num)) {
                        // Nếu giá trị num hợp lệ, đặt nó vào ô và thử giải tiếp
                        board[row][col] = num;

                        // Nếu giải thành công, trả về true
                        if (solveSudoku(board)) {
                            return true;
                        }

                        // Nếu giải không thành công, quay lui và thử giá trị khác
                        board[row][col] = 'X';
                    }
                }

                // Nếu không có giá trị nào hợp lệ, trả về false
                return false;
            }
        }
    }

    // Nếu tất cả ô đều đã điền, trả về true
    return true;
}

int main() {
    vector<vector<char>> board(N, vector<char>(N));

    // Đọc dữ liệu đầu vào
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    cout <<"-----------------------" <<"\n";
    // Giải bài toán Sudoku
    if (solveSudoku(board)) {
        // In ra ma trận Sudoku đã giải
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
    } else {
        cout << "Khong co loi giai" << endl;
    }

    return 0;
}
