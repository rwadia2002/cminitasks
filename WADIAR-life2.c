#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//tested on 7 5  board
int accesscoord[50][2];
int stopper=0;
int listoffinished[50][3];
//listoffinished is a list of the coordinates where any x is held
//it is 2d so space for x and  y coordinates
void rules(int width, int height){
int lifecounter=0;
int i;
// ijz common variables for numbering
int z;
int j;
int point=0;
int livestatus=0;
int counter=0;
int temparray[50][2];
//temporary array included so locally values are held and at the end coordinates are transferred to the global array
for (i=0;i<width;i++){
  for(j=0;j<height;j++){
    for (z=0;z<stopper;z++){
//cross reference the array and check if the array has coordinates spanning the whole coordinate range in it
      if (listoffinished[z][0]==i){
        if (listoffinished[z][1]==j){

// the coordinate is a live coordinate
          livestatus=1;
        }
      }

      if (listoffinished[z][0]==i+1){
        if (listoffinished[z][1]==j){
//will allocate a point each time the neighbour is present

          point++;
        }
      }
      if (listoffinished[z][0]==i-1){
        if (listoffinished[z][1]==j){


          point++;
        }
      }
      if (listoffinished[z][0]==i){
        if (listoffinished[z][1]==j+1){


          point++;
        }
      }
      if (listoffinished[z][0]==i){
        if (listoffinished[z][1]==j-1){


          point++;
        }
      }

      if (listoffinished[z][0]==i+1){
        if (listoffinished[z][1]==j+1){


          point++;
        }
      }

      if (listoffinished[z][0]==i-1){
        if (listoffinished[z][1]==j-1){


          point++;
        }
      }

      if (listoffinished[z][0]==i+1){
        if (listoffinished[z][1]==j-1){


          point++;
        }
      }

      if (listoffinished[z][0]==i-1){
        if (listoffinished[z][1]==j+1){


          point++;
        }
      }

    }


    if(point>1){


      if (point==2){
        if (livestatus==1){

          temparray[counter][0]=i;
          temparray[counter][1]=j;

          counter++;

        }


      }

      if (point==3){

// in any circumstance if there are three neighbours then the  cell can be switched on to a live cell

          temparray[counter][0]=i;
          temparray[counter][1]=j;

          counter++;





      }

    }

//reset point and live status at the end of the loop
    point=0;
    livestatus=0;


  }


}

for(i=0;i<counter;i++){
for (z=0;z<stopper;z++){
  if (temparray[i][0]==listoffinished[z][0]){
    if (temparray[i][1]==listoffinished[z][1]){

      listoffinished[z][2]++;

      listoffinished[i][2]=temparray[i][0];
//added array number that increments each time it is used over so if it is the same live cell it will increment again
    }

  }
}


  listoffinished[i][0]=temparray[i][0];
  listoffinished[i][1]=temparray[i][1];




}

stopper=counter;
}


// the count of live cells is the new stopper



void makerect(int width,int height){
  int plughole=0;

// makes rectangles

int i ;
int j;
int z;
int g;
int matchingcoord=0;




for (i=1;i<(height+3);i++){
// stops the program from writing after the final border is drawn

  if ((((i-1)==0)||((i-1)==height+1))){
    for(j=0;j<width+2;j++){
      if (((j==0)||(j==(width+1)))){
        printf("*");
        plughole++;


      }


      if (((j!=0)&&(j!=(width+1)))){
        printf("_");

      }

    }
    printf("\n\n");

  }

  if ((((i-1)!=0)&&((i-1)!=height+3))){
    if (plughole<4){
    // if x is anywhere it will be in this category

    for(j=0;j<width+2;j++){
      if (j==0){
        printf("|");
        //x cannot be here

      }
      if (j==width+1){

        printf("|");
        printf("\n\n");
      }

      // draws the top and bottom border and side piping

  if (((j!=0)&&(j!=width+1))){
// if age is more than 10 then put an x but if it is less than 10 show a number integer where it is alive from 0 - 9
      for(z=0;z<stopper;z++){
        if (i-1==listoffinished[z][0]){
          if (j-1==listoffinished[z][1]){
            matchingcoord=1;
            if (listoffinished[z][2]<10){
            printf("%i",listoffinished[z][2]);
          }
          if (listoffinished[z][2]>10){
          printf("X");
        }

          }
        }

      }
      if (matchingcoord==0){
      printf(" ");
    }

    }

matchingcoord=0;

}


}
}
}
}




void coordfinder(FILE* filepointer){
char numberofcoords[4];
char blankabsorb[4];
int i=0;
int counter=0;
// translating text file coordinates into an array
// the first thing done is that blank absorb is used to absorb blank inputs

for (i=0;i<1;i++){
  fgets(&numberofcoords,4,filepointer);
// gets the number of coordinates to take in

}
int coordarray[atoi(&numberofcoords)][2];
int j=0;
char coordinates[atoi(&numberofcoords)][5];

for (i=0;i<atoi(&numberofcoords);i++){
  fgets(&coordinates[i],4,filepointer);

  for (j=0;j<3;j++){

    if ((coordinates[i][j])!=(32)){
      coordarray[i][counter]=atoi(&coordinates[i][j]);

      accesscoord[i][counter]=coordarray[i][counter];

      counter++;


    }

  }
  counter=0;

  fgets(&blankabsorb,4,filepointer);
  //printf("%s eol\n",coordinates[i] );



}
// going to have to manually parse
// gets the number of coordinates to input
stopper= atoi(&numberofcoords);
int z=0;
for (i=0;i<stopper;i++){
  for(j=0;j<2;j++){

    listoffinished[i][j]=accesscoord[i][j];
    listoffinished[i][2]=0;
    z++;

  }
}


}






// main takes two arguments these arguments are the number of command line arguments and also the array of said arguments
int main(int argc, char* argv[]){
  int widthparam;
  int heightparam;
  // name wise operations go here

  int i;
  int j;
  for (i=0;i<6;i++){

  }

  // this is 1+ the num of argv given the number of argv is the counter + num of argv
// the firesty
if (argc==5){
  // so arg counter plus all argv
  // check if third term, so width
  if (atoi(argv[2])<78){

//height and width parameters subbed in and redoes the rules and board creation as per the set amount of intervals

    if (atoi(argv[3])<50){
      widthparam = atoi(argv[2]);
      heightparam = atoi(argv[3]);
      FILE* destfilepointer;
      destfilepointer = fopen(argv[1],"r");
      coordfinder(destfilepointer);
for (i=0;i<atoi(argv[4]);i++){

      makerect(widthparam,heightparam);
      rules(widthparam+1,heightparam+1);


}





    }
  }




}



printf("\n Finished\n ");
exit(0);
}
