#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>

// Function declarations
int main();
int signupPage();
int loginPage();
int studentMenu();
int profMenu();
void professorChoice();  // Added declaration
void studentChoice();    // Added declaration

// Function for professor menu	
void profile_detailsPage();
void aboutusPage();
void mark_attendancePage();
void classroom_professorPage();

// Function for student menu
void profile_detailsPage2();
void enrollmentPage();
void eog_requestPage();
void classroom_studentPage();

// Function for changing profile details
void change_emailPage();
void edit_numberPage();
void change_passPage();
void change_emailPage2();
void edit_numberPage2();
void change_passPage2();

// Storage for Prof attendance
char date[15];
char timeIn[15] = "N/A";
char timeOut[15] = "N/A";
char timeInAfternoon[15] = "N/A";
char timeOutAfternoon[15] = "N/A";

// Storage for Mark attendance
char studName[15];
char studLname[15];
char studSection[15];
char studSubject[15];
char datetoDay[15];
char presence[15];

// Storage for Personal details of user
char roleChoice[20];
char firstN[50];
char lastN[50];
char Fullname[50];
char birthD[50];
char userN[50]; // storage for username
char email[50]; 
char contactN[50]; 
char passW[50]; // storage for password
int valid = 1;

// Storage data for Evaluation of grade
char reqSemester [50];
char eogLname [50];
char eogFname [50];
char eogFullname [50];
char eogSID [50];
char eogSection [50];
char eogCourse [50];
char eogLevel [50];
char eogSY [50];
char eogReason [1000];
char eogReason2 [1000];

char userLevel[50]; // storage for user's college level
char profMajor[50]; // storage for user's major subject

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
    printf("     | Employee Name: %-91s|\n", Fullname);
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

void EOGdisplay () {
	printf("\n=====================================================================================================================\n");
    printf("*                                        Evaluation of Grades Request                                               *\n");
    printf("=====================================================================================================================\n");
}

void createAccountDisplay() {
	printf("\t\t\t============================================================\n");
    printf("\t\t\t*                     Create an Account                    *\n");
    printf("\t\t\t============================================================\n\n");
}

void loginDisplay() {
    printf("\t\t\t============================================================\n");
    printf("\t\t\t*                   Login your Account!                    *\n");
    printf("\t\t\t============================================================\n\n");
}

void changeAccountDisplay() {
	printf("\n=====================================================================================================================\n");
    printf("*                                          Change Account Information                                               *\n");
    printf("=====================================================================================================================\n");
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

// Main function with main loop
int main() {
    char user;
    hidecursor();
    
    while (1) { // Loop to keep the program running until user chooses to exit
        system("cls");
        printf("\n\n\n\n\n");
        printf("\t\t\t============================================================\n");
        printf("\t\t\t*                  WELCOME TO PHILTECH!                    *\n");
        printf("\t\t\t============================================================\n\n");

        printf("\t\t\t\t\t ----------------------------\n");
		printf("\t\t\t\t\t|       [ 1 ] Login          |\n");
		printf("\t\t\t\t\t ----------------------------\n");
		printf("\t\t\t\t\t ----------------------------\n");
        printf("\t\t\t\t\t|       [ 2 ] Sign Up        |\n");
        printf("\t\t\t\t\t ----------------------------\n");
        printf("\t\t\t\t\t ----------------------------\n");
        printf("\t\t\t\t\t|       [ 0 ] Exit           |\n");
        printf("\t\t\t\t\t ----------------------------\n");
        
        user = getch();

        switch (user) {
            case '1':
                loginPage(); // Call login page
                break;
            case '2':
                signupPage(); // Call signup page
                break;
            case '0':
                exit(0); // Exit the program
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}

// Signup page
int signupPage() {
	char roleC;
	
    system("cls");
    printf("\n\n\n\n\n");
    createAccountDisplay();
    printf("\t\t\tPERSONAL INFORMATION\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| Firstname: ");
    scanf("%s", firstN);
    printf("\t\t\t -----------------------------------------------------------\n");
    
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| Lastname: ");
    scanf("%s", lastN);
    printf("\t\t\t -----------------------------------------------------------\n");
    
    strcat(Fullname, lastN);
    strcat(Fullname, ", ");
    strcat(Fullname, firstN);
    
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| Birthday: ");
    scanf(" %[^\n]", birthD);
    printf("\t\t\t -----------------------------------------------------------\n");
        
account_info:
    system("cls");
    printf("\n\n\n\n\n");
    createAccountDisplay();
    printf("\t\t\tACCOUNT INFORMATION\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| Username: ");
    scanf("%s", userN);
    printf("\t\t\t -----------------------------------------------------------\n");

    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| Email: ");
    scanf("%s", email);
    printf("\t\t\t -----------------------------------------------------------\n");

    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| Contact Number: ");
    scanf("%s", contactN);
    printf("\t\t\t -----------------------------------------------------------\n");

    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| Password: ");
    scanf("%s", passW);
    printf("\t\t\t -----------------------------------------------------------\n");
    
position_Choices:
    system("cls");
    printf("\n\n\n\n\n");
    createAccountDisplay();
    printf("\t\t\t\t\t ----------------------------\n");
    printf("\t\t\t\t\t|    Choose your position:   |\n");
    printf("\t\t\t\t\t ----------------------------\n");
    printf("\t\t\t\t\t|      [ 1 ] Professor       |\n");
    printf("\t\t\t\t\t|      [ 2 ] Student         |\n");
    printf("\t\t\t\t\t ----------------------------\n");
    
    roleC = getch();
    system("cls");
    
    switch (roleC) {
        case '1':
        	printf("\n\n\n\n\n");
        	createAccountDisplay();
        	strcpy(roleChoice, "Professor");
        	printf("\t\t\tEnter your major subject:\n");
        	printf("\t\t\t -----------------------------------------------------------\n");
    		printf("\t\t\t| Subject: ");
    		scanf("%s", profMajor);
    		printf("\t\t\t -----------------------------------------------------------\n");
    		goto login_success;
            break;
        case '2':
        	printf("\n\n\n\n\n");
        	createAccountDisplay();
        	strcpy(roleChoice, "Student");
            printf("\t\t\tEnter your college level:\n");
        	printf("\t\t\t -----------------------------------------------------------\n");
    		printf("\t\t\t| Level: ");
    		scanf(" %[^\n]", userLevel);
    		printf("\t\t\t -----------------------------------------------------------\n");
    		goto login_success;
            break;
        default:
        	printf("\n\n\n\n\n");
        	createAccountDisplay();
            printf("\n\n");
            printf("\t\t\t\t\t(System): Invalid Input!\n");
            printf("\t\t\t\t\tPress any key to continue...");
    		getch();
    		goto position_Choices;
        }
        
login_success:
    printf("\n\t\t\tAccount created successfully!\n\n");
    printf("\t\t\tPress any key to continue...");
    getch();
    
    return 0; // Return to main loop
}

// Login page
int loginPage() {
    char loginUserN[50], loginPassW[50];

    system("cls");
    printf("\n\n\n\n\n");
    loginDisplay();
    printf("\t\t\tEnter your username:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| Username: ");
    scanf("%s", loginUserN);
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\tEnter your password:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| Password: ");
    scanf("%s", loginPassW);
    printf("\t\t\t -----------------------------------------------------------\n");

    // Check if login credentials match
    if (strcmp(loginUserN, userN) == 0 && strcmp(loginPassW, passW) == 0) {
    	if (strcmp(roleChoice, "Professor") == 0) {
    		printf("\n\n");
    		printf("\t\t\tSuccessfully logged in as %s professor!\n\n", profMajor);
    		printf("\t\t\tPress any key to continue...");
    		getch();
    		profMenu();
		} else if (strcmp(roleChoice, "Student") == 0) {
			printf("\n\n");
    		printf("\t\t\tSuccessfully logged in as %s student!\n\n", userLevel);
    		printf("\t\t\tPress any key to continue...");
    		getch();
			studentMenu();
		}   
    } else {
    	system("cls");
    	printf("\n\n\n\n\n");
        loginDisplay();
        printf("\t\t\t(System): Invalid username or password. Please try again.\n\n");
        printf("\t\t\tPress any key to continue...");
        getch();
        loginPage();
    }
    return 0; // Return to main loop
}

// Under Menu Page ==============================================================================
void profile_detailsPage () { //                                                                |
	char userProfile;
	
	system("cls");
	printf("\n=====================================================================================================================\n");
    printf("*                                              Account Information                                                  *\n");
    printf("=====================================================================================================================\n");
    printf("[ 9 ] Back\n\n");
    
    printf("\t\t ------------------------------------      ------------------------------------\n");
    printf("\t\t| Firstname: %-23s |    | Lastname: %-24s |\n", firstN, lastN);
    printf("\t\t ------------------------------------      ------------------------------------\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Birthday: %-67s|\n", birthD);
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Username: %-67s|\n", userN);
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t ------------------------------------      ------------------------------------\n");
    printf("\t\t| Position: Professor of Philtech    |    | Major Subject: %-16s    |\n", profMajor);
    printf("\t\t ------------------------------------      ------------------------------------\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Email Address: %-62s|\n", email);
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Contact Number: %-61s|\n", contactN);
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Password: %-67s|\n", passW);
    printf("\t\t ------------------------------------------------------------------------------\n\n");
    
    printf("\t==============================================================================================\n");
    printf("\t|                [ 1 ] Change Email. [ 2 ] Edit Number. [ 3 ] Change Password.               |\n");
    printf("\t==============================================================================================\n\n");
    
    userProfile = getch();
    
    switch (userProfile) {
    	case '1':
    		change_emailPage();
    		break;
    	case '2':
    		edit_numberPage();
    		break;
    	case '3':
    		change_passPage();
    		break;
    	case '9':
    		profMenu();
    		break;
    	default:
    		printf("\nInvalid Input!");
    		system("pause");
    		break;
	}
}
// Under edit professor profile details                                                         |
void change_emailPage () { //                                                                   |
	char loginPassW2[50];
	char emailInput[50];
	
	system("cls");
	changeAccountDisplay();
    printf("[ 9 ] Back\n\n");
	
	printf("\t\tEnter new email address:\n");
	printf("\t\t ------------------------------------------------------------------------------\n");
	printf("\t\t| Email: ");
    scanf(" %[^\n]s", emailInput);
    if (strcmp(emailInput, "9") == 0) {
        profile_detailsPage();
    }
    strcpy(email, emailInput); // Stored the new email in the email variable
    
    printf("\t\t ------------------------------------------------------------------------------\n\n");
    printf("\t\tPassword for verification:\n");
	printf("\t\t ------------------------------------------------------------------------------\n");
	printf("\t\t| Password: ");
    scanf("%s", loginPassW2);
    printf("\t\t ------------------------------------------------------------------------------\n\n");
    
    if (strcmp(loginPassW2, passW) == 0) {
        printf("\t\tEmail updated successfully.\n\n");
    
		printf("\t\tPress any key to continue...");
    	getch();
		profile_detailsPage();
    } else {
        printf("\t\t(System): Invalid password. Please try again.\n\n");
        printf("\t\tPress any key to continue...");
        getch();
        change_emailPage();
    }
}
void edit_numberPage () { //                                                                    |
	char loginPassW3[50];
	char contactInput[50];
	
	system("cls");
	changeAccountDisplay();
    printf("[ 9 ] Back\n\n");
	
    valid = 1; // Reset valid flag
    printf("\t\tEnter new Contact Number:\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Contact Number: ");
    scanf(" %[^\n]s", contactInput);

        if (strcmp(contactInput, "9") == 0) {
            profile_detailsPage();
        }

        for (int i = 0; i < strlen(contactInput); i++) {
            if (!isdigit(contactInput[i])) { // Check if the character is not a digit
                valid = 0;
                printf("\n\n");
                printf("\t\tError: Contact number must contain only digits.\n\n");
                printf("\t\tPress any key to continue...");
        		getch();
        		edit_numberPage();
                
            }
        }

    // Store the valid contact number
    strcpy(contactN, contactInput);
    
    printf("\t\t ------------------------------------------------------------------------------\n\n");
    printf("\t\tPassword for verification:\n");
	printf("\t\t ------------------------------------------------------------------------------\n");
	printf("\t\t| Password: ");
    scanf("%s", loginPassW3);
    printf("\t\t ------------------------------------------------------------------------------\n\n");
    
    if (strcmp(loginPassW3, passW) == 0) {
        printf("\t\tContact number updated successfully.\n\n");
    
		printf("\t\tPress any key to continue...");
    	getch();
		profile_detailsPage();
    } else {
        printf("\t\t(System): Invalid password. Please try again.\n\n");
        printf("\t\tPress any key to continue...");
        getch();
        edit_numberPage();
    }
}
void change_passPage() { //                                                                     |
	char loginPassW4[50];
    char passwordInput[50];
    char confirmPassword[50];

    system("cls");
    changeAccountDisplay();
    printf("[ 9 ] Back\n\n");

    // Password for verification
    printf("\t\tEnter a current password:\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Password: ");
    scanf("%s", loginPassW4);
    
    if (strcmp(loginPassW4, "9") == 0) {
        profile_detailsPage();
    }
    printf("\t\t ------------------------------------------------------------------------------\n\n");

    // Check if the entered current password is correct
    if (strcmp(loginPassW4, passW) != 0) {
        printf("\t\t(System): Invalid password. Please try again.\n\n");
        printf("\t\tPress any key to continue...");
        getch();
        change_passPage();
    } 

    printf("\t\tEnter new password:\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Password: ");
    scanf(" %[^\n]s", passwordInput);  // Read the new password
    printf("\t\t ------------------------------------------------------------------------------\n\n");

    // Confirm new password
    printf("\t\tPlease confirm your new password:\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Confirm Password: ");
    scanf(" %[^\n]s", confirmPassword);  // Get the confirmation password
    printf("\t\t ------------------------------------------------------------------------------\n\n");

    // Check if the new password and confirmation match
    if (strcmp(passwordInput, confirmPassword) != 0) {
        printf("\t\t(System): Passwords do not match. Please try again.\n\n");
        printf("\t\tPress any key to continue...");
        getch(); 
        change_passPage();
    }

    strcpy(passW, passwordInput);
    printf("\t\tPassword updated successfully.\n\n");

    printf("\t\tPress any key to continue...");
    getch();
    profile_detailsPage();
}
// End of Professor Menu Page ===================================================================

//===================================
void aboutusPage () {
	printf("This is about us page");
	system("pause");
}

void prof_attendancePage () {
	char input;

    getCurrentDate(date, sizeof(date));

    while (1) {
        system("cls"); 
        displayUI(date, timeIn, timeOut, timeInAfternoon, timeOutAfternoon);
        
        printf("              -------------------    --------------------    -------------------    --------------------\n");
        printf("             | [ Q ] Mark In (M) |  | [ W ] Mark Out (M) |  | [ A ] Mark In (N) |  | [ S ] Mark Out (N) |\n");
        printf("              -------------------    --------------------    -------------------    --------------------\n");

        input = getchar();
		
        if (input == 'q') {
            getCurrentTime(timeIn, sizeof(timeIn)); // Update Time In (morning)
            while (getchar() != '\n');
        } else if (input == 'w') {
            getCurrentTime(timeOut, sizeof(timeOut));
            while (getchar() != '\n');
        } else if (input == 'a') {
            getCurrentTime(timeInAfternoon, sizeof(timeInAfternoon)); // Update Time In (afternoon)
            while (getchar() != '\n');
        } else if (input == 's') {
            getCurrentTime(timeOutAfternoon, sizeof(timeOutAfternoon));
            while (getchar() != '\n');
        } else if (input == '9') {
            profMenu();
            break;
        } 

    }
}

void mark_attendancePage () {
	char user;

    system("cls");
    printf("\n=====================================================================================================================\n");
    printf("*[ 9 ] back                                              Attendance                                                   *\n");
    printf("=====================================================================================================================\n\n");

    printf("\t\t\tEnter a student last name:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    if (scanf("%10s", studLname) == 9) {
    	profMenu();
	}
    printf("\t\t\t -----------------------------------------------------------\n\n");

    printf("\t\t\tEnter a student first name:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%10s", studName);
    printf("\t\t\t -----------------------------------------------------------\n\n");

    printf("\t\t\tEnter a Section:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%10s", studSection);
    printf("\t\t\t -----------------------------------------------------------\n\n");

    printf("\t\t\tEnter a Subject:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%15s", studSubject);
    printf("\t\t\t -----------------------------------------------------------\n\n");

    printf("\t\t\tDate today (e.g., 01/11/01):\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%15s", datetoDay);
    printf("\t\t\t -----------------------------------------------------------\n\n");

    printf("\t\t\tPresence Today:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t|         [ 1 ] Present  [ 2 ] Absent  [ 3 ] Excuse         |\n");
    printf("\t\t\t -----------------------------------------------------------\n");

    user = getch();

    switch (user) {
        case '1':
            strcpy(presence, "Present");
            goto attendance_table;
            break;
        case '2':
            strcpy(presence, "Absent");
            goto attendance_table;
            break;
        case '3':
        	strcpy(presence, "Excuse");
        	goto attendance_table;
            break;
        default:
            printf("\t\t\tInvalid selection, returning to login.\n");
            printf("\t\t\tPress any key to continue...");
    		getch();
            mark_attendancePage();
            break;
    }
    
attendance_table:
	char user2;
	system("cls");
    printf("\t -----------------------------------------------------------------------------------------------------------\n");
    printf("\t| [ 9 ] back                                      PHILTECH                                                  |\n");
    printf("\t|                                                ATTENDANCE                                                 |\n");
    printf("\t -----------------------------------------------------------------------------------------------------------\n");
    printf("\t|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("\t -----------------------------------------------------------------------------------------------------------\n");
    printf("\t|    LASTNAME     |    FIRSTNAME    |     SECTION     |     SUBJECT     |      DATE       |     REMARKS     |\n");
    printf("\t -----------------------------------------------------------------------------------------------------------\n");
	printf("\t| Caballero       | Jhavie          | %-15s | %-15s | %-15s | Present         |\n", studSection, studSubject, datetoDay);
    printf("\t -----------------------------------------------------------------------------------------------------------\n");
    printf("\t| Alcober         | Emmanuel        | %-15s | %-15s | %-15s | Present         |\n", studSection, studSubject, datetoDay);
    printf("\t -----------------------------------------------------------------------------------------------------------\n");
    printf("\t| Ignacio         | Cristine        | %-15s | %-15s | %-15s | Absent          |\n", studSection, studSubject, datetoDay);
    printf("\t -----------------------------------------------------------------------------------------------------------\n");
    printf("\t| Reyes           | Meljine         | %-15s | %-15s | %-15s | Absent          |\n", studSection, studSubject, datetoDay);
    printf("\t -----------------------------------------------------------------------------------------------------------\n");
    printf("\t| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", studLname, studName, studSection, studSubject, datetoDay, presence);
    printf("\t -----------------------------------------------------------------------------------------------------------\n");
    
    user2 = getch();
    
    if (user2 == 9) {
    	profMenu();
	}
}

void classroom_professorPage () {
	printf("This is Classroom Management Teacher Verison");
	system("pause");
}

// Professor menu
int profMenu() {
	
	char userprofMenu;
	while (1) {
	system("cls");
    printf("---------\n");
	printf("|       | Name: %s\n", userN);
	printf("| [ 9 ] | Position: Professor of Philtech\n");
	printf("|       | Major Subject: %s\n", profMajor);
	printf("---------\n");
    printf("\n=====================================================================================================================\n");
    printf("*                                              Professor Menu Page                                                  *\n");
    printf("=====================================================================================================================\n\n");
    
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t|              [ 1 ] About Us                             |\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t|              [ 2 ] Attendance                           |\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t|              [ 3 ] Mark Attendance                      |\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t|              [ 4 ] Classroom Management                 |\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t|              [ 0 ] Exit                                 |\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    
    userprofMenu = getch();

        switch (userprofMenu) {
            case '1':
                aboutusPage();
                break;
            case '2':
                prof_attendancePage();
                break;
            case '3':
                mark_attendancePage();
                break;
            case '4':
            	classroom_professorPage();
                break;
            case '9':
            	profile_detailsPage();
            	break;
            case '0':
                printf("Exiting Professor Menu...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                system("pause");
		}
	}
}
// End of Professor Menu Page ==================================================================
void profile_detailsPage2 () {
	char userProfile2;
	
	system("cls");
	printf("\n=====================================================================================================================\n");
    printf("*                                              Account Information                                                  *\n");
    printf("=====================================================================================================================\n");
    printf("[ 9 ] Back\n\n");
    
    printf("\t\t ------------------------------------      ------------------------------------\n");
    printf("\t\t| Firstname: %-23s |    | Lastname: %-24s |\n", firstN, lastN);
    printf("\t\t ------------------------------------      ------------------------------------\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Birthday: %-67s|\n", birthD);
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Username: %-67s|\n", userN);
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t ------------------------------------      ------------------------------------\n");
    printf("\t\t| Position: Student's of Philtech    |    | College Level: %-16s    |\n", userLevel);
    printf("\t\t ------------------------------------      ------------------------------------\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Email Address: %-62s|\n", email);
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Contact Number: %-61s|\n", contactN);
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Password: %-67s|\n", passW);
    printf("\t\t ------------------------------------------------------------------------------\n\n");
    
    printf("\t==============================================================================================\n");
    printf("\t|                [ 1 ] Change Email. [ 2 ] Edit Number. [ 3 ] Change Password.               |\n");
    printf("\t==============================================================================================\n\n");
    
    userProfile2 = getch();
    
    switch (userProfile2) {
    	case '1':
    		change_emailPage2();
    		break;
    	case '2':
    		edit_numberPage2();
    		break;
    	case '3':
    		change_passPage2();
    		break;
    	case '9':
    		studentMenu();
    		break;
    	default:
    		printf("\nInvalid Input!");
    		system("pause");
    		break;
	}
}

// Under edit student's profile details
void change_emailPage2 () {
	char loginPassW2[50];
	char emailInput[50];
	
	system("cls");
	changeAccountDisplay();
    printf("[ 9 ] Back\n\n");
	
	printf("\t\tEnter new email address:\n");
	printf("\t\t ------------------------------------------------------------------------------\n");
	printf("\t\t| Email: ");
    scanf(" %[^\n]s", emailInput);
    if (strcmp(emailInput, "9") == 0) {
        profile_detailsPage2();
    }
    strcpy(email, emailInput); // Stored the new email in the email variable
    
    printf("\t\t ------------------------------------------------------------------------------\n\n");
    printf("\t\tPassword for verification:\n");
	printf("\t\t ------------------------------------------------------------------------------\n");
	printf("\t\t| Password: ");
    scanf("%s", loginPassW2);
    printf("\t\t ------------------------------------------------------------------------------\n\n");
    
    if (strcmp(loginPassW2, passW) == 0) {
        printf("\t\tEmail updated successfully.\n\n");
    
		printf("\t\tPress any key to continue...");
    	getch();
		profile_detailsPage2();
    } else {
        printf("\t\t(System): Invalid password. Please try again.\n\n");
        printf("\t\tPress any key to continue...");
        getch();
        change_emailPage2();
    }
}

void edit_numberPage2 () {
	char loginPassW3[50];
	char contactInput[50];
	
	system("cls");
	changeAccountDisplay();
    printf("[ 9 ] Back\n\n");
	
    valid = 1; // Reset valid flag
    printf("\t\tEnter new Contact Number:\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Contact Number: ");
    scanf(" %[^\n]s", contactInput);

        if (strcmp(contactInput, "9") == 0) {
            profile_detailsPage2();
        }

        for (int i = 0; i < strlen(contactInput); i++) {
            if (!isdigit(contactInput[i])) { // Check if the character is not a digit
                valid = 0;
                printf("\n\n");
                printf("\t\tError: Contact number must contain only digits.\n\n");
                printf("\t\tPress any key to continue...");
        		getch();
        		edit_numberPage2();
                
            }
        }

    // Store the valid contact number
    strcpy(contactN, contactInput);
    
    printf("\t\t ------------------------------------------------------------------------------\n\n");
    printf("\t\tPassword for verification:\n");
	printf("\t\t ------------------------------------------------------------------------------\n");
	printf("\t\t| Password: ");
    scanf("%s", loginPassW3);
    printf("\t\t ------------------------------------------------------------------------------\n\n");
    
    if (strcmp(loginPassW3, passW) == 0) {
        printf("\t\tContact number updated successfully.\n\n");
    
		printf("\t\tPress any key to continue...");
    	getch();
		profile_detailsPage2();
    } else {
        printf("\t\t(System): Invalid password. Please try again.\n\n");
        printf("\t\tPress any key to continue...");
        getch();
        edit_numberPage2();
    }
}

void change_passPage2 () {
	char loginPassW4[50];
    char passwordInput[50];
    char confirmPassword[50];

    system("cls");
    changeAccountDisplay();
    printf("[ 9 ] Back\n\n");

    // Password for verification
    printf("\t\tEnter a current password:\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Password: ");
    scanf("%s", loginPassW4);
    
    if (strcmp(loginPassW4, "9") == 0) {
        profile_detailsPage2();
    }
    printf("\t\t ------------------------------------------------------------------------------\n\n");

    // Check if the entered current password is correct
    if (strcmp(loginPassW4, passW) != 0) {
        printf("\t\t(System): Invalid password. Please try again.\n\n");
        printf("\t\tPress any key to continue...");
        getch();
        change_passPage2();
    } 

    printf("\t\tEnter new password:\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Password: ");
    scanf(" %[^\n]s", passwordInput);  // Read the new password
    printf("\t\t ------------------------------------------------------------------------------\n\n");

    // Confirm new password
    printf("\t\tPlease confirm your new password:\n");
    printf("\t\t ------------------------------------------------------------------------------\n");
    printf("\t\t| Confirm Password: ");
    scanf(" %[^\n]s", confirmPassword);  // Get the confirmation password
    printf("\t\t ------------------------------------------------------------------------------\n\n");

    // Check if the new password and confirmation match
    if (strcmp(passwordInput, confirmPassword) != 0) {
        printf("\t\t(System): Passwords do not match. Please try again.\n\n");
        printf("\t\tPress any key to continue...");
        getch(); 
        change_passPage2();
    }

    strcpy(passW, passwordInput);
    printf("\t\tPassword updated successfully.\n\n");

    printf("\t\tPress any key to continue...");
    getch();
    profile_detailsPage2();
}

void enrollmentPage () {
	printf("This is Enrollment Page");
	system("pause");
}

void eog_requestPage() {
	int count = 0;
	char user, user2;
	
	system("cls");
	EOGdisplay();
	printf("\t\t\tSTUDENT INFORMATION\n\n");
	
	printf("\t\t\tEnter Lastname:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", eogLname);
    printf("\t\t\t -----------------------------------------------------------\n\n");

    printf("\t\t\tEnter Firstname:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", eogFname);
    printf("\t\t\t -----------------------------------------------------------\n\n");

    printf("\t\t\tEnter Student ID No.:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", eogSID);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    // to combined two variable into 1 varible value
    // basic explanation the last and first name combined into fullname
    strcat(eogFullname, eogLname);
    strcat(eogFullname, ", ");
    strcat(eogFullname, eogFname);

student_information:
	system("cls");
	EOGdisplay();
	printf("\t\t\tSTUDENT INFORMATION\n\n");
	printf("\t\t\tEnter Section:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", eogSection);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    printf("\t\t\tEnter Year level:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf(" %[^\n]", eogLevel);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    printf("\t\t\tWhat's your course':\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| [ 1 ] Bachelor of Science in Computer Science             |\n");
    printf("\t\t\t| [ 2 ] Bachelor of Science in Office Administration        |\n");
    printf("\t\t\t| [ 3 ] Bachelor of Tech-Voc Teacher Education              |\n");
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    user2 = getch();
    
    switch (user2) {
    	case '1':
    		strcpy(eogCourse, "BSCS");
    		goto subject_details;
    		break;
    	case '2':
    		strcpy(eogCourse, "BSOA");
    		goto subject_details;
    		break;
    	case '3':
    		strcpy(eogCourse, "BTVTED");
    		goto subject_details;
    		break;
    	default:
    		printf("\t\t\tInvalid Input\n");
    		goto student_information;
    		break;
	}
    
subject_details:
    system("cls");
    EOGdisplay();
    printf("\t\t\tSTUDENT INFORMATION\n\n");
    
    printf("\t\t\tEnter S.Y. (Ex: 1999-2000):\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf(" %[^\n]", eogSY);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    printf("\t\t\tChoose Semester/Term:\n");
    printf("\t\t\t --------------------------     ----------------------------\n");
    printf("\t\t\t|       1st Semester       |   |        2nd Semester        |\n");
    printf("\t\t\t --------------------------     ----------------------------\n\n");
    
    user = getch();
    
    switch (user) {
    	case '1':
    		system("cls");
    		EOGdisplay();
    		strcpy(reqSemester, "FIRST SEMESTER GRADES");
    		printf("\n");
    		printf("\t\t\tReason for Evaluation request:\n");
    		printf("\t\t\t -----------------------------------------------------------\n");
    		printf("\t\t\t| ");
    		scanf(" %[^\n]", eogReason);
    		printf("\t\t\t -----------------------------------------------------------\n\n");
    		goto Submmiting_Request;
    		break;
    	case '2':
    		system("cls");
    		EOGdisplay();
    		printf("\n");
    		strcpy(reqSemester, "SECOND SEMESTER GRADES");
    		printf("\t\t\tReason for Evaluation request:\n");
    		printf("\t\t\t -----------------------------------------------------------\n");
    		printf("\t\t\t| ");
    		scanf(" %[^\n]", eogReason2);
    		printf("\t\t\t -----------------------------------------------------------\n\n");
    		goto Submmiting_Request;
    	default:
    		printf("\t\t\tInvalid Input choices\n");
    		printf("\t\t\tPress any key to continue...");
    		getch();
    		goto subject_details;
    		
Submmiting_Request: // Loading bar for submmiting Process
    	while (count < 20) {
        printf("\r\t\t\tSubmmiting Request");

        int dots = count % 4; // 0 to 3
        for (int i = 0; i < dots; i++) {
            printf("."); 
        }

        for (int i = dots; i < 3; i++) {
            printf(" ");
        }

        fflush(stdout);
        usleep(300000);

        count++;
    	}
    	
    	goto Process_loading;
	}
	
Process_loading:
		char symbols[] = { '|', '/', '-', '\\' };
    	int progress = 0;
    	
    	system("cls");
    	while (progress <= 100) {
    		gotoxy(50, 15);
        	printf("\r\t\t\t\tProcessing Request: %3d%% [", progress);
        
        	for (int i = 0; i < 20; i++) {
        	    if (i < progress / 5) {
            	    printf("#");
           	 } else {
            	    printf(" ");
           	 }
        	}

        	printf("] %c", symbols[progress % 4]);
        	fflush(stdout);
        
        	progress += 5;

        	usleep(200000);
    	}
    	printf("\nDone!\n");
    	
    	if (strcmp(eogCourse, "BSCS") == 0) {
    		goto BSCS_EOG_receipt;
		} else if (strcmp(eogCourse, "BSOA") == 0) {
			goto BSOA_EOG_receipt;
		} else if (strcmp(eogCourse, "BTVTED") == 0) {
			goto BTVTED_EOG_receipt;
		}
	
BSCS_EOG_receipt:
	char userbck;
	
	system("cls");
	printf("[ 9 ] back\n");
	printf("                                     %s\n", reqSemester);
	printf("                                        S.Y. %s\n", eogSY);
	printf(" -----------------------------------------------------------------------------------------------\n");
    printf("| Student Name: %-24s                    Student ID: %-14s          |\n", eogFullname, eogSID);
    printf("| Course: %-37s             Section: %-12s               |\n", eogCourse, eogSection);
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|  SUBJECT  |           SUBJECT           |   PROFESSOR'S   | PRE | MID |SEMI-|FINAL|  REMARKS  |\n");
    printf("|   CODE    |         DESCRIPTION         |      NAME       | LIM | TERM|FINAL|     |           |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   GE123   | Understanding the Self      | Mr.Vele         | 84  | 86  | 88  | 90  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   GE113   | Mathematics in Modern world | Mr.Rodriguez    | 88  | 90  | 92  | 94  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   CC123   | Introduction to Computing   | Mr.Gordon       | 82  | 84  | 86  | 88  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   CC114   | Fundamentals of programming | Mr.Jiminez      | 86  | 88  | 90  | 92  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   AS123   | Philtech Life and Spirit    | Mr.Atienza      | 85  | 87  | 89  | 91  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   GE124   | Readings in the PH History  | Mr.Nori         | 89  | 91  | 93  | 95  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   PE123   | Physical Fitness            | Mr.Atienza      | 87  | 89  | 91  | 93  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|  NSTP123  | National Service Training   | Mr.Atienza      | 86  | 88  | 90  | 92  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|                                                                AVERAGE|   89.7    |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    
    userbck = getch();
    
    switch (userbck) {
    	case '9':
    		studentMenu();
    		break;
    	default:
    		goto BSCS_EOG_receipt;
    		break;
	}
	
BSOA_EOG_receipt:
	char userbck2;
	
	system("cls");
	printf("[ 9 ] back\n");
	printf("                                     %s\n", reqSemester);
	printf("                                        S.Y. %s\n", eogSY);
	printf(" -----------------------------------------------------------------------------------------------\n");
    printf("| Student Name: %-24s                    Student ID: %-14s          |\n", eogFullname, eogSID);
    printf("| Course: %-37s             Section: %-12s               |\n", eogCourse, eogSection);
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|  SUBJECT  |           SUBJECT           |   PROFESSOR'S   | PRE | MID |SEMI-|FINAL|  REMARKS  |\n");
    printf("|   CODE    |         DESCRIPTION         |      NAME       | LIM | TERM|FINAL|     |           |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|  FIL123   | Komunikasyon sa Filipino    | Ms.Yabut        | 87  | 90  | 92  | 95  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   GE123   | Understanding the Self      | Mr.Vele         | 91  | 93  | 95  | 98  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   GE113   | Mathematics in Modern world | Mr.Rodriguez    | 86  | 88  | 90  | 93  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|  OACC123  | Foundations of Shorthand    | Mr.Macario      | 89  | 91  | 93  | 96  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|  OACC124  | Keyboard and Document       | Mr.Macario      | 88  | 90  | 92  | 94  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   AS123   | Philtech Life and Spirit    | Mr.Atienza      | 92  | 94  | 96  | 99  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   PE123   | Physical Fitness            | Mr.Atienza      | 90  | 92  | 94  | 97  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|  NSTP123  | National Service Training   | Mr.Atienza      | 89  | 91  | 93  | 96  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|                                                                AVERAGE|   94.8    |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    
    userbck = getch();
    
    switch (userbck2) {
    	case '9':
    		studentMenu();
    		break;
    	default:
    		goto BSOA_EOG_receipt;
    		break;
	}
	
BTVTED_EOG_receipt:
	char userbck3;
	
	system("cls");
	printf("[ 9 ] back\n");
	printf("                                     %s\n", reqSemester);
	printf("                                        S.Y. %s\n", eogSY);
	printf(" -----------------------------------------------------------------------------------------------\n");
    printf("| Student Name: %-24s                    Student ID: %-14s          |\n", eogFullname, eogSID);
    printf("| Course: %-37s             Section: %-12s               |\n", eogCourse, eogSection);
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|  SUBJECT  |           SUBJECT           |   PROFESSOR'S   | PRE | MID |SEMI-|FINAL|  REMARKS  |\n");
    printf("|   CODE    |         DESCRIPTION         |      NAME       | LIM | TERM|FINAL|     |           |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|  FCC123   | The Teaching Profession     | Mr.Rosales      | 90  | 92  | 93  | 94  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|  TLE123   | Home Economics Literacy     | Ms.Tesoro       | 93  | 94  | 95  | 96  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   GE123   | Purposive Communication     | Ms.Arceño       | 89  | 91  | 92  | 93  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   GE124   | Readings in the PH History  | Mr.Nori         | 91  | 93  | 94  | 95  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   GE113   | Mathematics in Modern world | Mr.Rodriguez    | 90  | 92  | 93  | 94  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   PLS12   | Philtech Life and Spirit    | Mr.Atienza      | 94  | 95  | 96  | 97  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|   PE123   | Physical Fitness            | Mr.Atienza      | 92  | 93  | 94  | 95  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|  NSTP123  | National Service Training   | Mr.Atienza      | 91  | 92  | 93  | 94  |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    printf("|                                                                AVERAGE|   92.8    |  PASSED   |\n");
    printf(" -----------------------------------------------------------------------------------------------\n");
    
    userbck = getch();
    
    switch (userbck3) {
    	case '9':
    		studentMenu();
    		break;
    	default:
    		goto BTVTED_EOG_receipt;
    		break;
	}
}

void classroom_studentPage () {
	printf("This is Classroom management Page");
	system("pause");
}

// Student menu
int studentMenu() {
	char userstudMenu;
	
	while (1) {
    system("cls");
    printf("---------\n");
	printf("|       | Name: %s\n", userN);
	printf("| [ 9 ] | Position: Student of Philtech\n");
	printf("|       | College Level: %s\n", userLevel);
	printf("---------\n");
    printf("\n=====================================================================================================================\n");
    printf("*                                                Student Menu Page                                                  *\n");
    printf("=====================================================================================================================\n\n");
    
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t|              [ 1 ] About Us                             |\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t|              [ 2 ] Enrollment                           |\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t|              [ 3 ] Submit EOG Request                   |\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t|              [ 4 ] Classroom Management                 |\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t|              [ 0 ] Exit                                 |\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    
    userstudMenu = getch();

        switch (userstudMenu) {
            case '1':
                aboutusPage();
                break;
            case '2':
                enrollmentPage ();
                break;
            case '3':
                eog_requestPage();
                break;
            case '4':
            	classroom_studentPage();
            	break;
            case '9':
            	profile_detailsPage2();
            	break;
            case '0':
                printf("Exiting Student Menu...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                system("pause");
		}
	}
}
