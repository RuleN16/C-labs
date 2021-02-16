/*
    Author:      Патраков Данил
    Group:       СБC−002−О−01 / 2
    Task:        4.1
    Description: Определить число пар одинаковых соседних элементов в каждой строчке и каждом столбце двумерного массива.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500

void scanf_with_number_check (int* number); // ввод и проверка ввода на буквы
int real_rand (const int a, const int b); // рандомная генерация числа, переменные a, b отвечают за промежуток, в котором будут генерироваться числа
int get_row (); // выбор способа ввода количества строк массива
int get_column (); // выбор способа ввода количества столбцов массива
int get_row_manual (); // ввод количества строк массива с клавиатуры
int get_column_manual (); // ввод количества столбцов массива с клавиатуры
int get_size_manual (const char* const size_str);
int choise_of_filling (); // выбор способа заполнения массива
int random_filling (); // рандомное заполнение массива
int manual_filling (); // заполнение массива с клавиатуры
int display_matrix (int arr [MAX_SIZE][MAX_SIZE], int row, int column); // вывод массива в виде матрицы (по желанию пользователя)
int get_amount_of_pairs (int arr [MAX_SIZE][MAX_SIZE], int row, int collumn); // нахождение и подсчёт пар


int main ()
{
    srand(time(NULL));
    int array [MAX_SIZE][MAX_SIZE];
    const int row = get_row();
    const int column = get_column();

    if (choise_of_filling() == 1)
    {
        for (int x = 0; x < row; x++)
        {
            for (int y = 0; y < column; y++)
            {
                array [x][y] = manual_filling();
            }

        }

    }
    else
    {
        for (int x = 0; x < row; x++)
        {
            for (int y = 0; y < column; y++)
            {
                 array [x][y] = random_filling();
            }

        }

    }
    display_matrix (array, row, column);

    printf ("Your array have %d rows and %d columns.\n"
            "The number of pairs of identical neighboring elements in each row and each column is: "
            "%d", row, column, get_amount_of_pairs(array, row, column));

    return 0;
}

void scanf_with_number_check (int* number) // ввод и проверка ввода на буквы
{
    int n = 0;
	do {
		n = scanf("%d", number);
		if (n != 1)
        {
            printf("Input error: \n"
            "You can type numbers only, try again: ");
            fflush(stdin);
        }
	} while (n != 1);
}

int real_rand (const int a, const int b) // рандомная генерация числа, переменные a, b отвечают за промежуток, в котором будут генерироваться числа
{
    const double rand_0_1 = rand() / (RAND_MAX + 1.0);
    int n = b - a + 1;
    const int res = a + (int) (rand_0_1 * n);
    return res;
}

int get_row () // выбор способа ввода количества строк массива
{
    int desigion = 0;

    do
    {
        printf ("Do you want to enter the number of rows by yourself, or use random generation?\n"
                "Enter 1 for manual input or 2 for random input: ");
        scanf_with_number_check (&desigion);
        if (desigion != 1 && desigion != 2)
        {
            printf ("Input error: \n"
            "You can type 1 or 2 only.\n");
            fflush(stdin);
        }
    } while (desigion != 1 && desigion != 2);

    if (desigion == 1)
        return get_row_manual();
    else return (real_rand (1, 500));
}

int get_column () // выбор способа ввода количества столбцов массива
{
    int desigion = 0;

    do
    {
        printf ("Do you want to enter the number of columns by yourself, or use random generation?\n"
                "Enter 1 for manual input or 2 for random input: ");
        scanf_with_number_check (&desigion);
        if (desigion != 1 && desigion != 2)
        {
            printf ("Input error: \n"
            "You can type 1 or 2 only.\n");
            fflush(stdin);
        }
    } while (desigion != 1 && desigion != 2);

    if (desigion == 1)
        return get_column_manual();
    else return (real_rand (1, 500));
}

int get_size_manual (const char* const size_str)
{
    int size = 0;

    do
    {
        printf ("Enter the number of %s of the array: ", size_str);
        scanf_with_number_check (&size);
        if (size > MAX_SIZE || size <= 0)
        {
            printf ("Input error: \n"
            "Number of %s cannot be equal or less than 0 and more than %d.\n", size_str, MAX_SIZE);
            fflush(stdin);
        }
    } while (size > MAX_SIZE || size <= 0);

    return size;
}

int get_row_manual () // ввод количества строк массива с клавиатуры
{
    return get_size_manual("rows");
}

int get_column_manual () // ввод количества столбцов массива с клавиатуры
{
    return get_size_manual("columns");
}

int choise_of_filling () // выбор способа заполнения массива
{
    int desigion = 0;

    do
    {
        printf ("Do you want to fill array by yourself, or use random generation?\n"
                "Enter 1 for manual input or 2 for random input: ");
        scanf_with_number_check (&desigion);
        if (desigion != 1 && desigion != 2)
        {
            printf ("Input error: \n"
            "You can type 1 or 2 only.\n");
            fflush(stdin);
        }
    } while (desigion != 1 && desigion != 2);

    return desigion;
}

int random_filling () // рандомное заполнение массива
{
    int min_element = 0;
    static int max_element = 0;

    if (max_element == 0)
    {
        printf ("Enter the beginning of the random number selection interval: ");
        scanf_with_number_check (&min_element);

        printf ("Enter the ending of the random number selection interval: ");
        scanf_with_number_check (&max_element);
    }

    return real_rand (min_element, max_element);
}

int manual_filling () // заполнение массива с клавиатуры
{
    int element = 0;

        printf ("Enter the element of array: ");
        scanf_with_number_check (&element);

    return element;
}

int display_matrix (int arr [MAX_SIZE][MAX_SIZE], int row, int column) // вывод массива в виде матрицы (по желанию пользователя)
{
    int desigion = 0;
    do
    {
        printf ("Do you want to see your array in matrix notation?\n"
                "Enter 1 for Yes or 2 for No: ");
        scanf_with_number_check (&desigion);
        if (desigion != 1 && desigion != 2)
        {
            printf ("Input error: \n"
            "You can type 1 or 2 only.\n");
            fflush(stdin);
        }
    } while (desigion != 1 && desigion != 2);

    if (desigion == 1)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                printf ("%d\t", arr[i][j]);
            }
            printf ("\n");
        }
    }

}

int get_amount_of_pairs (int arr [MAX_SIZE][MAX_SIZE], int row, int column) // нахождение и подсчёт пар
{
    int num = 0;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column-1; j++)
            if (arr [i][j] == arr [i][j+1])
            {
                printf ("Found elements: [%d][%d] and [%d][%d], their value is %d\n", i, j, i, j+1, arr [i][j]);
                num++;
            }

    for (int j = 0; j < column; j++)
        for (int i = 0; i < row-1; i++)
            if (arr [i][j] == arr [i+1][j])
            {
                printf ("Found elements: [%d][%d] and [%d][%d], their value is %d\n", i, j, i+1, j, arr [i][j]);
                num++;
            }

    return num;
}
