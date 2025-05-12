#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int IsPalindrome(char s[])
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
            return 0;
    }

    return 1;
}

int CountVowel(char s[])
{
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        switch (c)
        {
        case 'a':
            count++;
            break;
        case 'e':
            count++;
            break;
        case 'i':
            count++;
            break;
        case 'o':
            count++;
            break;
        case 'u':
            count++;
            break;
        default:
            break;
        }
    }

    return count;
}

char *StrAppend(char x[], char y[])
{
    int len_x = strlen(x);
    int len_y = strlen(y);

    int len = len_x + len_y;

    char *str = (char *)malloc(sizeof(char) * len + 1);

    for (int i = 0; i < len_x; i++)
        str[i] = x[i];

    for (int i = len_x; i < len; i++)
        str[i] = y[i - len_x];

    str[len] = '\0';

    return str;
}

void StrLower(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = (char)(str[i] + 32);
}

void StrUpper(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = (char)(str[i] - 32);
}

// Count occurrence of a word in a string
int StrCountWord(char str[], char word[])
{
    int word_count = 0;
    int word_index = 0;
    int word_len = 0;

    int str_word_len = 0;

    for (int i = 0; word[i] != '\0'; i++)
        word_len++;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == word[word_index])
        {
            if (str_word_len > word_len)
            {
                str_word_len = 0;
                word_index = 0;
                continue;
            }
            str_word_len++;
            word_index++;
        }
        else
            word_index = 0;

        if (word_index == word_len && (str[i + 1] == 32 || str[i + 1] == '\0' || str[i + 1] == '.'))
        {
            word_count++;
            word_index = 0;
            str_word_len = 0;
        }
    }

    return word_count;
}

// Remove all occurrences of a character from a string
void StrRemoveChar(char *str, char c)
{
    int s_len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
            continue;
        s_len++;
    }

    int arr_i = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
            continue;
        // This works because we are directly modifying the SHARED memory of the main char ptr and function char ptr
        // Assigning it a new pointer will only update the function char ptr to the new location, not the main ptr
        str[arr_i++] = str[i];
    }

    str[arr_i] = '\0';
}

void StrReplaceChar(char str[], char _old_char, char _new_char)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == _old_char)
            str[i] = _new_char;
}