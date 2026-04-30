#include <stdio.h>

int main() {
     int n ;
     scanf("%d",&n);
     int arr[n];

     for(int i =0 ; i<n ; i++){
        scanf("%d",arr[i]);
     }

     for (int i = 0 ; i<n ; i++){
        min = i;
        for (j= i+1; j<n ; i++){
            if (arr[j]<arr[min]){
                min = j;
            }
        }
            int temp =  arr[min];
            arr[min] = arr[i];
            arr[i] = temp ;

     }



    return 0;
}