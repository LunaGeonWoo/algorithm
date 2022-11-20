#include <iostream>
#include <map>
using namespace std;

int n, cnt=0;
bool board[9][9];
map<int,int> xchk,p,m;

bool safe(int y, int x) {
    return y>=0 && y<n && x>=0 && x<n; 
}

int chu[10] = {2,3,7,8}, n=4;
void dfs(int no, int sum1, int sum2, int sum3)
{
    if(no == n)
    {
        if(sum > 0) {
            ss.insert(sum);
        }
        return;
    }
    dfs(no+1,sum1+chu[no],sum2,sum3);
    dfs(no+1,sum1,sum2+chu[no],sum3);
    dfs(no+1,sum1,sum2,sum3+chu[no]);
}

ss.back() - ss.size()


void dfs(int y) {
    if(y==n) 
    {
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cnt++;
        return;
    }
    
    for(int x=0; x<n; x++)
    {
        if(xchk[x]==0 && p[x+y]==0 && m[x-y] == 0)
        {
            xchk[x] = p[x+y]= m[x-y] = 1;
            board[y][x]=1;
            dfs(y+1);
            board[y][x]=0;
            xchk[x] = p[x+y]= m[x-y] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << cnt << endl;
}