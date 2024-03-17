#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int snakewatergun(char you ,char comp){
    if(you == comp){
        return 0;
    }
    if(you == 's'&&comp=='g'){
        return -1;
    }
    else if(you == 'g'&&comp=='s'){
        return 1;
    }
    else if(you =='w'&&comp =='g'){
        return 1;
    }
    else if (you =='w'&&comp=='s'){
        return -1;
    }
    else if (you == 'g'&&comp == 'w'){
        return -1;
    }
    else if(you== 's'&&comp=='w'){
        return 1;
    }
}
int guess(int a){
    
    return a;
}

int main(){
    char you ,comp;
    int g;
    int result;
    srand(time(0));
    int number = rand()%100+1;
    if(number<33){
       comp = 's';
    }
    else if (number>33&&number<66){
        comp='w';
    }
    else{
        comp='g';
    }
    do{
    printf("Enter 's' for snake 'w'for water and 'g' for gun ");
    scanf("%c",&you);
    result = snakewatergun(you,comp);
    if (result==0){
        printf("Game draw!\n");
        continue;
    }
    else if (result ==-1){
        printf("you lose\n");
    }
    else{
        printf("you Win\n");
         g = guess(1);
    }
    }while(g != result);
    printf("you choose %c and computer choose %c",you,comp);
    return 0;
}