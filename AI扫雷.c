#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define ROW 9      // 游戏棋盘行数

#define COL 9      // 游戏棋盘列数

#define ROWS ROW+2 // 扩展棋盘行数（避免边界判断越界）

#define COLS COL+2 // 扩展棋盘列数

#define MINE_COUNT 10 // 地雷数量

// 函数声明
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char board[ROWS][COLS], int row, int col);

int FindMineCount(char mine[ROWS][COLS], int x, int y);

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

int main() {
	char mine[ROWS][COLS] = {0};  // 存储地雷信息，'1'表示地雷
	
	char show[ROWS][COLS] = {0};  // 展示给玩家的棋盘，初始为'*'
	
	// 初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	
	InitBoard(show, ROWS, COLS, '*');
	
	// 布置地雷
	srand((unsigned int)time(NULL));
	
	SetMine(mine, ROW, COL);
	
	// 显示初始棋盘
	printf("扫雷游戏开始！\n");
	
	DisplayBoard(show, ROW, COL);
	
	// 玩家排查地雷
	FindMine(mine, show, ROW, COL);
	
	return 0;
}

// 初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}

// 显示棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	// 打印列号
	for (j = 0; j <= col; j++) {
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);  // 打印行号
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

// 布置地雷
void SetMine(char board[ROWS][COLS], int row, int col) {
	int count = MINE_COUNT;
	while (count > 0) {
		// 生成1 - row和1 - col之间的随机坐标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';  // 标记地雷
			count--;
		}
	}
}

// 计算坐标(x,y)周围的地雷数量
int FindMineCount(char mine[ROWS][COLS], int x, int y) {
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
	mine[x][y - 1] + mine[x][y + 1] +
	mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}

// 玩家排查地雷逻辑
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = 0;  // 排查出的非地雷格子数
	
	while (win < row * col - MINE_COUNT) {
		printf("请输入要排查的坐标(行 列)：");
		scanf("%d %d", &x, &y);
		
		// 判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("很遗憾！你踩到地雷了，游戏结束！\n");
				DisplayBoard(mine, row, col);  // 显示地雷位置
				return;
			} else {
				// 计算周围地雷数并更新显示棋盘
				int count = FindMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		} else {
			printf("输入坐标非法，请重新输入！\n");
		}
	}
	
	printf("恭喜你！所有地雷已排查完毕，游戏胜利！\n");
}
