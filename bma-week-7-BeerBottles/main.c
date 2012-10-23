//
//  main.c
//  bma-week-7-BeerBottles
//
//  Created by Wally on 10/22/12.
//  Copyright (c) 2012 W M. All rights reserved.
//

#include <stdio.h>

void adjustVariables(int count, char **bttlTxt
                     , char **bttlTxtLess, char **drnkTxt)
{
    count--;
    int countLess = count -1;
    
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
    singTheSong(99);

    // insert code here...
    // printf("Hello, World!\n");
    return 0;
}

