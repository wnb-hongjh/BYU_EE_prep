#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

struct Record
{
    char content[50];
    int amount;
    char type; // 'i' 또는 'e'
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char keep = 'o';
    int count = 0;
    int sum = 0;
    int tf = 1;
    struct Record record[100];
    FILE *fp = fopen("money_tracing.txt", "r");
    if (fp != NULL)
    {
        while (fscanf(fp, "type: %c, amount: %d, content: %s\n", &record[count].type, &record[count].amount, record[count].content) != EOF)
        {
            count++;
        }
        fclose(fp);
    }

    while (keep == 'o')
    {
        printf("소비와 수익중 무엇입니까?(i/e): ");
        scanf(" %c", &record[count].type);
        while (record[count].type != 'i' && record[count].type != 'e')
        {
            while (getchar() != '\n')
                ;
            printf("잘못된 입력입니다. 소비와 수익중 무엇입니까?(i/e): ");
            scanf(" %c", &record[count].type);
        }
        printf("금액을 입력하세요: ");
        scanf("%d", &record[count].amount);
        printf("내용을 작성해주세요: ");
        scanf("%s", record[count].content);
        count++;

        printf("계속하고싶으시면 o/x 를 눌러주세요.");
        scanf(" %c", &keep);
    }

    fp = fopen("money_tracing.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "type: %c, amount: %d, content: %s\n", record[i].type, record[i].amount, record[i].content);
        if (record[i].type == 'i')
        {
            sum += record[i].amount;
        }
        else
        {
            sum -= record[i].amount;
        }
    }
    printf("총 손익: %d", sum);
    fclose(fp);
}