#include <stdio.h>
#include <malloc.h>
#include <math.h>
int CheckSim(char arr1[], char arr2[] );
typedef struct{
  char name[50];
  char surname[50];
  char midname[50];
  int birthday_year;
  int birthday_month;;
  int birthday_day;
  char passport[9];
  char belay[50];
  char education[50];
  char post[50];
  char salary[50];
  int entry_year;
  int entry_month;
  int entry_day;
  char addit[200];
  struct node *prev;
  struct node *next;
}node;
int delete(node *_node, node *head);
int actions(node *nod, node *head){
    printf("1 - dismiss\n");
    printf("2 - vacation\n");
    printf("Your choose: ");
    int t;
    scanf("%d", &t);
    if(t<1 || t > 2) return 0;
    switch(t){
    case 1:{
        delete(nod, head);break;
    }
    case 2:{
        int year;
        int month;
        int day;
        int days = 0;
        printf("enter current date:\n");
        printf("year: ");
        scanf("%d", &year);
        printf("month: ");
        scanf("%d", &month);
        printf("day: ");
        scanf("%d", &day);
        if(year - nod->entry_year >=1){
           days += (12 - nod->entry_month)*30;
        }
        if(month - nod->entry_month< 0){
            days += nod->entry_month * 30;
        }
        else
        days += (month - nod->entry_month)*30;
        if(day - nod->entry_day < 0){
            days += 30 - day;
        }
        if(days >= 6*30){
            int nd = day +14;
            int nm = month;
            if(nd>30){
                nm++;
                if(nm > 12){
                    year++;
                    nm = 12 - month;
                }
                nd = nd - 30;
            }
            printf("Go to vacation:%d/%d/%d - %d/%d/%d\n",year, month, day, year, nm,nd);

        }
        printf("days: %d", days);
        getch();
    }
    }
}
int show(node *node);
int birthdays(node *head){
    printf("Enter current date: \n");
    int day;
    int month;
    printf("day: ");
    scanf("%d", &day);
    printf("month: ");
    scanf("%d", &month);
    node *temp = head;
    while(temp!= NULL){
        int days = 0;
        if(month - temp->birthday_month < 0){
            days += (12 + (month - temp->birthday_month))*30;
        }
        else days += (month - temp->birthday_month)*30;
        if(day - temp->birthday_day < 0)
          days += 30 + (day - temp->birthday_day);
        else days = day - temp->birthday_day;
        if(days <= 10) show(temp);
        temp = temp->next;
    }
    return 0;
}
int AtaJob(node *head){
    node *temp = head;
    while(temp != NULL){
        char t[] = {"vacation"};
        if(!CheckSim(t, temp->salary)){
            show(temp);
        }
        temp = temp->next;
    }
    return 0;
}
int Vacation(node *head){
    node *temp = head;
    while(temp != NULL){
        char t[] = {"vacation"};
        if(CheckSim(t, temp->salary)){
            show(temp);
        }
        temp = temp->next;
    }
    return 0;
}
int menu(){
    system("cls");
    printf("1 - search \n");
    printf("2 - stuff \n");
    printf("3 - birthdays\n");
    printf("4 - at a job \n");
    printf("5 - on vacation\n");
    printf("6 - retire \n");
    int ret;
    printf("Your choose: ");
    scanf("%d", &ret);
    if(ret < 1 || ret > 6){
        return 0;
    }
    else return ret;

}
int stuff(node *head){
    node *temp = head;
    while(temp!= NULL){
           show(temp);
            temp = temp->next;
    }
    return 0;

}
int entry(node *head){
    int year;
    printf("Enter current year: ");
    scanf("%d", &year);
    node *temp = head;
    while(temp!= NULL){
        int k;
        if(year - temp->birthday_year < 0){
            k = 100 - (temp->birthday_year - year);
        }
        else k = year - temp->birthday_year;
        if(k >= 60) {
            show(temp);
            printf("na pensiyu\n");
        }
        temp = temp->next;
    }
    getch();
    return 0;
}
int show(node *node){
    printf("**********************************************\n");
    printf("%s\n", node->name);
    printf("%s\n", node->surname);
    printf("%s\n", node->midname);
    printf("birthday: %d/%d/%d\n", node->birthday_year, node->birthday_month, node->birthday_day);
    printf("passport: %s\n", node->passport);
    printf("belay: %s\n", node->belay);
    printf("education: %s\n", node->education);
    printf("post: %s\n", node->post);
    printf("salary: %s\n", node->salary);
    printf("entry date: %d/%d/%d\n", node->entry_year, node->entry_month, node->entry_day);
    printf("additional: %s\n", node->addit);
    printf("**********************************************\n");
    return 0;
}
node* search(node *head){
    system("cls");
    printf("1 - name\n");
    printf("2 - midname\n");
    printf("3 - surname\n");
    printf("4 - birth year\n");
    printf("5 - birth month\n");
    printf("6 - birth day\n");
    printf("7 - passport \n");
    printf("8 - bealy\n");
    printf("9 - education\n");
    printf("10 - post\n");
    printf("11 - salary\n");
    printf("12 - entry year\n");
    printf("13 - entry month\n");
    printf("14 - entry day\n");
    printf("15 - adittion \n");
    int ret;
    scanf("%d", &ret);
    if(ret < 1 || ret > 14) return 0;
    switch(ret){
    case 1:{
        node *temp = head;
        printf("enter name: ");
        char s[50];
        scanf("%s", s);
        int punkt = 1;
        while(temp!=NULL){
            if(CheckSim(temp->name, s)){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(CheckSim(temp->name, s)) punkt++;
            if(CheckSim(temp->name, s) && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;

    case 2:{
        node *temp = head;
        printf("enter surname: ");
        char s[50];
        scanf("%s", s);
        int punkt = 1;
        while(temp!=NULL){
            if(CheckSim(temp->surname, s)){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(CheckSim(temp->surname, s)) punkt++;
            if(CheckSim(temp->surname, s) && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;
    case 3:{
        node *temp = head;
        printf("enter midname: ");
        char s[50];
        scanf("%s", s);
        int punkt = 1;
        while(temp!=NULL){
            if(CheckSim(temp->midname, s)){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(CheckSim(temp->midname, s)) punkt++;
            if(CheckSim(temp->midname, s) && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;
    case 4:{
        node *temp = head;
        printf("enter birth year: ");
        int s;
        scanf("%d", &s);
        int punkt = 1;
        while(temp!=NULL){
            if(temp->birthday_year == s){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(temp->birthday_year == s) punkt++;
            if(temp->birthday_year == s && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;
    case 5: {
        node *temp = head;
        printf("enter birth month: ");
        int s;
        scanf("%d", &s);
        int punkt = 1;
        while(temp!=NULL){
            if(temp->birthday_month == s){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(temp->birthday_month == s) punkt++;
            if(temp->birthday_month == s && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;
    case 6:{
        node *temp = head;
        printf("enter birth day: ");
        int s;
        scanf("%d", &s);
        int punkt = 1;
        while(temp!=NULL){
            if(temp->birthday_day == s){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(temp->birthday_day == s) punkt++;
            if(temp->birthday_day == s && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;
    case 7: {
        node *temp = head;
        printf("enter passport code: ");
        char s[50];
        scanf("%s", s);
        int punkt = 1;
        while(temp!=NULL){
            if(CheckSim(temp->passport, s)){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(CheckSim(temp->passport, s)) punkt++;
            if(CheckSim(temp->passport, s) && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;
    case 8: {
        node *temp = head;
        printf("enter belay: ");
        char s[50];
        scanf("%s", s);
        int punkt = 1;
        while(temp!=NULL){
            if(CheckSim(temp->belay, s)){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(CheckSim(temp->belay, s)) punkt++;
            if(CheckSim(temp->belay, s) && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;
    case 9:{
        node *temp = head;
        printf("enter education: ");
        char s[50];
        scanf("%s", s);
        int punkt = 1;
        while(temp!=NULL){
            if(CheckSim(temp->education, s)){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(CheckSim(temp->education, s)) punkt++;
            if(CheckSim(temp->education, s) && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;
    case 10: {
        node *temp = head;
        printf("enter post: ");
        char s[50];
        scanf("%s", s);
        int punkt = 1;
        while(temp!=NULL){
            if(CheckSim(temp->post, s)){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(CheckSim(temp->post, s)) punkt++;
            if(CheckSim(temp->post, s) && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;
    case 11:{
        node *temp = head;
        printf("enter salary: ");
        char s[50];
        scanf("%s", s);
        int punkt = 1;
        while(temp!=NULL){
            if(CheckSim(temp->salary, s)){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(CheckSim(temp->salary, s)) punkt++;
            if(CheckSim(temp->salary, s) && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;
    case 12:{
        node *temp = head;
        printf("enter entry year: ");
        int s;
        scanf("%d", &s);
        int punkt = 1;
        while(temp!=NULL){
            if(temp->entry_year == s){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(temp->entry_year == s) punkt++;
            if(temp->entry_year == s && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;
    case 13: {
        node *temp = head;
        printf("enter entry month: ");
        int s;
        scanf("%d", &s);
        int punkt = 1;
        while(temp!=NULL){
            if(temp->entry_month == s){
               printf("number: %d\n", punkt);
               show(temp);
               punkt++;
            }
            temp = temp->next;
        }
        printf("choose person: ");
        int t = 0;
        punkt = 0;
        scanf("%d", &t);
        temp = head;
        while(temp != NULL){
            if(temp->entry_month == s) punkt++;
            if(temp->entry_month == s && punkt == t){
               return temp;
            }
            temp = temp->next;
        }
    }
        break;
    case 14:{
        {
                node *temp = head;
                printf("enter entry day: ");
                int s;
                scanf("%d", &s);
                int punkt = 1;
                while(temp!=NULL){
                    if(temp->entry_day == s){
                       printf("number: %d\n", punkt);
                       show(temp);
                       punkt++;
                    }
                    temp = temp->next;
                }
                printf("choose person: ");
                int t = 0;
                punkt = 0;
                scanf("%d", &t);
                temp = head;
                while(temp != NULL){
                    if(temp->entry_day == s) punkt++;
                    if(temp->entry_day == s && punkt == t){
                       return temp;
                    }
                    temp = temp->next;
                }
            }
                break;
    case 15: {
            node *temp = head;
            printf("enter additional info: ");
            char s[50];
            scanf("%s", s);
            int punkt = 1;
            while(temp!=NULL){
                if(CheckSim(temp->addit, s)){
                   printf("number: %d\n", punkt);
                   show(temp);
                   punkt++;
                }
                temp = temp->next;
            }
            printf("choose person: ");
            int t = 0;
            punkt = 0;
            scanf("%d", &t);
            temp = head;
            while(temp != NULL){
                if(CheckSim(temp->addit, s)) punkt++;
                if(CheckSim(temp->addit, s) && punkt == t){
                   return temp;
                }
                temp = temp->next;
            }
        }
            break;
    }
    }
}
int add(node **input, node **head){
 if(*head == NULL){
     (*input)->prev = NULL;
     (*input)->next = NULL;
     (*head) = (*input);;
     return 0;
 }

 if((*head)->next == NULL){
     (*input)->prev = *head;
     (*input)->next = NULL;
     (*head)->next = (*input);
     return 0;
 }
 else{
    (*input)->next = *head;
    (*input)->prev = NULL;
    (*head)->prev = (*input);
    (*head) = *input;
}
 return 1;
}
int delete(node *_node, node *head){
    if(_node == NULL) return 0;
    if(_node == head && _node->next!=NULL){

        head = _node->next;
        head->prev = NULL;
        free(_node);
        printf("delete 1\n");
        return 0;
    }
    if(_node->next == NULL){
        node *p = _node->prev;
        p->next = NULL;
        free(_node);
        printf("delete 2\n");
        return 0;
    }
    if(_node->next != NULL){
        node *p = _node->prev;
        node *n = _node->next;
        free(_node);
        p->next = n;
        n->prev = p;
        printf("delete 3\n");
        return 0;
    }

}
int main()
{
    node *head;
    head = NULL;
    FILE *f;
    f = fopen("data.txt", "rw");
    while(!feof(f)){
        node* temp;
        temp = (node*)malloc(sizeof (node));
        for(int i = 0; i < 16 ; i++){
            char buff[200];
            fgets(buff,200,f);
           // printf("%s ", buff);
            switch(i){
            case 0: {
                int n = 0;
                while(buff[n]!='\0' && buff[n]!='\n'){
                    temp->name[n] = buff[n];
                    temp->name[n+1] = '\0';
                    n++;
                }
                break;
            }
            case 1:{
                int n = 0;
                while(buff[n]!='\0' && buff[n]!='\n'){
                    temp->surname[n] = buff[n];
                    temp->surname[n+1] = '\0';
                    n++;
                }
                break;
            }
            case 2:{
                int n = 0;
                while(buff[n]!='\0' && buff[n]!='\n'){
                    temp->midname[n] = buff[n];
                    temp->midname[n+1] = '\0';
                    n++;
                }
                break;
            }
            case 3:{
                temp->birthday_year = ((int)buff[0] - 48)*10 + (int)buff[1] - 48;
                break;
            }
            case 4:{
                temp->birthday_month = ((int)buff[0] - 48)*10 + (int)buff[1] - 48;
                break;
            }
            case 5:{
                temp->birthday_day = ((int)buff[0] - 48)*10 + (int)buff[1] - 48;
                break;
            }
            case 6: {
                int n = 0;
                while(buff[n]!='\0' && buff[n]!='\n'){
                    temp->passport[n] = buff[n];
                    temp->passport[n+1] = '\0';
                    n++;
                }
            }
            case 7:{
                int n = 0;
                while(buff[n]!='\0' && buff[n]!='\n'){
                    temp->belay[n] = buff[n];
                    temp->belay[n+1] = '\0';
                    n++;
                }
                break;
            }
            case 8:{
                int n = 0;
                while(buff[n]!='\0' && buff[n]!='\n'){
                    temp->education[n] = buff[n];
                    temp->education[n+1] = '\0';
                    n++;
                }
                break;
            }
            case 9:{
                int n = 0;
                while(buff[n]!='\0' && buff[n]!='\n'){
                    temp->post[n] = buff[n];
                    temp->post[n+1] = '\0';
                    n++;
                }
                break;
            }
            case 10:{
                int n = 0;
                while(buff[n]!='\0' && buff[n]!='\n'){
                    temp->salary[n] = buff[n];
                    temp->salary[n+1] = '\0';
                    n++;
                }
                break;
            }
            case 11:{
                temp->entry_year = ((int)buff[0] - 48)*10 + (int)buff[1] - 48;
                break;
            }
            case 12:{
                temp->entry_month = ((int)buff[0] - 48)*10 + (int)buff[1] - 48;
                break;
            }
            case 13:{
                temp->entry_day = ((int)buff[0] - 48)*10 + (int)buff[1] - 48;
                break;
            }
            case 14:{
                int n = 0;
                while(buff[n]!='\0' && buff[n]!='\n'){
                    temp->addit[n] = buff[n];
                    temp->addit[n+1] = '\0';
                    n++;
                }
                break;
            }
            }

        }
        add(&temp,&head);
    }

fclose(f);
int flag = 1;
while(flag){
    switch(menu()){
    case 1: actions(search(head), head);break;
    case 2: stuff(head); break;
    case 3: birthdays(head); break;
    case 4: AtaJob(head);break;
    case 5: Vacation(head);break;
    case 6: entry(head);break;
    default: flag = 0;
    }
}
f = fopen("data.txt", "w");
node *temp = head;
while( temp!= NULL){
    int n = 0;

 fputs(temp->name, f);
 fputs("\n",f);
 fputs(temp->surname, f);
 fputs("\n",f);
 fputs(temp->midname, f);
 fputs("\n",f);
 char buff[3];
 buff[0] = (char)(temp->birthday_year/10 +48);
 buff[1] = (char)(temp->birthday_year%10 +48);
 buff[2] = '\0';
 fputs(buff, f);
 fputs("\n", f);
 buff[0] = (char)(temp->birthday_month/10 +48);
 buff[1] = (char)(temp->birthday_month%10 +48);
 buff[2] = '\0';
 fputs(buff, f);
 fputs("\n", f);
 buff[0] = (char)(temp->birthday_day/10 +48);
 buff[1] = (char)(temp->birthday_day%10 +48);
 buff[2] = '\0';
 fputs(buff, f);
 fputs("\n", f);
 fputs(temp->passport,f);
 fputs("\n", f);
 fputs(temp->belay,f);
 fputs("\n",f);
 fputs(temp->education,f);
 fputs("\n",f);
 fputs(temp->post,f);
 fputs("\n",f);
 fputs(temp->salary,f);
 fputs("\n",f);
 buff[0] = (char)(temp->entry_year/10 +48);
 buff[1] = (char)(temp->entry_year%10 +48);
 buff[2] = '\0';
 fputs(buff, f);
 fputs("\n",f);
 buff[0] = (char)(temp->entry_month/10 +48);
 buff[1] = (char)(temp->entry_month%10 +48);
  buff[2] = '\0';
 fputs(buff, f);
 fputs("\n",f);
 buff[0] = (char)(temp->entry_day/10 +48);
 buff[1] = (char)(temp->entry_day%10 +48);
 buff[2] = '\0';
 fputs(buff, f);
 fputs("\n",f);
 fputs(temp->addit,f);
 fputs("\n",f);
 fputs("\n",f);
    temp = temp->next;
}
temp = head;
while(temp!=NULL){
    node* tt = temp->next;
 free(temp);
 temp = tt;
}
    return 0;
}
int CheckSim(char arr1[], char arr2[] ){
    int size_1 = 0;
    int size_2 = 0;
    int max_size = 0;
    int check = 0;
    while(arr1[size_1]!='\0') size_1++;
    while(arr2[size_2]!='\0') size_2++;
    if(size_1 > size_2){
        max_size = size_1;
    }
    else{
        max_size = size_2;
    }
    for(int i = 0; i < max_size; i++){
        if(arr1[i] == arr2[i]) check++;
    }
    if(check == max_size) return 1;
    else return 0;
}
