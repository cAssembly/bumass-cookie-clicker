#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

int main() {

    struct termios orig;
    tcgetattr(STDIN_FILENO, &orig);
    struct termios raw = orig;
    cfmakeraw(&raw);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);

    long long cookies = 0;
    long long cps = 1;
    long long clickPower = 1;
    time_t last = time(NULL);

    while (1) {
        // update cookies
        time_t now = time(NULL);
        cookies += cps * (now - last);
        last = now;

    // ui
    system("clear");
    printf("\rCookies: %lld\n", cookies);
    printf("\rCookies Per Second:%lld\n", cps);
    printf("\n"); 

    printf("\r⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣶⣿⣿⡿⠿⠷⣶⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("\r⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⣿⣇⠀⠀⢸⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀\n");
    printf("\r⠀⠀⠀⠀⢀⣴⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀\n");
    printf("\r⠀⠀⠀⢠⣿⡟⠁⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀\n");
    printf("\r⠀⠀⢠⣿⣿⣿⣦⣄⣠⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢿⣿⣿⣿⣷⠀⠀⠀\n");
    printf("\r⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⢹⣿⣿⣿⡇⠀⠀\n");
    printf("\r⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⣿⠀⠀\n");
    printf("\r⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀\n");
    printf("\r⠀⠀⠈⢿⣿⣿⣿⣿⠟⠻⣿⣿⠋⠀⠉⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⢙⣿⠃⠀⠀\n");
    printf("\r⠀⠀⠀⠈⢿⣿⣿⠁⠀⠀⠘⣿⣆⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀\n");
    printf("\r⠀⠀⠀⠀⠀⠙⢿⣦⣤⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀\n");
    printf("\r⠀⠀⠀⠀⠀⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠉⢹⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀\n");
    printf("\r⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⠿⣿⣿⣿⣷⡤⠾⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("\n");  

    printf("\r(1)  Click (+%lld)\n", clickPower);
    printf("\r(2)  Buy Cursor (+1 CPS) [cost: 50]\n");
    printf("\r(3)  3. Buy Grandma (+5 CPS) [cost: 200]\n");
    printf("\r(4)  4. Buy Grandma (+25 CPS) [cost: 1000]\n");
    printf("\r(5)  5. Buy Cookie Farm (+100 CPS) [cost: 10000]\n");
    printf("\r(6)  6. Buy Cookieium Mine (+1000 CPS) [cost: 50,000]\n");
    printf("\r(7)  7. Buy Cookie Factory (+5000 CPS) [cost: 250,000]\n");
    printf("\r(8)  8. Buy Cookie Bank (+10,000 CPS) [cost: 500,000]\n");
    printf("\r(9)  9. Buy Cookie Shrine (+50,000 CPS) [cost: 1,000,000]\n");
    printf("\r(0)  0. Buy Wizard tower (+250,000 CPS) [cost: 1,000,000,0]\n"); 

    printf("\r(q) Quit\n");
    printf("\rChoose: ");

        // input stuff
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        struct timeval tv = {0, 0};
        if (select(1, &fds, NULL, NULL, &tv) > 0) {
            char c = getchar();
            if (c == '1') cookies += clickPower;
            else if (c == '2' && cookies >= 50) { cookies -= 50; cps += 1; }
            else if (c == '3' && cookies >= 200) { cookies -= 200; cps += 5; }
            else if (c == '4' && cookies >= 1000) { cookies -= 1000; cps += 25; }
            else if (c == '5' && cookies >= 10000) { cookies -= 10000; cps += 100; }
            else if (c == '6' && cookies >= 50000) { cookies -= 50000; cps += 1000; }
            else if (c == '7' && cookies >= 250000) { cookies -= 250000; cps += 5000; }
            else if (c == '8' && cookies >= 500000) { cookies -= 500000; cps += 10000; }
            else if (c == '9' && cookies >= 1000000) { cookies -= 1000000; cps += 50000; }
            else if (c == '0' && cookies >= 10000000) { cookies -= 10000000; cps += 250000; }

            else if (c == 'q') break;
        }

        usleep(100000); // rewrite output
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &orig); // restore terminal
    return 0;
}
