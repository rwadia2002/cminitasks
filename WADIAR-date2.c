#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// essentially the purpose of this should be to synethesise input of string and break it up
char string[13];
int wrongdate=1;
int adder(char string[]){
  // the length of said string
  // so take the string in as a date then it is possible to break it up and also put a stop to it to count how long it is
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
  int dayint=0;
    // very useful because soon day needs to be acted on and manipulated like an int
  int monthint=0;
  // month will need to be an into not char

  int monthsverify=0;
  int yearint=0;
  // verifies if the month is a real month
  //year is told in int form

  int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
      // the days for each calendar month of course this gets updated when referring to leap year in next program
  int countdays=0;
  //counts the days from a specified point and totals it , so if it is february 2nd 2002 then it will add 2 plus january days  plus 2002 lots of 365
  char strings={00000};
  char extra[1]= {"!"};
      // I chose to use exclamation as a flag
  strcat(string,extra);
  //printf("%s STRING",string );

  // concatenates the ddmmyy with the flag



  for (count=0;count<11;count++){
    if ((int) string[count]!= 33){
    //printf("%c \n",string[count]);
    convert = (int) (string[count]);
    //printf("%d\n",convert);

    if (((convert)==(47)) || ((convert)==(45))){
      ++hflag;
      ++count;
      //flags up now that hyphen has been reached and retrieved the day
      //printf("%i flag\n",hflag );

      //flags up now that hyphen has been reached and retrieved the day

    }
    // verifying what the instance is , is it a hyphen or a slash because after that a month must be there or a year

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

      if ((flagger == 47) || (flagger)==(45)){
        day[count]=0;
        day[1]=0;
        day[0]=string[0];
        ++hflag;
        ++count;

        //flags up now that hyphen has been reached and retrieved the day
        //printf("%s only one digit here daycount\n",day );
        //printf("%i future flag\n",hflag );
        count++;
        dayint=atoi(day);
      }
}// now an int is needed for that formed that string


    }



    if (hflag == 1){
      //now we must move on to the months becaue a hyphen or slash is reached

    if (monthcount<3){
      month[monthcount]=string[count];
      ++monthcount;
      //printf("\n%s month\n",month);
      monthint= atoi(month);
      //appending month in a similar fashion
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

//div 4 essentially and check
   if ((yearint%4)==0){
     // if yearint is a multiple of 4
       months[1]=29;
       //printf("leapyear");
       divcalc=div(yearint-1,4);
       //printf("%d divcalc\n",divcalc );
//then add all but that year's leap year as it is unsure if feb 29th has been crossed
   }
   if ((yearint%4)!=0){
     //if yearint is not a multiple of 4
       divcalc=div(yearint,4);
       //printf("%i divcalc\n",divcalc);
//or regular add leap year if not a leap year
   }
//add on those leap years
   total+=divcalc.quot;
   //printf("divcalc.quot added %i\n",divcalc.quot);
   for (countdays=0;countdays<monthint-1;countdays++) {

    //monthint -1
    total+=months[countdays];
    //printf("\nmonths countdays %i\n",months[countdays]);}
    //printf("\n%i final total\n",total );
    }

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
        // start adding up since 0AD the months elapsed and days elapsed

      // sound a wrong date alarm if year is not between 0 and 10000
      //sound a wrong date alarm if the month is not 0 to 12
      // sound an alarm if the day is less than 1 or does not pertain to that month so 31st february is an example



      }
        if (dayint>(months[monthint])){
          //printf("the day is which is %i outside the maximum of %i\n",dayint,months[monthint] );
            fprintf(stderr,"ERROR - day is not accepted\n");
            wrongdate++;
      }
      //the main program is simple it calls for input 2 times then calls this above program to keep 2 absolute markings from 0AD and subtract them
      return total;


      }


      main(){
      do{
      wrongdate=0;
      char string1[12];
      scanf("%s",string1);
      char string2[12];
      scanf("%s",string2);
      //printf("\n%i the final figure",adder(string1));
      //printf("\n%i the final figure",adder(string2));
      printf("%i",adder(string2)-adder(string1));
      }
      while (wrongdate>0);
      //if there is a wrong date do it again
      }
