#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>

char enrollStatus [50];
char enrollCourse [50];
char enrollLname [50];
char enrollFname [50];
char enrollMname [50];
char enrollmentFullname [50];
char enrollBday [50];
char enrollGender [50];
char enrollEmail [50];
char enrollContact [50];
char enrollAddress [50];
char enrollHSname [50];
char enrollHSaddress [50];
char enrollHSgraduation [50];
char enrollMFname [50];
char enrollFFname [50];
char enrollGContact [50];
char enrollSchedule [50];
char enrollLevel [50];
char enrollSubmit [50] = "Submit";
char enrollPayment [50];
char paymentCredit [50];
char paymentVerification [50];

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void enrollment_display () {
	printf("\n=====================================================================================================================\n");
    printf("*                                                Enrollment Page                                                    *\n");
    printf("=====================================================================================================================\n\n");
}

void enrollment_studentnotice_display () {
	printf("\t\tStudent Basic Information:\n");
    printf("\t\t ------------------------------------------------------------------------------------\n");
    printf("\t\t| To safeguard the privacy of our prospective student, we strictly adhere to RA      |\n");
    printf("\t\t| No. 10173, the Data Privacy Act, when collecting and managing information during   |\n"); 
    printf("\t\t| our college registration process.                                                  |\n");
    printf("\t\t ------------------------------------------------------------------------------------\n\n");
}

void enrollment_paymentnotice_display () {
	printf("\t\tStudent Basic Information:\n");
    printf("\t\t ------------------------------------------------------------------------------------\n");
    printf("\t\t| To secure your slot, please pay a reservation fee of P1,500.00.                    |\n");
    printf("\t\t ------------------------------------------------------------------------------------\n\n");
}

int main () {
	enrollmentpage:

	char userStatus, userCourse, userGender, userLevel, userSchedule, userPayment, userEnroll, userReq, userDetails;
	char submitConfirm[50];
	system("cls");
	enrollment_display();
	
	printf("\t\t\tStatus:\n");
    printf("\t\t\t ---------------------------------------------------\n");
    printf("\t\t\t|            [ 1 ] New Applicant                    |\n");
    printf("\t\t\t|            [ 2 ] Old Applicant                    |\n");
    printf("\t\t\t|            [ 3 ] Transferee                       |\n");
    printf("\t\t\t|            [ 4 ] Old Curriculum/ALS               |\n");
    printf("\t\t\t ---------------------------------------------------\n\n");
    
    userStatus = getch();
    
    switch (userStatus) {
    	case '1':
    		strcpy(enrollStatus, "New_Applicant");
    		printf("\t\t\t|New Applicant");
    		goto Course_choice;
    		break;
    	case '2':
    		strcpy(enrollStatus, "Old_Applicant");
    		printf("\t\t\t|Old Applicant");
    		goto Course_choice;
    		break;
    	case '3':
    		strcpy(enrollStatus, "Transferee");
    		printf("\t\t\t|Transferee");
    		goto Course_choice;
    		break;
    	case '4':
    		strcpy(enrollStatus, "Old_Curriculum");
    		printf("\t\t\t|Old Curriculum/ALS");
    		goto Course_choice;
    		break;
    	default:
    		printf("Invalid Input\n");
    		goto enrollmentpage;
    		break;
    }
    
Course_choice:
	printf("\n\n\n");
	printf("\t\t\tPreferred Course:\n");
    printf("\t\t\t ---------------------------------------------------\n");
    printf("\t\t\t| [ 1 ] BTVTED - Bachelor of Technical Teacher      |\n");
    printf("\t\t\t|       Education Major in Food Service Management. |\n"); 
    printf("\t\t\t| [ 2 ] BSOA - Bachelor of Science in Office        |\n");
    printf("\t\t\t|       Addministration.                            |\n");
    printf("\t\t\t| [ 3 ] BSCS - Bachelor of Science in Computer      |\n");
    printf("\t\t\t|       Science.                                    |\n");
    printf("\t\t\t ---------------------------------------------------\n\n");
    
    userCourse = getch();
    system("cls");
    
    switch(userCourse) {
    	case '1':
    		strcpy(enrollCourse, "BTVTED");
    		goto Student_basic_information;
    		break;
    	case '2':
    		strcpy(enrollCourse, "BSOA");
    		goto Student_basic_information;
    		break;
    	case '3':
    		strcpy(enrollCourse, "BSCS");
    		goto Student_basic_information;
    		break;
    	default:
    		printf("Invalid Input\n");
    		goto Course_choice;
    		break;
	}
	
Student_basic_information:
	enrollment_display();
	enrollment_studentnotice_display();
    
    printf("\t\t\tEnter Lastname:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", enrollLname);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    printf("\t\t\tEnter Firstname:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", enrollFname);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    printf("\t\t\tEnter Middle name:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", enrollMname);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    strcat(enrollmentFullname, enrollLname);
    strcat(enrollmentFullname, ", ");
    strcat(enrollmentFullname, enrollFname);
    strcat(enrollmentFullname, ", ");
    strcat(enrollmentFullname, enrollMname);
    
Student_basic_information02:
    system("cls");
    enrollment_display();
	enrollment_studentnotice_display();
	
	printf("\t\t\tEnter Date of Birth:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf(" %[^\n]", enrollBday);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    printf("\t\t\tGender:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| [ 1 ] Male                                                |\n");
    printf("\t\t\t| [ 2 ] Female                                              |\n");
    printf("\t\t\t| [ 3 ] Others:                                             |\n");
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    userGender = getch();
    
    switch (userGender) {
    	case '1':
    		strcpy(enrollGender, "Male");
    		goto Student_basic_information03;
    		break;
    	case '2':
    		strcpy(enrollGender, "Female");
    		goto Student_basic_information03;
    		break;
    	case '3':
    		printf("\t\t\tEnter Other Gender:\n");
    		printf("\t\t\t -----------------------------------------------------------\n");
    		printf("\t\t\t| ");
    		scanf("%s", enrollGender);
    		printf("\t\t\t -----------------------------------------------------------\n\n");
    		goto Student_basic_information03;
    		break;
    	default:
    		printf("Invalid Input\n");
    		goto Student_basic_information02;
    		break;
	}
    
Student_basic_information03:
    system("cls");
    enrollment_display();
	enrollment_studentnotice_display();
	
	printf("\t\t\tEnter Email Address: (ex@gmail.com)\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", enrollEmail);
    char *atSymbol = strchr(enrollEmail, '@');
    if (atSymbol != NULL) {
        char *domain = strstr(atSymbol, "gmail.com");
        if (domain != NULL && strcmp(domain, "gmail.com") == 0) {
            printf("\t\t\t -----------------------------------------------------------\n\n");
            goto Contactno;
        }
    }

    printf("Invalid email. Please try again.\n");
    printf("Press any key to continue...\n");
    getch();
    goto Student_basic_information03;

Contactno:
	printf("\t\t\tEnter Contact No.:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", enrollContact);

    int length = strlen(enrollContact);

    if (length == 11) {
        for (int i = 0; i < length; i++) {
            if (!isdigit(enrollContact[i])) {
                printf("\nInvalid contact number. It must contain only digits.\n");
                printf("Press any key to try again...\n");
                getch();
                goto Contactno;
            }
        }
        printf("\t\t\t -----------------------------------------------------------\n\n");
        goto Home_address;
    } else {
        printf("\nInvalid contact number. It must contain exactly 11 digits.\n");
        printf("Press any key to try again...\n");
        getch();
        goto Contactno;
    }

Home_address:
    printf("\t\t\tEnter Home Address:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf(" %[^\n]", enrollAddress);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
Student_basic_information04:
    system("cls");
    enrollment_display();
	enrollment_studentnotice_display();
	
	printf("\t\t\tEnter High School Name:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf(" %[^\n]", enrollHSname);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    printf("\t\t\tEnter High School Address:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf(" %[^\n]", enrollHSaddress);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    printf("\t\t\tEnter Year of Graduation:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf(" %[^\n]", enrollHSgraduation);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
Student_basic_information05:
    system("cls");
    enrollment_display();
	enrollment_studentnotice_display();
	
	printf("\t\t\tEnter Mother's Name:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf(" %[^\n]", enrollMFname);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    printf("\t\t\tEnter Father's Name:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf(" %[^\n]", enrollFFname);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    printf("\t\t\tEnter Guardian Contact No.:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", enrollGContact);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
Student_basic_information06:
    system("cls");
    enrollment_display();
	enrollment_studentnotice_display();
	
	printf("\t\t\tPreferred Schedule:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| [ 1 ] REGULAR CLASS (3-4 DAYS)                            |\n");
    printf("\t\t\t| [ 2 ] SUNDAY CLASS  (7AM-7PM)                             |\n");
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    userSchedule = getch ();
    
    switch (userSchedule) {
    	case '1':
    		strcpy(enrollSchedule, "Regular Class");
    		goto Submit_information;
    		break;
    	case '2':
    		strcpy(enrollSchedule, "Sunday Class");
    		goto Submit_information;
    		break;
    	default:
    		printf("Invalid Input\n");
    		goto Student_basic_information06;
    		break;
	}
	
	if (strcmp(enrollStatus, "New_Applicant") == 0) {
    		goto Submit_information;
		} else if (strcmp(enrollStatus, "Old_Applicant") == 0) {
			goto Submit_information;
		} else if (strcmp(enrollStatus, "Old_Curriculum") == 0) {
			goto Submit_information;
		} else if (strcmp(enrollStatus, "Transferee") == 0) {
			goto Student_basic_information07;
		}

Student_basic_information07:
    system("cls");
    enrollment_display();
	enrollment_studentnotice_display();
	
	printf("\t\t\tChoose Academic Level:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t|  [1] 1ST YEAR, [2] 2ND YEAR, [3] 3RD YEAR, [4] 4TH YEAR   |\n");
    printf("\t\t\t -----------------------------------------------------------\n\n");
    
    userLevel = getch();
    
    switch(userLevel) {
    	case '1':
    		strcpy(enrollLevel, "1ST YEAR");
    		goto Submit_information;
    		break;
    	case '2':
    		strcpy(enrollLevel, "2ND YEAR");
    		goto Submit_information;
    		break;
    	case '3':
    		strcpy(enrollLevel, "3RD YEAR");
    		goto Submit_information;
    		break;
    	case '4':
    		strcpy(enrollLevel, "4TH YEAR");
    		goto Submit_information;
    		break;
    	default:
    		printf("Invalid Input\n");
    		goto Student_basic_information07;
    		break;
	}

Submit_information:
	printf("\t\t\tInput (Submit) to continue:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", submitConfirm);
    printf("\t\t\t -----------------------------------------------------------\n\n");

    if (strcmp(submitConfirm, enrollSubmit) == 0) {
    	goto Payment_field;
    } else {
    	printf("\t\t\t*******************************************************\n");
    	printf("\t\t\t*        Incorrect Input! Please try again...         *\n");
    	printf("\t\t\t*******************************************************\n");
    	printf("");
    	getch();
    	
    	if (strcmp(enrollStatus, "New_Applicant") == 0) {
    		goto Student_basic_information06;
		} else if (strcmp(enrollStatus, "Old_Applicant") == 0) {
			goto Student_basic_information06;
		} else if (strcmp(enrollStatus, "Old_Curriculum") == 0) {
			goto Student_basic_information06;
		} else if (strcmp(enrollStatus, "Transferee") == 0) {
			goto Student_basic_information07;
		}
	}
	
Payment_field:
	system("cls");
    enrollment_display();
    enrollment_paymentnotice_display();
	
	printf("\t\t\tChoose Payment Method:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| [ 1 ] Credit Card                                         |\n");
    printf("\t\t\t| [ 2 ] Gcash                                               |\n");
    printf("\t\t\t| [ 3 ] Paymaya                                             |\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    
    userPayment = getch();
    
    switch (userPayment) {
    	case '1':
    		strcpy(enrollPayment, "Credit Card");
    		printf("\t\t\t|Credit Card Method\n\n");
    		goto Credit_card_method;
    		break;
    	case '2':
    		strcpy(enrollPayment, "Gcash");
    		printf("\t\t\t|Gcash Method\n\n");
    		goto Online_method;
    		break;
    	case '3':
    		strcpy(enrollPayment, "Paymaya");
    		printf("\t\t\t|Paymaya Method\n\n");
    		goto Online_method;
    		break;
    	default:
    		printf("Invalid Input\n");
    		goto Payment_field;
    		break;
	}
	
Credit_card_method:
	printf("\t\t\tEnter Credit Card No.:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", paymentCredit);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    goto Payment_verification;
	
Online_method:
	printf("\t\t\tEnter %s No.:\n", enrollPayment);
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", paymentCredit);
    printf("\t\t\t -----------------------------------------------------------\n\n");
    goto Payment_verification;
    
Payment_verification:
	system("cls");
    enrollment_display();
    
    printf("\t\t  Processing your payment, please wait. This may take a few moments...\n");
    printf("\t\tDo not close this window or navigate away while we verify your details.\n\n\n");
    
	printf("\t\t\tEnter Verification Code.:\n");
    printf("\t\t\t -----------------------------------------------------------\n");
    printf("\t\t\t| ");
    scanf("%s", paymentVerification);
    printf("\t\t\t -----------------------------------------------------------\n\n");

	
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
    
Enrollment_Receipt:
	
	system("cls");
	printf("CONFIRMATION OF ENROLLMENT\n\n");
	printf("\tYour payment has been successfully verified!\n");
	printf("\tThank you for completing your enrollment. A copy of receipt has been sent to your email.\n\n");
	printf("\t\t ------------------------------------\n");
	printf("\t\t|    [ Q ] See Enrollment Details    |\n");
	printf("\t\t ------------------------------------\n\n");
	
    printf("\tNow you can proceed with submitting your requirements. Visit us at CRDM Building, 2nd Floor,\n");
    printf("\tPhilTech GMA, located in Brgy. Gavino Maderan, GMA, Cavite.\n\n");
    printf("\t\t ------------------------------------\n");
    printf("\t\t|    [ E ] See Requirements          |\n");
    printf("\t\t ------------------------------------\n\n");
    printf("\tFor any inquiries or assistance, feel free to contact us at 0997-224-0222 or 0955-135-4689.\n\n");
    printf("\tWe look forward to welcoming you to Philtech-GMA\n");
    
    userEnroll = getch();
    
    switch (userEnroll) {
    	case 'Q':
    		goto Enrollment_details;
    		break;		
    	case 'E':
    		goto Enrollment_requirements;
    		break;
	}

Enrollment_details:
	
	system("cls");
	printf("\t\t\t*******************************************************\n");
    printf("\t\t\t*                 ENROLLMENT DETAILS:                 *\n");
    printf("\t\t\t*******************************************************\n");
    printf("\t\t\t* Personal Information:                               *\n");
    printf("\t\t\t*   Fullname: %-39s *\n", enrollmentFullname);
    printf("\t\t\t*   Date of Birth: %-34s *\n", enrollBday);
    printf("\t\t\t*   Gender: %-41s *\n", enrollGender);
    printf("\t\t\t*   Email Address: %-34s *\n", enrollEmail);
    printf("\t\t\t*   Home Address: %-35s *\n", enrollAddress);
    printf("\t\t\t*   Contact Number: %-33s *\n", enrollContact);
    printf("\t\t\t*                                                     *\n");
    printf("\t\t\t* Other Information:                                  *\n");
    printf("\t\t\t*   Status: %-41s *\n", enrollStatus);
    printf("\t\t\t*   Course: %-41s *\n", enrollCourse);
    printf("\t\t\t*   Schedule: %-39s *\n", enrollSchedule);
    printf("\t\t\t*                                                     *\n");
    printf("\t\t\t* Payment Information:                                *\n");
    printf("\t\t\t*   Payment method: %-33s *\n", enrollPayment);
    printf("\t\t\t*   Account number: %-33s *\n", paymentCredit);
    printf("\t\t\t*******************************************************\n");
    
    userDetails = getch();
    
    switch(userDetails) {
		case '9':
			goto Enrollment_Receipt; // Temporary
			break;
		default:
			goto Enrollment_details;
			break;
	}
	
    
Enrollment_requirements:
	system("cls");
	printf("\t\t ------------------------------------------------------------------------------\n");
	printf("\t\t| [ 9 ] Close                    Transmitted                                   |\n");
	printf("\t\t|                                 COLLEGE                                      |\n");
	printf("\t\t|------------------------------------------------------------------------------|\n");
	printf("\t\t| QTY |                         PARTICULAR                                     |\n");
	printf("\t\t|------------------------------------------------------------------------------|\n");
	printf("\t\t|  1  | FORM 138/CARD (Original) and (Photocopy)                               |\n");
	printf("\t\t|------------------------------------------------------------------------------|\n");
	printf("\t\t|  1  | GOOD MORAL (Original) and (Photocopy)                                  |\n");
	printf("\t\t|------------------------------------------------------------------------------|\n");
	printf("\t\t|  1  | TRANSCRIPT (Original) and (Photocopy)                                  |\n");
	printf("\t\t|------------------------------------------------------------------------------|\n");
	printf("\t\t|  4  | PSA (Photocopy)                                                        |\n");
	printf("\t\t|------------------------------------------------------------------------------|\n");
	printf("\t\t|  4  | 2x2 Picture (White Background W/Name Tag)                              |\n");
	printf("\t\t|------------------------------------------------------------------------------|\n");
	printf("\t\t|  4  | 1x1 Picture (White Background W/Name Tag)                              |\n");
	printf("\t\t|------------------------------------------------------------------------------|\n");
	printf("\t\t|  1  | Long Brown Envelope                                                    |\n");
	printf("\t\t|------------------------------------------------------------------------------|\n");
	printf("\t\t|  1  | Long Plastic Envelope                                                  |\n");
	printf("\t\t|------------------------------------------------------------------------------|\n");
	printf("\t\t|  1  | White Long Folder                                                      |\n");
	printf("\t\t ------------------------------------------------------------------------------\n");
	
	userReq = getch();
	
	switch(userReq) {
		case '9':
			goto Enrollment_Receipt; //Temporary
			break;
		default:
			goto Enrollment_requirements;
			break;
	}
	
	return 0;
}
