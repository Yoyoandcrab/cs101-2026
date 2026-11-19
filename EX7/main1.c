#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    int lotto[5][7];
    int i,j,k, num, repeat;
    
    FILE *fp;
    
    srand(time(NULL));
    
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);
    
    if (n < 1 || n > 5)
    {
        printf("輸入錯誤，請輸入 1~5！\n");
        return 0;
    }
    
     for (i = 0; i < n; i++)
    {
        for (j = 0; j < 7; j++)
        {
            do
            {
                num = rand() % 69 + 1;
                repeat = 0;

                // 檢查是否重複
                for (k = 0; k < j; k++)
                {
                    if (lotto[i][k] == num)
                    {
                        repeat = 1;
                        break;
                    }
                }

            } while (repeat);

            lotto[i][j] = num;
        }
    }
    
    fp = fopen("lotto.txt", "w");
    
    if(fp == NULL)
    {
        printf("檔案開啟失敗！\n");
        return 1;
    }
    
    fprintf(fp, "========== lotto649 ==========\n");
    fprintf(fp, "日期：%s", ctime(&(time_t){time(NULL)}));
    
    for (i = 0; i < 5; i++)
    {
        if (i < n)
        {
            fprintf(fp, "[%d]: ", i + 1);

            for (j = 0; j < 7; j++)
            {
                fprintf(fp, "%02d ", lotto[i][j]);
            }

            fprintf(fp, "\n");
        }
        else
        {
            fprintf(fp, "[%d]: -- -- -- -- -- -- --\n", i + 1);
        }
    }
    
    fprintf(fp, "========== csie@CGU ==========\n");

    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
