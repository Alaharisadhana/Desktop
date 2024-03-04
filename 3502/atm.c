#include<stdio.h>
#include<stdlib.h>
void main(){
    int pin,ch;
    double d,w,b=5000;
    printf("*************WELCOME TO THE ATM**************\n");
    printf("\nplease insert your card\n");
printf("\nplease enter your pin\n");
scanf("%d",&pin);
if(pin!=123){
    printf("Invalid pin");

}

while(1){
    printf("1:check your balance\n 2:with drawl of money\n 3:depoist of money\n 4:account details\n 5:exit");
    printf("enter your choice");
    scanf("%d",ch);
    switch(ch){
        case 1:printf("your balance is %lf",b);
               break;
        case 2:printf("please enter amount to withdrawl");
        if(w>b){
            printf("insuffcient amount to draw,please check balance and try again!");


        }
        else{
            scanf("%lf",&w);
            b=b-w;
            printf("your amount is dispensed sucessfully");
    
        }
        break;
        case 3:printf("please enter amount to deposit");
               scanf("%lf",&d);
               b=b+d;
               printf("sucessfully deposited into your account");
               break;
         case 4:printf("your balance is%lf",b);
               printf("you have depoisted %lf",d);
               printf("your dispensend amount is %lf",w);
               printf("THANK YOU");
               break;
          case 5:exit(0);     

    
    }
}
}

