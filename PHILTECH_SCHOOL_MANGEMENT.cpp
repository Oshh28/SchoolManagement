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

// Storage for enrollment
char enrollStatus[50] = "Select Applicant Type";
char enrollProgram[50] = "Select Program or Course";
char enrollLastname[50];
char enrollGender[50];
char enrollBirth[50];
char enrollContact[50];
char enrollEmail[50];
char enrollAddress[50];
char enrollPayment[50];

// Storage data for section student names
char lastname[20][20] = {"IGNACIO", "CRUZ", "MENDOZA", "RIVERA", "PEREZ", "LOPEZ", "CASTILLO", "SANTOS", "FERRER", "FRANCISCO", "VILLANUEVA", "MARQUEZ", "HERNANDEZ", "ESPIRITO", "BAUTISTA", "AQUINO", "SALVADOR", "DELA CRUZ", "RAMOS", "GARCIA"};
char firstname[20][20] = {"CRISTINE", "ALISHA", "EASON", "DAVE", "ANGELO", "NICELY", "ATREUS", "SUNNY", "MIRA", "ELLIANA", "TESSA", "LENA", "MILANA", "JETT", "JONES", "MAEVE", "SAYLOR", "SAGE", "PALMER", "JAY"};
char remarks[20][10] = {"N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A"};
int current = 0;

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

char markSection [15];
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

void Stud_Classroom_display () {
	printf("+----------------------------------------------------------------------------------------------------------------------+\n");
	printf("|                                               CLASSROOM MANAGEMENT                                                   |\n");
	printf("+----------------------------------------------------------------------------------------------------------------------+\n");
}
void payment_display () {
	int showOptions2 = 0;
	int showOptions3 = 0;
	printf("Admission Portal\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                * --------------------- * ------------- * ----------- /                               |\n");
        printf("|                       Application Details     Applicant Profile     Payment     Confirmation                         |\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n\n");
        
        printf("                                                  Payment Process\n\n");
        
        printf("             The Total fee for your chosen program [1] ^\n");
        
        if (showOptions2) {
        	printf("              +---------------------------+-----------------+\n");
	    	printf("              |   ASSESESSMENT OF FEES    |      CASH       |\n");
	    	printf("              +---------------------------+-----------------+\n");
	    	printf("              |   No. of Unit             |              22 |\n");
	    	printf("              |   Amount per Unit         |          400.00 |\n");
	    	printf("              +---------------------------+-----------------+\n");
	    	printf("              |       Tuition Fee         |        8.800.00 |\n");
	    	printf("              +---------------------------+-----------------+\n");
		}
	    
	    printf("\n             Preferred payment method:\n");
        printf("              ----------------------------------------------\n");
        printf("             | %-38s [2] ^ |\n", enrollPayment);
        printf("              ----------------------------------------------\n");
        
        if (showOptions3) {
        	printf("              ----------------------------------------------\n");
        	printf("             |  [ z ] Credit Card                           |\n");
        	printf("             |  [ x ] Bank Transfer                         |\n");
       		printf("             |  [ c ] Gcash                                 |\n");
        	printf("             |  [ v ] Paymaya                               |\n");
       	    printf("              ----------------------------------------------\n");
        }
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
while (1) {
	char user1;
	system("cls");
	printf(" +---+-------------------------------------------------+(----)+---------------------------------------------------+---+\n");
    printf("|| .| [ 9 ] back                                       |  ||  |                                                   |.  |\n");
    printf("|  .|--------------------------------------------------|  ||  |---------------------------------------------------|.| |\n");
    printf("| |.| 1. BRIEF HISTORY OF PHILTECH                     |  ||  |  Educational Services                             |.| |\n");
    printf("| |.|                                                  |  ||  |                                                   |.  |\n");
    printf("|  .| Philippine Technological Institute of Science    |  ||  |  Additional programs accredited by the Technical  || ||\n");
    printf("| |.| Arts and Trade Inc. was founded in 2010 as a     |  ||  |  Education and Skills Development Authority -     |. ||\n");
    printf("|| .| non-stock non-profit non-sectarian private       |  ||  |  Rizal. The first batch of graduates marched      |.| |\n");
    printf("| |.| Educational Institution to blaze the trail in    |  ||  |  onto their commencement exercises on April 5,    |.| |\n");
    printf("|  .| the field of technical education. Its eleven     |  ||  |  2013 with no less than the TESDA Rizal           |.  |\n");
    printf("| |.| founders were a mixture of engineers, a          |  ||  |  Provincial Office Director Velma A. Salazar as   |.| |\n");
    printf("| |.| scientist/inventor and practitioner in the IT    |  ||  |  their graduation guest of honor.                 |. ||\n");
    printf("|  .| industry, school administrators, managers, and   |  ||  |                                                   |. ||\n");
    printf("|  || academic professionals in both public and        |  ||  |  By November of 2012, the negotiation for         |.  |\n");
    printf("|  || private institutions. Today, the school is more  |  ||  |  additional branches went underway. The Board of  |.  |\n");
    printf("|| .| popularly known as PHILTECH.                     |  ||  |  Trustees resolved that two new PHILTECH branches |.| |\n");
    printf("|  .|                                                  |  ||  |  should be established and operated in Sta. Rosa, |.| |\n");
    printf("| |.| The first school was established in November     |  ||  |  Laguna and General Mariano Alvarez, Cavite.      |.  |\n");
    printf("| |.| of 2010 and is presently located at F.T.         |  ||  |  Both branches opened in the first semester of    |. ||\n");
    printf("|| .| Catapusan St. in Tanay, Rizal. In June 2011,     |  ||  |  school year 2013-2014.                           |.| |\n");
    printf("|  .| Philippine Technological Institute of Science    |  ||  |                                                   |.| |\n");
    printf("|  .| Arts and Trade Inc. opened and offered two-year  |  ||  |  With Tanay (560 students), Sta. Rosa branch (350 |.  |\n");
    printf("|| .| programs in Information technology, hotel and    |  ||  |  students), and GMA branch (250 students), school |.| |\n");
    printf("| |.| restaurant services, and business outsourcing    |  ||  |  year 2013-2014 totaled at least 1160 students.   |. ||\n");
    printf("|  .| management.                                      |  ||  |                                                   |.  |\n");
    printf("| |.|                                                  |  ||  |  PHILTECH never tires from helping our Filipino   |.  |\n");
    printf("| |.| With every member of the Board of Trustees       |  ||  |  youth. It is patriotic. As educators, it is      || ||\n");
    printf("|  .| going out of their way to promote the school     |  ||  |  always fulfilling to mold young minds into       ||  |\n");
    printf("|| .| and its program offerings, the first semester    |  ||  |  productive citizens. Indeed, it is always a      |.  |\n");
    printf("| |.| of school year 2011-2012 continued to provide    |  ||  |  blessing.                                        |.| |\n");
    printf("|| .| the same.                                        |  ||  |                                                   |.| |\n");
    printf("|   +--------------------------------------------------+(----)+---------------------------------------------------+   |\n");
    printf("[__-___--__--____-----______---_________--------___________--________--___---______------____--____----____--__--___-_]");
    
    user1 = getch();
    if (user1 == '9') {
    	if (strcmp(roleChoice, "Professor") == 0) {
    		profMenu();
		} else if (strcmp(roleChoice, "Student") == 0) {
			studentMenu();
		}   
	}
}
    
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
	while (1) {
		system("cls");
        printf("     +-----------------------------------------------------------------------+\n");
        printf("     |                             ATTENDANCE                                |\n");
        printf("     |                            COURSE: BSCS                               |\n");
        printf("     +-----------------------------------------------------------------------+\n");
        printf("     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
        printf("     +-----------------------------------------------------------------------+\n");
        printf("     |     |    LASTNAME     |    FIRSTNAME    | M.I |        REMARKS        |\n");
        printf("     +-----------------------------------------------------------------------+\n");
        
        for (int i = 0; i < 20; i++) {
            printf("     | %2d  |  %-12s   |   %-12s  |  %c  |     %8s          |\n", 
                i + 1, lastname[i], firstname[i], lastname[i][0], remarks[i]);
            printf("     +-----------------------------------------------------------------------+\n");
        }
        
        // only mark if current student is N/A
        if (strcmp(remarks[current], "N/A") == 0) {
            printf("\nMarking attendance for %s %s\n", firstname[current], lastname[current]);
            printf("Press P for Present, A for Absent, E for Excused\n");
        
            char choice = getch();
            choice = toupper(choice);
        
            if (choice == 'P') strcpy(remarks[current], "Present");
            else if (choice == 'A') strcpy(remarks[current], "Absent");
            else if (choice == 'E') strcpy(remarks[current], "Excused");
        
            // Move to next N/A student
            do {
               current = (current + 1) % 20;
            } while (strcmp(remarks[current], "N/A") != 0);
        }
	}
}

void classroom_professorPage () {
Classroom_Management:
	char classUser;
	system("cls");
	Stud_Classroom_display ();
	printf("[ 9 ] back\n");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t ---------------------------------------\n");
	printf("\t\t\t\t\t|        [ 1 ] Weekly Schedule          |\n");
	printf("\t\t\t\t\t ---------------------------------------\n");
	printf("\t\t\t\t\t ---------------------------------------\n");
	printf("\t\t\t\t\t|        [ 2 ] Mark Attendance          |\n");
	printf("\t\t\t\t\t ---------------------------------------\n");
	printf("\t\t\t\t\t ---------------------------------------\n");
	printf("\t\t\t\t\t|        [ 3 ] Campus Map               |\n");
	printf("\t\t\t\t\t ---------------------------------------\n");
	
	classUser = getch();
	
	switch (classUser) {
		case '1':
			goto Weekly_Schedule;
			break;
		case '2':
			goto Mark_Attendance;
			break;
		case '9':
			profMenu();
			break;
		default:
			goto Classroom_Management;
		    break;
	}
	
Weekly_Schedule:
	system("cls");
	Stud_Classroom_display ();
	printf("To be Announce\n");
	
Mark_Attendance:
	system("cls");
	Stud_Classroom_display ();
	printf("             Enter Specific Section:\n");
    printf("              ------------------------------------------------------------------------------------------\n");
    printf("             |                                                                                          |\n");
    printf("              ------------------------------------------------------------------------------------------\n");
        
    printf("\033[2A\033[15C");
    scanf(" %[^\n]", markSection);
    
    while (1) {
		system("cls");
		char user1;
		Stud_Classroom_display ();
        printf("     +-----------------------------------------------------------------------+\n");
        printf("     |                             ATTENDANCE                     [ 9 ] back |\n");
        printf("     |                          SECTION: %-35s |\n", markSection);
        printf("     +-----------------------------------------------------------------------+\n");
        printf("     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
        printf("     +-----------------------------------------------------------------------+\n");
        printf("     |     |    LASTNAME     |    FIRSTNAME    | M.I |        REMARKS        |\n");
        printf("     +-----------------------------------------------------------------------+\n");
        
        for (int i = 0; i < 20; i++) {
            printf("     | %2d  |  %-12s   |   %-12s  |  %c  |     %8s          |\n", 
                i + 1, lastname[i], firstname[i], lastname[i][0], remarks[i]);
            printf("     +-----------------------------------------------------------------------+\n");
        }
        
        // only mark if current student is N/A
        if (strcmp(remarks[current], "N/A") == 0) {
            printf("\nMarking attendance for %s %s\n", firstname[current], lastname[current]);
            printf("Press P for Present, A for Absent, E for Excused\n");
        
            char choice = getch();
            choice = toupper(choice);
        
            if (choice == 'P') strcpy(remarks[current], "Present");
            else if (choice == 'A') strcpy(remarks[current], "Absent");
            else if (choice == 'E') strcpy(remarks[current], "Excused");
        
            // Move to next N/A student
            do {
               current = (current + 1) % 20;
            } while (strcmp(remarks[current], "N/A") != 0);
        }
        
        user1 = getch();
        
        if (user1 == '9') {
        	goto Classroom_Management;
		}
	}
	
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
    printf("\t\t\t|              [ 3 ] Classroom Management                 |\n");
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
	Welcome_view:
	char userStart;
	system("cls");
    printf("+----------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                           PHILTECH ONLINE ENROLLMENT                                                 |\n");
    printf("+----------------------------------------------------------------------------------------------------------------------+\n");
    printf("                                                                                                         [ 9 ] back\n");
    printf("\n");
    printf("               We're excited to have you join us! Please follow the steps below to complete your enrollment\n");
    printf("               process. It only takes a few minutes.\n\n\n");
    
    printf("                                    Steps Overview:\n\n");
    printf("                                       > Select your program or course.\n");
    printf("                                       > Fill out your personal information.\n");
    printf("                                       > Confirm and pay your enrollment fee.\n");
    printf("                                       > Receive your confirmation.\n\n\n");
    
    printf("                                              ------------------------\n");
    printf("                                             | [1] Start Enrollment   |\n");
    printf("                                              ------------------------\n");
    
    userStart = getch();
    system("cls");
    switch (userStart) {
    	case '1':
    		goto Application_view;
    		break;
    	case '9':
    		studentMenu();
    		break;
	}
    
Application_view:
    char chooseStatus;
    char user1;
    int showOptions = 0;
    int showOptions1 = 0;
    
    while (1) {
        system("cls");
        printf("Admission Portal\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                * --------------------- / ------------- / ----------- /                               |\n");
        printf("|                       Application Details     Applicant Profile     Payment     Confirmation                         |\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n\n");
        
        printf("                                                Application Details\n\n");
        
        printf("             Type of applicant:\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        printf("             | %-82s [1] ^ |\n", enrollStatus);
        printf("              ------------------------------------------------------------------------------------------\n");
        
        // Applicant Type Dropdown
        if (showOptions) {
            printf("              ------------------------------------------------------------------------------------------\n");
            printf("             |  [ q ] New Applicant                                                                     |\n");
            printf("             |  [ w ] Old Applicant                                                                     |\n");
            printf("             |  [ e ] Transferee                                                                        |\n");
            printf("             |  [ r ] Old Curriculum/ALS                                                                |\n");
            printf("              ------------------------------------------------------------------------------------------\n");
        }

        printf("\n             Preferred program:\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        printf("             | %-82s [2] ^ |\n", enrollProgram);
        printf("              ------------------------------------------------------------------------------------------\n");
        
        // Program Dropdown
        if (showOptions1) {
            printf("              ------------------------------------------------------------------------------------------\n");
            printf("             |  [ a ] BS Computer Science                                                               |\n");
            printf("             |  [ s ] BS Office Administration                                                          |\n");
            printf("             |  [ d ] BTVTED Major in Food Service Management                                           |\n");
            printf("              ------------------------------------------------------------------------------------------\n");
        }
        
        printf("\n\n\n");
        printf("                                                                -----------------      -----------------\n");
        printf("                                                               |    [n] Next     |    |    [b] Back     |\n");
        printf("                                                                -----------------      -----------------\n");
        
        chooseStatus = getch();
        
        // Applicant Type Handling
        if (chooseStatus == '1') {
            showOptions = !showOptions;
            showOptions1 = 0;  // Close other dropdown
        }
        else if (chooseStatus == '2') {
            showOptions1 = !showOptions1;
            showOptions = 0;  // Close other dropdown
        }
        else if (chooseStatus == 'n') {
            goto Applicant_Profile;
        }
        else if (chooseStatus == 'b') {
            goto Welcome_view;
        }
        
        // Handle Applicant Type selections
        if (showOptions) {
            switch (chooseStatus) {
                case 'q':
                    strcpy(enrollStatus, "New Applicant");
                    showOptions = 0;
                    break;
                case 'w':
                    strcpy(enrollStatus, "Old Applicant");
                    showOptions = 0;
                    break;
                case 'e':
                    strcpy(enrollStatus, "Transferee");
                    showOptions = 0;
                    break;
                case 'r':
                    strcpy(enrollStatus, "Old Curriculum/ALS");
                    showOptions = 0;
                    break;
            }
        }

        // Handle Program selections
        if (showOptions1) {
            switch (chooseStatus) {
                case 'a':
                    strcpy(enrollProgram, "BS Computer Science");
                    showOptions1 = 0;
                    break;
                case 's':
                    strcpy(enrollProgram, "BS Office Administration");
                    showOptions1 = 0;
                    break;
                case 'd':
                    strcpy(enrollProgram, "BTVTED Major in Food Service Management");
                    showOptions1 = 0;
                    break;
            }
        }
    }
    	
Applicant_Profile:
    while (1) {  
    system("cls");
        printf("Admission Portal\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                * --------------------- * ------------- / ----------- /                               |\n");
        printf("|                       Application Details     Applicant Profile     Payment     Confirmation                         |\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n\n");
        
        printf("                                                  Applicant Profile\n\n");
        
        printf("             Given Full Name:\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        printf("             |                                                                                          |\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        
        printf("\033[2A\033[15C");
        scanf(" %[^\n]", enrollLastname);
        
        printf("\n\n             Sex at birth:\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        printf("             |                                                                                          |\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        
        printf("\033[2A\033[15C");
        scanf(" %[^\n]", enrollGender);
        
        printf("\n\n             Date of birth:\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        printf("             |                                                                                          |\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        
        printf("\033[2A\033[15C");
        scanf(" %[^\n]", enrollBirth);
        
        system("cls");
        printf("Admission Portal\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                * --------------------- * ------------- / ----------- /                               |\n");
        printf("|                       Application Details     Applicant Profile     Payment     Confirmation                         |\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n\n");
        
        printf("                                                  Applicant Profile\n\n");
        
        printf("             Email Address:\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        printf("             |                                                                                          |\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        
        printf("\033[2A\033[15C");
        scanf(" %[^\n]", enrollEmail);
        
        printf("\n\n             Contact Number:\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        printf("             |                                                                                          |\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        
        printf("\033[2A\033[15C");
        scanf(" %[^\n]", enrollContact);
        
      
        printf("\n\n             Home Address:\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        printf("             |                                                                                          |\n");
        printf("              ------------------------------------------------------------------------------------------\n");
        
        printf("\033[2A\033[15C");
        scanf(" %[^\n]", enrollAddress);
        
        printf("\n\n\n");
        printf("                                                                -----------------      -----------------\n");
        printf("                                                               |    [n] Next     |    |    [b] Back     |\n");
        printf("                                                                -----------------      -----------------\n");
        
        user1 = getch();
        
        switch (user1) {
        	case 'n':
        		goto Payment_Process;
        		break;
        	case 'b':
        		goto Application_view;
        		break;
		}
	}
	
Payment_Process:
	char chooseStatus1;
	int showOptions2 = 0;
	int showOptions3 = 0;
	while (1) { 
	    system("cls");
        printf("Admission Portal\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                * --------------------- * ------------- * ----------- /                               |\n");
        printf("|                       Application Details     Applicant Profile     Payment     Confirmation                         |\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n\n");
        
        printf("                                                  Payment Process\n\n");
        
        printf("             The Total fee for your chosen program [3] ^\n");
        
        if (showOptions2) {
        	printf("              +---------------------------+-----------------+\n");
	    	printf("              |   ASSESESSMENT OF FEES    |      CASH       |\n");
	    	printf("              +---------------------------+-----------------+\n");
	    	printf("              |   No. of Unit             |              22 |\n");
	    	printf("              |   Amount per Unit         |          400.00 |\n");
	    	printf("              +---------------------------+-----------------+\n");
	    	printf("              |       Tuition Fee         |        8.800.00 |\n");
	    	printf("              +---------------------------+-----------------+\n");
		}
	    
	    printf("\n             Preferred payment method:\n");
        printf("              ----------------------------------------------\n");
        printf("             | %-38s [4] ^ |\n", enrollPayment);
        printf("              ----------------------------------------------\n");
        
        if (showOptions3) {
        	printf("              ----------------------------------------------\n");
        	printf("             |  [ z ] Credit Card                           |\n");
        	printf("             |  [ x ] Bank Transfer                         |\n");
       		printf("             |  [ c ] Gcash                                 |\n");
        	printf("             |  [ v ] Paymaya                               |\n");
       	    printf("              ----------------------------------------------\n");
        }
        
        if (strlen(enrollPayment) > 0) {
        float tuitionFee = 8800.00;
        float enteredAmount;
        do {
            printf("\n             Enter payment amount:\n");
            printf("              ----------------------------------------------\n");
            printf("             |                                              |\n");
            printf("              ----------------------------------------------\n");
            
            printf("\033[2A\033[15C");
        	scanf(" %f", &enteredAmount);
            
            if (enteredAmount != tuitionFee) {
                printf("\n\n              Error: Please enter the exact amount of %.2f\n", tuitionFee);
                printf("              Press any key to try again...");
                getch();
                system("cls");
                payment_display();
            } else if (enteredAmount == tuitionFee) {
            	goto Process_loading;
			}
        } while (enteredAmount != tuitionFee);
    }
        
        chooseStatus1 = getch();
        
        if (chooseStatus1 == '3') {
            showOptions2 = !showOptions2;
            showOptions3 = 0;
            continue;
        }
        
        if (chooseStatus1 == '4') {
            showOptions3 = !showOptions3;
            showOptions2 = 0;
            continue;
        }
        
        if (showOptions3) {
            switch (chooseStatus1) {
                case 'z':
                    strcpy(enrollPayment, "Credit Card");
                    showOptions3 = 0;
                    break;
                case 'x':
                    strcpy(enrollPayment, "Bank Transfer");
                    showOptions3 = 0;
                    break;
                case 'c':
                    strcpy(enrollPayment, "Gcash");
                    showOptions3 = 0;
                    break;
                case 'v':
                    strcpy(enrollPayment, "Paymaya");
                    showOptions3 = 0;
                    break;
            }
    	}
	}
	
Process_loading:
		char symbols[] = { '|', '/', '-', '\\' };
    	int progress = 0;
    	
    	system("cls");
    	while (progress <= 100) {
    		gotoxy(50, 15);
        	printf("\r\t\t\t\tProcessing Payment: %3d%% [", progress);
        
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
    	
Confirmation_receipt:
	char user2;
	while (1) {  
		system("cls");
        printf("Admission Portal\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                * --------------------- * ------------- * ----------- *                               |\n");
        printf("|                       Application Details     Applicant Profile     Payment     Confirmation                         |\n");
        printf("+----------------------------------------------------------------------------------------------------------------------+\n\n");
        
        printf("                                                    Confirmation\n\n");
        
        printf("   Congratulations, %s\n\n", enrollLastname);
        
        printf("              You've successfully enrolled in %s. Your journey begins here!\n\n", enrollProgram);
        printf("              Next Steps:\n");
        printf("                   > Pass your requirements and documents in Philtech office.\n");
        printf("                   > PhilTech GMA, located in Brgy. Gavino Maderan, GMA, Cavite.\n");
        printf("                   > Office available 8AM to 5PM, Monday to Friday\n\n");
        
        printf("                       +--------------------------------------------+\n");
        printf("                       |             ENROLLMENT SUMMARY             |\n");
        printf("                       +--------------------------------------------+\n");
        printf("                       | Applicant Type: %-26s |\n", enrollStatus);
        printf("                       | Program: %-33s |\n", enrollProgram);
        printf("                       | Name: %-36s |\n", enrollLastname);
        printf("                       | Gender: %-34s |\n", enrollGender);
        printf("                       | Birth Date: %-30s |\n", enrollBirth);
        printf("                       | Email: %-35s |\n", enrollContact);
        printf("                       | Contact: %-33s |\n", enrollEmail);
        printf("                       | Address: %-33s |\n", enrollAddress);
        printf("                       | Payment method: %-26s |\n", enrollPayment);
        printf("                       +--------------------------------------------+\n");
        printf("                       | Your Reference Number: #X9A2B7C3D4         |\n");
        printf("                       +--------------------------------------------+\n\n\n");
        
        printf("                                    ---------------------\n");
        printf("                                   | [9] Go to Dashboard |\n");
        printf("                                    ---------------------\n");
        
        user2 = getch();
        if (user2 == '9') {
        	studentMenu();
		}
	}
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
	
	if (strcmp(enrollProgram, "Select Program or Course") == 0) {
        goto welcome;
    } else {
        goto Classroom_Management;
    }
    
welcome:
	system("cls");
	Stud_Classroom_display ();
	
	printf("\n\n\n\n\n\n\n\n");
	printf("                                 +----------------------------------------------+\n");
	printf("                                 |        You are not currently enrolled.       |\n");
	printf("                                 +----------------------------------------------+\n");
    printf("                                 Press any key to back student dashboard...");
    getch();
    studentMenu();
	system("pause");
	
Classroom_Management:
	char classUser;
	system("cls");
	printf("[ 9 ] back\n");
	Stud_Classroom_display ();
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t ---------------------------------------\n");
	printf("\t\t\t\t\t|        [ 1 ] Weekly Schedule          |\n");
	printf("\t\t\t\t\t ---------------------------------------\n");
	printf("\t\t\t\t\t ---------------------------------------\n");
	printf("\t\t\t\t\t|        [ 2 ] Enrolled Subjects        |\n");
	printf("\t\t\t\t\t ---------------------------------------\n");
	printf("\t\t\t\t\t ---------------------------------------\n");
	printf("\t\t\t\t\t|        [ 3 ] Campus Map               |\n");
	printf("\t\t\t\t\t ---------------------------------------\n");
	
	classUser = getch();
	
	switch (classUser) {
		case '1':
			if (strcmp(enrollProgram, "BS Computer Science") == 0) {
				goto Class_schedule_BSCS; 
			} else if (strcmp(enrollProgram, "BS Office Administration") == 0) {
				goto Class_schedule_BSOA;
			} else if (strcmp(enrollProgram, "BTVTED Major in Food Service Management") == 0) {
				goto Class_schedule_BTVTED;
			}
			break;
		case '2':
			if (strcmp(enrollProgram, "BS Computer Science") == 0) {
				goto Class_SubEnrolled_BSCS; 
			} else if (strcmp(enrollProgram, "BS Office Administration") == 0) {
				goto Class_SubEnrolled_BSOA;
			} else if (strcmp(enrollProgram, "BTVTED Major in Food Service Management") == 0) {
				goto Class_SubEnrolled_BTVTED;
			}
			break;
		case '9':
			studentMenu();
			break;
		default:
			goto Classroom_Management;
			break;
	}
	
Class_schedule_BSCS:
char user1;
	while (1) { 
	system("cls");
	printf("     +-----------------------------------------------------------------------------------------------------------------------------+\n");
	printf("     |                                                       WEEKLY SCHEDULE                                          [ 9 ] back   |\n");
	printf("     |                                                        COURSE: BSCS                                                         |\n");
	printf("     +-----------------------------------------------------------------------------------------------------------------------------+\n");
	printf("     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
	printf("     +-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	printf("     |      TIME       |     MONDAY      |     TUESDAY     |    WEDNESDAY    |    THURSDAY     |      FRIDAY     |     SATURDAY    |\n");
	printf("     |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	printf("     |    7:00-8:00    |_________________|    PATHFIT1     |_________________|                 |_________________|                 |\n");
	printf("     |    8:00-8:45    |                 |    ROOM 104     |                 |    CC114 LAB    |                 |      GE123      |\n");
	printf("     |-----------------+-----------------+-----------------+-----------------+    COMPLAB 1    +-----------------+     ROOM 406    |\n");
	printf("     |    9:00-10:00   |_________________|                 |     NSTP123     |                 |_________________|_________________|\n");
	printf("     |   10:00-10:45   |                 |                 |     ROOM 104    |                 |                 |                 |\n");
	printf("     |-----------------+-----------------+    CC123 LAB    +-----------------+-----------------+-----------------+      GE113      |\n");
	printf("     |   11:15-12:00   |_________________|    ROOM 406     |      AS123      |                 |_________________|     ROOM 406    |\n");
	printf("     |    12:00-1:00   |                 |                 |     ROOM 104    |    CC114 LEC    |                 |                 |\n");
	printf("     |-----------------+-----------------+                 +-----------------+    ROOM 406     +-----------------+-----------------|\n");
	printf("     |    1:00-2:00    |_________________|_________________|_________________|_________________|_________________|                 |\n");
	printf("     |    2:00-2:45    |                 |                 |                 |                 |                 |      GE124      |\n");
	printf("     |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+     ROOM 406    |\n");
	printf("     |    3:00-4:00    |_________________|_________________|_________________|_________________|_________________|_________________|\n");
	printf("     |    4:00-4:45    |                 |                 |                 |                 |                 |                 |\n");
	printf("     +-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	
	user1 = getch();
	if (user1 == '9') {
		goto Classroom_Management;
	}
}
	
	
	
Class_SubEnrolled_BSCS:
char user2;
while (1) { 
	system("cls");
	printf("     +-----------------------------------------------------------------------------------------------------------+\n");
	printf("     |                                              ENROLLED SUBJECT                                [ 9 ] back   |\n");
	printf("     |                                                COURSE: BSCS                                               |\n");
	printf("     +-----------------------------------------------------------------------------------------------------------+\n");
	printf("     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
	printf("     +-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	printf("     |  SUBJECT CODE:  |                           SUBJECT DESCRIPTION                         |      UNITS      |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      GE123      |                          Understanding the self                       |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      GE113      |                     Mathematics in the Modern World                   |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      CC123      |            Introduction to Computing with Productivity Tools          |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      CC114      |                      Fundamentals of Programming 1                    |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      AS123      |                       PhilTech Life and Spirit                        |        2        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      GE124      |                  Readings in the Philippine History                   |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      PE123      |                           Physical Fitness 1                          |        2        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |     NSTP123     |                  National Service Training Program 1                  |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |                                                                            TOTAL UNITS: |       22        |\n");
	printf("     +-----------------------------------------------------------------------------------------+-----------------+\n");
	
	user2 = getch();
	if (user2 == '9') {
		goto Classroom_Management;
	}
}

Class_schedule_BSOA:
char user3;
while (1) { 
	system("cls");
	printf("     +-----------------------------------------------------------------------------------------------------------------------------+\n");
	printf("     |                                                       WEEKLY SCHEDULE                                          [ 9 ] back   |\n");
	printf("     |                                                        COURSE: BSOA                                                         |\n");
	printf("     +-----------------------------------------------------------------------------------------------------------------------------+\n");
	printf("     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
	printf("     +-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	printf("     |      TIME       |     MONDAY      |     TUESDAY     |    WEDNESDAY    |    THURSDAY     |      FRIDAY     |     SATURDAY    |\n");
	printf("     +-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	printf("     |    7:00-8:00    |_________________|     OACC123     |    PATHFIT1     |_________________|_________________|                 |\n");
	printf("     |    8:00-8:45    |                 |     ROOM 403    |    ROOM 104     |                 |                 |     OACC124     |\n");
	printf("     |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+     COMPLAB1    |\n");
	printf("     |    9:00-10:00   |_________________|      AS123      |                 |_________________|_________________|_________________|\n");
	printf("     |   10:00-10:45   |                 |     ROOM 104    |     FIL123      |                 |                 |                 |\n");
	printf("     |-----------------+-----------------+-----------------+    ROOM 104     +-----------------+-----------------+      GE123      |\n");
	printf("     |   11:15-12:00   |_________________|     NSTP123     |_________________|_________________|_________________|     ROOM 410    |\n");
	printf("     |    12:00-1:00   |                 |     ROOM 104    |                 |                 |                 |                 |\n");
	printf("     |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------|\n");
	printf("     |    1:00-2:00    |_________________|_________________|_________________|_________________|_________________|                 |\n");
	printf("     |    2:00-2:45    |                 |                 |                 |                 |                 |      GE113      |\n");
	printf("     |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+     ROOM 410    |\n");
	printf("     |    3:00-4:00    |_________________|_________________|_________________|_________________|_________________|_________________|\n");
	printf("     |    4:00-4:45    |                 |                 |                 |                 |                 |                 |\n");
	printf("     +-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	
	user3 = getch();
	if (user3 == '9') {
		goto Classroom_Management;
	}
}

Class_SubEnrolled_BSOA:
char user4;
while (1) { 
	system("cls");
	printf("     +-----------------------------------------------------------------------------------------------------------+\n");
	printf("     |                                              ENROLLED SUBJECT                                [ 9 ] back   |\n");
	printf("     |                                                COURSE: BSOA                                               |\n");
	printf("     +-----------------------------------------------------------------------------------------------------------+\n");
	printf("     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
	printf("     +-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	printf("     |  SUBJECT CODE:  |                           SUBJECT DESCRIPTION                         |      UNITS      |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      FIL123     |                  Komunikasyon sa Akademikong Filipino                 |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      GE123      |                          Understanding the self                       |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      GE113      |                     Mathematics in the Modern World                   |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |     OACC123     |                        Foundation of Shorthand                        |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |     OACC124     |                  Keyboarding and Documents Processing                 |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      AS123      |                       PhilTech Life and Spirit                        |        2        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      PE123      |                           Physical Fitness 1                          |        2        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |     NSTP123     |                  National Service Training Program 1                  |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |                                                                            TOTAL UNITS: |       22        |\n");
	printf("     +-----------------------------------------------------------------------------------------+-----------------+\n");
	
	user4 = getch();
	if (user4 == '9') {
		goto Classroom_Management;
	}
}

Class_schedule_BTVTED:
char user5;
while (1) { 
	system("cls");
	printf("     +-----------------------------------------------------------------------------------------------------------------------------+\n");
	printf("     |                                                       WEEKLY SCHEDULE                                          [ 9 ] back   |\n");
	printf("     |                                                       COURSE: BTVTED                                                        |\n");
	printf("     +-----------------------------------------------------------------------------------------------------------------------------+\n");
	printf("     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
	printf("     +-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	printf("     |      TIME       |     MONDAY      |     TUESDAY     |    WEDNESDAY    |    THURSDAY     |      FRIDAY     |     SATURDAY    |\n");
	printf("     |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	printf("     |    7:00-8:00    |_________________|     OACC124     |    PATHFIT1     |_________________|_________________|                 |\n");
	printf("     |    8:00-8:45    |                 |     ROOM 403    |    ROOM 104     |                 |                 |     OACC123     |\n");
	printf("     |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+     COMPLAB1    |\n");
	printf("     |    9:00-10:00   |_________________|       PLS       |                 |_________________|_________________|_________________|\n");
	printf("     |   10:00-10:45   |                 |     ROOM 104    |     NSTP123     |                 |                 |                 |\n");
	printf("     |-----------------+-----------------+-----------------+    ROOM 104     +-----------------+-----------------+       GE1       |\n");
	printf("     |   11:15-12:00   |_________________|      NSTP1      |_________________|_________________|_________________|     ROOM 410    |\n");
	printf("     |    12:00-1:00   |                 |    ROOM 104     |                 |                 |                 |                 |\n");
	printf("     |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------|\n");
	printf("     |    1:00-2:00    |_________________|_________________|_________________|_________________|_________________|                 |\n");
	printf("     |    2:00-2:45    |                 |                 |                 |                 |                 |       GE2       |\n");
	printf("     |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+     ROOM 410    |\n");
	printf("     |    3:00-4:00    |_________________|_________________|_________________|_________________|_________________|_________________|\n");
	printf("     |    4:00-4:45    |                 |                 |                 |                 |                 |                 |\n");
	printf("     +-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	
	user5 = getch();
	if (user5 == '9') {
		goto Classroom_Management;
	}
}
	
Class_SubEnrolled_BTVTED:
char user6;
while (1) { 
	system("cls");
	printf("     +-----------------------------------------------------------------------------------------------------------+\n");
	printf("     |                                              ENROLLED SUBJECT                                [ 9 ] back   |\n");
	printf("     |                                               COURSE: BTVTED                                              |\n");
	printf("     +-----------------------------------------------------------------------------------------------------------+\n");
	printf("     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |\n");
	printf("     +-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
	printf("     |  SUBJECT CODE:  |                           SUBJECT DESCRIPTION                         |      UNITS      |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      FCC123     |         The Child and adolescent learner and learning principles      |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      FCC124     |                         The Teaching Profession                       |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      TLE123     |                  Teaching ICT as an Explanatory Course                |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      TLE124     |                         Home Economics Literacy                       |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      GE123      |                         Purposive Communication                       |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      GE124      |                     Readings in Philippine History                    |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      GE113      |                     Mathematics in the Modern World                   |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      PLS12      |                        PhilTech Life and Spirit                       |        2        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |      PE123      |                           Physical Fitness 1                          |        2        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |     NSTP123     |                  National Service Training Program 1                  |        3        |\n");
	printf("     +-----------------+-----------------------------------------------------------------------+-----------------+\n");
	printf("     |                                                                            TOTAL UNITS: |       28        |\n");
	printf("     +-----------------------------------------------------------------------------------------+-----------------+\n");
	
	user6 = getch();
	if (user6 == '9') {
		goto Classroom_Management;
	}
}

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
