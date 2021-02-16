/*
    Author:      Патраков Данил
    Group:       СБC−002−О−01 / 2
    Task:        3.1
    Description: Из массива, состоящего из 27 натуральных чисел, найти пару рядом стоящих чисел, НОД которых будет минимален по отношению к остальным парам. Вывести эти числа и их позиции.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_OF_ARRAY 27

int gcd();
int get_element();

int main()
{
    srand(time(0));
    int numbers [SIZE_OF_ARRAY];

    for (int x = 0; x<SIZE_OF_ARRAY; x++)
    {
        numbers[x] = get_element();
    }

    for (int x = 0; x<SIZE_OF_ARRAY; x++)
    {
        printf ("Element %d of array: %d\n", x, numbers[x]);
    }

    int min_pair_gcd_index_1 = 0;
    int min_pair_gcd_index_2 = 1;
    int min_pair_gcd = gcd(numbers[min_pair_gcd_index_1], numbers[min_pair_gcd_index_2]);

    for (int i = 0; i < SIZE_OF_ARRAY-1; i++)
    {
        const int pair_gcd = gcd(numbers[i], numbers[i+1]);
        if (pair_gcd < min_pair_gcd)
        {
            min_pair_gcd_index_1 = i;
            min_pair_gcd_index_2 = i+1;
            min_pair_gcd = pair_gcd;
        }
    }

    printf ("Answer: %d, %d. Their positions: %d, %d. Their GCD: %d.",
            numbers[min_pair_gcd_index_1], numbers[min_pair_gcd_index_2],
            min_pair_gcd_index_1, min_pair_gcd_index_2, min_pair_gcd);

    return 0;
}

int get_element()
{
    const int no_choise = 0;
    const int keyboard_input = 1;
    const int random_input = 2;

    static int choise_of_input = no_choise;

    if (choise_of_input == no_choise)
    {
        int choise_of_input_is_not_correct = 0;
        do
        {
            printf("Do you want to use your own numbers or automatically generated ones?\n"
            "Type 1 for use your own numbers and 2 for automatically ones: ");

            int n = scanf ("%d", &choise_of_input);
            int y = (choise_of_input != keyboard_input && choise_of_input != random_input);

            choise_of_input_is_not_correct = (n != 1 || y);

            if (choise_of_input_is_not_correct)
            {
                printf ("Input error: \n"
                "You can type 1 or 2 only.\n");
                fflush(stdin);
            }
        } while (choise_of_input_is_not_correct);
    }

    if (choise_of_input == keyboard_input)
    {

        int input_number = 0;
        int n = 0;

        do
        {
            printf ("Enter the number: ");
            n = scanf ("%d", &input_number);

            if (n = 0 || input_number <= 0)
            {
                printf ("Input error: \n"
                "You can type natural numbers only.\n");
                fflush(stdin);
            }
        } while (n = 0 || input_number <= 0);

        return input_number;
    }


    if (choise_of_input == random_input)
    {
        return rand();
    }
}

int gcd(const int a, const int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}
