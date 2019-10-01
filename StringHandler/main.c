#include <stdio.h>

//Count specific character num in a sentence
#define SENTENCE    "Jack is working on this program.\n"

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
    long num = get_char_count_of_sentence(CHAR_COUNT_OF_SPECIFIC_CHAR, SENTENCE, 'k');
    printf("the result is %d\n", num);
    return 0;
}

