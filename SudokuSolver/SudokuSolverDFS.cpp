#include <iostream>
#include <queue>

using namespace std;

int cnt = 0;

void printSudoku(int board[9][9]) {
    cout << "┌───────┬───────┬───────┐" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0) cout << "│ ";

            if (board[i][j] == 0) cout << "  ";
            else cout << board[i][j] << ' ';
        }
        cout << "│ ";

        if (i == 2 || i == 5)
        {
            cout << endl << "├───────┼───────┼───────┤";
        }
        cout << endl;
    }
    cout << "└───────┴───────┴───────┘" << endl;
}

void dfs(int board[9][9], int index, int n) {
    if (n > 9) return;
    if (index >= 81) {
        printSudoku(board);
        cout << ++cnt << "번째 정답" << endl;
        return;
    }

    int y = index / 9, x = index % 9;
    if (board[y][x] != 0)
    {
        dfs(board, index + 1, 1);
        return;
    }

    for (int i = 0; i < 9; i++) {
        if (board[y][i] == n || board[i][x] == n || board[y / 3 * 3 + i / 3][x / 3 * 3 + i % 3] == n)
        {
            dfs(board, index, n + 1);
            return;
        }
    }

    int cpyboard[9][9];
    copy(&board[0][0], &board[0][0] + 9 * 9, &cpyboard[0][0]);
    cpyboard[y][x] = n;

    //this code is working only windows
    /*system("cls");
    printSudoku(board);*/

    dfs(cpyboard, index + 1, 1);
    dfs(board, index, n + 1);
}

int main()
{
    int board[9][9] = {
        {0,0,0,5,0,3,0,0,8},
        {2,0,4,0,6,0,0,9,0},
        {0,1,0,0,0,0,0,0,0},
        {0,7,0,0,0,0,0,5,0},
        {5,0,1,0,0,6,3,0,0},
        {0,9,0,0,1,0,0,0,0},
        {0,0,0,2,0,0,9,0,0},
        {7,0,0,0,0,0,0,0,0},
        {6,0,5,0,4,0,0,2,0}
    };
    
    //If you want to input on variable "board" delete code.
    // for (int i = 0; i < 9; i++)
    // {
    //     cout << i + 1 << "줄: ";
    //     string r;
    //     cin >> r;
    //     for (int j = 0; j < 9; j++) {
    //         board[i][j] = r[j] - '0';
    //     }
    // }
    //To This Code
    
    printSudoku(board);
    
    dfs(board, 0, 1);
    if (cnt == 0) cout << "해결할 수 없는 스도쿠입니다.";
}
