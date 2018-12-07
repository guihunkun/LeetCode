#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 10;
const int D[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

char map[N][N], memory[N][N];
bool visit[N][N][4];

int trans(int x, int y) {
    if (x < 1) return 0;
    if (y > 5) return 1;
    if (x > 5) return 2;
    if (y < 1) return 3;
}

bool arrive(int x, int y, int d, int depth, int from) {
    if (visit[x][y][d] || map[x][y] == '*') {
        return false;
    }
    if (x < 1 || x > 5 || y < 1 || y > 5) {
        int now = trans(x, y);
        if (now == from) {
            return false;
        }
        return depth >= 3;
    }
    int next;
    if (map[x][y] == '/') {
        next = 3 - d;
    } else {
        next = d ^ 1;
    }
    visit[x][y][d] = visit[x][y][next] = true;
    return arrive(x + D[next][0], y + D[next][1], next ^ 2, depth + 1, from);
}

bool judge() {
    for (int i = 1; i <= 5; ++ i) {
        if (map[i][1] == '*') {
            continue;
        }
        memset(visit, 0, sizeof(visit));
        if (arrive(i, 1, 3, 0, 3)) {
            return true;
        }
        memset(visit, 0, sizeof(visit));
        if (arrive(1, i, 0, 0, 0)) {
            return true;
        }
        memset(visit, 0, sizeof(visit));
        if (arrive(i, 5, 1, 0, 1)) {
            return true;
        }
        memset(visit, 0, sizeof(visit));
        if (arrive(5, i, 2, 0, 2)) {
            return true;
        }
    }
    return false;
}

int main() {
    for (int ii = 1; ii <= 5; ++ ii) {
        scanf("%s", map[ii] + 1);
    }
    memcpy(memory, map, sizeof(map));
    if (judge()) {
        puts("WIN");
        return 0;
    }

    int sx, sy;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++ j) {
            if (map[i][j] == '*') {
                sx = i;
                sy = j;
            }
        }
    }
    // L:
    for (int step = 1; sy + step <= 5; ++ step) {
        memcpy(map, memory, sizeof(map));
        for (int i = sy; i < sy + step; ++ i) {
            std::swap(map[sx][i], map[sx][i + 1]);
        }
        if (judge()) {
            printf("L%d\n", step);
            return 0;
        }
    }
    // R:
    for (int step1 = 1; sy - step1 >= 1; ++ step1) {
        memcpy(map, memory, sizeof(map));
        for (int i = sy; i > sy - step1; -- i) {
            std::swap(map[sx][i], map[sx][i - 1]);
        }
        if (judge()) {
            printf("R%d\n", step);
            return 0;
        }
    }
    // D:
    for (int step2 = 1; sx - step2 >= 1; ++ step2) {
        memcpy(map, memory, sizeof(map));
        for (int i = sx; i > sx - step2; -- i) {
            std::swap(map[i][sy], map[i - 1][sy]);
        }
        if (judge()) {
            printf("D%d\n", step);
            return 0;
        }
    }
    // U:
    for (int step3 = 1; sx + step3 <= 5; ++ step3) {
        memcpy(map, memory, sizeof(map));
        for (int i = sx; i < sx + step3; ++ i) {
            std::swap(map[i][sy], map[i + 1][sy]);
        }
        if (judge()) {
            printf("U%d\n", step);
            return 0;
        }
    }
    puts("FAIL");
    return 0;
}