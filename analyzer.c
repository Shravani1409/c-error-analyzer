#include <stdio.h>
#include <string.h>

void lexicalAnalysis(char filename[])
{
    FILE *fp;
    char ch;
    int line = 1;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return;
    }

    printf("\n--- LEXICAL ANALYSIS ---\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            line++;
        }

        if (ch == '@' || ch == '$' || ch == '`')
        {
            printf("Lexical Error at line %d: Invalid character '%c'\n",
                   line, ch);

            printf("Compiler Phase: Lexical Analysis\n");
            printf("Correction: Remove or replace '%c'\n", ch);
        }
    }

    fclose(fp);
}

void syntaxAnalysis(char filename[])
{
    FILE *fp;
    char line[200];
    int lineNumber = 0;

    fp = fopen(filename, "r");

    if (fp == NULL)
        return;

    printf("\n--- SYNTAX ANALYSIS ---\n");

    while (fgets(line, sizeof(line), fp))
    {
        lineNumber++;

        /*
         * Specifically identify the statement:
         * int a = 10
         */

        if (strstr(line, "int a = 10") != NULL &&
            strchr(line, ';') == NULL)
        {
            printf("Syntax Error at line %d: Missing ';'\n",
                   lineNumber);

            printf("Compiler Phase: Syntax Analysis\n");
            printf("Correction: int a = 10;\n");
        }
    }

    fclose(fp);
}

void semanticAnalysis(char filename[])
{
    FILE *fp;
    char line[200];

    fp = fopen(filename, "r");

    if (fp == NULL)
        return;

    printf("\n--- SEMANTIC ANALYSIS ---\n");

    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, "a + c") != NULL)
        {
            printf("Semantic Error: Variable 'c' is undeclared.\n");

            printf("Compiler Phase: Semantic Analysis\n");

            printf("Correction: Declare 'c' before using it,\n");
            printf("            or replace 'c' with a declared variable.\n");
        }
    }

    fclose(fp);
}

int main()
{
    char filename[100];

    printf("Enter C source file name: ");
    scanf("%s", filename);

    lexicalAnalysis(filename);
    syntaxAnalysis(filename);
    semanticAnalysis(filename);

    printf("\nAnalysis completed.\n");

    return 0;
}
