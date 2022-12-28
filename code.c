#include <stdio.h>
#include <string.h>
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
    printf("********************************************\n");
    printf("*                                          *\n");
    printf("*           Application Login              * \n");
    printf("*                                          *\n");
    printf("********************************************\n");

    printf("1. Admin Login \n");
    printf("2. User Login \n");
    printf("3. Exit \n");
    printf("\n");
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

// All Patient List
void all_patient_list()
{
    char patientName[MAX_LIMIT];
    int age;
    char date[MAX_LIMIT];
    char dischargedDate[MAX_LIMIT];
    char doctorName[MAX_LIMIT];
    system("CLS");
    printf("Admited Patient List: \n");
    printf("------------------------------------------------------------------\n");
    printf("|      Patient Name      |     Age     |        Date (Admited)   |\n");
    printf("------------------------------------------------------------------\n");
    FILE *admitedPatientList;
    admitedPatientList = fopen("admitedPatient.txt", "r");
    for (; !feof(admitedPatientList);)
    {
        fscanf(admitedPatientList, "%s %d %s", &patientName, &age, &date);
        printf("|%20s    | %7d     | %20s    |\n", patientName, age, date);
    }
    fclose(admitedPatientList);
    printf("------------------------------------------------------------------\n");
    printf("\n Discharged Patient List: \n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("|      Patient Name      |     Age     |        Date (Admited)   |      Date (Discharge)   |\n");
    printf("--------------------------------------------------------------------------------------------\n");
    FILE *dischargedPatientList;
    dischargedPatientList = fopen("dischargedPatient.txt", "r");
    for (; !feof(dischargedPatientList);)
    {
        fscanf(dischargedPatientList, "%s %d %s %s", &patientName, &age, &date, &dischargedDate);
        printf("|%20s    | %7d     | %20s    | %20s    |\n", patientName, age, date, dischargedDate);
    }
    fclose(dischargedPatientList);
    printf("--------------------------------------------------------------------------------------------\n");
    printf("\n NonAdmited Patient List: \n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("|      Patient Name      |     Age     |          Date           |          Doctor         |\n");
    printf("--------------------------------------------------------------------------------------------\n");
    FILE *nonAdmitedPatientList;
    nonAdmitedPatientList = fopen("nonAdmitedPatient.txt", "r");
    for (; !feof(nonAdmitedPatientList);)
    {
        fscanf(nonAdmitedPatientList, "%s %d %s %s", &patientName, &age, &date, &doctorName);
        printf("|%20s    | %7d     | %20s    | %20s    |\n", patientName, age, date, doctorName);
    }
    fclose(nonAdmitedPatientList);
    printf("--------------------------------------------------------------------------------------------\n");
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
    // char givenUser[20], givenPass[20];
    // scanf("%s %s", &givenUser, &givenPass);
    // printf("User input - %s %s\n", givenUser, givenPass);
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
        // printf("File input - %s %s\n", userName, password);
        machingUser = strcmp(userName, givenUser);
        machingPass = strcmp(password, givenPass);
        if (machingPass == 0 && machingUser == 0)
        {
            match = 1;
            // printf("Matched output - %s %s\n", adminUserName, adminPassword);
            break;
        }
        else
        {
            match = 0;
        }
        // if (feof(users))
        //     break;
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
        printf("Invalid credentials! for admin panel.\n \n");
        return 0;
    }
}

void user_panel()
{
    printf("-------------------------------------------\n");
    printf("|                                          |\n");
    printf("|              Welcome to the              | \n");
    printf("|            Imperial Hospital             | \n");
    printf("|            User(Saff) Panel              | \n");
    printf("|                                          |\n");
    printf("-------------------------------------------\n");
    char userChoise;
    printf("1. All Patient List\n");
    printf("2. Available seats \n");
    printf("3. Exit \n");
    printf("\n");
    printf("Enter Your Choice: ");
    scanf("%c", &userChoise);
    scanf("%c", &userChoise);
    while (userChoise != '1' && userChoise != '2' && userChoise != '3')
    {
        printf("\n");
        printf("Invalid Argument \n \n");
        printf("Enter 1 for All Patient List \n");
        printf("Enter 2 for Available seats\n");
        printf("Enter 3 for Exit \n");
        printf("\n");
        printf("Enter Your Choise: ");
        scanf("%c", &userChoise);
    }
    if (userChoise == '1')
    {
        system("CLS");
        all_patient_list();
        user_panel();
    }
    else if (userChoise == '2')
    {
        system("CLS");
        int seats = booked_seats();
        printf("%30s\n", "Available Seats: ");
        printf("-------------------------------------------\n");
        printf("|    Total Seats    |   Available Seats   |\n");
        printf("-------------------------------------------\n");
        printf("|%10d          |%11d         |\n", 100, 100 - seats);
        printf("-------------------------------------------\n\n");
        user_panel();
    }
    else if (userChoise == '3')
    {
    }
}

// Admin Panel
void admin_panel()
{
    // system("CLS");
    printf("-------------------------------------------\n");
    printf("|                                          |\n");
    printf("|              Welcome to the              | \n");
    printf("|            Imperial Hospital             | \n");
    printf("|               Admin Panel                | \n");
    printf("|                                          |\n");
    printf("-------------------------------------------\n");
    int adminChoise;
    printf("1. Admit a Patient\n");
    printf("2. Discharge a Patient\n");
    printf("3. Add a Patient (Non Admited!)\n");
    printf("4. All Patient List\n");
    printf("5. Available seats \n");
    printf("6. Exit \n");
    printf("\n");
    printf("Enter Your Choice: ");
    scanf("%d", &adminChoise);
    while (adminChoise != 1 && adminChoise != 2 && adminChoise != 3 && adminChoise != 4 && adminChoise != 5 && adminChoise != 6)
    {
        printf("\n");
        printf("Invalid Argument \n \n");
        printf("Enter 1 for Admit a Patient \n");
        printf("Enter 2 for Discharge a Patient\n");
        printf("Enter 3 Add a Patient (Non Admited!) \n");
        printf("Enter 4 All Patient List \n");
        printf("Enter 5 for Available seats \n");
        printf("Enter 6 for Exit \n");
        printf("\n");
        printf("Enter Your Choise: ");
        scanf("%d", &adminChoise);
    }
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
        printf("\n********************************\n");
        printf("*  Patient added successfully  *\n");
        printf("********************************\n");
        admin_panel();
    }
    else if (adminChoise == 2)
    {
        // discharge
        int n = booked_seats();
        // printf("Seats - %d", n);
        struct Patient restPatient[n];
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
            fscanf(admitedPatientList, "%s %d %s", &restPatient[pr].patientName, &restPatient[pr].age, &restPatient[pr].date);
            if (strcmp(restPatient[pr].patientName, patientName) == 0)
            {
                FILE *dischargedPatient;
                dischargedPatient = fopen("dischargedPatient.txt", "a");
                fprintf(dischargedPatient, "\n%s %d %s %s", restPatient[pr].patientName, restPatient[pr].age, restPatient[pr].date, dischargeDate);
                fclose(dischargedPatient);
            }
        }
        fclose(admitedPatientList);
        FILE *patientList;
        patientList = fopen("admitedPatient.txt", "w");
        for (int pr = 0; pr < n - 1; pr++)
        {
            //  fscanf(patientList, "%s %d %s", &restPatient[pr].patientName, &restPatient[pr].age, &restPatient[pr].date);
            if (strcmp(restPatient[pr].patientName, patientName) != 0)
            {
                fprintf(patientList, "\n%s %d %s", restPatient[pr].patientName, restPatient[pr].age, restPatient[pr].date);
                // printf("\n%s %d %s", restPatient[pr].patientName, restPatient[pr].age, restPatient[pr].date);
            }
        }
        fclose(patientList);
        printf("\n*************************************\n");
        printf("*  Patient discharged successfully  *\n");
        printf("*************************************\n");
        admin_panel();
    }
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
        printf("\n********************************\n");
        printf("*  Patient added successfully  *\n");
        printf("********************************\n");
        admin_panel();
    }
    else if (adminChoise == 4)
    {
        all_patient_list();
        // char patientName[MAX_LIMIT];
        // int age;
        // char date[MAX_LIMIT];
        // char dischargedDate[MAX_LIMIT];
        // char doctorName[MAX_LIMIT];
        // system("CLS");
        // printf("Admited Patient List: \n");
        // printf("------------------------------------------------------------------\n");
        // printf("|      Patient Name      |     Age     |        Date (Admited)   |\n");
        // printf("------------------------------------------------------------------\n");
        // FILE *admitedPatientList;
        // admitedPatientList = fopen("admitedPatient.txt", "r");
        // for (; !feof(admitedPatientList);)
        // {
        //     fscanf(admitedPatientList, "%s %d %s", &patientName, &age, &date);
        //     printf("|%20s    | %7d     | %20s    |\n", patientName, age, date);
        // }
        // fclose(admitedPatientList);
        // printf("------------------------------------------------------------------\n");
        // printf("\n Discharged Patient List: \n");
        // printf("--------------------------------------------------------------------------------------------\n");
        // printf("|      Patient Name      |     Age     |        Date (Admited)   |      Date (Discharge)   |\n");
        // printf("--------------------------------------------------------------------------------------------\n");
        // FILE *dischargedPatientList;
        // dischargedPatientList = fopen("dischargedPatient.txt", "r");
        // for (; !feof(dischargedPatientList);)
        // {
        //     fscanf(dischargedPatientList, "%s %d %s %s", &patientName, &age, &date, &dischargedDate);
        //     printf("|%20s    | %7d     | %20s    | %20s    |\n", patientName, age, date, dischargedDate);
        // }
        // fclose(dischargedPatientList);
        // printf("--------------------------------------------------------------------------------------------\n");
        // printf("\n NonAdmited Patient List: \n");
        // printf("--------------------------------------------------------------------------------------------\n");
        // printf("|      Patient Name      |     Age     |          Date           |          Doctor         |\n");
        // printf("--------------------------------------------------------------------------------------------\n");
        // FILE *nonAdmitedPatientList;
        // nonAdmitedPatientList = fopen("nonAdmitedPatient.txt", "r");
        // for (; !feof(nonAdmitedPatientList);)
        // {
        //     fscanf(nonAdmitedPatientList, "%s %d %s %s", &patientName, &age, &date, &doctorName);
        //     printf("|%20s    | %7d     | %20s    | %20s    |\n", patientName, age, date, doctorName);
        // }
        // fclose(nonAdmitedPatientList);
        // printf("--------------------------------------------------------------------------------------------\n");
        admin_panel();
    }
    else if (adminChoise == 5)
    {
        system("CLS");
        int seats = booked_seats();
        printf("%30s\n", "Available Seats: ");
        printf("-------------------------------------------\n");
        printf("|    Total Seats    |   Available Seats   |\n");
        printf("-------------------------------------------\n");
        printf("|%10d          |%11d         |\n", 100, 100 - seats);
        printf("-------------------------------------------\n\n");
        admin_panel();
    }
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

int main()
{
    char userChoice;

    printf("-------------------------------------------\n");
    printf("|                                          |\n");
    printf("|              Welcome to the              | \n");
    printf("|            Imperial Hospital             | \n");
    printf("|                                          |\n");
    printf("-------------------------------------------\n");

    userChoice = home_menu();
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
            // printf("%s %s", adminUserName, adminPassword);
            loggedinInfo = admin_login(adminUserName, adminPassword);
        }
    }
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
    else if (userChoice == '3')
    {
        printf("Exitting from the program\n");
    }

    return 0;
}