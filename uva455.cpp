#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void deln(char *str)
{
	int n = 0;
	while (1)
	{
		if (str[n] == '\n')
		{
			str[n] = '\0';
			break;
		}
		n++;
	}
}
int main(int argc, char const *argv[])
{
	const int MAX = 85;
	int n;
	char str[MAX];
	memset(str, 0, MAX - 1);
	scanf("%d", &n);
	printf("\n");
	getchar();
	int *period = (int *)malloc(n * sizeof(int));
	for (int i = 0; i<n; i++) {
		fgets(str, MAX - 1, stdin);
		printf("\n");
		deln(str);
		int re, min = 0;
		int l = strlen(str);
		for (int t = 1; t<l; t++) {
			if (str[t] == str[0]) {
				if (!min) {
					for (int p1 = t, p2 = 0; p2 < t&&str[p1] != '\0'; p1++, p2++) {
						if (str[p1] == str[p2]) {
							re = 1;
							continue;
						}
						else {
							re = 0;
							break;
						}
					}
					if (re)
						min = t;
				}
				else
					for (int p1 = t, p2 = 0; p2 < min&&str[p1] != '\0'; p1++, p2++) {
						if (str[p1] == str[p2]) {
							re = 1;
							continue;
						}
						else {
							re = 0;
							break;
						}
					}
				if (re)
					t += min - 1;
			}
			if(min==1){
				for(int p=0;p<l;p++)
					if(str[p]!=str[0]){
						min=0;
						break;
					}
			}
			if (str[t+1] == '\0' && (min == 0 || l%min)) {
				min = l;
				break;
			}
		}
		period[i] = min;
		memset(str, 0, MAX - 1);
	}
	for (int i = 0; i<n-1; i++)
		printf("%d\n\n", period[i]);
	printf("%d\n",period[i]);
	return 0;
}