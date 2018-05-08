#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 200
struct address{
  char city[10];
  char street[20];
  char zip[10];};
struct link{
  char phone[20];
  char name[20];
  char QQ[15];
  char email[40];
  struct address addr;
  };
  FILE *fp;
    int Count=0;
    int i;
    char mingzi[20];
    struct link s[MaxSize];
    void new_readfromfile(struct link s[]);
    void new_link(struct link s[]);
    void search_link(struct link s[]);
    void skim_link(struct link s[]);
    void amend_link(struct link s[]);
    void delete_link(struct link s[]);
    void ifyou(int Count,struct link s[]);

  int main()
  {
      int choice,num;
      new_readfromfile(s);      /*导入已保存在文件中的联系人*/
      do{
         printf("\n\t--------------Welcome to use the address book-------------");     /*通讯录主菜单*/
         printf("\n\tNumber of contacts:%d",Count);
         printf("\n\tPlease input 0~5");
         printf("\n\t               1-new                2-search             ");
         printf("\n\t               3-skim               4-amend              ");
         printf("\n\t               5-delete             0-exit               ");
         printf("\n\t---------------------------------------------------------\n");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1:new_link(s); break;
          case 2:search_link(s); break;
          case 3:skim_link(s); break;
          case 4:amend_link(s); break;
          case 5:delete_link(s); break;
          case 0:break;
      }
      }while(choice!=0);
      printf("END\n");

  }


      void new_readfromfile(struct link s[])   /*导入已保存在文件中的联系人函数*/
      {
          Count=0;
          FILE *fp;
          FILE *fp1;
          if((fp=fopen("c:f12-1.txt","r"))==NULL)  /*判断文件是否存在*/
          {
              if((fp=fopen("c:f12-1.txt","w"))==NULL)  /*新建文件*/
              {
                  printf("File open error!\n");
                  exit(0);
              }
          }
          char ch;
         fp1=fopen("c:f12-1.txt","r");
         ch=fgetc(fp1);
         if(ch==EOF )
         Count--;
          while(!feof(fp))
          {
              fscanf(fp,"%s %s %s %s %s %s %s ",s[Count].name,s[Count].phone,s[Count].QQ,
                     s[Count].email,s[Count].addr.city,s[Count].addr.street,s[Count].addr.zip);
              Count++;
          }
      }



      void new_link(struct link s[])  /*新建联系人函数*/
      {
          FILE *fp;
          int choice,i;
          char b,c;
          struct link s1;
          if(Count==MaxSize)
             printf("The array is full!\n");
          printf("name:");
          scanf("%s",s1.name);
          printf("phone:");
          scanf("%s",s1.phone);
          printf("QQ:");
          scanf("%s",s1.QQ);
          printf("email:");
          scanf("%s",s1.email);
          struct address addr;
          printf("city:");
          scanf("%s",s1.addr.city);
          printf("street:");
          scanf("%s",s1.addr.street);
          printf("zip:");
          scanf("%s",s1.addr.zip);
          printf("Do you want to save this contact(Y/N):"); /*是否保存此联系人到文件中提示*/
          scanf(" %c",&b);
          if(b!='Y')
            return;
            s[Count]=s1;
            if((fp=fopen("c:f12-1.txt","a"))==NULL)
              {
                  printf("File open error!\n");
                  exit(0);
              }
              fprintf(fp,"%s %s %s %s %s %s %s ",s[Count].name,s[Count].phone,s[Count].QQ,
                      s[Count].email,s[Count].addr.city,s[Count].addr.street,s[Count].addr.zip);
          Count++;
          printf("Contacts have been saved!\n");
          if(fclose(fp)){
            printf("Can not close the file!\n");
            return;
          }
          printf("Do you want to continue(Y/N):");
          scanf(" %c",&c);
          if(c!='Y')
            return;
          else
            new_link(s);

      }




      void search_link(struct link s[])   /*查询联系人函数*/
      {
          char c;
          int i,flag=0;
          if(Count==0)
          {
              printf("Count of people is zero!\n");
              return;
          }
          printf("Please input name:");
          scanf("%s",mingzi);
          for(i=0;i<Count;i++)
          {
              if(strcmp(s[i].name,mingzi)==0)
                {flag=1;
                break;}
          }
          if(flag)
          {
             printf("name:%s  ",s[i].name);
             printf("phone:%s  ",s[i].phone);
             printf("QQ:%s  ",s[i].QQ);
             printf("email:%s  ",s[i].email);
             printf("address:%s%s%s \n",s[i].addr.city,s[i].addr.street,s[i].addr.zip);
          }
          else
            printf("Not Found!\n");
            printf("Do you want to continue(Y/N):");
          scanf(" %c",&c);
          if(c!='Y')
            return;
          else
            search_link(s);
      }

      void skim_link(struct link s[])  /*浏览所有联系人函数*/
      {
          if(Count==0){
            printf("address list is zero!\n");
            return;
            }
            i=0;
            printf("name\t   phone\t   QQ\t   email\t   address\n");
            ifyou(Count-1,s);  /*调用递归函数*/
      }
      void ifyou(int Count,struct link s[])  /*递归函数*/
      {
          if(Count>=0){
             printf("%s\t",s[i].name);
             printf("%s\t",s[i].phone);
             printf("%s\t",s[i].QQ);
             printf("%s\t",s[i].email);
             printf("%s%s%s\n",s[i].addr.city,s[i].addr.street,s[i].addr.zip);
             i++;
             ifyou(Count-1,s);
          }
      }


       void amend_link(struct link s[])  /*修改联系人函数*/
       {
           char c;
          int i,flag=0;
          if(Count==0)
          {
              printf("Count of people is zero!\n");
              return;
          }
          printf("Please enter a name to update:");
                 scanf("%s",mingzi);
          for(i=0;i<Count;i++)
          {
              if(strcmp(s[i].name,mingzi)==0)
                {flag=1;getchar();
                break;}
          }
          int choice;
          printf("name:");
          scanf("%s",s[i].name);
          printf("phone:");
          scanf("%s",s[i].phone);
          printf("QQ:");
          scanf("%s",s[i].QQ);
          printf("email:");
          scanf("%s",s[i].email);
          struct address addr;
          printf("city:");
          scanf("%s",s[i].addr.city);
          printf("street:");
          scanf("%s",s[i].addr.street);
          printf("zip:");
          scanf("%s",&s[i].addr.zip);
          if((fp=fopen("c:f12-1.txt","w"))==NULL)
              {
                  printf("File open error!\n");
                  exit(0);
              }
              for(i=0;i<Count;i++){
              fprintf(fp,"%s %s %s %s %s %s %s ",s[i].name,s[i].phone,s[i].QQ,s[i].email,
                      s[i].addr.city,s[i].addr.street,s[i].addr.zip);}
          if(fclose(fp)){
            printf("Can not close the file!\n");
            return;}
            printf("Do you want to continue(Y/N):");
          scanf(" %c",&c);
          if(c!='Y')
            return;
          else
            amend_link(s);
       }


       void delete_link(struct link s[])  /*删除联系人函数*/
       {
           char c;
          int i,j,flag=0;
          if(Count==0)
          {
              printf("Count of people is zero!\n");
              return;
          }
          printf("Please enter a name to delete:");
          scanf("%s",mingzi);
          for(i=0;i<Count;i++)
          {
              if(strcmp(s[i].name,mingzi)==0)
                {flag=1;
                break;}
          }
          if(flag)
          {
              for(j=i;j<Count;j++)
              {
                  s[j]=s[j+1];
                  if(j==Count-2)
                    break;
              }
              Count--;
              printf("The contact has been deleted\n");
          }
          else
            printf("Not Found!\n");
            if((fp=fopen("c:f12-1.txt","w"))==NULL)
              {
                  printf("File open error!\n");
                  exit(0);
              }
              for(i=0;i<Count;i++){
              fprintf(fp,"%s %s %s %s %s %s %s ",s[i].name,s[i].phone,s[i].QQ,s[i].email,
                      s[i].addr.city,s[i].addr.street,s[i].addr.zip);}
          if(fclose(fp)){
            printf("Can not close the file!\n");
            return;}
           printf("Do you want to continue(Y/N):");
          scanf(" %c",&c);
          if(c!='Y')
            return;
          else
            delete_link(s);
       }


