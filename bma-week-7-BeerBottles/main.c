//
//  main.c
//  bma-week-7-BeerBottles
//
//  Created by W. Mooncai on 10/22/12.
//  Copyright (c) 2012 W M. All rights reserved.
//
//  Crossfire Building Mobile Apps Homework Week 8
//

#include <stdio.h>
#include <stdlib.h>

#include "bma-week-8-BeerBottles.h"

void adjustVariables(int count, char **bttlTxt
                     , char **bttlTxtLess, char **drnkTxt)
{
    // These operations were functioned to satisfy HW requirements.
    
    count--;
    int countLess = count - 1;
    
    *bttlTxt = (count == 0) ? "bottle" : "bottles";
    
    *bttlTxtLess = (countLess == 1) ? "more bottles" : "bottles" ;
    
    *drnkTxt = ( (count % 5) == 0 ) ? "Take one"
             : ( (count % 2) == 0 ) ? "Chug some" : "Funnel some" ;
}

void singTheSong(int numberOfBottles)
{    
    char* bottleText = "";
    char* lessBottleText = "";
    char* drinkText = "";
    
    adjustVariables(numberOfBottles, &bottleText, &lessBottleText, &drinkText);

    int oneLessBottle = numberOfBottles - 1;
    
    if (numberOfBottles > 0) {

        printf("%d %s of beer on the wall, %d %s of beer.\n"
               , numberOfBottles, bottleText, numberOfBottles, bottleText);
        
        if (oneLessBottle > 0) {
            printf("%s down, pass it around, %d %s of beer on the wall.\n\n"
                   , drinkText
                   , oneLessBottle
                   , lessBottleText);
            
        singTheSong(oneLessBottle);
            
        } else {
            
            printf("%s down, pass it around, no more bottles of beer on the wall.\n"
                   , drinkText);
        }
    };
}

int main(int argc, const char * argv[])
{
    int bottlesOfBeerOnTheWall = 99;
    
    if (argc == 2) bottlesOfBeerOnTheWall = atoi(argv[1]);
    
    printf("%d bottles of beer on the wall!\n\n", bottlesOfBeerOnTheWall);
    
    singTheSong(bottlesOfBeerOnTheWall);
    
    printf("\nmmmm... That was goooood, <buuuuuuuuurp>!");

    return 0;
}

