#include <stdio.h>
char input[200];
char output[200];
int  stackInt[200];
int  stackChar[200];
int  topInt = -1;
int  topChar = -1;

int main(void)
{
    int i;
    while(scanf("%s",input) != EOF)
    {
        for(i = 0;input[i] != '\0';i++)
        {
            output[i] = ' ';
            if(topInt == -1 && (input[i] == '(' || input[i] == ')'))
            {
                stackInt[++topInt] = i;
                stackChar[++topChar] = input[i];
            }
            else if(input[i] == '(')
            {
                stackInt[++topInt] = i;
                stackChar[++topChar] = input[i];
            }
            else if(input[i] == ')')
            {
                if(stackChar[topChar] == '(')
                {
                    topChar --;
                    topInt --;
                }
                else
                {
                    stackInt[++topInt] = i;
                    stackChar[++topChar] = input[i];
                }
            }
        }
        output[i] = '\0';
        while(topInt != -1)
        {
            if(stackChar[topChar] == ')')
                output[stackInt[topInt]] = '?';
            else if(stackChar[topChar] == '(')
                output[stackInt[topInt]] = '$';
            topChar--;
            topInt --;
        }
        printf("%s\n%s\n",input,output);
        topChar = -1;
        topInt  = -1;
    }
    return 0;
}
