#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


/* maximum number of employees that can be stored at once (relevant only
   to storage using an array) */
#define MAX_EMPLOYEES 200
#define MAX_NAME_LENGTH 100
#define MAX_JOB_LENGTH  100

/* Employee structure
 */
struct Employee
{
   /* Employee details */
   char name[MAX_NAME_LENGTH+1]; /* name string */
   char sex;                     /* sex identifier, either 'M' or 'F' */
   int  age;                     /* age */
   char job[MAX_JOB_LENGTH+1];   /* job string */

   /* pointers to previous and next employee structures in the linked list
      (for if you use a linked list instead of an array) */
   struct Employee *prev, *next;
};
struct Employee emparr[MAX_EMPLOYEES];
int count=1;
// need to make an array of the structs to store data


 int comparator(const void* cmp1,const void* cmp2){
   const char **cmp1string = (const char **)cmp1;
   const char **cmp2string = (const char **)cmp2;
   return(strcmp(*cmp1string,*cmp2string));
 }
static int read_line ( FILE *fp, char *line, int max_length )
{
   int i;
   char ch;


   i = 0;


   {

      ch = fgetc(fp);


      if ( ch == EOF )
	 return -1;


      if ( ch == '\n' )
      {

	 line[i] = '\0';
	 return 0;
      }


      if ( i < max_length )
	 line[i++] = ch;
   }


   return -1;
}







static int read_string ( FILE *fp,
			 char *prefix, char *string, int max_length )
{
   int i;

   /* read prefix string */
   for ( i = 0; i < strlen(prefix); i++ )
      if ( fgetc(fp) != prefix[i] )
	 /* file input doesn't match prefix */
	 return -1;

   /* read remaining part of line of input into string */
   return ( read_line ( fp, string, max_length ) );
}


static void menu_add_employee(void)
{

//employee variables to store employee data
//reads piped in data and adds it to the specified variable
  char employeename[MAX_NAME_LENGTH];
  char employeesex;
  char employeeage[10];
  char employeejob[MAX_JOB_LENGTH];
  int i;
  fprintf ( stderr, "PLEASE ENTER NAME ");
  read_line(stdin,employeename,MAX_NAME_LENGTH);
  do{
    fprintf ( stderr, "PLEASE ENTER SEX  ");
    read_line(stdin,&employeesex,2);
}while(
//check if m or f else keep asking
    (employeesex!=(77))&&(employeesex!=(70)));
  do{
    fprintf ( stderr, "PLEASE ENTER AGE  ");
    read_line(stdin,employeeage,3);}while(atoi(employeeage)<0);
  fprintf ( stderr, "PLEASE ENTER JOB ");
  read_line(stdin,employeejob,MAX_JOB_LENGTH);

  for (i=0;i<strlen(employeejob);i++){
    emparr[count].job[i]=(employeejob)[i];
// adds all to array components
  }
for (i=0;i<strlen(employeename);i++){


emparr[count].name[i]=(employeename)[i];

// checks count of name, each name is indexed in struct style
}

//adds to array using varibkles doing checks once in valid range only then will they be subbed in


  emparr[count].sex=employeesex;
  emparr[count].age=atoi(employeeage);



  for (i=0;i<MAX_NAME_LENGTH;i++){

  }

count++;

   /* fill in the code here in part 1, and add any extra functions you need */
}

/* menu_print_database():
 *
 * Print database of employees to standard output.
 */
 static void menu_print_database(void)
 {
   int i ;
   int y;
   int firstname;
   int z;
   int samenamecount=0;
   char samenames[samenamecount][MAX_NAME_LENGTH];
   char *namearray[]={};

   for (i=0;i<count;i++){
     namearray[i]=emparr[i].name;

   }
qsort(namearray,count,sizeof(char*),comparator);
for (i=0;i<count;i++){
  for (y=1;y<count;y++){
    if (namearray[i]==emparr[y].name){

//qsort the array using the comparator
//some isolated variables for numbering

      printf("Name: %s\n",emparr[y].name );
      printf("Sex: %c\n",emparr[y].sex );
      printf("Age: %i\n",emparr[y].age );
      printf("Job: %s\n",emparr[y].job );

// prints name sex and age



    }
  }
}


      // printf("Name: %s\n",emparr[i].name );
      // printf("Sex: %c\n",emparr[i].sex );
       //printf("Age: %i\n",emparr[i].age );
      // printf("Job: %s\n",emparr[i].job );









    /* fill in the code here in part 1, and add any extra functions you need */

}
/* menu_delete_employee():
 *
 * Delete new employee from database.
 */
static void menu_delete_employee(void)
{
  char employeename[MAX_NAME_LENGTH];
  fprintf(stderr, "ENTER FULL NAME OF EMPLOYEE");
  read_line(stdin,employeename,MAX_NAME_LENGTH);
  int i ;
  int y;

  int flag=0;
  for (y=0;y<count;y++){
    for (i=0;i<MAX_NAME_LENGTH;i++){
      //first extends to max name length if the deletable name is a 1:1 copy it will delete the user details

    if(strcmp(&employeename[i],&emparr[y].name[i])==1){
      if (*(emparr[y].name)==*(employeename)){
        for (i=y;i<100;i++){
          emparr[y]=emparr[y+1];
          flag=1;



        }
        for (i=1;i<y;i++){
          emparr[y]=emparr[y-1];
          flag=1;

        }



      }
    }

    }

  }//flag signals this is invalid and a wrong entry
  if (flag==0){
    fprintf(stderr, "ERROR Noone of that name is here");

}
  }



/* read file containing database of employees */
static void read_employee_database ( char *file_name )
{ FILE * filepointer;
  int linecount=0;
  int counter=0;
  count=0;
  filepointer = fopen (file_name,"r");
  char charspotter;
  charspotter=fgetc(filepointer);
  char restofname[50]={"Name: "};
  char restofsex[60]={"Sex: "};
  char restofage[60]={"Age: "};
  char restofjob[60]={"Job: "};
  char employeename[MAX_NAME_LENGTH];
  char employeesex;
  char employeeage[3];
  char employeejob[MAX_JOB_LENGTH];
  do{
    if isspace(charspotter){

      linecount++;
    }
//using the space detector function check for spaces

  }while(charspotter!=EOF);
  int i;
  for(counter=0;(counter<(linecount/4));counter++) {
//just sets the char array for each one , using read to strings
//atoi where necessary

//reads string in line then loops it over

   read_string(filepointer,restofname,employeename,MAX_NAME_LENGTH);
   read_string(filepointer,restofsex,&employeesex,3);
   read_string(filepointer,restofage,employeeage,10);
   read_string(filepointer,restofjob,employeejob,MAX_JOB_LENGTH);

     for (i=0;i<strlen(employeejob);i++){
       emparr[count].job[i]=(employeejob)[i];
   // adds all to array components
     }
   for (i=0;i<strlen(employeename);i++){

   //counts in characters one by one
   emparr[count].name[i]=(employeename)[i];

 }

    emparr[count].sex=employeesex;
    emparr[count].age=atoi(employeeage);
    count++;
    // this is the universal count that looks at what index of the contacts is , so all contacts written to the same index and then the index gets incremented

}



// i chose 15 as a test number but in other cases it can dynamically adjust to whatever size is necessa
fclose(filepointer);
}

/* codes for menu */
#define ADD_CODE    0
#define DELETE_CODE 1
#define PRINT_CODE  2
#define EXIT_CODE   3

int main ( int argc, char *argv[] )
{
   /* check arguments */
   if ( argc != 1 && argc != 2 )
   {
      fprintf ( stderr, "Usage: %s [<database-file>]\n", argv[0] );
      exit(-1);
   }

   /* read database file if provided, or start with empty database */
   if ( argc == 2 )
      read_employee_database ( argv[1] );

   for(;;)
   {
      int choice, result;
      char line[301];

      /* print menu to standard error */
      fprintf ( stderr, "\nOptions:\n" );
      fprintf ( stderr, "%d: Add new employee to database\n", ADD_CODE );
      fprintf ( stderr, "%d: Delete employee from database\n", DELETE_CODE );
      fprintf ( stderr, "%d: Print database to screen\n", PRINT_CODE );
      fprintf ( stderr, "%d: Exit database program\n", EXIT_CODE );
      fprintf ( stderr, "\nEnter option: " );

      if ( read_line ( stdin, line, 300 ) != 0 ) continue;

      result = sscanf ( line, "%d", &choice );
      if ( result != 1 )
      {
	 fprintf ( stderr, "corrupted menu choice\n" );
	 continue;
      }

      switch ( choice )
      {
         case ADD_CODE: /* add employee to database */
	 menu_add_employee();
	 break;

         case DELETE_CODE: /* delete employee from database */
	 menu_delete_employee();
	 break;

         case PRINT_CODE: /* print database contents to screen
			     (standard output) */
	 menu_print_database();
	 break;

	 /* exit */
         case EXIT_CODE:
	 break;

         default:
	 fprintf ( stderr, "illegal choice %d\n", choice );
	 break;
      }

      /* check for exit menu choice */
      if ( choice == EXIT_CODE )
	 break;
   }

   return 0;
}
