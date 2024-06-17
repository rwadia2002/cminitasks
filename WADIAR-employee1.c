#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


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



// the comparator is used so that where strcmp and qsort is needed it can make comparisons if strings are the same so it passes detailed pointers in parameters
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
  // employee names at max length
  char employeename[MAX_NAME_LENGTH];
  char employeesex;
  char employeeage[10];
  char employeejob[MAX_JOB_LENGTH];
// initialise all key elements
//prompts to std error using i as a counting int
  int i;
  fprintf ( stderr, "PLEASE ENTER NAME ");
  read_line(stdin,employeename,MAX_NAME_LENGTH);
  do{
    fprintf ( stderr, "PLEASE ENTER SEX  ");
    read_line(stdin,&employeesex,2);
    // keep asking for the gender until it fits 77 and 70 means ansi for m and f
}while(

    (employeesex!=(77))&&(employeesex!=(70)));
  do{
    fprintf ( stderr, "PLEASE ENTER AGE  ");
    read_line(stdin,employeeage,3);}while(atoi(employeeage)<0);
    //keep checking on age while it is above 0
  fprintf ( stderr, "PLEASE ENTER JOB ");
  //prints prompts to stderror
  read_line(stdin,employeejob,MAX_JOB_LENGTH);

  for (i=0;i<strlen(employeejob);i++){
    emparr[count].job[i]=(employeejob)[i];
//add each job character
  }
for (i=0;i<strlen(employeename);i++){
//add each employeename up to the employeenamesizeth employee name character

emparr[count].name[i]=(employeename)[i];


}




  emparr[count].sex=employeesex;
  emparr[count].age=atoi(employeeage);
//gender is a character but type specified age is a string so should be int


  for (i=0;i<MAX_NAME_LENGTH;i++){

  }

count++;
//count increases every time a number is added
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
// for all of the emparr names so all the different people logged
   for (i=0;i<count;i++){
     namearray[i]=emparr[i].name;
     // quicksort an array of all the names that is put together then print it to screen
     // so now going in order of names which name
   }
qsort(namearray,count,sizeof(char*),comparator);
for (i=0;i<count;i++){
  for (y=1;y<count;y++){
    if (namearray[i]==emparr[y].name){

// pull out the name whereby the sorted name order is there, go back into the array and pick its sex age and job out

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

    if(strcmp(&employeename[i],&emparr[y].name[i])==1){

      if (*(emparr[y].name)==*(employeename)){

        for (i=y;i<100;i++){
          emparr[y]=emparr[y+1];
          flag=1;



        }
      }
    }

    }

  }
  if (flag==0){
    fprintf(stderr, "ERROR Noone of that name is here");

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
