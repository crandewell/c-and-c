#include<stdio.h>
int main()
{
	//??????????2025.10.23 Night

	const int size = 3;
	int board[size][size];
	int i, j;
	int numofx;
	int numofo;
	int result = -1;
	/*-1??????1??X??0??o??*/

	//?????????

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			scanf_s("%d", &board[i][j]);
		}
	}
	//??????
	for (i = 0; i < size && result == -1; i++) {
		numofo = numofx = 0;
		for (j = 0; j < size; j++) {
			if (board[i][j]==1) {
				numofx++;
			}
			else {
				numofo++;
			}
		}
		if (numofo == size) {
			result = 0;
		}
		else if (numofx == size) {
			result = 1;
		}
	}
	//???????

	if (result == -1) {
		for (j = 0; j < size && result == -1; j++) {
			numofo = numofx = 0;
			for (i = 0; i < size; i++) {
				if (board[i][j] == 1) {
					numofx++;
				}
				else {
					numofo++;
				}
			}
			if (numofo == size) {
				result = 0;
			}
			else if (numofx == size) {
				result = 1;
			}
		}
	}
	//?????????????
	numofo = numofx = 0;
	for (i = 0; i < size; i++) {
		if (board[i][i] == 1) {
			numofx++;
		}
		else {
			numofo++;
		}
	}
	if (numofo == size) {
		result = 0;
	}
	else if (numofx == size) {
		result = 1;
	}

	//??????????????
	numofo = numofx = 0;
	for (i = 0; i < size; i++) {
		if (board[i][size - i - 1] == 1) {
			numofx++;
		}
		else {
			numofo++;
		}
	}
	return 0;
}
