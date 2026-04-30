#include <stdlib.h>
#include <stdio.h>

int main() {
    int n ;
    int flag;
    int key ;
    int arr [100];
    scanf("%d",&n);
    flag = 0;
    for (int i =0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    printf("type the key you wnat to find");
    scanf("%d",&key);
    
    for (int i =0 ; i<n ;i++){
        if (arr[i]==key){
            printf("the key is present");
        }
        flag = 1;
    }

    if(!flag){
        printf("the key not found");
    }
    return 0;
}