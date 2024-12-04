#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>

void getCurrentDate(char *buffer, size_t size) {
    time_t t;
    struct tm *tm_info;

    // Get the current time
    t = time(NULL);
    tm_info = localtime(&t);

    // Format the date into "YYYY-MM-DD"
    strftime(buffer, size, "%Y-%m-%d", tm_info);
}

void getCurrentTime(char *buffer, size_t size) {
    time_t t;
    struct tm *tm_info;

    // Get the current time
    t = time(NULL);
    tm_info = localtime(&t);

    // Format the time into "HH:MM"
    strftime(buffer, size, "%H:%M", tm_info);
}

void displayUI(const char *date, const char *timeIn, const char *timeOut, const char *timeInAfternoon, const char *timeOutAfternoon) {
    printf("     +-----------------------------------------------------------------------------------------------------------+\n");
    printf("     | Employee Name:                                                                                            |\n");
    printf("     | Department: Faculty                                                                                       |\n");
    printf("     +-----------------------------------------------------------------------------------------------------------+\n");
    printf("     |                                             ATTENDANCE RECORD                                             |\n");
    printf("     +-----------------------------------------------------------------------------------------------------------+\n");
    printf("     | DATE: %-10s  |                                                                                       |\n", date);
    printf("     +-----------------------------------------------------------------------------------------------------------+\n");
    printf("     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("     +-----------------+-----------------------------------------------------------------------------------------+\n");
    printf("     |      TIME:      |                             MORNING SESSION                                             |\n");
    printf("     +-----------------+-----------------------------------------------------------------------------------------+\n");
    printf("     |      %-10s |                                 TIME IN                                                 |\n", timeIn);
    printf("     +-----------------+-----------------------------------------------------------------------------------------+\n");
    printf("     |      %-10s |                                 TIME OUT                                                |\n", timeOut);
    printf("     +-----------------+-----------------------------------------------------------------------------------------+\n");
    printf("     |      TIME:      |                            AFTERNOON SESSION                                            |\n");
    printf("     +-----------------+-----------------------------------------------------------------------------------------+\n");
    printf("     |      %-10s |                                 TIME IN                                                 |\n", timeInAfternoon);
    printf("     +-----------------+-----------------------------------------------------------------------------------------+\n");
    printf("     |      %-10s |                                 TIME OUT                                                |\n", timeOutAfternoon);
    printf("     +-----------------------------------------------------------------------------------------------------------+\n");
}

int main() {
    char input;
    char date[15];
    char timeIn[15] = "N/A";
    char timeOut[15] = "N/A";
    char timeInAfternoon[15] = "N/A";
    char timeOutAfternoon[15] = "N/A";

    // Initialize the date
    getCurrentDate(date, sizeof(date));

    while (1) {
        system("cls"); 
        displayUI(date, timeIn, timeOut, timeInAfternoon, timeOutAfternoon); // Display the UI with current Date, Times
        
        printf("              -------------------    --------------------    -------------------    --------------------\n");
        printf("             | [ Q ] Mark In (M) |  | [ W ] Mark Out (M) |  | [ A ] Mark In (N) |  | [ S ] Mark Out (N) |\n");
        printf("              -------------------    --------------------    -------------------    --------------------\n");

        input = getchar();
		
        if (input == 'q') {
            getCurrentTime(timeIn, sizeof(timeIn)); // Update Time In (morning)
            printf("Morning IN marked at: %s on %s\n", timeIn, date);
            while (getchar() != '\n'); // Clear buffer
        } else if (input == 'w') {
            getCurrentTime(timeOut, sizeof(timeOut)); // Update Time Out (morning)
            printf("Morning OUT marked at: %s on %s\n", timeOut, date);
            while (getchar() != '\n'); // Clear buffer
        } else if (input == 'a') {
            getCurrentTime(timeInAfternoon, sizeof(timeInAfternoon)); // Update Time In (afternoon)
            printf("Afternoon IN marked at: %s on %s\n", timeInAfternoon, date);
            while (getchar() != '\n'); // Clear buffer
        } else if (input == 's') {
            getCurrentTime(timeOutAfternoon, sizeof(timeOutAfternoon)); // Update Time Out (afternoon)
            printf("Afternoon OUT marked at: %s on %s\n", timeOutAfternoon, date);
            while (getchar() != '\n'); // Clear buffer
        } else if (input == 9) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid input. Please press 'q', 'w', 'a', 's', or 'e'.\n");
            while (getchar() != '\n'); // Clear buffer
        }
    }

    return 0;
}


