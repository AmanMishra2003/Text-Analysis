//
// Created by Aman Mishra
// Putting avg letter frequency in french and english
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// ---------------------------------------------------
// Average word length for each alphabet (A–Z)
// ---------------------------------------------------
const double english_avg_len[26] = {
    4.2, 6.1, 5.3, 4.9, 4.7, 5.1, 5.0, 4.8, 3.9, 5.4, 5.6, 5.2, 5.3,
    5.1, 4.8, 5.5, 6.2, 5.0, 4.9, 4.8, 4.7, 5.5, 4.6, 5.8, 5.1, 6.0
};

const double french_avg_len[26] = {
    4.6, 5.8, 5.4, 5.1, 4.9, 5.2, 5.3, 4.7, 4.2, 6.1, 5.5, 5.3, 5.4,
    5.1, 4.8, 5.6, 6.0, 5.2, 5.0, 4.9, 5.1, 5.4, 4.7, 6.3, 5.8, 6.2
};

// ---------------------------------------------------
// Language Character Sets
// ---------------------------------------------------

// ✅ Shared basic alphabet (A–Z + a–z)
const char english_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

// ❌ French-specific accented and special letters
const char *french_dissimilar_chars[] = {
    "à", "â", "ä", "æ",
    "ç",
    "é", "è", "ê", "ë",
    "î", "ï",
    "ô", "œ",
    "ù", "û", "ü",
    "ÿ"
};

#define FRENCH_DISSIMILAR_COUNT (sizeof(french_dissimilar_chars) / sizeof(french_dissimilar_chars[0]))

// ---------------------------------------------------
// Function to print average word length by alphabet
// ---------------------------------------------------
void print_avg_word_length(const char *language) {
    const double *data = NULL;

    if (language[0] == 'E' || language[0] == 'e') {
        data = english_avg_len;
    } else if (language[0] == 'F' || language[0] == 'f') {
        data = french_avg_len;
    } else {
        printf("Unsupported language.\n");
        return;
    }

    printf("\nAverage Word Length by Alphabet in %s:\n", language);
    printf("----------------------------------------\n");
    for (int i = 0; i < 26; i++) {
        printf("%c : %.2f\n", 'A' + i, data[i]);
    }
}

// ---------------------------------------------------
// Function to print characters unique or shared
// ---------------------------------------------------
void print_language_characters(const char *language) {
    if (language[0] == 'E' || language[0] == 'e') {
        printf("\nEnglish Shared Alphabet Characters:\n");
        printf("%s\n", english_chars);
    }
    else if (language[0] == 'F' || language[0] == 'f') {
        printf("\nFrench Shared Alphabet Characters:\n");
        printf("%s\n", english_chars);

        printf("\nFrench Dissimilar (Accented) Characters:\n");
        for (int i = 0; i < FRENCH_DISSIMILAR_COUNT; i++) {
            printf("%s ", french_dissimilar_chars[i]);
        }
        printf("\n");
    }
    else {
        printf("Unsupported language.\n");
    }
}

// ---------------------------------------------------
// Main Function
// ---------------------------------------------------
int main(void) {
    FILE* fptr;

    // Opening the file in read mode
    fptr = fopen("filename.txt", "r");

    // checking if the file is 
    // opened successfully
    if (fptr == NULL) {
        printf("The file is not opened.");
    }

    // Print English details
    print_avg_word_length("English");
    print_language_characters("English");

    // Print French details
    print_avg_word_length("French");
    print_language_characters("French");

    return 0;
}
