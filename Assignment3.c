#include <stdio.h>
struct stud
{
    int roll;
    char name[20];
    float per;
    char add[50];
    char d;
}s[10],st;

void accept(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nEnter Details of student %d\n",i+1);
        printf("\nEnter student roll number ");
        scanf("%d",&s[i].roll);
        printf("\nEnter the student name ");
        scanf(" %[^\n]%*c",s[i].name);
        printf("\nEnter the address ");
        scanf(" %[^\n]%*c",s[i].add);
        printf("\nEnter division of student ");
        scanf("%c",&s[i].d);
        printf("\nEnter student percentage ");
        scanf("%f",&s[i].per);

    }
}


void write_to_file(int n)
{
    int i;
    FILE *fp;
    fp=fopen("data.txt","a");
    if(fp==NULL)
       printf("\nError");
    else
       for(int i=0;i<n;i++)
           fprintf(fp,"%d %s %f %c %s\n",s[i].roll,s[i].name,s[i].per,s[i].d,s[i].add);
    fclose(fp);
}

void disp(int n)
{
    FILE *fp;
    fp=fopen("data.txt","r");
    if(fp==NULL)
       printf("\nError");
    else
       for(int i=0;i<n;i++)
            {  
                fscanf(fp,"%d %s %f %c %s",&st.roll,st.name,&st.per,&st.d,st.add);
                printf("%d \t%s \t%0.2f \t%c \t%s\n",st.roll,st.name,st.per,st.d,st.add);
            }
    fclose(fp);
}

void search(int n,int rn)
{
    int c=0;
    int roll;
    char nm[100];
    float p;
    FILE *fp;
    fp=fopen("data.txt","r+");
    if(fp==NULL)
       printf("\nError");
    else
        for(int i=0;i<n;i++)
        {
            fscanf(fp,"%d %s %f %c %s",&st.roll,st.name,&st.per,&st.d,st.add);
            if(st.roll==rn)
            {  
                c=1;
                printf("\n%d \t%s \t%0.2f \t%c \t%s\n",st.roll,st.name,st.per,st.d,st.add);
                break;
            }
        }    
    if(c==0)
       printf("\nStudent not found");
    fclose(fp);
}

void delete(int n,int rn)
{
    int roll;
    char nm[100];
    int t=0;
    float p;
    FILE *fp;
    fp=fopen("data.txt","r");
    FILE *f;
    f=fopen("data1.txt","w");
    if(fp==NULL)
       printf("\nError");
    else
    {
        for(int i=0;i<n;i++)
        {
            fscanf(fp,"%d %s %f %c %s",&st.roll,st.name,&st.per,&st.d,st.add);
            if(st.roll!=rn)
            {  
                t++;
                fprintf(f,"%d %s %f %c %s\n",st.roll,st.name,st.per,st.d,st.add);
            }
            
        }    
    }
    fclose(f);
    fclose(fp);
    f=fopen("data1.txt","r");
    fp=fopen("data.txt","w");
    if(f==NULL)
       printf("\nError");
    else
    {
        for(int i=0;i<n-1;i++)
        {
                fscanf(f,"%d %s %f %c %s",&st.roll,st.name,&st.per,&st.d,st.add);
                fprintf(fp,"%d %s %f %c %s\n",st.roll,st.name,st.per,st.d,st.add);
        }
            
    }
    FILE *f1;
    
    fclose(f);
    fclose(fp);
    f1=fopen("data.txt","r");
    if(f1==NULL)
       printf("\nError");
    else
    {
        for(int i=0;i<n-1;i++)
        {
                fscanf(f1,"%d %s %f %c %s",&st.roll,st.name,&st.per,&st.d,st.add);
                printf("%d \t%s \t%0.2f \t%c \t%s\n",st.roll,st.name,st.per,st.d,st.add);
        }
            
    }
}
int main()
{
    int n;
    int ch;
    int rn;
    printf("\nEnter the number of students ");
    scanf("%d",&n);
    accept(n);
    write_to_file(n);
    while(1)
    {
        printf("\nEnter 1 to display all the records ");
        printf("\nEnter 2 to search for a particular student ");
        printf("\nEnter 3 to delete information of a particular student ");
        printf("\nEnter 0 to exit ");
        printf("\nEnter the choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
              disp(n);
              break;
            case 2:
               printf("\nEnter the roll no of student to display record ");
               scanf("%d",&rn);
               search(n,rn);
               break;
            case 3:
               printf("\nEnter the roll no of student to delete record ");
               scanf("%d",&rn);
               delete(n,rn);
               break;
            case 0:
               printf("\nThank you ");
               return 0;
            default:
               printf("\nEnter valid choice ");
               
        }
    }
    return 0;
}
