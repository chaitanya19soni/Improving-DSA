#include <stdlib.h>
#include <stdio.h>

int binarysearch (int n ,int taget , int arr[]){
    int left = 0;
    int right = n-1;

    
    while(left<=right){
        int mid = (left +right) /2 ;
        
        if (arr[mid] == taget){
            return mid ;
        }
        if (mid<left){
            left = mid +1;
        }
        else{
            right = mid-1;
        }
    }
}


int main() {
    int n, target ;

    scanf("%d",&n);
    int * arr = (int *)malloc(n*sizeof(int));
    for (int i = 0 ;i<n;i++){
        scanf("%d",&arr[i]);
    }

    scanf("%d",&target);

    int index = binarysearch( n, target ,arr[100]);

    if (index == -1){
        printf("target found");
    }
    else{
        printf("target lost");
    }


    return 0;
}



