#include <stdio.h>

int main()
{
    int n = 6;
    int spc = n;
    for (int i = 1 ; i<=n ; i++){
        for (int j = spc ; j>=1 ; j--){
            printf(" ");
        }
        for (int k = 1 ; k<=i ; k++){
             printf("%d ",i);
        }
        printf("\n");
        spc--;
    }

}
