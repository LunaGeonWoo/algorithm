#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Point { int x, y; };

int paper[256][256], width, height;
int pow2[9], LR[4] = {1,0,3,2}, UD[4] = {2,3,0,1};
Point startAt = {0,0};
stack<int> dirs;

int dir2num(char d) {
    switch (d)
    {
    case 'U':
        return 0;
    case 'D':
        return 1;
    case 'R':
        return 2;
    default:
        return 3;
    }
}

int flip(int hole, int dir) {
    if(dir < 2) {
        return UD[hole];
    } else {
        return LR[hole];
    }
}

void fill_paper(int dir) {
    if(dir < 2) {
        if(dir == 0) {
            for(int i=0; i<pow2[height]; i++) 
                for(int j=0; j<pow2[width]; j++) 
                    paper[startAt.y + pow2[height] + i][startAt.x + j] = flip(paper[startAt.y + pow2[height] - i - 1][startAt.x + j], dir);
        } else {
            for(int i=0; i<pow2[height]; i++) 
                for(int j=0; j<pow2[width]; j++) 
                    paper[startAt.y - (i + 1)][startAt.x + j] = flip(paper[startAt.y + i][startAt.x + j], dir);
            startAt.y-=pow2[height];
        }
        height++;
    } else {
        if(dir == 2) {
            for(int i=0; i<pow2[width]; i++) 
                for(int j=0; j<pow2[height]; j++) 
                    paper[startAt.y + j][startAt.x - (i+1)] = flip(paper[startAt.y + j][startAt.x + i], dir);
            startAt.x-=pow2[width];
        } else {
            for(int j=0; j<pow2[height]; j++) 
                for(int i=0; i<pow2[width]; i++) 
                    paper[startAt.y + j][startAt.x + pow2[width] + i] = flip(paper[startAt.y + j][startAt.x + pow2[width] - (i+1)], dir);
        }
        width++;
    }
}

void solve() {
    int dir;
    while(dirs.size()) {
        dir = dirs.top(); dirs.pop();
        fill_paper(dir);
    }
}

void init_pow2() {
    pow2[0]=1;
    for(int i=1; i < 9; i++) pow2[i] = pow2[i-1] * 2;
}

int32_t main() {
    init_pow2();
    int k, h;
    cin >> k;
    width = height = k - 1;
    char d; 
    for(int i=0, dir; i<2*k; i++) {
        cin >> d;
        dir = dir2num(d);
        if(dir < 2) {
            if(dir == 1) startAt.y += pow2[height];
            height--;
        } else {
            if(dir == 2) startAt.x += pow2[width];
            width--;
        }
        dirs.push(dir);
    }
    height = width = 0;
    cin >> h;
    paper[startAt.y][startAt.x] = h;
    solve();

    for(int y=0; y < pow2[k]; y++) {
        for(int x=0; x < pow2[k]; x++) {
            cout << paper[y][x] << ' ';
        }
        cout << '\n';
    }
}