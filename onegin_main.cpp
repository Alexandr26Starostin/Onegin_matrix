#include <stdio.h>
#include <assert.h>

const int line_max_count = 14;
const int symbol_max_count = 45;

int strcmp (char* first_line, char* second_line);
void strchange (char* first_line, char* second_line);
char lower (char letter);


int main ()
{
    FILE* onegin_file;
    onegin_file = fopen ("onegin_text.txt", "r");
    assert (onegin_file);

    char onegin_text[line_max_count][symbol_max_count] = {};

    for (int number_line = 0; number_line < line_max_count; number_line++)
    {
        fgets (&(onegin_text[number_line][0]), symbol_max_count, onegin_file);

        printf ("%s", &onegin_text[number_line][0]);

    }  

    fclose (onegin_file);

    for (int g = line_max_count; g > 0; g--)
    {
        for (int i = 0; i < g; i++)
        {
            if (strcmp (&onegin_text[i][0], &onegin_text[i+1][0]) > 0)
            {
                strchange (&onegin_text[i][0], &onegin_text[i+1][0]);
            }
        }
    }
    printf ("\n\n\n");

    for (int number_line = 1; number_line < line_max_count+1; number_line++)
    {
        printf ("%s", number_line, &onegin_text[number_line][0]);
    }

    printf("\n\n");

    return 0;
}

int strcmp (char* first_line, char* second_line)
{
    assert (first_line);
    assert (second_line);

    int i = 0;
    while ( (((int) first_line[i]  >= 65 && (int) first_line[i]  <= 90) ? lower (first_line[i])  : first_line[i]) 
          - (((int) second_line[i] >= 65 && (int) second_line[i] <= 90) ? lower (second_line[i]) : second_line[i]) == 0 
            && first_line[i] != '\0') 
    {
        i++;
    }

    return ((((int) first_line[i]  >= 65 && (int) first_line[i]  <= 90) ? lower (first_line[i])  : first_line[i]) 
          - (((int) second_line[i] >= 65 && (int) second_line[i] <= 90) ? lower (second_line[i]) : second_line[i]));
}

void strchange (char* first_line, char* second_line)
{
    assert (first_line);
    assert (second_line);

    for (int i = 0; i < symbol_max_count; i++)
    {
        char temporary = first_line[i];
        first_line[i]  = second_line[i];
        second_line[i] = temporary;
    }
}

char lower (char letter)
{
    return letter - 'A' + 'a';
}