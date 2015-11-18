#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    FILE *fp;
    int i,j;
    char ch;
    fp=fopen("mnemonics.txt","r");
    printf("------------------MNEMONICS THAT CAN BE USED FOR THE MACHINE:---------------\n\n");
    while(ch != EOF)
    {
        ch=getc(fp);
        putchar(ch);
    }
    fclose(fp);
}
