#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct segregate
{
    char str[10];
}seg;
void main()
{
    FILE *fp,*f,*fop,*fsym,*fob_prog,*ftext;
    seg add[100],label[100],mnemonik[100],operand[100],opr[100],sym[100];
    int i,j,address,o=0,l=0,m=0,r,ctr,p,q,k,d,tmp,t,txt=0,txt2;
    int adres[100],length,op[100],sm[100],text[100],tempo,LOCCTR,LEN,val,val1,val2,len[10];
    char c[10],s[10],temp[10];
    printf("--------------------------PRESS ENTER TO SEE MNEMONICS-------------------------\n\n");
    getch();
    fp=fopen("mnemonics.txt","r");
    printf("------------------MNEMONICS THAT CAN BE USED FOR THE MACHINE:---------------\n\n");
    while(c[0] != EOF)
    {
        c[0]=getc(fp);
        putchar(c[0]);
    }
    fclose(fp);
    printf("\n\n---------------------PRESS ENTER TO SEE THE ASSEMBLY CODE:--------------------\n\n");
    getch();
    f=fopen("assemblycode.txt","r");
    printf("\n\n--------------------------ASSEMBLY CODE IS:----------------------\n\n");
    while(c[1]!=EOF)
    {
        c[1]=getc(f);
        putchar(c[1]);
    }
    fclose(f);
    printf("\n\n--------------------ENTER THE STARTING ADDRESS OF THE CODE:---------------------\n\n");
    scanf("%x",&address);
    tempo=address;
    adres[0]=address;
    f=fopen("assemblycode.txt","r");
    i=1;
    while(c[2] != EOF)
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
      c[2]=getc(f);
    }
    fclose(f);
     for(k=1;k<m-1;k++)
    {
        if(strcmp(mnemonik[k].str,"RWD")==0)
        {
            adres[k]=adres[k-1]+(3*(atoi(operand[k].str)));
        }
        else if(strcmp(mnemonik[k].str,"RBT")==0)
        {
            adres[k]=adres[k-1]+(atoi(operand[k].str));
        }
        else
            adres[k]=adres[k-1]+3;
    }
    i=0;
    printf("\n\n------------------AFTER ADDRESSING THE CODE IS:-------------------\n\n");
     f=fopen("assemblycode.txt","r");
    printf("ADDRESS\t");
   while(c[3] != EOF)
    {
        c[3]=getc(f);
        if(c[3] == '\n')
        {
            printf("%c",c[3]);
            printf("%x \t",adres[i]);// %x IS USED FOR HEXADECIMAL
            i++;
        }
        else
            printf("%c",c[3]);
    }
    ctr=i;
    fclose(f);
    length=adres[ctr-1]-adres[0];
    printf("\n\n\n\n--------------------------LENGTH OF THE PROGRAM:   0%x--------------------\n\n",length);
    printf("\n\n-------------------PRESS ENTER TO SEE OPTAB FOR THE MACHINE---------------------\n\n");
    getch();
    fop=fopen("optab.txt","r");
    printf("\n\n-----------------------------OPTAB FOR THE MACHINE:-----------------------------\n\n");
    while(c[4] != EOF)
    {
        c[4]=getc(fop);
        putchar(c[4]);
    }
    fclose(fop);
    fsym=fopen("symtab.txt","w");
    for(k=0;k<o-1;k++)
    {
        for(j=0;j<l-1;j++)
        {
            if(strcmp(operand[k].str,label[j].str)==0)
            {
                fprintf(fsym,"%s \t",operand[k].str);
                fprintf(fsym,"%x \n",adres[j-1]);
            }
        }
    }
    fclose(fsym);
    printf("\n\n-------------------PRESS ENTER TO SEE SYMTAB FOR THE MACHINE--------------------\n\n");
    getch();
    fsym=fopen("symtab.txt","r");
    printf("\n\n---------------------------SYMTAB FOR THE MACHINE:------------------------------\n\n");
    while(c[5] != EOF)
    {
        c[5]=getc(fsym);
        putchar(c[5]);
    }
    fclose(fsym);
    fop=fopen("optab.txt","r");
    i=0;
    while(c[6]!=EOF)
    {
        fscanf(fop,"%s%d",&opr[i].str,&op[i]);
        i++;
        c[6]=getc(fop);
    }
    p=i;
    fclose(fop);
    fsym=fopen("symtab.txt","r");
    i=0;
    while(c[7]!=EOF)
    {
        fscanf(fop,"%s%d",&sym[i].str,&sm[i]);
        i++;
        c[7]=getc(fsym);
    }
    q=i;
    fclose(fsym);
    f=fopen("assemblycode.txt","r");
    t=1;
    while(c[8] != EOF)
    {
      d=t%3;
      switch(d)
      {
        case 0:fscanf(f,"%s",&temp);
               for(tmp=0;tmp<q;tmp++)
               {
                   if(strcmp(temp,sym[tmp].str)==0)
                   {
                      text[txt]=sm[tmp];
                      txt++;
                   }
               }
               break;
        case 1:fscanf(f,"%s",&temp);
               break;
        case 2:fscanf(f,"%s",&temp);
               if(strcmp(temp,"RWD")==0 || strcmp(temp,"RBT")==0)
               {
                text[txt]=-1;
                txt++;
               }
               else
               {
                for(tmp=0;tmp<p;tmp++)
                {
                   if(strcmp(temp,opr[tmp].str)==0)
                   {
                      text[txt]=op[tmp];
                      txt++;
                   }
                }
               }
               break;
      }
      t++;
      c[8]=getc(f);
    }
    fclose(f);
     if(txt!=0)
    {
    LEN=txt;
    i=LEN%20;
    j=LEN/20;
    k=0;
    if(j!=0)
    {
    while(j!=0)
    {
        len[k]=30;
        j--;
        k++;
    }
    }
    len[k]=i;
    }
    ftext=fopen("textrecord.txt","w");
    for(txt2=0;txt2<txt;txt2++)
    {
        fprintf(ftext,"%d",text[txt2]);
    }
    fclose(ftext);
    LOCCTR=0;
    i=0;
     fob_prog=fopen("object_program.txt","w");
    fprintf(fob_prog,"HEADER RECORD IS AS FOLLOWS:\n\nH^%s^00%x^0000%x\n\n",label[0].str,tempo,length);
    fprintf(fob_prog,"TEXT RECORD IS AS FOLLOWS:\n\nT^00%x^%x",adres[LOCCTR],len[0]);
    for(txt2=0;txt2<txt;txt2++)
    {
        if(text[txt2]!=-1)
        {
        if(txt2%20!=0 || txt2==0)
        {
        if(txt2%2==0)
            fprintf(fob_prog,"^");
        fprintf(fob_prog,"%d",text[txt2]);
        }
        else if(txt2%20==0 || txt2!=0)
        {
            i++;
            fprintf(fob_prog,"NEXT TEXT RECORD IS:\n\nT^00%x^%x",adres[10*i],len[i]);
             if(txt2%2==0)
            fprintf(fob_prog,"^");
            fprintf(fob_prog,"%d",text[txt2]);
        }
        }
    }
    fprintf(fob_prog,"\n\nEND RECORD IS AS FOLLOWS:\n\nE^00%x",tempo);
    fclose(fob_prog);
    printf("\n\n---------------------PRESS ENTER TO SEE THE OBJECT PROGRAM----------------------\n\n");
    getch();
    fob_prog=fopen("object_program.txt","r");
    printf("\n\n--------------------------OBJECT PROGRAM FOR THE CODE:--------------------------\n\n");
    while(c[9] != EOF)
    {
        c[9]=getc(fob_prog);
        putchar(c[9]);
    }
    fclose(fob_prog);
}
