/*
    Author:      Патраков Данил
    Group:       СБC−002−О−01 / 2
    Task:        1.1
    Description: Ввести длину и ширину прямоугольника и получить его площадь и периметр.
*/

#include <stdio.h>

int main ()
{
    printf ("Enter the length of the rectangle: ");

    int length = 0;
    const int n = scanf ("%d", &length);

    if (n != 1)
    {
        printf ("Input error: "
       "Length must be a number");
       return -1;
    }

    if (length <= 0)
    {
        printf ("Input error: "
       "Length must be a positive number");
       return -1;
    }
    printf ("Enter the width of the rectangle: ");

    int width = 0;
    const int q = scanf ("%d", &width);

    if (q != 1)
    {
        printf ("Input error: "
                "Width must be a number");
        return -1;
    }

    if (width <= 0)
    {
        printf ("Input error: "
                "Width must be a positive number");
       return -1;
    }

    const int area = width * length;
    const int perimeter = (width + length) * 2;

    printf ("The area of the rectangle is: %d\n", area);
    printf ("The perimeter of the rectangle is: %d\n", perimeter);

    return 0;
}
