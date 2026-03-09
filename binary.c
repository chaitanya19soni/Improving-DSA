#include <stdio.h>
#include <stdlib.h>

int binarySearch (int n , int target , int arr[]){
 int left = 0 ;
 int right  =  n-1;

 while (left <= right){
    int mid = (left +right)/2;
    
    if (arr[mid] == target){
        return  mid ;
    }
  if (arr[mid] < target){
        left = mid +1;
    }
    else {
        right =  mid-1 ;
    }
 }
 return -1;
}

int main() {
 
int n , target ;    

int * arr = (int*)malloc(n * sizeof(int));

scanf("%d",&n);

for (int i = 0 ; i<n ; i++)
{
    scanf("%d",&arr[i]);
}

scanf("%d",&target);
 
int index = binarySearch(n,target,arr);


if (index == -1){
    printf("present %d\n",target);
}

else{
    printf("absent\n");
}

return 0;

}


