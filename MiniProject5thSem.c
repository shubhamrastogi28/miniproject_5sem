#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct segregate
{
    char str[10];
}seg;
void main()
{
    FILE *fp,*f;
    seg add[20],label[20],mnemonik[20],operand[20];
    int i,j,address,o=0,l=0,m=0,r,ctr;
    int adres[20],length;
    char c,c2,c3,ch;
    fp=fopen("mnemonics.txt","r");
    printf("------------------MNEMONICS THAT CAN BE USED FOR THE MACHINE:---------------\n\n");
    while(ch != EOF)
    {
        ch=getc(fp);
        putchar(ch);
    }
    fclose(fp);
    f=fopen("assemblycode.txt","r");
    printf("\n\n--------------------------ASSEMBLY CODE IS:----------------------\n\n");
    while(c!=EOF)
    {
        c=getc(f);
        putchar(c);
    }
    fclose(f);
     f=fopen("assemblycode.txt","r");
    i=1;
    while(c3 != EOF)
    {
      r=i%3;
      switch(r)
      {
        case 0:fscanf(f,"%s",&operand[o].str);
               o++;
               break;

        case 1: fscanf(f,"%s",&label[l].str);
                l++;
                break;

        case 2:fscanf(f,"%s",&mnemonik[m].str);
               m++;
               break;
      }
      i++;
      c3=getc(f);
    }
    fclose(f);
    i=0;
    printf("\n\n-----------------ENTER THE STARTING ADDRESS OF THE CODE:------------\n");
    scanf("%d",&address);
    printf("\n\n------------------AFTER ADDRESSING THE CODE IS:-------------------\n\n");
     f=fopen("assemblycode.txt","r");
    printf("ADDRESS\t");
   while(c2 != EOF)
    {
        c2=getc(f);
        if(c2 == '\n')
        {
            printf("%c",c2);
            printf("%x \t",address);// %x IS USED FOR HEXADECIMAL
            adres[i]=address;
            address=address+3;
            i++;
        }
        else
            printf("%c",c2);
    }
    ctr=i;
    fclose(f);
    length=adres[ctr-1]-adres[0];
    printf("\n\n\n\n--------------------------LENGTH OF THE PROGRAM:   0%x--------------------\n\n",length);
}
