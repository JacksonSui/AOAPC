#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 85
float onemass(char ch);
int main(){
	int n;
	char formula[MAX];
	scanf("%d",&n);
	getchar();
	float ans[n];
	for(int i=0;i<n;i++){
		fgets(formula,MAX,stdin);
		float tot=0.0;
		for(int t=0;t<strlen(formula);t++){
			float base;
			if(isalpha(formula[t])){
				base=onemass(formula[t]);
				int time=1;
				if(isdigit(formula[t+1])){
					if(isdigit(formula[t+2]))
						time=(formula[t+1]-'0')*10+(formula[t+2]-'0');
					else
						time=(formula[t+1]-'0');
				}
				//printf("%d\n",time);
				tot+=base*time;
			}
			else
				continue;
		}
		ans[i]=tot;
	}
	for(int i=0;i<n;i++)
		printf("%.3f\n",ans[i]);
}

float onemass(char ch){
	const float C=12.01;
	const float H=1.008;
	const float O=16.00;
	const float N=14.01;
	switch(ch){
		case 'C':
		return C;
		case 'H':
		return H;
		case 'O':
		return O;
		case 'N':
		return N;
	}
}