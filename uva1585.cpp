#include<stdio.h>
int main(){
    int i,n;
    scanf("%d",&n);
    getchar();
    int ans[n];
    for(i=0;i<n;i++){
	char input;
	int tot=0,pon=0;
	while((input=getchar())!='\n'){
		if(input=='O'){
			pon++;
			tot+=pon;
		}
		else
			pon=0;
	}
		ans[i]=tot;
    }
    for(i=0;i<n;i++){
	printf("%d\n",ans[i]);
    }
	return 0;
}
