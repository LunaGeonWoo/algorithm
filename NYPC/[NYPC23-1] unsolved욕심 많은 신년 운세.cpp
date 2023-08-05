#include <bits/stdc++.h>
#define int int64_t
#define H idx*2
#define V idx*2+1
using namespace std;

struct Point { int y, x; };
struct Line { 
    Point startAt, endAt; 
    void print() {
        cout << startAt.y+1 << ' ' << startAt.x+1 << ' ' << endAt.y+1 << ' ' << endAt.x+1 << '\n';
    }
    int len() {
        return endAt.y + endAt.x - startAt.y - startAt.x + 1;
    }
    bool h_isOverlapWith(Line l) {
        return (l.startAt.x <= startAt.x && startAt.x <= l.endAt.x) || (l.startAt.x <= endAt.x && endAt.x <= l.endAt.x);
    }
    bool v_isOverlapWith(Line l) {
        return (l.startAt.y <= startAt.y && startAt.y <= l.endAt.y) || (l.startAt.y <= endAt.y && endAt.y <= l.endAt.y);
    }
    int X() { return startAt.x; }
    int Y() { return startAt.y; }
};

int N, M, T;
char grid[50][50];
vector<string> words;
vector<vector<Line>> words_locations;
vector<Line> ans_h[50], ans_v[50], ans;

void check_horizontal(int idx, string word, int size) {
    for(int y=0; y<N; y++) {
        for(int x=0; x<=M-size; x++) {
            for(int i=0; i<size; i++) {
                if(grid[y][x+i] != word[i]) break;
                if(i == size-1) words_locations[H].push_back({{y,x}, {y,x+size-1}});
            }
        }
    }
}

void check_vertical(int idx, string word, int size) {
    for(int y=0; y<=N-size; y++) {
        for(int x=0; x<M; x++) {
            for(int i=0; i<size; i++) {
                if(grid[y+i][x] != word[i]) break;
                if(i == size-1) words_locations[V].push_back({{y,x}, {y+size-1,x}});
            }
        }
    }
}

void fill_words_locations(int idx) {
    string word = words[idx];
    int word_size = word.size();
    check_horizontal(idx, word, word_size);
    check_vertical(idx, word, word_size);
}

void fill_ansDir(int idx) {
    vector<Line> line = words_locations[H];
    for(auto l : line) ans_h[l.Y()].push_back(l);
    line = words_locations[V];
    for(auto l : line) ans_v[l.X()].push_back(l);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int y=0; y<N; y++) 
        for(int x=0; x<M; x++) 
            cin >> grid[y][x];
    cin >> T;
    words.resize(T);
    words_locations.resize(T*2);
    for(int i=0; i<T; i++) cin >> words[i];
    for(int i=0; i<T; i++) fill_words_locations(i);
    for(int i=0; i<T; i++) fill_ansDir(i);
    
    // for(auto word : words_locations) {
    //     for(auto location : word) {
    //         location.print();
    //     }
    // }
    // cout << '\n';

    for(int y=0; y<N; y++) {
        cout << ans_h[y].size() << ' ';
    }
    cout << '\n';
    for(int x=0; x<M; x++) {
        cout << ans_v[x].size() << ' ';
    }
    cout << '\n';

    for(int y=0; y<N; y++) {
        if(ans_h[y].size() == 1) {
            ans.push_back(ans_h[y][0]);
            continue;
        } else if(ans_h[y].size() == 0) continue;
        int max_len = 0;
        vector<Line> sub_ans;
        for(int num=1; num<=ans_h[y].size(); num++){
            vector<int> shuffle(ans_h[y].size());
            fill_n(shuffle.begin(), num, 1);
            do {
                bool isOverlap=false;
                int i=0, len=0;
                vector<int> choosen;
                for(auto p : shuffle) {
                    if(p == 1) {
                        choosen.push_back(i);
                        if(choosen.size() == num) break;
                    }
                    i++;
                }
                vector<Line> sub_ans2;
                for(i=0; i<num; i++) {
                    for(auto s : sub_ans2) {
                        if(s.h_isOverlapWith(ans_h[y][choosen[i]])) {
                            isOverlap = true;
                            break;
                        }
                    }
                    if(isOverlap) break;
                    len+=ans_h[y][choosen[i]].len();
                    sub_ans2.push_back(ans_h[y][choosen[i]]);
                }
                if(isOverlap) continue;
                if(max_len < len) {
                    max_len = len;
                    sub_ans = sub_ans2;
                }
            } while (prev_permutation(shuffle.begin(), shuffle.end()));
        } 
        ans.insert(ans.end(), sub_ans.begin(), sub_ans.end());
    }
    
    for(int x=0; x<M; x++) {
        if(ans_v[x].size() == 1) {
            ans.push_back(ans_v[x][0]);
            continue;
        } else if(ans_v[x].size() == 0) continue;
        int max_len = 0;
        vector<Line> sub_ans;

        for(int num=1; num<=ans_v[x].size(); num++){
            vector<int> shuffle(ans_v[x].size());
            fill_n(shuffle.begin(), num, 1);
            do {
                bool isOverlap=false;
                int i=0, len=0;
                vector<int> choosen;
                for(auto p : shuffle) {
                    if(p == 1) {
                        choosen.push_back(i);
                        if(choosen.size() == num) break;
                    }
                    i++;
                }
                vector<Line> sub_ans2;
                for(i=0; i<num; i++) {
                    for(auto s : sub_ans2) {
                        if(s.v_isOverlapWith(ans_v[x][choosen[i]])) {
                            isOverlap = true;
                            break;
                        }
                    }
                    if(isOverlap) break;
                    len+=ans_v[x][choosen[i]].len();
                    sub_ans2.push_back(ans_v[x][choosen[i]]);
                }
                if(isOverlap) continue;
                if(max_len < len) {
                    max_len = len;
                    sub_ans = sub_ans2;
                }
            } while (prev_permutation(shuffle.begin(), shuffle.end()));
        } 
        ans.insert(ans.end(), sub_ans.begin(), sub_ans.end());
    }
    cout <<'\n' << ans.size() << '\n';
    for(auto a : ans) {
        a.print();
    }
}