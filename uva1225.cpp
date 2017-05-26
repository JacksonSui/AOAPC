#include<stdio.h>
#include<string.h>
int check(int n);
int main(){
	int n;
	scanf("%d",&n);
	int data[n];
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	for(int i=0;i<n;i++){
		int l=check(data[i])+1;
		char str[l]={},temp[5];
		for(int t=1;t<=data[i];t++){
			sprintf(temp,"%d",t);
			strcat(str,temp);
		}
		int count[10]={0};
		for(int s=0;s<l;s++){
			switch(str[s]){
				case '0':count[0]++;break;
				case '1':count[1]++;break;
				case '2':count[2]++;break;
				case '3':count[3]++;break;
				case '4':count[4]++;break;
				case '5':count[5]++;break;
				case '6':count[6]++;break;
				case '7':count[7]++;break;
				case '8':count[8]++;break;
				case '9':count[9]++;break;
			}
		}
		for(int t=0;t<10;t++){
		    (t==9)?printf("%d",count[t]):printf("%d ",count[t]);
		}
		printf("\n");
	}
	return 0;
}

int check(int n){
	if(n<10)
		return n;
	else if(n>=10&&n<100)
		return ((n-10+1)*2+9);
	else if(n>=100&&n<1000)
		return ((n-100+1)*3+(99-10+1)*2+9);
	else if(n>=1000&&n<10000)
		return ((n-1000+1)*4+(999-100+1)*3+(99-10+1)*2+9);
}