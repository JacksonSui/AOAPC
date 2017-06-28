#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LMAX 80

typedef struct {
	int bx;
	int by;
	int suc;
	char PuzT[5][15];
	char Move[LMAX];
}Puzzle;

void find_blank(Puzzle *puz){
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (puz->PuzT[i][j] == ' ') {
				puz->bx = i;
				puz->by = j;
			}
}

int move(Puzzle *puz,char *order) {
	int bx = puz->bx;
	int by = puz->by;
	for (int i = 0; i < strlen(order); i++) {
		switch (order[i]) {
		case 'A':
			if (puz->bx == 0)
				return 0;
			puz->PuzT[bx][by] = puz->PuzT[bx - 1][by];
			puz->PuzT[--bx][by] = ' ';
			break;
		case 'B':
			if (puz->bx == 4)
				return 0;
			puz->PuzT[bx][by] = puz->PuzT[bx + 1][by];
			puz->PuzT[++bx][by] = ' ';
			break;
		case 'L':
			if (puz->by == 0)
				return 0;
			puz->PuzT[bx][by] = puz->PuzT[bx][by - 1];
			puz->PuzT[bx][--by] = ' ';
			break;
		case 'R':
			if (puz->by == 4)
				return 0;
			puz->PuzT[bx][by] = puz->PuzT[bx][by + 1];
			puz->PuzT[bx][++by] = ' ';
			break;
		default:
			return 0;
		}
	}
	return 1;
}

int main(){
	char order;
	Puzzle *puzzle;
	int n, ord;
	puzzle = (Puzzle *)malloc(sizeof(Puzzle));
	for (n = 0; ; n++) {
		puzzle = (Puzzle *)realloc(puzzle, (n + 1) * sizeof(Puzzle));
		for (int i = 0; i < 5; i++) {
			fgets(puzzle[n].PuzT[i], 7, stdin);
			fflush(stdin);
			if (puzzle[n].PuzT[i][0] == 'Z')
				goto out;
		}
		find_blank(&puzzle[n]);
		for (ord = 0; (order = getchar()) != '0'; ord++) {
			if (order == '\n') {
				ord--;
				continue;
			}
			puzzle[n].Move[ord] = order;
		}
		puzzle[n].Move[ord] = '\0';
		getchar();
	}
out:
	for (int i = 0; i < n; i++) 
		puzzle[i].suc = move(&puzzle[i], puzzle[i].Move);
	for (int i = 0; i < n; i++) {
		printf("Puzzle #%d:\n", i + 1);
		if (!puzzle[i].suc) {
			printf("This puzzle has no final configuration.\n");
			if (i + 1 != n)
				putchar('\n');
			continue;
		}
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				putchar(puzzle[i].PuzT[j][k]);
				putchar((k != 4) ? ' ' : '\n');
			}
		}
		if (i + 1 != n)
			putchar('\n');
	}
	free(puzzle);
	return 0;
}