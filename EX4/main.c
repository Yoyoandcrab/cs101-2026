#include <stdio.h>

int main()
{
    FILE* fp;
    int a[] = {0,1,2};
    char b[] = "ABC";
    float c[] = {1.1,1.2,1.3};
    
    fp = fopen("a.bin", "wb+");
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);
    fseek(fp, 0, SEEK_SET);
    fread(a, sizeof(int), 3, fp);
    fread(b, sizeof(char), 3, fp);
    fread(c, sizeof(float), 3, fp);
    
    for(int i = 0; i < 3; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int i = 0; i < 3; i++){
        printf("%c ", b[i]);
    }
    printf("\n");
    for(int i = 0; i < 3; i++){
        printf("%.6f ", c[i]);
    }
    return 0;
}
