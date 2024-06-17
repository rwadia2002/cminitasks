#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// tested on 7 5 board
int accesscoord[50][2];
int stopper=0;
int listoffinished[50][3];
//full array of all the live coordinates
void rules(int width, int height){
  // sets the variables like i j z for counting
  //temparray to temporarily store the variables until ported to listoffinished
int lifecounter=0;
int i;
int z;
int j;
int point=0;
int livestatus=0;
int counter=0;
int temparray[50][2];
for (i=0;i<width;i++){
  for(j=0;j<height;j++){
    for (z=0;z<stopper;z++){

      if (listoffinished[z][0]==i){
        if (listoffinished[z][1]==j){
// checks if the coordinate referenced is already a live one

          livestatus=1;
        }
      }
//checking the neighbours of all coordinates
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


      if (point==2){
        if (livestatus==1){

          temparray[counter][0]=i;
          temparray[counter][1]=j;

          counter++;

        }


      }

      if (point==3){



          temparray[counter][0]=i;
          temparray[counter][1]=j;

          counter++;





      }

    }


    point=0;
    livestatus=0;


  }


}

for(i=0;i<counter;i++){
for (z=0;z<stopper;z++){
  if (temparray[i][0]==listoffinished[z][0]){
    if (temparray[i][1]==listoffinished[z][1]){
//assigning the coordinate plots with age of how long it has been on board , if previously on the board
      listoffinished[z][2]++;

      listoffinished[i][2]=temparray[i][0];

    }

  }
}


  listoffinished[i][0]=temparray[i][0];
  listoffinished[i][1]=temparray[i][1];

//assigns the listoffinished list so it can be read by other functions, this being the new list of coordinates which are live


}

stopper=counter;
}






void makerect(int width,int height){
  int plughole=0;


// plughole stops the program once the second horizontal border is put in as all the piping and frame work is done after this
int i ;
int j;
int z;
int g;
int matchingcoord=0;


//draws the frame

for (i=1;i<(height+3);i++){


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
    // marks the frame with an x if the coordinate has been there over 10 intervals or over else marks the coordinate with the number of how long it has been there from 0-9

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
// this function traces the array of live cells originally from the file itself

for (i=0;i<1;i++){
  fgets(&numberofcoords,4,filepointer);


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
//gets the x and y coordinates in the array

    }

  }
  counter=0;

  fgets(&blankabsorb,4,filepointer);
  // ignores blank points



}
// stopper stops the loop when the number of terms to plot is reached
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







int main(int argc, char* argv[]){
  int initialarray[50][3];
  int widthparam;
  int heightparam;
//sets the period is 0 along with height and width being initialised.
  int i;
  int j;
  int z;
  int flag=0;
  int period=0;
  for (i=0;i<6;i++){

  }

  // this is 1+ the num of argv given the number of argv is the counter + num of argv
// if there is enough arguments
if (argc==5){
  // so arg counter plus all argv
  // check if third term, so width
  if (atoi(argv[2])<78){

// keeps the loop for building rectangles and running verification going but keeps an image of the original array the first time the program is run and if the live cells resemble the array
//it will stop the program because now a period is reached and this shape will continually repeat itself

    if (atoi(argv[3])<50){
      widthparam = atoi(argv[2]);
      heightparam = atoi(argv[3]);
      FILE* destfilepointer;
      destfilepointer = fopen(argv[1],"r");
      coordfinder(destfilepointer);
      for (z=0;z<50;z++){
      initialarray[z][0]==listoffinished[z][0];
      initialarray[z][1]==listoffinished[z][1];

      }
for (i=0;i<atoi(argv[4]);i++){

//sets a flag up if the array for live cells is the same

      flag=0;
      makerect(widthparam,heightparam);
      rules(widthparam+1,heightparam+1);
      period++;
      for (z=0;z<50;z++){
        if (i>0){
        if (listoffinished[z][0]==initialarray[z][0]){

          if (listoffinished[z][1]==initialarray[z][1]){
            flag++;

          }
        }
      }

      if (flag==stopper){
        printf("Period detected (%i) exiting",period);
        exit(0);
      }


      }

    //exits on period detection
}





    }
  }




}




}
