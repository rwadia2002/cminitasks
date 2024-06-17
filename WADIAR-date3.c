#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// essentially the purpose of this should be to synethesise input of string and break it up
char string[13];
// so take the string in as a date then it is possible to break it up and also put a stop to it to count how long it is

int dayint=0;
int monthint=0;
int yearint=0;
int wrongdate=1;
// make these global so read outside the function
int comparator(const void* cmp1,const void* cmp2){
  return(*(int*)cmp1- *(int*)cmp2);
  // inbuilt quicksort function needs a comparator to work so it take dereferced pointers for each location comparing them if
  //one is bigger than the other then the subtraction will result in positive but the reverse will be negative and same will result in zero
}
int adder(){
  wrongdate=0;
  //needs to be reset here
  // the length of said string
  int count=0;
      // just a normal counter to initialise
  int hflag=0;
  // hyphen or slash flag
  int convert=0;
  // what this does is effectively converts each character into an ansii number to pick up hyphen and slash
  char day[1]={0};
  // divide and conquer each part into a mini array like day month and year

  int daycounter=0;
  char month[1]={0};
  int monthcount=0;
    // seperate counter for months because the program dips into months so if it is march it will add the days from jan to feb
  int flagger=0;
  // flagger is here for whatever the next item in the date sequence is mainly because when single digits are given that needs a seperate case of action
  int yearcount=0;
  // dynamically keeps track of length of years so it is clear how many characters long the given year is

  char year[5]={00000};
  // initialising year in
  int monthsverify=0;
  // verifies if the month is a real month
  int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};


  int countdays=0;
  //counts the days from a specified point and totals it , so if it is february 2nd 2002 then it will add 2 plus january days  plus 2002 lots of 365
  char strings={00000};
  char extra[1]= {"!"};
  scanf("%s",string);
  strcat(string,extra);
  //printf("%s STRING",string );



  for (count=0;count<11;count++){
    if ((int) string[count]!= 33){
    //printf("%c \n",string[count]);
    convert = (int) (string[count]);
    //printf("%d\n",convert);

    if (((convert)==(47)) || ((convert)==(45))){
      ++hflag;
      ++count;
      //flags up now that hyphen has been reached and retrieved the day

    // verifying what the instance is , is it a hyphen or a slash because after that a month must be there or a year



    }
    // flagger
    flagger = (int) (string [1]);
// sometimes it is a one digit day and the code will otherwise take slash as a character

    if (hflag == 0){
              // while we remain on the days section
      if (((convert)!=(47)) || ((convert)!=(45))){
      day[count]=0;
      day[count]=string[count];
      //printf("%s daycount\n",day);
      dayint=atoi(day);
      //printf("%i dayint",dayint);
//if a hyphen or slash is spotted ahead
      if ((flagger == 47) || (flagger)==(45)){
        day[count]=0;
        day[1]=0;
        day[0]=string[0];
        ++hflag;
        ++count;

        //flags up now that hyphen has been reached and retrieved the day

      // verifying what the instance is , is it a hyphen or a slash because after that a month must be there or a year

        //printf("%i future flag\n",hflag );
        count++;
        dayint=atoi(day);
      }
}

    }
// now an int is needed for that formed that string


    if (hflag == 1){

    if (monthcount<3){
      month[monthcount]=string[count];
      ++monthcount;
      //printf("\n%s month\n",month);
      monthint= atoi(month);
    }

    }


    if (hflag==2){
      if (yearcount<6){
      year[yearcount]=string[count];
      ++yearcount;
      //printf("%s year \n",year );
      yearint=atoi(year);
    }

    }
  }

  }

  //printf("%c",string[0]:string[1]+1);

  //printf("%s %s %s this is it",day,month,year);
  //printf("%i %i %i",dayint,monthint,yearint);

   int total=0;
   total+=dayint;
   //printf("DAYINT added %i",total);
   total+=yearint*365;
   int moduloleapyear;
   div_t divcalc;
   divcalc=div(yearint,4);


   if ((yearint%4)==0){
     // if yearint is a multiple of 4
       months[1]=29;
       //printf("leapyear");
       divcalc=div(yearint-1,4);
       //printf("%d divcalc\n",divcalc );

   }
   if ((yearint%4)!=0){
     //if yearint is not a multiple of 4
       divcalc=div(yearint,4);
       //printf("%i divcalc\n",divcalc);

   }

   total+=divcalc.quot;
   //printf("divcalc.quot added %i\n",divcalc.quot);
   for (countdays=0;countdays<monthint-1;countdays++) {

    //monthint -1
    total+=months[countdays];
    //printf("\nmonths countdays %i\n",months[countdays]);
  }
    //printf("\n%i final total\n",total );
    // here use div fuimctopm and essentially check if it is a multiple of 4
    //then if it is add the leap year after the fact, since february 29th only add it in if after february 29th



        if (yearint<1){
          wrongdate++;
          fprintf(stderr,"ERROR - year is not accepted--too small\n");

        }
        if (yearint>10000){
          wrongdate++;
          fprintf(stderr,"ERROR - year is not accepted-- too big\n");

        }
        for (count=0;count<13;count++){
          if (monthint==count){
            //printf("month verified\n" );
            monthsverify=1;
          }

        }
        if (monthsverify!=1){
          fprintf(stderr,"ERROR - month is not accepted\n");
            wrongdate++;
        }
        if (dayint<1){

          fprintf(stderr,"ERROR - day is not accepted- too small\n");
          wrongdate++;
        }
          if (dayint>(months[monthint])){
            //printf("the day is which is %i outside the maximum of %i\n",dayint,months[monthint] );
              fprintf(stderr,"ERROR - day is not accepted\n");
            wrongdate++;

}
// sound a wrong date alarm if year is not between 0 and 10000
//sound a wrong date alarm if the month is not 0 to 12
// sound an alarm if the day is less than 1 or does not pertain to that month so 31st february is an example


  return total;


  }



 main(){
   wrongdate=0;
   int counter=0;
   // initialise some counters
   int counter2=0;
   //sometimes you need two because of nested for loops
   int step=0;
   // amount of steps or repetitions needed to fill the dates in
   scanf("%i",&step);
   int newlist;
   int totaller[20][4]={};
   // engaging 2d arrays to deal with the totals , essentially have the total from absolute time and store dayint monthint and yearint at that time
   int totallerlist[30]={};
   //1d list of totals
   int count=0;
   // initialise a third count
   int saveddates[30][4]={};
   // another array to keep the dates and respective details
   int finalform[30]={};
   // the last array for the dates
   int winningnumbers[30]={};
     int count4=0;
     // the last numbers go here
   for (counter=0;counter<step;counter++){
     totaller[counter][0]=adder();
     //printf("here it is %i\n",totaller[counter][0]);

// take the total number of days since 0AD
     totallerlist[counter]=totaller[counter][0];
     //printf("%i totaller \n",totaller[1]);
     //printf("%i dayint\n",dayint );
     //printf("%i monthint\n",monthint );
     //printf("%i yearint",yearint);

     // fill the array in such that the absolute dates elapsed since 0ad along with day month and year are all stored
     saveddates[counter][0]=totallerlist[counter];
     saveddates[counter][1]=dayint;
     saveddates[counter][2]=monthint;
     saveddates[counter][3]=yearint;
     finalform[counter]=totaller[counter];


     dayint=0;
     monthint=0;
     yearint=0;

   }
//reset day month and year they are needed again

   //we have the dates
   // use inbuilt quicksort function to track the dates in order
   qsort(finalform,step,sizeof(int),comparator);
   //printf("size of final form %i\n",(sizeof(finalform)/sizeof(finalform[0])));
   for (counter=0;counter<50;counter++){
     //printf("%i finalform\n",finalform[counter]);
     }
   for (counter=0;counter<step;counter++){
     //printf("%i sorted\n",finalform[counter] );
     for (counter2=0;counter2<step;counter2++){
     if (finalform[counter]=saveddates[counter2][0]){
       //printf("he's here! %i\n",saveddates[counter2][1]);
       // linking up the absolute days once in order with their respective day month and year
     }
   }

//attempts were made to filter out the non-accepted result but it deleted the rest of the data so I left it out

   }
   //printf("%i\n",totaller[30] );
   //counter=0;
   //step=0;
   //for counter=
   for (counter=0;counter<step;counter++){
     //printf("totaller %i\n",totallerlist[counter]);
     winningnumbers[count4]=totallerlist[counter];
     count4++;
     //printf("%i-- %i-- %i\n",saveddates[counter][1],saveddates[counter][2],saveddates[counter][3] );






}
qsort(winningnumbers,step,sizeof(int),comparator);
for (counter=0;counter<step;counter++){
  //printf("%i\n",winningnumbers[counter] );
  int transportvar=0;
  transportvar = winningnumbers[counter];
  for (counter2=0;counter2<step;counter2++){
    if (transportvar==(saveddates[counter2][0])){
      printf("%i / %i / %i \n",saveddates[counter2][1],saveddates[counter2][2],saveddates[counter2][3] );

//for every successfully matched up line wiht day month year then also absolute day match up and print together ,so they are anchored together in a sorted order

    }



    }

  }

step=0;

}
