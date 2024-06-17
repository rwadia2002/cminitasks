#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// tested on 7 5  board
int accesscoord[50][2];
int stopper=0;
int listoffinished[50][2];
//listoffinished is a list of the coordinates where any x is held
//it is 2d so space for x and  y coordinates
void rules(int width, int height){
// function to implement rules
int lifecounter=0;
int i;
// ijz common variables for numbering
int z;
int j;
int point=0;
int livestatus=0;
// if the coordinate read off of is live
int counter=0;
int temparray[50][2];
// point is there if the to allocate score based on alive neighbours
for (i=0;i<width;i++){
  for(j=0;j<height;j++){
    for (z=0;z<stopper;z++){
// compare coordinate board with array of marked coordinates
      if (listoffinished[z][0]==i){
        if (listoffinished[z][1]==j){

// coordinates of live point itself
          livestatus=1;
        }
      }
//now will compare if the coordinates directly above, below , to the left, to the right , diagonal neighbours and if any are alive give a point
      if (listoffinished[z][0]==i+1){
        if (listoffinished[z][1]==j){


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
// if the points are over 1 so more than 1 neighbour, if point is 2 then only allow if the coordinate itself is alive

      if (point==2){
        if (livestatus==1){

          temparray[counter][0]=i;
          temparray[counter][1]=j;

          counter++;

        }


      }

      if (point==3){

// if the point is 3 allow regardless of life of coordinate and deny any more or less than 2 or 3

          temparray[counter][0]=i;
          temparray[counter][1]=j;

          counter++;





      }

    }


    point=0;
    livestatus=0;


  }
// temparray is set up so that the array can be reset globally so in future the program uses this new array

}

for(i=0;i<counter;i++){
  listoffinished[i][0]=temparray[i][0];
  listoffinished[i][1]=temparray[i][1];
//sets the array accordingly


}

stopper=counter;
}






void makerect(int width,int height){
  int plughole=0;
//make rectangle
//plughole to stop the program after the border is drawn


int i ;
int j;
int z;
int g;
int matchingcoord=0;




for (i=1;i<(height+3);i++){
//draw the top and bottom

  if ((((i-1)==0)||((i-1)==height+1))){
    for(j=0;j<width+2;j++){
      if (((j==0)||(j==(width+1)))){
        printf("*");
        plughole++;
      //  printf("%i",plughole);

      }
      //x cannot be h

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

  if (((j!=0)&&(j!=width+1))){
// print only if it is not a border and also the coordinate is in the array of coordinates
      for(z=0;z<stopper;z++){
        if (i-1==listoffinished[z][0]){
          if (j-1==listoffinished[z][1]){
            matchingcoord=1;
            printf("X");
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

//finds the coordinates in the array
for (i=0;i<1;i++){
  fgets(&numberofcoords,4,filepointer);


}
//blank absorb ignores blanks
int coordarray[atoi(&numberofcoords)][2];
int j=0;
char coordinates[atoi(&numberofcoords)][5];
//enough space for coordinate input
//if coordinate is not a space then input

for (i=0;i<atoi(&numberofcoords);i++){
  fgets(&coordinates[i],4,filepointer);

  for (j=0;j<3;j++){

    if ((coordinates[i][j])!=(32)){
      coordarray[i][counter]=atoi(&coordinates[i][j]);

      accesscoord[i][counter]=coordarray[i][counter];

      counter++;
// increment the counter to go to next point

    }

  }
  counter=0;
  // counter reset

  fgets(&blankabsorb,4,filepointer);




}
//stopper limits coordinate number
stopper= atoi(&numberofcoords);
int z=0;
for (i=0;i<stopper;i++){
  for(j=0;j<2;j++){

    listoffinished[i][j]=accesscoord[i][j];
    z++;
//list of finished writes these to the global array
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

// runs the functions use height and width parameters

    if (atoi(argv[3])<50){
      widthparam = atoi(argv[2]);
      heightparam = atoi(argv[3]);
      FILE* destfilepointer;
      destfilepointer = fopen(argv[1],"r");
      coordfinder(destfilepointer);
for (i=0;i<atoi(argv[4]);i++){

      makerect(widthparam,heightparam);
      rules(widthparam+1,heightparam+1);

      // we know the amount of sets of coordinates
}
printf("\n Finished\n ");
exit(0);





    }
  }




}




}
