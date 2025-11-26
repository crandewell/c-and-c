#include<stdio.h>
int main()
{
	char teamA[]={'a','b','c'};
	char teamB[]={'x','y','z'};
	
	char i,j,k;//表示abc的对手
	
	for(i='x';i<='z';i++){
		for(j='x';j<='z';j++){
			if(i!=j){
				for(k='x';k<='z';k++){
					if(i!=k&&j!=k){
						if(i!='x'&&k!='x'&&k!='z'){
							printf("比赛顺序为 a--%c b--%c c--%c\n",i,j,k);
						}
					}
					
				}
			}
		}
	}
	return 0;
}
