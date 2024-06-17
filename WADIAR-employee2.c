#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


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




 int comparator(const void* cmp1,const void* cmp2){
   const char **cmp1string = (const char **)cmp1;
   const char **cmp2string = (const char **)cmp2;
   return(strcmp(*cmp1string,*cmp2string));
 }
static int read_line ( FILE *fp, char *line, int max_length )
{
   int i;
   char ch;

   /* initialize index to string character */
   i = 0;

   /* read to end of line, filling in characters in string up to its
      maximum length, and ignoring the rest, if any */
   for(;;)
   {
      /* read next character */
      ch = fgetc(fp);

      /* check for end of file error */
      if ( ch == EOF )
	 return -1;

      /* check for end of line */
      if ( ch == '\n' )
      {
	 /* terminate string and return */
	 line[i] = '\0';
	 return 0;
      }

      /* fill character in string if it is not already full*/
      if ( i < max_length )
	 line[i++] = ch;
   }

   /* the program should never reach here */
   return -1;
}

/* read_string():
 *
 * Reads a line from the input file pointer "fp", starting with the "prefix"
 * string, and filling the string "string" with the remainder of the contents
 * of the line. If the start of the line does not match the "prefix" string,
 * the error condition (-1) is returned. Having read the prefix string,
 * read_string() calls read_line() to read the remainder of the line into
 * "string", up to a maximum length "max_length", and returns the result.
 */
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

/* menu_add_employee():
 *
 * Add new employee to database
 */
static void menu_add_employee(void)
{
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

    (employeesex!=(77))&&(employeesex!=(70)));
  do{
    fprintf ( stderr, "PLEASE ENTER AGE  ");
    read_line(stdin,employeeage,3);}while(atoi(employeeage)<0);
  fprintf ( stderr, "PLEASE ENTER JOB ");
  read_line(stdin,employeejob,MAX_JOB_LENGTH);

  for (i=0;i<strlen(employeejob);i++){
    emparr[count].job[i]=(employeejob)[i];

  }
for (i=0;i<strlen(employeename);i++){


emparr[count].name[i]=(employeename)[i];


}




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



      printf("Name: %s\n",emparr[y].name );
      printf("Sex: %c\n",emparr[y].sex );
      printf("Age: %i\n",emparr[y].age );
      printf("Job: %s\n",emparr[y].job );





    }
  }
}


      // printf("Name: %s\n",emparr[i].name );
      // printf("Sex: %c\n",emparr[i].sex );
       //printf("Age: %i\n",emparr[i].age );
      // printf("Job: %s\n",emparr[i].job );









    /* fill in the code here in part 1, and add any extra functions you need */

}
//This code essentially runs in the program to get rid of a particular names

static void menu_delete_employee(void)
{
  char employeename[MAX_NAME_LENGTH];
  // takes the employeename set up as a variable , the employee to delete
  fprintf(stderr, "ENTER FULL NAME OF EMPLOYEE");
  read_line(stdin,employeename,MAX_NAME_LENGTH);
  //takes this deletable from stdin as now it is known what there is to delete
  //
  int i ;
  int y;

  int flag=0;
  for (y=0;y<count;y++){
    for (i=0;i<MAX_NAME_LENGTH;i++){

    if(strcmp(&employeename[i],&emparr[y].name[i])==1){

      if (*(emparr[y].name)==*(employeename)){
        //check if the full string is the same
        for (i=y;i<100;i++){
          emparr[y]=emparr[y+1];
          flag=1;
//flag is there to signal the end whereby it means the data has been located
// the point of this is that any content that is one ahead or more in front of the detected term move it onto the previous slot before it hence covering up the delete term
//shuffle the data before it too else anything before gives lots of zeroes

        }




      }
    }

    }

  }
  if (flag==0){
    fprintf(stderr, "ERROR Noone of that name is here");
    // if the whole course of the program is achieved and no employee found then say no one of that name is here

}
  }



/* read file containing database of employees */
static void read_employee_database ( char *file_name )
{
   /* fill in the code here in part 3, and add any extra functions you need */
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
