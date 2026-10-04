#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> maps, visited;
int xf, yf, xh, yh;
int N, M, D;

bool dfs(int x, int y){
    visited[x][y] = 1;
    if (x == xh && y == yh) return true;

    if (x < N - 1 && !visited[x+1][y] && maps[x+1][y] && dfs(x+1, y)) return true;
    if (x > 0 && !visited[x-1][y] && maps[x-1][y] && dfs(x-1, y)) return true;
    if (y < M - 1 && !visited[x][y+1] && maps[x][y+1] && dfs(x, y+1)) return true;
    if (y > 0 && !visited[x][y-1] && maps[x][y-1] && dfs(x, y-1)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> D;

    vector<vector<char>> grid(N, vector<char>(M));
    maps.assign(N, vector<bool>(M, true));
    visited.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'F') { xf = i; yf = j; }
            if (grid[i][j] == 'H') { xh = i; yh = j; }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c = grid[i][j];
            if (c == '#') {
                maps[i][j] = false;
                continue;
            }

            if (c == '<' || c == '>' || c == '^' || c == 'v') {
                maps[i][j] = false;

                int dx = 0, dy = 0;
                if (c == '<') dy = -1;
                if (c == '>') dy = 1;
                if (c == '^') dx = -1;
                if (c == 'v') dx = 1;

                int nx = i, ny = j;
                for (int step = 0; step < D; step++) {
                    nx += dx; ny += dy;
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
                    if (grid[nx][ny] == '#' || grid[nx][ny] == '<' || grid[nx][ny] == '>' ||
                        grid[nx][ny] == '^' || grid[nx][ny] == 'v') break;
                    if (grid[nx][ny] == 'F' || grid[nx][ny] == 'H') {
                        cout << "NO";
                        return 0;
                    }
                    maps[nx][ny] = false;
                }
            }
        }
    }

    bool ans = false;
    if (maps[xf][yf] && maps[xh][yh])
        ans = dfs(xf, yf);

    cout << (ans ? "YES" : "NO");
    return 0;
}