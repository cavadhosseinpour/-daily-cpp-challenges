#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* findAndReplace(const char *text, const char *old_text, const char *new_text);

int main(void)
{
    int buffer_size = 50;
    char *text = malloc(buffer_size * sizeof(char));
    char *old_text = malloc(buffer_size * sizeof(char));
    char *new_text = malloc(buffer_size * sizeof(char));

    printf("Enter the text: ");
    fgets(text, buffer_size, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline from text

    
    printf("Enter the text you want to modify: ");
    fgets(old_text, buffer_size, stdin);
    old_text[strcspn(old_text, "\n")] = '\0'; // Remove newline from text

    
    printf("Enter the text you want to replace: ");
    fgets(new_text, buffer_size, stdin);
    new_text[strcspn(new_text, "\n")] = '\0'; // Remove newline from text

    char *result = findAndReplace(text, old_text, new_text);
    printf("The new string is: %s\n", result);


    free(text);
    free(old_text);
    free(new_text);
    free(result);
    return 0;
}

char* findAndReplace(const char *text, const char *old_text, const char *new_text)
{
    if (!text || !old_text || !new_text) return NULL;

    int text_len = 0, old_len = 0, new_len = 0;
    while (text[text_len] != '\0') text_len++;
    while (old_text[old_len] != '\0') old_len++;
    while (new_text[new_len] != '\0') new_len++;

    // printf("The size of the text, old and new are %i & %i & %i\n", text_len, old_len, new_len);

    int final_len = text_len - old_len + new_len;

    char *replaced_string = (char*)malloc((final_len + 1) * sizeof(char));
    if (!replaced_string) return NULL;

    int i = 0;
    int k = 0;
    while (i < text_len)
    {
        int match = 1;
        for (int j = 0; j < old_len; j++)
        {
            if ((i + j) >= text_len || text[i + j] != old_text[j])
            {
                match = 0;
                break;
            }
        }
        if (match && old_len > 0)
        {
            for (int j = 0; j < new_len; j++)
            {
                replaced_string[k++] = new_text[j];
            }
            i += old_len;
        }
        else
        {
            replaced_string[k++] = text[i];
            i++;
        }
    }

    replaced_string[k] = '\0';
    return replaced_string;
}