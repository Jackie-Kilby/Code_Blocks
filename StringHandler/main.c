#include <stdio.h>

//Count specific character num in a sentence
#define SENTENCE    "Jack is working on this program.\n"
const char example_sentence[] = "That is a \' sentence.\'\"";

static void example_program_7_6_in_C_Primer_Plus(void);

typedef enum {
    CHAR_COUNT_WITHOUT_SPECIFIC_CHAR,
    CHAR_COUNT_OF_SPECIFIC_CHAR
} mode_t;

long get_char_count_of_sentence(mode_t mod, const char sentence[], char specchar)
{
    long count = 0;
    int i = 0;

    if (CHAR_COUNT_WITHOUT_SPECIFIC_CHAR == mod) {
        for (i=0 ; '\0' != sentence[i]; i++) {
            if (specchar != sentence[i]) {
                count++;
            }
        }
    } else if (CHAR_COUNT_OF_SPECIFIC_CHAR == mod) {
        for (i=0 ; '\0' != sentence[i]; i++) {
            if (specchar == sentence[i]) {
                count++;
            }
        }
    }
    return count;
}


int main() {
    example_program_7_6_in_C_Primer_Plus();
    return 0;
}

static void example_program_7_6_in_C_Primer_Plus(void)
{
    unsigned int result = 0;
    //To count characters in a sentence without "'" and """
#if 0 //The method of using API
    result = sizeof(example_sentence) - 1;
    result -= get_char_count_of_sentence(CHAR_COUNT_OF_SPECIFIC_CHAR, example_sentence, '\'');
    result -= get_char_count_of_sentence(CHAR_COUNT_OF_SPECIFIC_CHAR, example_sentence, '\"');
#endif //
#if 1 // The method of using getchar()
    char ch;
    printf("Now it's time for you to input your sentence! The '.' will make it end:\n");

    while ( (ch = getchar()) != '.' ) {
        if ('\'' != ch && '\"' != ch) {
            result ++;
        }
    }
#endif //

    printf("The num of chars without ' and \" in sentence is %u\n", result);
}