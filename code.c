#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 500
#define MAX_HISTORY 100

char lines[MAX_LINES][MAX_LENGTH];
int line_count = 0;

/* ---------- Utility Functions ---------- */

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void read_line(char *str, int size)
{
    if (fgets(str, size, stdin) != NULL)
    {
        str[strcspn(str, "\n")] = '\0';
    }
}

/* ---------- Display ---------- */

void display()
{
    if (line_count == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (int i = 0; i < line_count; i++)
    {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

/* ---------- Insert ---------- */

void insert_line()
{
    int position;
    char text[MAX_LENGTH];

    if (line_count >= MAX_LINES)
    {
        printf("Document is full.\n");
        return;
    }

    printf("Enter line number to insert at (1-%d): ", line_count + 1);

    if (scanf("%d", &position) != 1)
    {
        printf("Invalid line number.\n");
        clear_input_buffer();
        return;
    }

    clear_input_buffer();

    if (position < 1 || position > line_count + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    printf("Enter text: ");
    read_line(text, MAX_LENGTH);

    /* Shift lines down */
    for (int i = line_count; i >= position; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    strcpy(lines[position - 1], text);
    line_count++;

    printf("Line inserted successfully.\n");
}

/* ---------- Delete ---------- */

void delete_line()
{
    int position;

    if (line_count == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("Enter line number to delete (1-%d): ", line_count);

    if (scanf("%d", &position) != 1)
    {
        printf("Invalid line number.\n");
        clear_input_buffer();
        return;
    }

    clear_input_buffer();

    if (position < 1 || position > line_count)
    {
        printf("Invalid line number.\n");
        return;
    }

    /* Shift lines up */
    for (int i = position - 1; i < line_count - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    line_count--;

    printf("Line deleted successfully.\n");
}

/* ---------- Edit ---------- */

void edit_line()
{
    int position;
    char text[MAX_LENGTH];

    if (line_count == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("Enter line number to edit (1-%d): ", line_count);

    if (scanf("%d", &position) != 1)
    {
        printf("Invalid line number.\n");
        clear_input_buffer();
        return;
    }

    clear_input_buffer();

    if (position < 1 || position > line_count)
    {
        printf("Invalid line number.\n");
        return;
    }

    printf("Current text: %s\n", lines[position - 1]);
    printf("Enter new text: ");

    read_line(text, MAX_LENGTH);

    strcpy(lines[position - 1], text);

    printf("Line edited successfully.\n");
}

/* ---------- Save ---------- */

void save_file()
{
    char filename[100];
    FILE *file;

    printf("Enter filename: ");
    read_line(filename, sizeof(filename));

    file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return;
    }

    for (int i = 0; i < line_count; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("File saved successfully.\n");
}

/* ---------- Load ---------- */

void load_file()
{
    char filename[100];
    FILE *file;

    printf("Enter filename: ");
    read_line(filename, sizeof(filename));

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return;
    }

    line_count = 0;

    while (line_count < MAX_LINES &&
           fgets(lines[line_count], MAX_LENGTH, file) != NULL)
    {
        lines[line_count][strcspn(lines[line_count], "\n")] = '\0';
        line_count++;
    }

    fclose(file);

    printf("File loaded successfully. %d lines loaded.\n", line_count);
}

/* ---------- Search ---------- */

void search_text()
{
    char search[MAX_LENGTH];
    int found = 0;

    if (line_count == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("Enter word or phrase to search: ");
    read_line(search, MAX_LENGTH);

    for (int i = 0; i < line_count; i++)
    {
        if (strstr(lines[i], search) != NULL)
        {
            printf("Found on line %d: %s\n", i + 1, lines[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Text not found.\n");
    }
}

/* ---------- Find & Replace ---------- */

void replace_text()
{
    char find[MAX_LENGTH];
    char replace[MAX_LENGTH];

    printf("Enter text to find: ");
    read_line(find, MAX_LENGTH);

    if (strlen(find) == 0)
    {
        printf("Search text cannot be empty.\n");
        return;
    }

    printf("Enter replacement text: ");
    read_line(replace, MAX_LENGTH);

    int replacements = 0;

    for (int i = 0; i < line_count; i++)
    {
        char result[MAX_LENGTH] = "";
        char *start = lines[i];
        char *match;

        while ((match = strstr(start, find)) != NULL)
        {
            char temp[MAX_LENGTH];

            /* Text before match */
            int prefix_length = match - start;

            if ((int)(strlen(result) + prefix_length +
                      strlen(replace) + 1) >= MAX_LENGTH)
            {
                printf("Replacement would make line too long.\n");
                break;
            }

            strncat(result, start, prefix_length);
            strcat(result, replace);

            start = match + strlen(find);
            replacements++;
        }

        if (strlen(start) > 0)
        {
            if (strlen(result) + strlen(start) < MAX_LENGTH)
                strcat(result, start);
        }

        strcpy(lines[i], result);
    }

    printf("%d replacement(s) made.\n", replacements);
}

/* ---------- Statistics ---------- */

void statistics()
{
    int words = 0;
    int characters = 0;

    for (int i = 0; i < line_count; i++)
    {
        int in_word = 0;

        characters += strlen(lines[i]);

        for (int j = 0; lines[i][j] != '\0'; j++)
        {
            if (lines[i][j] == ' ' ||
                lines[i][j] == '\t')
            {
                in_word = 0;
            }
            else if (!in_word)
            {
                words++;
                in_word = 1;
            }
        }
    }

    printf("\n----- STATISTICS -----\n");
    printf("Lines      : %d\n", line_count);
    printf("Words      : %d\n", words);
    printf("Characters : %d\n", characters);
    printf("----------------------\n");
}

/* ---------- Help ---------- */

void help()
{
    printf("\n========== HELP ==========\n");

    printf("insert   - Insert a new line\n");
    printf("delete   - Delete a line\n");
    printf("edit     - Edit an existing line\n");
    printf("display  - Display document\n");
    printf("save     - Save document to a file\n");
    printf("load     - Load document from a file\n");
    printf("search   - Search for a word or phrase\n");
    printf("replace  - Find and replace text\n");
    printf("stats    - Show line/word/character count\n");
    printf("help     - Show this help menu\n");
    printf("quit     - Exit editor\n");

    printf("===========================\n");
}

/* ---------- Main ---------- */

int main()
{
    char command[50];

    printf("====================================\n");
    printf("       SIMPLE LINE EDITOR\n");
    printf("====================================\n");

    printf("Type 'help' to see available commands.\n");

    while (1)
    {
        printf("\n> ");
        read_line(command, sizeof(command));

        if (strcmp(command, "insert") == 0)
        {
            insert_line();
        }
        else if (strcmp(command, "delete") == 0)
        {
            delete_line();
        }
        else if (strcmp(command, "edit") == 0)
        {
            edit_line();
        }
        else if (strcmp(command, "display") == 0)
        {
            display();
        }
        else if (strcmp(command, "save") == 0)
        {
            save_file();
        }
        else if (strcmp(command, "load") == 0)
        {
            load_file();
        }
        else if (strcmp(command, "search") == 0)
        {
            search_text();
        }
        else if (strcmp(command, "replace") == 0)
        {
            replace_text();
        }
        else if (strcmp(command, "stats") == 0)
        {
            statistics();
        }
        else if (strcmp(command, "help") == 0)
        {
            help();
        }
        else if (strcmp(command, "quit") == 0)
        {
            printf("Exiting editor...\n");
            break;
        }
        else if (strlen(command) == 0)
        {
            continue;
        }
        else
        {
            printf("Unknown command. Type 'help' for available commands.\n");
        }
    }

    return 0;
}
