//
// Created by ike on 2018/1/21.
//


#include <cstdio>
#include <climits>
#include <utility>
#include <queue>

using namespace std;

class Program {
    static const int MAX_N = 20, MAX_M = 20;
    const int INF = INT_MAX >> 2;
    typedef pair<int,int> P;

    char maze[MAX_N][MAX_M+1] = {
            "#S######.#",
            "......#..#",
            ".#.##.##.#",
            ".#........",
            "##.##.####",
            "....#....#",
            ".#######.#",
            "....#.....",
            ".####.###.",
            "....#...#G"
    };
    int N = 10,M = 10;
    int sx = 0, sy = 1;//起点坐标
    int gx = 9, gy = 9;//终点坐标
    int d[MAX_N][MAX_M];

    int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; //四个方向移动的坐标

    int bfs() {
        queue<P> que;
        for (int i=0; i<N; ++i)
            for (int j=0; j<M; ++j)
                d[i][j] = INF;

        que.push(P(sx, sy));
        d[sx][sy] = 0;

        while (que.size()) {
            P p = que.front(); que.pop();
            if (p.first == gx && p.second == gy) break;
            for (int i=0; i<4; i++) {
                int nx = p.first + dx[i], ny = p.second + dy[i];
                if (0<=nx&&nx<N&&0<=ny&&ny<M&&maze[nx][ny]!='#'&&d[nx][ny]==INF) {
                    que.push(P(nx,ny));
                    d[nx][ny]=d[p.first][p.second]+1;
                }
            }
        }
        return d[gx][gy];
    }

public:
    void solve() {
        int res = bfs();
        printf("result = %d\n", res);
    }
};


int main (){

    Program P;
    P.solve();
    return 0;
};