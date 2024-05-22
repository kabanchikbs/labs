#include <stdio.h> 
#include "labs.h" 
 
int main(){ 
    int numberOfLaba; 
    scanf("%d", &numberOfLaba); 
    switch(numberOfLaba){ 
    case 1: return labaone(); 
    case 2: return labatwo(); 
    case 3: return labathree(); 
    case 4: return labafour(); 
    case 5: return labafive(); 
    case 6: return labasix(); 
    case 7: return labaseven();
    case 11: return onedop();
    case 22: return twodop();
    case 33: return threedop();
    case 44: return fourdop();
    case 55: return fivedop();
    case 66: return sixdop();
    } 
    return 0; 
}
