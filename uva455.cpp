#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	const int MAX=85;
	int n;
	char str[MAX];
	memset(str,0,MAX-1);
	scanf("%d",&n);
	getchar();
	int period[n];
	for(int i=0;i<n;i++){
		fgets(str,MAX-1,stdin);
		int min,re=0;
		int l=strlen(str);
		for(int t=1;t<l;t++){
			if(str[t]==str[0]){
				for(int p1=t,p2=0;p2<t&&str[p1]!='\0';p1++,p2++){
					if(str[p1]!=str[p2]){
						re=1;
						break;
					}
					if(!(p2%(t-1)))
						min=t;
				}
				if(re)
					t++;
				else
					t+=min;
				if(str[t]=='\0'){
					min=l;
					break;
				}
			}
		}
		period[i]=min;
		memset(str,0,MAX-1);
	}
	for(int i=0;i<n;i++)
		printf("%d\n\n",period[i]);
	return 0;
}