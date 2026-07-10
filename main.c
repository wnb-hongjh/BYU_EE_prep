#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Sample
{
    int index;
    float time;
    float value;
};

int print_result(FILE *fp)
{
    int index;
    float time, value;
    while (fscanf(fp, "샘플 #%d  시간: %fs  값: %f", &index, &time, &value) != EOF)
    {
        printf("[index]: %d\n[time]: %f\n[value]: %f\n", index, time, value);
    }
}

int main()
{
    int n = 100;
    struct Sample *samples = malloc(n * sizeof(struct Sample));
    if (samples == NULL)
    {
        printf("ERROR\n");
        return 1;
    }
    FILE *fp = fopen("sample.txt", "w");
    if (fp == NULL)
    {
        printf("reading error\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        samples[i].index = i + 1;
        samples[i].time = i * 0.01;
        samples[i].value = sin(2 * M_PI * 1.0 * samples[i].time);
        fprintf(fp, "샘플 #%d  시간: %.2fs  값: %.3f", samples[i].index, samples[i].time, samples[i].value);
    }
    fclose(fp);
    free(samples);
    samples = NULL;

    char yn;
    fp = fopen("sample.txt", "r");
    printf("Do you want to see the result?(y/n): ");
    scanf("%c", &yn);
    if (yn == 'y')
    {
        print_result(fp);
    }
    fclose(fp);
    return 0;
}
