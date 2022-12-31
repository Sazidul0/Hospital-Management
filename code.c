#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_LIMIT 20

struct Patient
{
    char patientName[MAX_LIMIT];
    int age;
    char date[MAX_LIMIT];
};

char home_menu()
{
    char userChoice;
    printf("\t\t********************************************\n");
    printf("\t\t*                                          *\n");
    printf("\t\t*           Application Login              * \n");
    printf("\t\t*                                          *\n");
    printf("\t\t********************************************\n");

    printf("\t\t1. Admin Login \n");
    printf("\t\t2. User Login \n");
    printf("\t\t3. Exit \n");
    printf("\t\t\n");
    printf("Enter Your Choice: ");
    scanf("%c", &userChoice);

    while (userChoice != '1' && userChoice != '2' && userChoice != '3')
    {
        printf("\n");
        printf("Invalid Argument \n");
        printf("Enter 1 for Admin Login \n");
        printf("Enter 2 for User Login \n");
        printf("Enter 3 for Exit from the Application \n");
        printf("\n");
        printf("Enter Your Choise: ");
        scanf("%c", &userChoice);
    }
    return userChoice;
}

// Function Declaretion
void admin_panel();
void user_panel();
int booked_seats();
void doctor_list();

// All Patient List
void all_patient_list()
{
    char patientName[MAX_LIMIT];
    int age;
    char date[MAX_LIMIT];
    char dischargedDate[MAX_LIMIT];
    char doctorName[MAX_LIMIT];
    system("CLS");
    printf("\tAdmitted Patient List: \n");
    printf("\t------------------------------------------------------------------\n");
    printf("\t|      Patient Name      |     Age     |        Date (Admited)   |\n");
    printf("\t------------------------------------------------------------------\n");
    FILE *admitedPatientList;
    admitedPatientList = fopen("admitedPatient.txt", "r");
    for (; !feof(admitedPatientList);)
    {
        fscanf(admitedPatientList, "%s %d %s", &patientName, &age, &date);
        printf("\t|%20s    | %7d     | %20s    |\n", patientName, age, date);
    }
    fclose(admitedPatientList);
    printf("\t------------------------------------------------------------------\n");
    printf("\n\t Discharged Patient List: \n");
    printf("\t--------------------------------------------------------------------------------------------\n");
    printf("\t|      Patient Name      |     Age     |        Date (Admited)   |      Date (Discharge)   |\n");
    printf("\t--------------------------------------------------------------------------------------------\n");
    FILE *dischargedPatientList;
    dischargedPatientList = fopen("dischargedPatient.txt", "r");
    for (; !feof(dischargedPatientList);)
    {
        fscanf(dischargedPatientList, "%s %d %s %s", &patientName, &age, &date, &dischargedDate);
        printf("\t|%20s    | %7d     | %20s    | %20s    |\n", patientName, age, date, dischargedDate);
    }
    fclose(dischargedPatientList);
    printf("\t--------------------------------------------------------------------------------------------\n");
    printf("\n\t NonAdmited Patient List: \n");
    printf("\t--------------------------------------------------------------------------------------------\n");
    printf("\t|      Patient Name      |     Age     |          Date           |          Doctor         |\n");
    printf("\t--------------------------------------------------------------------------------------------\n");
    FILE *nonAdmitedPatientList;
    nonAdmitedPatientList = fopen("nonAdmitedPatient.txt", "r");
    for (; !feof(nonAdmitedPatientList);)
    {
        fscanf(nonAdmitedPatientList, "%s %d %s %s", &patientName, &age, &date, &doctorName);
        printf("\t|%20s    | %7d     | %20s    | %20s    |\n", patientName, age, date, doctorName);
    }
    fclose(nonAdmitedPatientList);
    printf("\t--------------------------------------------------------------------------------------------\n");
}

// User Login
int user_login(char givenUser[MAX_LIMIT], char givenPass[MAX_LIMIT])
{
    int logedin = 0;
    int match = 0;
    int i;
    char userName[MAX_LIMIT];
    char password[MAX_LIMIT];
    int machingUser = 1, machingPass = 1;
    FILE *users;
    users = fopen("staffUserName.txt", "r");

    FILE *pass;
    pass = fopen("staffPass.txt", "r");

    for (i = 0; !feof(users); i++)
    {
        fscanf(users, "%s", userName);
        fscanf(pass, "%s", password);
        machingUser = strcmp(userName, givenUser);
        machingPass = strcmp(password, givenPass);
        if (machingPass == 0 && machingUser == 0)
        {
            match = 1;
            break;
        }
        else
        {
            match = 0;
        }
    }
    fclose(users);
    fclose(pass);
    if (match == 1)
    {
        printf("Successfully logedin to User panel!");
        system("CLS");
        user_panel();
        return 1;
    }
    else
    {
        printf("Invalid credentials! for user panel.");
        return 0;
    }
}

// Admin login
int admin_login(char givenUser[MAX_LIMIT], char givenPass[MAX_LIMIT])
{
    int match = 0;
    int i;
    char userName[MAX_LIMIT];
    char password[MAX_LIMIT];
    int machingUser = 1, machingPass = 1;
    FILE *users;
    users = fopen("adminUserName.txt", "r");

    FILE *pass;
    pass = fopen("adminPass.txt", "r");

    for (i = 0; !feof(users); i++)
    {
        fscanf(users, "%s", userName);
        fscanf(pass, "%s", password);
        machingUser = strcmp(userName, givenUser);
        machingPass = strcmp(password, givenPass);
        if (machingPass == 0 && machingUser == 0)
        {
            match = 1;
            break;
        }
        else
        {
            match = 0;
        }
    }
    fclose(users);
    fclose(pass);
    if (match == 1)
    {
        printf("Successfully logedin to Admin panel!\n");
        system("CLS");
        admin_panel();
        return 1;
    }
    else
    {
        printf("Invalid credentials for admin panel.\n \n");
        return 0;
    }
}

void user_panel()
{
    printf("\t\t-------------------------------------------\n");
    printf("\t\t|                                          |\n");
    printf("\t\t|              Welcome to the              | \n");
    printf("\t\t|            Imperial Hospital             | \n");
    printf("\t\t|            User(Saff) Panel              | \n");
    printf("\t\t|                                          |\n");
    printf("\t\t-------------------------------------------\n");
    char userChoise;
    printf("\t\t1. All Patient List\n");
    printf("\t\t2. Available seats \n");
    printf("\t\t3. Doctor List \n");
    printf("\t\t4. Exit \n");
    printf("\t\t\n");
    printf("Enter Your Choice: ");
    scanf("%c", &userChoise);
    scanf("%c", &userChoise);
    while (userChoise != '1' && userChoise != '2' && userChoise != '3' && userChoise != '4')
    {
        printf("\n");
        printf("Invalid Argument \n \n");
        printf("Enter 1 for All Patient List \n");
        printf("Enter 2 for Available seats\n");
        printf("Enter 3 for Doctor List\n");
        printf("Enter 4 for Exit \n");
        printf("\n");
        printf("Enter Your Choice: ");
        scanf("%c", &userChoise);
    }
    // All patient list
    if (userChoise == '1')
    {
        system("CLS");
        all_patient_list();
        user_panel();
    }
    // Available Seats
    else if (userChoise == '2')
    {
        system("CLS");
        int seats = booked_seats();
        printf("%35s\n", "Available Seats: ");
        printf("\t-------------------------------------------\n");
        printf("\t|    Total Seats    |   Available Seats   |\n");
        printf("\t-------------------------------------------\n");
        printf("\t|%10d          |%11d         |\n", 100, 100 - seats);
        printf("\t-------------------------------------------\n\n");
        user_panel();
    }
    // Doctor List
    else if (userChoise == '3')
    {
        system("CLS");
        doctor_list();
        user_panel();
    }
    // Exit
    else if (userChoise == '4')
    {
    }
}

// Admin Panel
void admin_panel()
{
    printf("\t\t-------------------------------------------\n");
    printf("\t\t|                                          |\n");
    printf("\t\t|              Welcome to the              | \n");
    printf("\t\t|            Imperial Hospital             | \n");
    printf("\t\t|               Admin Panel                | \n");
    printf("\t\t|                                          |\n");
    printf("\t\t-------------------------------------------\n");
    int adminChoise;
    printf("\t\t1. Admit a Patient\n");
    printf("\t\t2. Discharge a Patient\n");
    printf("\t\t3. Add a Patient (Non Admitted!)\n");
    printf("\t\t4. All Patient List\n");
    printf("\t\t5. Available seats \n");
    printf("\t\t6. Exit \n");
    printf("\n");
    printf("Enter Your Choice: ");
    scanf("%d", &adminChoise);
    while (adminChoise != 1 && adminChoise != 2 && adminChoise != 3 && adminChoise != 4 && adminChoise != 5 && adminChoise != 6)
    {
        printf("\n");
        printf("Invalid Argument \n \n");
        printf("Enter 1 for Admit a Patient \n");
        printf("Enter 2 for Discharge a Patient\n");
        printf("Enter 3 Add a Patient (Non Admitted!) \n");
        printf("Enter 4 All Patient List \n");
        printf("Enter 5 for Available seats \n");
        printf("Enter 6 for Exit \n");
        printf("\n");
        printf("Enter Your Choise: ");
        scanf("%d", &adminChoise);
    }
    // Admit a Patient
    if (adminChoise == 1)
    {
        char patientName[MAX_LIMIT];
        int age;
        char date[MAX_LIMIT];
        printf("Enter Patient Name: ");
        scanf("%s", &patientName);
        printf("Enter Patient Age: ");
        scanf("%d", &age);
        printf("Enter Date: ");
        scanf("%s", &date);
        FILE *newAdmit;
        newAdmit = fopen("admitedPatient.txt", "a");
        fprintf(newAdmit, "\n%s %d %s", patientName, age, date);
        fclose(newAdmit);
        printf("\n\t\t********************************\n");
        printf("\t\t*  Patient added successfully  *\n");
        printf("\t\t********************************\n");
        admin_panel();
    }
    else if (adminChoise == 2)
    {
        // discharge a patient
        int n = booked_seats();
        struct Patient currentPatient[n];
        char patientName[MAX_LIMIT];
        char dischargeDate[MAX_LIMIT];
        printf("Enter Patient Name: ");
        scanf("%s", &patientName);
        printf("Enter Date (Discharge): ");
        scanf("%s", &dischargeDate);
        FILE *admitedPatientList;
        admitedPatientList = fopen("admitedPatient.txt", "r");
        for (int pr = 0; !feof(admitedPatientList); pr++)
        {
            fscanf(admitedPatientList, "%s %d %s", &currentPatient[pr].patientName, &currentPatient[pr].age, &currentPatient[pr].date);
            if (strcmp(currentPatient[pr].patientName, patientName) == 0)
            {
                // Discharge info adding
                FILE *dischargedPatient;
                dischargedPatient = fopen("dischargedPatient.txt", "a");
                fprintf(dischargedPatient, "\n%s %d %s %s", currentPatient[pr].patientName, currentPatient[pr].age, currentPatient[pr].date, dischargeDate);
                fclose(dischargedPatient);
            }
        }
        fclose(admitedPatientList);
        FILE *patientList;
        patientList = fopen("admitedPatient.txt", "w");
        for (int pr = 0; pr < n - 1; pr++)
        {
            if (strcmp(currentPatient[pr].patientName, patientName) != 0)
            {
                fprintf(patientList, "\n%s %d %s", currentPatient[pr].patientName, currentPatient[pr].age, currentPatient[pr].date);
            }
        }
        fclose(patientList);
        printf("\n\t\t*************************************\n");
        printf("\t\t*  Patient discharged successfully  *\n");
        printf("\t\t*************************************\n");
        admin_panel();
    }
    // Add a Patient(Non Admitted)
    else if (adminChoise == 3)
    {

        char patientName[MAX_LIMIT];
        int age;
        char date[MAX_LIMIT];
        char doctorName[MAX_LIMIT];
        printf("Enter Patient Name: ");
        scanf("%s", &patientName);
        printf("Enter Patient Age: ");
        scanf("%d", &age);
        printf("Enter Date: ");
        scanf("%s", &date);
        printf("Enter Doctor Name: ");
        scanf("%s", &doctorName);
        FILE *newAdmit;
        newAdmit = fopen("nonAdmitedPatient.txt", "a");
        fprintf(newAdmit, "\n%s %d %s %s", patientName, age, date, doctorName);
        fclose(newAdmit);
        printf("\n\t\t********************************\n");
        printf("\t\t*  Patient added successfully  *\n");
        printf("\t\t********************************\n");
        admin_panel();
    }
    // All patient list
    else if (adminChoise == 4)
    {
        all_patient_list();
        admin_panel();
    }
    // Available Seats
    else if (adminChoise == 5)
    {
        system("CLS");
        int seats = booked_seats();
        printf("%30s\n", "Available Seats: ");
        printf("\t-------------------------------------------\n");
        printf("\t|    Total Seats    |   Available Seats   |\n");
        printf("\t-------------------------------------------\n");
        printf("\t|%10d          |%11d         |\n", 100, 100 - seats);
        printf("\t-------------------------------------------\n\n");
        admin_panel();
    }
    // Exit from the program
    else if (adminChoise == 6)
    {
    }
}

// available_seats
int booked_seats()
{
    char patientName[MAX_LIMIT];
    int age;
    char date[MAX_LIMIT];
    int seats = 0;
    FILE *admitedPatientList;
    admitedPatientList = fopen("admitedPatient.txt", "r");
    for (; !feof(admitedPatientList);)
    {
        fscanf(admitedPatientList, "%s %d %s", &patientName, &age, &date);
        seats++;
    }
    fclose(admitedPatientList);
    return seats;
}

// Doctor List
void doctor_list()
{
    char doctorsName[MAX_LIMIT];
    char days[MAX_LIMIT];
    char specialization[MAX_LIMIT];

    FILE *doctorList;
    doctorList = fopen("doctor.txt", "r");
    printf("\n\n\t\t\t Imperial Hospital Doctor List\n\n");
    printf("\t-------------------------------------------------------------------\n");
    printf("\t|     Doctor Name    |    Days(In week)   |     Specialization    |\n");
    printf("\t-------------------------------------------------------------------\n");
    for (; !feof(doctorList);)
    {
        fscanf(doctorList, "%s %s %s", &doctorsName, &days, &specialization);

        printf("\t| %15s     | %12s      | %17s    |\n", doctorsName, days, specialization);
    }
    printf("\t-------------------------------------------------------------------\n");
    fclose(doctorList);
}

// Main Funtion
int main()
{
    char userChoice;

    printf("\t\t-------------------------------------------\n");
    printf("\t\t|                                          |\n");
    printf("\t\t|              Welcome to the              | \n");
    printf("\t\t|            Imperial Hospital             | \n");
    printf("\t\t|                                          |\n");
    printf("\t\t-------------------------------------------\n");

    userChoice = home_menu();
    // Admin login
    if (userChoice == '1')
    {
        int loggedinInfo = 0;
        for (int i = 0; i <= 3, loggedinInfo != 1; i++)
        {
            if (i == 3 || loggedinInfo == 1)
            {

                printf("You have entered wrong credentials 3 times!\n");
                break;
            }
            char adminUserName[MAX_LIMIT], adminPassword[MAX_LIMIT];
            printf("Enter UserName: ");
            scanf("%s", &adminUserName);
            printf("Enter Password: ");
            scanf("%s", &adminPassword);
            loggedinInfo = admin_login(adminUserName, adminPassword);
        }
    }
    // User login
    else if (userChoice == '2')
    {
        int loggedinInfo = 0;

        for (int i = 0; i <= 3, loggedinInfo != 1; i++)
        {
            if (i == 3 || loggedinInfo == 1)
            {

                printf("You have entered wrong credentials 3 times!\n");
                break;
            }
            char staffUserName[MAX_LIMIT], staffPass[MAX_LIMIT];
            printf("Enter UserName: ");
            scanf("%s", &staffUserName);
            printf("Enter Password: ");
            scanf("%s", &staffPass);
            loggedinInfo = user_login(staffUserName, staffPass);
        }
    }
    // Exit
    else if (userChoice == '3')
    {
        printf("Exitting from the program\n");
    }

    return 0;
}