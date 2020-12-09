#ifndef KB_H
#define KB_H
#include "monitor.h"


//array 1000 elements

char readStr()
{
    char buff;
    u8int i = 0;
    u8int reading = 1;
    char *buffstr;
    while(reading) {
        if(inb(0x64) & 0x1) {
            switch(inb(0x60)) { 
      /*case 1:
                printch('(char)27);           Escape button
                buffstr[i] = (char)27;
                i++;
                break;*/
        case 2:
                monitor_put('1');
                buffstr[i] = '1';
                i++;
                break;
        case 3:
                monitor_put('2');
                buffstr[i] = '2';
                i++;
                break;
        case 4:
                monitor_put(('3'));
                buffstr[i] = '3';
                i++;
                break;
        case 5:
                monitor_put('4');
                buffstr[i] = '4';
                i++;
                break;
        case 6:
                monitor_put('5');
                buffstr[i] = '5';
                i++;
                break;
        case 7:
                monitor_put('6');
                buffstr[i] = '6';
                i++;
                break;
        case 8:
                monitor_put('7');
                buffstr[i] = '7';
                i++;
                break;
        case 9:
                monitor_put('8');
                buffstr[i] = '8';
                i++;
                break;
        case 10:
                monitor_put('9');
                buffstr[i] = '9';
                i++;
                break;
        case 11:
                monitor_put('0');
                buffstr[i] = '0';
                i++;
                break;
        case 12:
                monitor_put('-');
                buffstr[i] = '-';
                i++;
                break;
        case 13:
                monitor_put('=');
                buffstr[i] = '=';
                i++;
                break;
        case 14:
                monitor_put('\b');
                i--;
                buffstr[i] = 0;
                break;
        case 15:
                monitor_put('\t');
                buffstr[i] = '\t';
                i++;
                break;
        case 16:
                monitor_put('q');
                buffstr[i] = 'q';
                i++;
                break;
        case 17:
                monitor_put('w');
                buffstr[i] = 'w';
                i++;
                break;
        case 18:
                monitor_put('e');
                buffstr[i] = 'e';
                i++;
                break;
        case 19:
                monitor_put('r');
                buffstr[i] = 'r';
                i++;
                break;
        case 20:
                monitor_put('t');
                buffstr[i] = 't';
                i++;
                break;
        case 21:
                monitor_put('y');
                buffstr[i] = 'y';
                i++;
                break;
        case 22:
                monitor_put('u');
                buffstr[i] = 'u';
                i++;
                break;
        case 23:
                monitor_put('i');
                buffstr[i] = 'i';
                i++;
                break;
        case 24:
                monitor_put('o');
                buffstr[i] = 'o';
                i++;
                break;
        case 25:
                monitor_put('p');
                buffstr[i] = 'p';
                i++;
                break;
        case 26:
                monitor_put('[');
                buffstr[i] = '[';
                i++;
                break;
        case 27:
                monitor_put(']');
                buffstr[i] = ']';
                i++;
                break;
        case 28:
               // printch('\n');
               // buffstr[i] = '\n';
                  i++;
               reading = 0;
                break;
      /*  case 29:
                printch('q');           Left Control
                buffstr[i] = 'q';
                i++;
                break;*/
        case 30:
                monitor_put('a');
                buffstr[i] = 'a';
                i++;
                break;
        case 31:
                monitor_put('s');
                buffstr[i] = 's';
                i++;
                break;
        case 32:
                monitor_put('d');
                buffstr[i] = 'd';
                i++;
                break;
        case 33:
                monitor_put('f');
                buffstr[i] = 'f';
                i++;
                break;
        case 34:
                monitor_put('g');
                buffstr[i] = 'g';
                i++;
                break;
        case 35:
                monitor_put('h');
                buffstr[i] = 'h';
                i++;
                break;
        case 36:
                monitor_put('j');
                buffstr[i] = 'j';
                i++;
                break;
        case 37:
                monitor_put('k');
                buffstr[i] = 'k';
                i++;
                break;
        case 38:
                monitor_put('l');
                buffstr[i] = 'l';
                i++;
                break;
        case 39:
                monitor_put(';');
                buffstr[i] = ';';
                i++;
                break;
        case 40:
                monitor_put((char)44);               //   Single quote (')
                buffstr[i] = (char)44;
                i++;
                break;
        case 41:
                monitor_put((char)44);               // Back tick (`)
                buffstr[i] = (char)44;
                i++;
                break;
     /* case 42:                                 Left shift 
                printch('q');
                buffstr[i] = 'q';
                i++;
                break;
        case 43:                                 \ (< for somekeyboards)   
                printch((char)92);
                buffstr[i] = 'q';
                i++;
                break;*/
        case 44:
                monitor_put('z');
                buffstr[i] = 'z';
                i++;
                break;
        case 45:
                monitor_put('x');
                buffstr[i] = 'x';
                i++;
                break;
        case 46:
                monitor_put('c');
                buffstr[i] = 'c';
                i++;
                break;
        case 47:
                monitor_put('v');
                buffstr[i] = 'v';
                i++;
                break;                
        case 48:
                monitor_put('b');
                buffstr[i] = 'b';
                i++;
                break;               
        case 49:
                monitor_put('n');
                buffstr[i] = 'n';
                i++;
                break;                
        case 50:
                monitor_put('m');
                buffstr[i] = 'm';
                i++;
                break;               
        case 51:
                monitor_put(',');
                buffstr[i] = ',';
                i++;
                break;                
        case 52:
                monitor_put('.');
                buffstr[i] = '.';
                i++;
                break;            
        case 53:
                monitor_put('/');
                buffstr[i] = '/';
                i++;
                break;            
        case 54:
                monitor_put('.');
                buffstr[i] = '.';
                i++;
                break;            
        case 55:
                monitor_put('/');
                buffstr[i] = '/';
                i++;
                break;            
        /*case 56:
                printch(' ');           Right shift
                buffstr[i] = ' ';
                i++;
                break;*/           
        case 57:
                monitor_put(' ');
                buffstr[i] = ' ';
                i++;
                break;

        case 58:
                monitor_put(13); //ENTER
                break;

            
                }
        }
    }
    buffstr[i] = 0;                   
    return buffstr;                 
    
}

#endif
