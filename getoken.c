#include "shell.h"

/**
 * get_token - Tokenize a string into an array of tokens.
 * @line: The input string to tokenize.
 *
 * Return: An array of token strings.
 */

char **get_token(char *line)
{
    char *token = NULL, *tokencp = NULL;
    char **cmd = NULL;
    int cont = 0, i = 0;
    
    if(!line)
        return(NULL);
    tokencp = _strdup(line);
    token = strtok(tokencp, SPECIF);
    if(token == NULL)
    {
        free(line), line = NULL;
        free(tokencp), tokencp = NULL;
        return(NULL);
    
    }
    while (token)
    {
        cont++;
        token = strtok(NULL, SPECIF);
    }
    free(tokencp), tokencp = NULL;
    
    cmd = malloc(sizeof(char *) * (cont + 1));
    if(!cmd)
    {
        free(line), line = NULL;
        return (NULL);
    }
    token = strtok(line, SPECIF);
    while (token)
    {
        cmd[i] = _strdup(token);
        token = strtok(NULL, SPECIF);
        i++;
    }
    free(line), line = NULL;
    cmd[i] = NULL;
    return(cmd);
}
