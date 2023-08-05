#include <bits/stdc++.h>
#define int int64_t
#define LEFT 0
#define CENTER 1
#define RIGHT 2
using namespace std;

vector<string> book;
int N,M,ali=LEFT;

void print_line(vector<string> out_line, int len) {
    switch (ali)
    {
    case LEFT: {
        cout << out_line[0];
        for(int i=1; i<out_line.size(); i++) cout << '-' << out_line[i];
        for(int i=len; i<M; i++) cout << '-';
        cout << '\n';
        break;
    }
    case CENTER: {
        int left_len = (M-len)/2;
        for(int i=0; i<left_len; i++) cout << '-';
        cout << out_line[0];
        for(int i=1; i<out_line.size(); i++) cout << '-' << out_line[i]; 
        for(int i=left_len + len; i<M; i++) cout << '-';
        cout << '\n';
        break;
    }
    case RIGHT: {
        for(int i=0; i<M-len; i++) cout << '-';
        cout << out_line[0];
        for(int i=1; i<out_line.size(); i++) cout << '-' << out_line[i];
        cout << '\n';
        break;
    }
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    cin.ignore();
    book.resize(N);

    for(int i=0; i<N; i++) getline(cin, book[i]);
    for(int i=0; i<N; i++) {
        string line = book[i];
        if(line == "<CENTER>") {
            ali = CENTER;
        } else if(line == "</CENTER>") {
            ali = LEFT;
        } else if(line == "<RIGHT>") {
            ali = RIGHT;
        } else if(line == "</RIGHT>") {
            ali = LEFT;
        } else {
            istringstream iss(line);
            vector<string> out_line;
            string token;
            int len = 0;
            while(iss >> token) {
                if(len == 0) {
                    out_line.push_back(token);
                    len += token.size();
                } else if(len + 1 + token.size() <= M) {
                    out_line.push_back(token);
                    len += 1 + token.size();
                } else {
                    print_line(out_line, len);
                    out_line.clear();
                    out_line.push_back(token);
                    len = token.size();
                }
            }
            print_line(out_line, len);
        }
    }
}