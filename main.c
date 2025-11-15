#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Program started!\n");
    long long cookies = 0;
    long long cookiesPerSecond= 1;
    long long cookieMult = 50;
    
    int choice;
    time_t last = time(NULL);

    while (1){
        time_t now =time(NULL);
        if (now >last) {
            cookies += cookiesPerSecond *(now - last);
            last = now;
        }
    


    printf(" Cookies: %lld\n", cookies);
    printf(" Cookies Per Second:%lld\n", cookiesPerSecond);
    printf("(choice) 1. Click (+%lld)\n", cookieMult);
    printf("(choice) 2. Buy Cursor (+1 CPS) [cost: 50]\n");
    printf("(choice) 3. Buy Grandma (+5 CPS) [cost: 200]\n");
    printf("(choice) 100. Quit\n");
    printf("Choose: ");
    scanf("%d", &choice);

    if (choice ==1){
        cookies += cookieMult;
    }
    else if (choice ==2){
        if (cookies >=50) {
            cookies -=50;
            cookiesPerSecond += 1;
        } else{
            printf("Not enough cookies\n");
        }
    }else if (choice ==3){
        if (cookies >=200) {
            cookies -=200;
            cookiesPerSecond += 5;
        } else{
            printf("Not enough cookies\n");
        }
    }
    else if (choice ==100){
        printf(":(\n");
        break;
        
    }
    else{
        printf("invalid option\n");
    }
} }