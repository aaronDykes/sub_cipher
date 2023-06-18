#ifndef _SUB_CHIPER
#include "sub_cipher.h"
#endif

void run()
{
	Freq f;
	f.char_freq = calloc(ALPHABET, sizeof(int));
	f.str       = malloc(sizeof(char) * (int)ENCRYPTED_LEN(cipher5));

	str_cop(f.str, cipher5);

	while (1)
		frequency_analysis(&f);

	free(f.str);
	free(f.char_freq);

	f.str       = NULL;
	f.char_freq = NULL;
}

static void str_cop(char *s, char *c)
{
	while ((*s++ = *c++))
		;
}

static void frequency_analysis(Freq *f)
{
	char *s = f->str;
	for (int i = 0; i < ALPHABET; i++)
		*(f->char_freq + i) = 0;

	for (; *s; s++)
		if (isalpha(*s))
			*(f->char_freq + *s - 'A') += 1;

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
 */
static void sort_frequency(Freq *f)
{
	for (int i = 0; i < ALPHABET; i++)
		*(f->alpha_sort + i) = (f->char_freq + i);

	qsort(f->alpha_sort, ALPHABET, sizeof(int *), compare);
	printf("\n");

	display_freq_analysis(f);
}

static void display_freq_analysis(Freq *f)
{
	char *s1 = f->str;
	char *s2 = mapping;
	char *s3 = common;

	for (int i = 0; i < ALPHABET; i++) {
		if (((i % 2) == 0) && i != 0)
			printf("\n");
		printf(
		    "\t%c: %d", (char)(*(f->alpha_sort + i) - f->char_freq + 'A'),
		    **(f->alpha_sort + i)
		);
	}
	while (*s2)
		printf("%c", *s2++);

	while (*s3)
		printf("%c", *s3++);

	while (*s1)
		printf("%c", *s1++);

	input(f);
}

static void swap_ch(Freq *f, char swap1, char swap2)
{
	char *s = f->str;

	for (; *s; s++)
		if (*s == swap1)
			*s = swap2;
		else if (*s == swap2)
			*s = swap1;
}

static void input(Freq *f)
{
	char c1 = 0, c2 = 0;

	printf("\n%s", "Enter char 1 and char 2: ");
	scanf(" %c %c", &c1, &c2);
	assert((isalpha(c1) && isalpha(c2)) && isupper(c1) && isupper(c2));
	swap_ch(f, c1, c2);
}
