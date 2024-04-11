#include <stdio.h>
#include <wiringPi.h>
#include "../module/device_module.h"

#define LED 1
#define SWITCH 4

int temp_sw = 0;
int prev_sw = 0;
int check_open_user = 0;

int user_mode()
{
    if (wiringPiSetup() == -1) return -1;

    pinMode(LED, OUTPUT);
    pinMode(SWITCH, INPUT);

    while (1) {
        temp_sw = digitalRead(SWITCH);

        if (temp_sw == HIGH && temp_sw != prev_sw) {
            printf("pressed\n");
            prev_sw = temp_sw;
            openmax();
            digitalWrite(LED, HIGH);
            break;
        }
        else if (temp_sw == HIGH && temp_sw == prev_sw) {
            while (digitalRead(SWITCH) == HIGH) {
                printf("pressing\n");
                run();
                check_open_user = 1;
                digitalWrite(LED, HIGH);
                delay(500);
                digitalWrite(LED, LOW);
            }
            if (check_open_user == 1) break;
        }
        delay(1000);
    }

    return 0;
}
