/*
    Author:      Патраков Данил
    Group:       СБC−002−О−01 / 2
    Task:        5.1
    Description: В предложении найти слова, в которых согласных букв больше, чем гласных. За согласные принимать все символы, которые не являются гласными буквами английского алфавита.
*/

#include <stdio.h>
#include <malloc.h>

char* get_sentence (int* const size); // ввод строки
void scanf_with_number_check (int* number); // ввод числа и проверка ввода на буквы
int get_allocatable_str(char** str_ptr, int* const len_ptr); // динамическое выделение памяти
void letters_scan (char* sentence, int size); // поиск и вывод подходящих по условию слов

int main()
{
    int size_of_sentence = 0;
    char* sentence = get_sentence (&size_of_sentence);
    letters_scan(sentence, size_of_sentence);
    free(sentence);
    return 0;
}

char* get_sentence (int* const size_ptr) // ввод строки
{
    char* sentence;
    printf ("Enter the sentence: \n");

    const int alloc_error_code = get_allocatable_str(&sentence, size_ptr);

    if (alloc_error_code == -1)
    {
        return -1;
    }

    return sentence;
}

void scanf_with_number_check (int* number) // ввод числа и проверка ввода на буквы
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

int get_allocatable_str(char** str_ptr, int* const len_ptr) // динамическое выделение памяти
{
	const int init_size = 10;

	int size = init_size;
	char* str = (char*)malloc(init_size * sizeof(char));

	if (str == NULL)
    {
        return -1;
    }

	char symbol = 0;
	int index_of_symbol = 0;
	const char input_end = '\n';

	do {
		symbol = getchar();
		str[index_of_symbol] = symbol;
		index_of_symbol += 1;

		if (index_of_symbol == size) {
			const int reallocate_size = size + init_size;
			char* str_temp_realloc = (char*)realloc(str, reallocate_size * sizeof(char));
			if (str_temp_realloc != NULL) {
				str = str_temp_realloc;
				size = reallocate_size;
			} else {
				free(str);
				return -1;
			}
		}
	} while (symbol != input_end);

	const int size_of_ends = 1;
	const int reallocate_size = index_of_symbol + size_of_ends;
	char* str_temp_realloc = (char*)realloc(str, reallocate_size * sizeof(char));
	if (str_temp_realloc != NULL) {
		str = str_temp_realloc;
		size = reallocate_size;
		str[size - 1] = '\0';
	} else {
		free(str);
		return -1;
	}

	*str_ptr = str;
	*len_ptr = size;

	return 0;
}

void letters_scan (char* sentence, int size) // поиск и вывод подходящих по условию слов
{
    char vowels[] = "AEIOUYaeiouy";
    char consonant_word[size];
    int pointer = 0;
    int vowels_count = 0;
    int symbols_count = 0;

    for (int i = 0; i < size; i++)
    {
        if (sentence[i] != ' ')
        {
            symbols_count++;
            for (int j = 0; j < 12; j++)
            {
                if (sentence[i] == vowels[j])
                {
                    vowels_count++;
                }
            }
            consonant_word[pointer] = sentence[i];
            pointer++;
        }
        else
        {
            if ((symbols_count - vowels_count) > vowels_count)
            {
                printf ("Word found: %s\n", consonant_word);
            }
            pointer = 0;
            vowels_count = 0;
            symbols_count = 0;
            for (int x = 0; x < size; x++)
            {
                consonant_word[x] = '\0';
            }
        }
        if (i == (size-1) && (symbols_count - vowels_count) > vowels_count)
        {
            printf ("Word found: %s\n", consonant_word);
        }
    }
}
