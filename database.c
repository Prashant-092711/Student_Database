#include<stdio.h>
#include<conio.h>
 void addstudent();
 void studentrecord();
 void searchstudent();
 void delete();
  struct student
  {
   char first_name[20];
   char last_name[20];
   int roll_number;
   char class[10];
   char vill[20];
   float per;
   };
 void main()
 {
     int choice;
     while(choice!=5){
    printf("\t\t\t============STUDENT DATABASE MANGEMENT SYSTEM============");
    printf("\n\n\t\t\t\t 1. ADD STUDENT RECORD\n");
    printf("\t\t\t\t 2. STUDENT RECORDS\n");
    printf("\t\t\t\t 3. SEARCH STUDENT\n");
    printf("\t\t\t\t 4. DELETE RECORD\n");
    printf("\t\t\t\t 5. EXIT\n");
    printf("\t\t\t=======================================\n");
    printf("\t\t\t");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
case 1:
    addstudent();
    break;

case 2:
    studentrecord();
    printf("\t\t\tPress Any Key To Exit\n");
    getch();
    break;
case 3:
    searchstudent();
    printf("\n\t\t\tPress Any Key To exit\n");
    getch();
    break;
case 4:
    delete();
    printf("\n\t\t\tPress Any Key To exit\n");
    getch();
    break;
     }
 }
 }
  void addstudent()
  {
      char another;
      FILE *fp;
      struct student info;

      do
      {

          printf("\t\t\t==========ADD STUDENT INFO==========");
          fp=fopen("student_info","a");
          printf("\n\t\t\tEnter First Name : ");
          scanf("%s",&info.first_name);
          printf("\n\t\t\tEnter Last Name  : ");
          scanf("%s",&info.last_name);
          printf("\n\t\t\tEnter Roll Number: ");
          scanf("%d",&info.roll_number);
          printf("\n\t\t\tEnter Class      : ");
          scanf("%s",&info.class);
          printf("\n\t\t\tEnter Address    : ");
          scanf("%s",&info.vill);
          printf("\n\t\t\tEnter Percentage : ");
          scanf("%f",&info.per);
          printf("\n\t\t\t_________________________\n");
          if(fp==NULL)
          {
              fprintf(stderr,"\t\t\t Can't open file\n");
          }else{
          printf("\t\t\tRecord Stored Successfuly\n");
          }
          fwrite(&info,sizeof(struct student),1,fp);
          fclose(fp);
          printf("\t\t\t Add Another Record?(y/n) : ");
          scanf("%s",&another);
          }

     while(another=="y"|| another=="Y");{

    }
  }
  void studentrecord()
  {
       FILE *fp;
      struct student info;
      fp=fopen("student_info","r");
      printf("\t\t\t==========STUDENT RECORDS==========\n");

      if(fp==NULL)
      {
          fprintf(stderr,"\t\t\tCan't open files\n");
      }else
      {
          printf("\t\t\tRecords\n");
          printf("\t\t\t________________\n\n");
      }
      while(fread(&info,sizeof(struct student),1,fp))
      {
          printf("\n\t\t\tStudent Name : %s %s",info.first_name,info.last_name);
          printf("\n\t\t\tRoll Number  : %d",info.roll_number);
          printf("\n\t\t\tClass        : %s",info.class);
          printf("\n\t\t\tAddress      : %s",info.vill);
          printf("\n\t\t\tPercentage   : %f",info.per);
          printf("\n\t\t\t___________________________________________\n");

      }
      fclose(fp);
      getch();

  }
  void searchstudent()
  {
      FILE *fp;
      struct student info;
      int roll_no,found=0;
      fp=fopen("student_info","r");

      printf("\t\t\t==========Search Student==========\n\n\n");
      printf("\t\t\tEnter roll no: ");
      scanf("%d",&roll_no);

      while(fread(&info,sizeof(struct student),1,fp))
      {
          if(info.roll_number==roll_no)
            {
          found=1;
          printf("\n\t\t\tStudent name : %s %s",info.first_name,info.last_name);
          printf("\n\t\t\tRoll No      :%d",info.roll_number);
          printf("\n\t\t\tClass        :%s",info.class);
      }
  }
  if(!found)
  {
      printf("\n\t\t\tRecord Not Found\n");
  }


  fclose(fp);


  getch();
  }


  void delete()
  {
      FILE *fp,*fpl;
      struct student info;
      int roll_no,found=0;

      printf("\t\t\t==========Search Student Record==========\n\n\n");
      fp=fopen("student_info","r");
      fpl=fopen("temp.txt","w");
      printf("\t\t\tEnter roll no : ");
      scanf("%d",&roll_no);

      if(fp==NULL)
      {
          fprintf(stderr,"\t\t\tCan't open files\n");
      }
      while(fread(&info,sizeof(struct student),1,fp))
      {
          if(info.roll_number==roll_no){
            found=1;
          }else{
          fwrite(&info,sizeof(struct student),1,fp);
          }
      }

      fclose(fp);
      fclose(fpl);

      if(found){
        remove("student_info");
        rename("temp.txt","student_info");
        printf("\n\t\t\tRecord Deleted Successfully\n");

      }
      if(!found)
      {
          printf("\n\t\t\tRecord Not Found\n");
      }
      getch();
    }
