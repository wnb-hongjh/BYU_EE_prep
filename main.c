#include <stdio.h>

int main()
{
    FILE *fp = fopen("sensor.txt", "r");
    if (fp == NULL)
    {
        printf("opening file failed");
        return 1;
    }

    while (fscanf(fp, "ID: %d, 값: %f\n", &id, &value) != EOF)
    {
        printf("읽어온 데이터 -> ID: %d, 값: %.2f\n", id, value);
    }
    fclose(fp);
    return 0;
}