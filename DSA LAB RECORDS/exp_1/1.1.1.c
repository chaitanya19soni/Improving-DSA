#include <stdio.h>
int main (){
	
int n ;
int arr[100];
 int key ;
	int flag =0;
	scanf("%d",&n);
	for (int i = 0 ; i<n; i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&key);
	for (int i=0;i<n;i++){
		if(arr[i]==key){
			printf("found at position %u\n",i);
		flag=1;
		}
	}
	if(!flag){
		printf("%d not found\n",key);
	}
}