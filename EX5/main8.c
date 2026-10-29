#include <stdio.h>
int recursion(int i, int j){
    if(j == 1){
        printf("%d*%d=%d\n", i, j, i*j);
        return 0;
    }
    else if(j > 1){
        recursion(i, j-1);
        printf("%d*%d=%d\n", i, j, i*j);
    }
}

int main()
{
    recursion(1, 9);
    return 0;
}
