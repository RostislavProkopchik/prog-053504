#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
float input_mm = 0;
void Input();
void ShowMenu();
void Input();
int menu_input();
void ToInch(float mm);
void ToYard(float mm);
void ToFoot(float mm);
void ToMiles(float mm);
void ShowInput();
void ConvertToEnglish();
void AboutProgram();
void ToVershok(float mm);
void ToArshin(float mm);
void ToSajen(float mm);
void ToVersta(float mm);
void ConvertToRussian();

int main() {

    int CheckExit = 1;

        while(CheckExit){
           ShowMenu();
           CheckExit =  menu_input();
    }
        system("cls");
        printf(" Press any key to exit...\n");

    return 0;
}
    void ShowMenu(){
        system("cls");
        printf("****************************** \n");
        printf("****  FREE CONVERTING !!! **** \n");
        printf("****************************** \n");
        printf("**     Input value -->    1 ** \n");
        printf("** Convert to russian --> 2 ** \n");
        printf("** Convert to english --> 3 ** \n");
        printf("** Default value (mm) --> 4 ** \n");
        printf("**    About program --> 5   ** \n");
        printf("** Exit ----------------> 0 ** \n");
        printf("******************************\n");
        printf("Action number --> ");

    }

    int menu_input(){
    int choice = 0;
    scanf("%d", &choice);
    if(choice < 0 || choice >5){
        printf("ERORR!!!");
    }
    switch (choice) {

    case 1: Input(); break;
    case 2: ConvertToRussian(); break;
    case 3: ConvertToEnglish(); break;
    case 4: ShowInput(); break;
    case 5: AboutProgram(); break;
    case 0: {
        return 0;
       }
    default: {
        return 0;
       }
      }
    return 1;
    }

    void Input(){
        int choice = 0;
        m0:
        system("cls");
        printf("** Input **\n");
        printf(" 1 - for mm\n");
        printf(" 2 - for m \n");
        printf(" 3 - for km\n");
        printf(" 0 - menu\n");
        scanf("%d", &choice);

        if(choice < 1 || choice >3){
            goto m0;
        }

        switch(choice){
        case 1:{
            float temp;
            m1:
            printf("Input mm -> ");
            scanf("%f", &temp);
            if(temp < 0){
                printf("ERROR!!\n");
                goto m1;
            }
            else input_mm = temp;

            break;
        }
        case 2:{
            float temp;
            m2:
            printf("Input m -> ");
            scanf("%f", &temp);
            if(temp < 0){
                printf("ERROR!!\n");
                goto m2;
            }
            else input_mm = temp*1000;

            break;
        }
        case 3:{
            float temp;
            m3:
            printf("Input km -> ");
            scanf("%f", &temp);
            if(temp < 0){
                printf("ERROR!!\n");
                goto m3;
            }
            else input_mm = temp*1000000;

            break;
        }
        case 0:{
            return;
            break;
        }
        default: return;
        }

    }
    void ToInch(float mm){
       system("cls");
       printf("** Inches ** \n");
       float temp = mm/254; // 1 inch = 254 mm
       printf("** %.3f\n", temp);
       printf(" Press any key to ext \n");
       getch();

    }

    void ToFoot(float mm){
        system("cls");
        printf("** Foots ** \n");
        float temp = mm/ 12 / 254; // 1 foot = 12 inch
        printf("%.3f\n", temp);
        printf(" Press any key to exit \n");
        getch();
    }

    void ToYard(float mm){
        system("cls");
        printf("** Yard ** \n");
        float temp = mm / 3 /12/ 254; // 1 yard = 3 foot
        printf("%.3f\n", temp);
        printf(" Press any key to exit \n");
        getch();

  }

    void ToMiles(float mm){
        system("cls");
        printf("** Miles ** \n");
        float temp = mm / 1760/ 3 / 12 / 254;  // 1 mile = 1760 yard
        printf("%.3f\n", temp);
        printf(" Press any key to exit \n");
        getch();

    }


    void ConvertToEnglish(){
        system("cls");
        printf("** English vals ** \n");
        printf("** Convert mm to : \n");
        printf("** 1  -  inches\n");
        printf("** 2  -  foots\n");
        printf("** 3  -  yards\n");
        printf("** 4  -  miles\n");
        printf("** action -> ");
        int action = 0;
        scanf("%d", &action);
        switch(action){
        case 1: ToInch(input_mm); break;
        case 2: ToFoot(input_mm); break;
        case 3: ToYard(input_mm); break;
        case 4: ToMiles(input_mm); break;
        default: return;
        }
    }

    void ShowInput(){
        system("cls");
        printf("**** Yor value ****\n");
        printf("***  %.5f ***\n", input_mm);
        printf(" Press any key to ext \n");
        getch();

    }

    void AboutProgram(){
        system("cls");
        printf("** About Program ** \n");
        printf("**   ver 0.02    ** \n");
        printf("** Author:       ** \n");
        printf("** Prokopchik    ** \n");
        printf("** Rostislav     ** \n");
        printf("** BSUiR         ** \n");
        printf("** HELP !!!!!!   ** \n");
        printf(" Press any key to ext \n");
        getch();

    }
    void ToVershok(float mm){
        system("cls");
        printf("** Vershki ** \n");
        float temp = mm / 44.45;  // 1 vershik = 44.45 mm
        printf("%.3f\n", temp);
        printf(" Press any key to exit \n");
        getch();

    }
    void ToArshin(float mm){
        system("cls");
        printf("** Arshins ** \n");
        float temp = mm / 44.45/ 16;  // 1 arshina = 16 vershkov
        printf("%.3f\n", temp);
        printf(" Press any key to exit \n");
        getch();

    }
    void ToSajen(float mm){
        system("cls");
        printf("** Sajnes ** \n");
        float temp = mm / 44.45/ 16 / 3;  // 1 sajen = 3 arshini
        printf("%.3f\n", temp);
        printf(" Press any key to exit \n");
        getch();

    }
    void ToVersta(float mm){
        system("cls");
        printf("** Versts ** \n");
        float temp = mm / 44.45 / 16 / 3/ 500;  // 1 versta = 500 sajens
        printf("%.3f\n", temp);
        printf(" Press any key to exit \n");
        getch();

    }
    void ConvertToRussian(){
        system("cls");
        printf("** Russian vals ** \n");
        printf("** Convert mm to : \n");
        printf("** 1  -  vershki\n");
        printf("** 2  -  arshini\n");
        printf("** 3  -  sajni\n");
        printf("** 4  -  versti\n");
        printf("** action -> ");
        int action = 0;
        scanf("%d", &action);
        switch(action){
        case 1: ToVershok(input_mm); break;
        case 2: ToArshin(input_mm); break;
        case 3: ToSajen(input_mm); break;
        case 4: ToVersta(input_mm); break;
        default: return;
        }
    }
