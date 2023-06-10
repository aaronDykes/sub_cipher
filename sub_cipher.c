#ifndef _SUB_CHIPER
#include "sub_cipher.h"
#endif

void run()
{
	Freq f;
	f.char_freq = calloc(alphabet, sizeof(int));
	f.str       = malloc(sizeof(char) * (int)encrypted_length(cipher));

	str_cop(f.str, cipher);

	while (1)
		frequency_analysis(&f);
	free(f.str);
	free(f.char_freq);
}

static void str_cop(char *s, char *c)
{
	while ((*s++ = *c++))
		;
}

static void frequency_analysis(Freq *f)
{
	char *s = f->str + 0;
	for (int i = 0; i < alphabet; i++)
		*(f->char_freq + i) = 0;

	while (*s) {
		if (isalpha(*s))
			*(f->char_freq + *s - 'A') += 1;
		s++;
	}

	sort_frequency(f);
}

static int compare(const void *a, const void *b)
{
	int **a_ptr = (int **)a, **b_ptr = (int **)b;
	return (**b_ptr - **a_ptr);
}

/**
    alpha_sort[0] = highest frequency char
    alpha_sort[25] = lowest frequency char

    Address values 'MUST' be mapped to
    orignal index after sorting method

    ie addresses can't be in sequential order
 */
static void sort_frequency(Freq *f)
{
	for (int i = 0; i < alphabet; i++)
		*(f->alpha_sort + i) = (f->char_freq + i);

	qsort(f->alpha_sort, alphabet, sizeof(int *), compare);
	printf("\n");

	display_freq_analysis(f);
}

static void display_freq_analysis(Freq *f)
{
	char *s1 = f->str + 0;
	char *s2 = mapping + 0;
	char *s3 = common + 0;

	for (int i = 0; i < alphabet; i++) {
		if (((i % 2) == 0) && i != 0)
			printf("\n");
		printf(
		    "\t%c: %d", (char)(*(f->alpha_sort + i) - f->char_freq + 'A'),
		    **(f->alpha_sort + i)
		);
	}
	printf("\n\n");
	while (*s2)
		printf("%c", *s2++);

	printf("\nCommon characters: ");
	while (*s3)
		printf("%c", *s3++);

	while (*s1)
		printf("%c", *s1++);

	input(f);
}

static void swap_ch(Freq *f, char swap1, char swap2)

{
	char *s = f->str + 0;

	while (*s) {
		if (*s == swap1)
			*s = swap2;
		else if (*s == swap2)
			*s = swap1;
		s++;
	}
}

static void input(Freq *f)
{
	char c1 = 0, c2 = 0;

	printf("\n%s", "Enter char 1 and char 2: ");
	scanf(" %c %c", &c1, &c2);
	swap_ch(f, c1, c2);
}

