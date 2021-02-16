/*
    Author:      Патраков Данил
    Group:       СБC−002−О−01 / 2
    Task:        2.13
    Description: Вывести все трехзначные числа, сумма цифр которых равна натуральному числу, которое задал пользователь.
*/

#include <stdio.h>
#include <assert.h>

int main ()
{
    int number = 0; // global rename "number" -> "result_sum"


    do
    {
        printf ("Enter the natural number: ");
        const int n = scanf ("%d", &number);

        if (n != 1)
        {
            printf ("Input error: \n"
            "Natural number must be a number\n");
            fflush(stdin);
        } else {}

        if (number <= 0)
        {
            printf ("Input error: \n"
            "Natural number cannot be equal or less than 0\n");
        } else {}

    } while (number <= 0);

    const int max_number = 27;
    if (number > max_number)
    {
        printf ("There is no three-digit numbers whose sum of digits is %d\n", number);
        return 0;
    }

    printf ("All three-digit numbers whose sum of digits is %d:\n", number);

    const int min_final_number = 100;
    const int max_final_number = 1000;

    for (int final_number = min_final_number; final_number < max_final_number; final_number++)
    {
        const int reminder_a = final_number;
        const int digit_a = reminder_a % 10;

        const int reminder_b = reminder_a / 10;
        const int digit_b = reminder_b % 10;

        const int reminder_c = reminder_b / 10;
        const int digit_c = reminder_c % 10;

        const int sum = digit_a + digit_b + digit_c;
        const int result = digit_c*100 + digit_b*10 + digit_a;

        assert (result == final_number);

        if (sum == number)
        {
            printf ("%d\n", result);
        }
    }
    return 0;
}
