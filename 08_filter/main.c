#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Sample
{
    int index;
    float time;
    float clean_value;
    float noisy_value;
    float filtered_value;
};

int main()
{
    srand(time(NULL));

    int n = 300;
    struct Sample *samples = malloc(n * sizeof(struct Sample));
    if (samples == NULL)
    {
        printf("error ro read the file");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        float noise = ((rand() % 100) / 100.0 - 0.5) * 0.4;
        samples[i].index = i + 1;
        samples[i].time = i * 0.01;
        samples[i].clean_value = sin(2 * M_PI * 1.0 * samples[i].time);
        samples[i].noisy_value = samples[i].clean_value + noise;

        // printf("index: %d\ntime: %.2f\nclean_value: %f\nnoisy_value: %f\n\n", samples[i].index, samples[i].time, samples[i].clean_value, samples[i].noisy_value);
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            samples[i].filtered_value = (samples[i].noisy_value + samples[i + 1].noisy_value) / 2;
        }
        else if (i == n - 1)
        {
            samples[i].filtered_value = (samples[i - 1].noisy_value + samples[i].noisy_value) / 2;
        }
        else
        {
            samples[i].filtered_value = (samples[i - 1].noisy_value + samples[i].noisy_value + samples[i + 1].noisy_value) / 3;
        }
        // printf("filtered_value: %f\n\n", samples[i].filtered_value);
    }

    FILE *fp = fopen("filtering_result.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "index: %d\ntime: %.2f\nclean_value: %f\nnoisy_value: %f\nfiltered_value: %f\n\n", samples[i].index, samples[i].time, samples[i].clean_value, samples[i].noisy_value, samples[i].filtered_value);
    }
    fclose(fp);
    fp = NULL;
    free(samples);

    return 0;
}
