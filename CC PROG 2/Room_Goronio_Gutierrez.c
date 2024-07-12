/******************************************************************************
This is to certify that this project is my own & partners work, based on
my/our personal efforts in studying and applying the concepts learned. I/we
have constructed the functions and their respective algorithms and
corresponding code by me (and my partner). The program was run, tested, and
debugged by my own efforts. I further certify that I have not copied in
part or whole or otherwise plagiarized the work of other students and/or
persons.
<Allen Andrei D. Gutierrez> - 12207292 - S11
<Ricky James H. Goronio> - 12207268 - S11
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 20
#define ROOMS 35
#define MAX 151

typedef char string[MAX];

struct ReserveInfo
{
    int Id; //Variable for Id of Reserver
    char FullName[61]; // Variable Full Name of Reserver 
    char CYear[11]; // Variable for College Year fo Reserver
    char Program[11]; // Variable for College Program fo Reserver
    char Date [11]; // Variable for Date of Reservation
    char Time[16]; // Variable for Time of Reservation
    int Par; // Variable for number of Participants
    char Room[11]; // Variable for Room to Reserve
    char Desc[101]; // Variable for Description of Activity
    char Status[21]; // Variable for Status of Reservation
};

struct BRooms
{
    char Rooms[11]; // Variable for Name of Rooms
    char Type[16]; // Variable for Type of Room
    int Capacity; // Variable for Capacity of the Room
};

/* This function displays the Main Menu of Program and asks the user 
	for input, the input is needed for the switch statement
@return value of op
Precondition: Input must be int and within the available choices
*/
int displayMenu()
{
	int op;
	printf("Room Reservation\n");
	printf("Select Mode:\n");
	printf("(1)Admin Module %15s%20s\n", "(2)Reservation", "(3)Exit");
	printf("Input number: ");
	scanf("%d", &op);
	
	return op;
}

/* This function displays the Admin Module of Program and asks the user 
	for input, the input is needed for the switch statement
@return value of op
Precondition: Input must be int and within the available choices
*/
int displayAdminModule()
{
    int op;
    printf("\nAdmin Module\n");
    printf("Select Mode:\n");
    printf("(1)Import Rooms %15s%15s\n", "(2)Import Reservations", "(3)Exit");
    printf("Input number: ");
	scanf("%d", &op);

    return op;
}

/* This function displays the Reservation Module of Program and asks the user 
	for input, the input is needed for the switch statement
@return value of op
Precondition: Input must be int and within the available choices
*/
int displayReservationModule()
{
	int op;
	printf("\nReservation Module\n");
	printf("Select Mode:\n");
	printf("(1)Display Rooms %25s%25s%25s%25s\n", "(2)Make Reservation", "(3)Edit Reservation", "(4)Delete Reservation", "(5)Main Menu");
	printf("Input Number: ");
	scanf("%d", &op);
	return op;
}

/* This function ask the user for a filename to import the rooms
	within the file, the imported rooms are then added to the
	Structure BRooms
@param *B is the pointer array for the Structure BRooms
@param *rcount is the pointer for the int Roomcount
Precondition: Inputed string must include file extention and file must exist
*/
void ImportRooms(struct BRooms *B, int *rcount)
{
    FILE *fp;
    int i = 0;
    string fname;
	char ask = 'n';

    do{
		printf("Enter filename with file extension: ");//Ask for the filename
		scanf(" %[^\n]%*c", fname);

		fp = fopen(fname, "r");//Opens text file
		if(fp == NULL)
		{
			printf("File not found, try again(y/n): ");
			scanf(" %c", &ask);
		}
		else
		{
			ask = 'b';
		}
	}while(ask == 'y');

    printf("\nIMPORTING ROOMS....\n");
    if(ask == 'b')
    {
        while(fscanf(fp, "%s %s %d", B[i].Rooms, B[i].Type, &B[i].Capacity) == 3 && i < ROOMS) // Scans values stored in the txt file
        {

            printf("Room: %s", B[i].Rooms); // Displays Stored values
            printf(" Type: %s", B[i].Type);
            printf(" Capacity: %d\n", B[i].Capacity);
            i++;
        }

        *rcount = i; // Updates the value of Roomcount
        fclose(fp);
        printf("Total no of rooms imported: %d\n", *rcount);
        printf("\nIMPORTING ROOMS COMPLETED\n");
    }
}

/* This function ask the user for a filename to import the rooms
	within the file, the imported rooms are then added to the
	Structure ReserveInfo
@param *A is the pointer array for the Structure ReserveInfo
@param *r is the pointer for the int rec
Precondition: Inputed string must include file extention and file must exist
*/
void ImportReservations(struct ReserveInfo *A, int *r)
{
    FILE *fp;
    int i = 0;
    string fname;
	char ask = 'n';

    do{
		printf("Enter filename with file extension: ");//Ask for the filename
		scanf(" %[^\n]%*c", fname);

		fp = fopen(fname, "r");//Opens text file
		if(fp == NULL)
		{
			printf("File not found, try again(y/n): ");
			scanf(" %c", &ask);
		}
		else
		{
			ask = 'b';
		}
	}while(ask == 'y');

    printf("\nIMPORTING RESERVATIONS....\n");
    if(ask == 'b')
    {
        while(fscanf(fp, "%d %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %[^\n] %[^\n]", 
                &A[i].Id, A[i].FullName, A[i].CYear, A[i].Program, A[i].Date,
                A[i].Time,  A[i].Room, & A[i].Par, A[i].Desc, A[i].Status) == 10 && i < SIZE) // Scans values stored in the txt file
        {
            printf("\nID Number: %d\n", A[i].Id); // Displays Stored values
            printf("Name of Reserver: %s\n", A[i].FullName);
            printf("%s\n", A[i].CYear);
            printf("Program: %s\n", A[i].Program);
            printf("Date of Reservation: %s\n", A[i].Date);
            printf("Time of Reservation: %s\n", A[i].Time);
            printf("Selected Room: %s\n", A[i].Room);
            printf("Number of Participants: %d\n", A[i].Par);
            printf("Description of Activity: %s\n", A[i].Desc);
            printf("Status of Reservation: %s\n", A[i].Status);
            i++;
        }
        *r = i; // Updates the value of Roomcount
        fclose(fp);
        printf("\nTotal no of reservations imported: %d\n", *r); 
        printf("\nIMPORTING RESERVATIONS COMPLETED\n");
    }
}

/* This function displays the rooms contained in Structure BRooms
    as well as display the available timeslots for reservation
    and total number of rooms 
@param *B is the pointer array for the Structure BRooms
@param *rcount is the pointer for the int Roomcount
Precondition: BRooms must values stored inorder to display rooms
*/
void DisplayRooms(struct BRooms *B, int *rcount)
{
    int i, count;
    count = *rcount;

    printf("Total number of Rooms: %d\n", *rcount);
    printf("Room %15s%15s\n", "Type", "Capacity");

    for(i = 0; i < count; i++) // Loop to print all Rooms, Types and Capacity fo each Room
    {
        printf("|%s%15s%15d\n|", B[i].Rooms, B[i].Type, B[i].Capacity);
        printf("__________________________________________________\n");
    }
    printf("These are the available time slots\n");
    printf("For MTHF\n");
    printf("09:15 - 10:45 || 11:00 - 12:30 || 12:45 - 14:15|| 14:30 - 16:00|| 16:15 - 17:45 || 18:00 - 19:00\n");
    printf("For WS\n");
    printf("09:00 - 12:00 || 13:00 - 16:00 || 16:15 - 19:15\n");
}

/* This function checks if the no. of reservations made by the given
    ID number and returns the count when the function is called
@param *A is the pointer array for the Structure BRooms
@param *r is the pointer for the int rec
@param n is the parameter for tempid
Precondition: Proper parameters are in place for the function call to work
*/
int ReservationCount(struct ReserveInfo *A, int *r, int n)
{
    int i, count = 0;
    for(i = 0; i < *r; i++)
    {
        if(n == A[i].Id)
            count++;
    }
    return count;
}

/* This function allows the user to make Reservations, inputted information
    such as ID number, Name, Room to reserve, date of reservation, etc. are 
	then saved to the Structure ReserveInfo
@param *A is the pointer array for the Structure ReservationInfo
@param *B is the pointer array for the Structure BRooms
@param *r is the pointer for the int rec
@param *rcount is the pointer for the int Roomcount
@return none as the fuction is void
Precondition: Inputs must be a string or int
*/
void CreateReservation(struct ReserveInfo *A, struct BRooms *B, int *r, int *rcount)
{
    int tempid, temppar, check = 0, exit = 0; // The temp variables used to store Id and Participants, check and xit are used for looping conditions
    int parcheck, shedcheck, timeslotcheck; // Used for looping conditions
    int count, sub, rsub; // count is used to store value from Reservation
    int i, j, k; // used for loops
    char temptime[16]; // The temp variables used to store strings for time, date and room
    char tempdate[16];
    char temproom[16];
    char MTHF[6][16] = {"09:15-10:45", "11:00-12:30", "12:45-14:15", "14:30-16:00", "16:15-17:45", "18:00-19:00"}; // Used for checking of time lot
    char WS[3][16] = {"09:00-12:00", "13:00-16:00", "16:15-19:15"}; // Used for checking of time lot
    char ask; //Used to ask for the day of reservation

    sub = *r; // sub is used to store value from *r
    rsub = *rcount; // rsub is used to store value from *rcount

    do {
        printf("\nEnter ID Number: ");
        scanf("%d", &tempid);
        count = ReservationCount(A, r, tempid);
        if (count == 3) { //Check if count is equal to 3 if count is 3 displays error message stating that maximum reservation made for ID no.
            printf("\nERROR! Maximum allowed reservations for ID has been met, please try again after previous reservations are finished!\n");
        } else {
            check = 1;
        }
    } while (check != 1);

    A[sub].Id = tempid;
    printf("\nEnter Full Name: "); // Inputs strings to the Struct ReserveInfo
    scanf(" %[^\n]%*c", A[sub].FullName);
    printf("\nEnter College Year in the format of Year X: ");
    scanf(" %[^\n]%*c", A[sub].CYear);
    printf("\nEnter Program: ");
    scanf(" %[^\n]%*c", A[sub].Program);

    check = 0;
    do { // Loop to check for availablity of the room based on the time and date of reservation as well as if inputed time is an appropriate time slot
        printf("Enter Preferred Room in the format of XYYYYZ (G0306B): ");
        scanf(" %[^\n]%*c", temproom);
        printf("Enter Date of Reservation in the format of MM/DD/YYYY: ");
        scanf(" %[^\n]%*c", tempdate);
        printf("Enter Time of Reservation in the format of XX:XX-XX:XX: ");
        scanf(" %[^\n]%*c", temptime);

        shedcheck = 0;
        for (i = 0; i < sub; i++)
         { // Checks if room is available
            if (strcmp(A[i].Room, temproom) == 0 && strcmp(A[i].Date, tempdate) == 0 && strcmp(A[i].Time, temptime) == 0) { 
                shedcheck = 1;
            }
        }

        if (shedcheck == 1)
         {
            printf("The chosen date and time for Room %s has already been reserved, please try again\n\n", temproom);
            strcpy(temproom, "");
            strcpy(tempdate, "");
            strcpy(temptime, "");
        } 
        else 
        {
            timeslotcheck = 0; // Set timeslotcheck to 0
            printf("Enter day of reservation (M T W H F S): "); // Ask for day of reservation
            scanf(" %c", &ask);
            if(ask == 'M'|| ask == 'T'|| ask == 'H'|| ask == 'F'|| ask == 'm'|| ask == 't'|| ask == 'h'|| ask == 'f') // If day of reservation is MTHF
            {
                k = 0; // Set k to 0
                while(exit != 1) // Loop to check if time is within the time slot of that day
                {
                    if(strcmp(temptime, MTHF[k]) != 0) 
                    {
                        timeslotcheck = 1; //If not with in time slot of that day updates values of the two variables
                        exit = 1;
                    }
                    if(k == 6) // If k is equal to 6 update updates value of exit 
                    {
                        exit = 1; // if exit is 1 terminates the loop
                    }
                    k++;

                }
                if(timeslotcheck == 1) // If timeslotcheck is 1 display error message and loops back to ask for new room, date and time
                {
                    printf("\nThe time of reservation does not correspond to the fixed timeslot of that day, please try again\n\n");
                    check = 0;
                }
                else // If timeslotcheck is still 0 stores temp room, date and time to struct ReserveInfo
                {
                    strcpy(A[sub].Room, temproom);
                    strcpy(A[sub].Date, tempdate);
                    strcpy(A[sub].Time, temptime);
                    check = 1;
                    
                }
            }
            else if(ask == 'W'|| ask == 'S'|| ask == 'w'|| ask == 's') // If day of reservation is WS
            {
                k = 0; // Set k to 0
                while(exit != 1)
                {
                    if(strcmp(temptime, WS[k]) != 0) // Loop to check if time is within the time slot of that day
                    {
                        timeslotcheck = 1;  //If not with in time slot of that day updates values of the two variables
                        exit = 1;
                    }
                    if(k == 3) // If k is equal to 3 update updates value of exit
                    {
                        exit = 1; // if exit is 1 terminates the loop
                    }
                    k++;
                }
                if(timeslotcheck == 1) // If timeslotcheck is 1 display error message and loops back to ask for new room, date and time
                {
                    printf("\nThe time of reservation does not correspond to the fixed timeslot of that day, please try again\n\n");
                    check = 0;
                }
                else
                {
                    strcpy(A[sub].Room, temproom); // If timeslotcheck is still 0 stores temp room, date and time to struct ReserveInfo
                    strcpy(A[sub].Date, tempdate);
                    strcpy(A[sub].Time, temptime);
                    check = 1;
                }
            }
        }

    } while (check != 1);

    check = 0; 
    do { // Loop to check if temppar is greater than capacity of room, if so loop back to enter new number of participants
        printf("Enter no. of participants: ");
        scanf("%d", &temppar);

        parcheck = 0;
        for (j = 0; j < rsub; j++) { // Searches for the room and its capacity 
            if (strcmp(B[j].Rooms, temproom) == 0 && temppar > B[j].Capacity) {
                parcheck = 1; // Updates parcheck if temppar is greater than capacity
            }
        }

        if (parcheck == 1) {
            printf("The number of participants exceeds the capacity of the chosen room, please try again\n\n"); // Displays error prompt
            check = 0;
        } else { 
            A[sub].Par = temppar; // If temppar is within the capacity of room updates var A.Par of Struct ReserveInfo 
            check = 1;
        }

    } while (check != 1);

    printf("\nEnter Description of Activity: "); // Enters description of activity
    scanf(" %[^\n]%*c", A[sub].Desc);
    strcpy(A[sub].Status, "Not Completed"); // Updates the status of reservation to Not Completed

    printf("\n---RESERVATION MADE---\n");
    printf("ID Number: %d\n", A[sub].Id);
    printf("Name of Reserver: %s\n", A[sub].FullName);
    printf("%s\n", A[sub].CYear);
    printf("Program: %s\n", A[sub].Program);
    printf("Date of Reservation: %s\n", A[sub].Date);
    printf("Time of Reservation: %s\n", A[sub].Time);
    printf("Selected Room: %s\n", A[sub].Room);
    printf("Number of Participants: %d\n", A[sub].Par);
    printf("Description of Activity: %s\n", A[sub].Desc); // Prints all previous inputed information to show reservation is succesful

    *r = *r + 1; // updates the number of int rec
}

/* This function allows the user to edit the details (ID, Name, Year, Program,
   Date, Time, Room, Description, and Status) of a chosen Reservation which 
   will update the said Reservation in the array of structures "ReserveInfo"
@param *A is the pointer array for the Structure ReservationInfo
@param *B is the pointer array for the Structure BRooms
@param *r is the pointer for the int rec
@param *rcount is the pointer for the int Roomcount
@return none as the fuction is void
Precondition: Inputs must be a string or int
*/
void EditReservation(struct ReserveInfo *A, struct BRooms *B, int *r, int *rcount)
{
	int i, j; //Used for loops 
	int pos; //Used to edit specific reservation
	char op; //Used in switch case to edit chosen detail
	
	char temptime[16]; // The temp variables used to store strings for time, date and room
    char tempdate[16];
    char temproom[16];
    char tempstatus[16];

	char MTHF[6][16] = {"09:15-10:45", "11:00-12:30", "12:45-14:15", "14:30-16:00", "16:15-17:45", "18:00-19:00"}; // Used for checking of time lot
    char WS[3][16] = {"09:00-12:00", "13:00-16:00", "16:15-19:15"}; // Used for checking of time lot
    char ask; //Used to ask for the day of reservation
    
    int nReserved = *r, nRooms = *rcount; //Value holders from *r and *rcount
	
	for(i = 0; i < nReserved; i++) //Display all current reservations
	{
		printf("[%d] %s, %s, %s, %s\n", i+1, A[i].FullName, A[i].Room, A[i].Date, A[i].Time); //Loop to print all present reservations
	}
	
	printf("Reservation number [x]: ");
	scanf("%d", &pos); //Get the index of the chosen reservation to edit
	
	do
	{
		
		//Display reservation details
		printf("[1] %d\n", A[pos-1].Id);
		printf("[2] %s\n", A[pos-1].FullName);
		printf("[3] %s\n", A[pos-1].CYear);
		printf("[4] %s\n", A[pos-1].Program);
		printf("[5] %s\n", A[pos-1].Date);
		printf("[6] %s\n", A[pos-1].Time);
		printf("[7] %d\n", A[pos-1].Par);
		printf("[8] %s\n", A[pos-1].Room);
		printf("[9] %s\n", A[pos-1].Desc);
		printf("[0] %s\n", A[pos-1].Status);
		
		//Ask the user which detail to edit
		printf("Option: ");
		scanf(" %c", &op);
		
		switch(op)
		{
		case '0': //Edit the status of the reservation. If status is set to 'Complete', reservation will be deleted.
			printf("New Status: ");
			scanf("%c", &tempstatus);
			if(strcmp(tempstatus, "Complete") == 0)
			{
				A[pos] = A[pos+1];
				*r--;
				printf("Status changed. Reservation completed. Returning...");
				op = '!';
			}
			else
			{
				printf("Change made. Press enter to continue editing or enter [!] to exit\n");
			}
			
		break;
		
		case '1': //Edit the ID of the reservation
			printf("New ID: ");
			scanf("%d", &A[pos-1].Id);
			printf("Change made. Enter to continue edit or enter [!] to exit\n");
		break;
		
		case '2':
			printf("New Name: "); //Edit the ID of the reservation
			scanf(" %[^\n]%*c", A[pos-1].FullName);
			printf("Change made. Press enter to continue editing or enter [!] to exit\n");
		break;
		
		case '3':
			printf("New Year: "); //Edit the year level of the reservation
			scanf(" %[^\n]%*c", A[pos-1].CYear);
			printf("Change made. Press enter to continue editing or enter [!] to exit\n");
		break;
		
		case '4':
			printf("New Program: "); //Edit the Program of the reservation
			scanf(" %[^\n]%*c", A[pos-1].Program);
			printf("Change made. Press enter to continue editing or enter [!] to exit\n");
		break;
		
		case '5':
			printf("New Date: "); //Edit the Date of the reservation.
			scanf(" %[^\n]%*c", &tempdate);
			printf("Day of Date (M T W H F S): ");
			scanf("%c", &ask);
			if(ask == 'M' || ask == 'T' || ask == 'H' || ask == 'F' || ask ) //'ask' is for checking if the day of the new Date aligns with the timeslots for that day.
			{
				for(i = 0; i < nReserved; i++)
				{
					if(strcmp(A[pos-1].Time, MTHF[i]) != 0) //If timeslot is not allowed for new Date, display error and asks for another input.
					{
						printf("Error. Time reserved is cannot be used on that date. Try again.\n");
					}
					else if(strcmp(A[pos-1].Time, MTHF[i]) == 0) //If timeslot is allowed for new Date, update A[pos-1].Date with tempdate
					{
						strcpy(A[pos-1].Date, tempdate);
						printf("Change made. Press enter to continue editing or enter [!] to exit\n");
					}
					else
					{
						printf("Invalid. Try again.\n");
					}
				}
			}
			else if(ask == 'W' || ask == 'S' || ask == 'w'|| ask == 's')
			{
				for(i = 0; i < nReserved; i++)
				{
					if(strcmp(A[pos-1].Time, WS[i]) != 0)
					{
						printf("Error. Time reserved is cannot be used on that date. Try again.\n");
					}
					else if(strcmp(A[pos-1].Time, WS[i]) == 0)
					{
						strcpy(A[pos-1].Date, tempdate);
						printf("Change made. Press enter to continue editing or enter [!] to exit\n");
					}
					else
					{
						printf("Invalid. Try again.\n");
					}
				}
			}
			else
			{
				printf("Invalid. Try again.\n");
			}
		break;
		
		case '6':
			printf("New Time: "); //Edit the time slot of the Reservation
			scanf(" %[^\n]%*c", &temptime);
			printf("Day of Reservation (M | T | W | H | F | S): ");
			scanf("%c", &ask);
			
			if(ask == 'M' || ask == 'T' || ask == 'H' || ask == 'F' || ask == 'm'|| ask == 't'|| ask == 'h'|| ask == 'f') //Check if new Time slot is within the range of time slots for that day
			{
				for(i = 0; i < nReserved; i++)
				{
					if(strcmp(temptime, MTHF[i]) != 0) //If temptime is not valid, display error and asks for another input.
					{
						printf("Error. Time reserved is cannot be used on that date. Try again.\n");
					}
					else if(strcmp(A[pos-1].Time, MTHF[i]) == 0)
					{
						strcpy(A[pos].Date, tempdate); //If temptime is valid, update A[pos-1].Time with temptime
						printf("Change made. Press enter to continue editing or enter [!] to exit\n");
					}
					else
					{
						printf("Invalid. Try again.\n");
					}
				}
			}
			else if(ask == 'W' || ask == 'S' || ask == 'w'|| ask == 's')
			{
				for(i = 0; i < nReserved; i++)
				{
					if(strcmp(temptime, WS[i]) != 0)
					{
						printf("Error. Time reserved is cannot be used on that date. Try again.\n");
					}
					else if(strcmp(A[pos-1].Time, WS[i]) == 0)
					{
						strcpy(A[pos-1].Date, tempdate);
						printf("Change made. Press enter to continue editing or enter [!] to exit\n");
					}
					else
					{
						printf("Invalid. Try again.\n");
					}
				}
			}
			else
			{
				printf("Invalid. Try again.\n");
			}
			
			printf("Change made. Press enter to continue editing or enter [!] to exit\n");
		break;
		
		case '7': //Edit the value of participants of reservation
			printf("New Participants: "); 
			scanf("%d", &A[pos-1].Par);
			printf("Change made. Press enter to continue editing or enter [!] to exit\n");
		break;
		
		case '8': //Edit the room of the reservation
			printf("New Room: ");
			scanf(" %[^\n]%*c", temproom);
			
			i = 0;
			
			do
			{
				if(strcmp(temproom, B[i].Rooms) == 0) //Check if room is valid
				{
					for(j = 0; j < nReserved; j++) //If yes, loop check if room is reserved
					{
						if(strcmp(temproom, A[i].Room) == 0)
						{
							if(strcmp(A[pos-1].Time, A[i].Time) == 0) //If yes, display error and ask again
							{
								printf("Error. Room already reserved for the timeslot."); 
							}
							else //If not, change A[pos-1].Room with temproom
							{
								strcpy(A[pos-1].Room, temproom);
								printf("Room changed. Press enter to continue editing or enter [!] to exit\n");
							}
						}
					}
				}
				i++;
			}while(strcmp(temproom, B[i].Rooms) == 0);
			
		break;
		
		case '9': //Edit the description of the reservation
			printf("New Description: ");
			scanf(" %[^\n]%*c", A[pos-1].Desc);
			printf("Change made. Press enter to continue editing or enter [!] to exit\n");
		break;
		}
		
	}while(op != '!');
}

/* This function allows the user to delete a chosen Reservation which 
   will update the said Reservation in the array of structures "ReserveInfo"
@param *A is the pointer array for the Structure ReservationInfo
@param *r is the pointer for the int rec
@return none as the fuction is void
Precondition: Inputs must be a string or int
*/
void DeleteReservation(struct ReserveInfo *A, int *r)
{
	int i, j, pos; //Used for looping and get index of reservation to be deleted
	char ask; //Ask to proceed with deleting the reservation
	
	//Display all current reservations
	for(i = 0; i < *r; i++){
		printf("[%d] %s, %s, %s, %s\n", i, A[i].FullName, A[i].Room, A[i].Date, A[i].Time);
	}
	
	//Choose reservation
	printf("Please input the reservation number of the customer [index]: ");
	scanf("%d", &pos);
	
	printf("\n Are you sure you want to delete this reservation? (Y/N): ");
	scanf(" %c", &ask);
	
	if(ask == 'Y' || ask == 'y') //If yes, proceed with delete
	{
		for(j = i; j < (*r - 1); j++)
		{
			A[pos] = A[pos+1]; //Update list of reservations
		}
		(*r)--; //Update value of rec in main
		printf("Reservation deleted. Returning.");
		printf(".");
		printf(".\n");
	
	}
	else //If no, cancel delete
	{
		printf("Reservation not deleted. Returning.");
		printf(".");
		printf(".\n");
	}
}

/* This function exports the records of the Structure ReserveInfo
@param *A is the pointer array for the Structure ReserveInfo 
@param *r is the pointer for the int rec
@return none as the fuction is void
Precondition: None as this function automatically writes the data into a txt file
*/
void ExportReservations(struct ReserveInfo *A, int *r)
{
    FILE *fp;
    int i;
    
    fp = fopen("ReservationList.txt", "w");
    for(i = 0; i < *r; i++)
    {
        fprintf(fp, "%d\n", A[i].Id);
	    fprintf(fp, "%s\n", A[i].FullName);
	    fprintf(fp, "%s\n", A[i].CYear);
	    fprintf(fp, "%s\n", A[i].Program);
	    fprintf(fp, "%s\n", A[i].Date);
	    fprintf(fp, "%s\n", A[i].Time);
	    fprintf(fp, "%s\n", A[i].Room);
        fprintf(fp, "%d\n",  A[i].Par);
        fprintf(fp, "%s\n", A[i].Desc);
        strcpy(A[i].Status, "Complete");
        strcat(A[i].Status, "\n");+
        fprintf(fp, "%s\n", A[i].Status);
    }
    printf("--RESERVATIONS EXPORTED--\n\n");
    fclose(fp);
}

int main()
{
    struct ReserveInfo Info[SIZE]; // Struct for Info of Reservers
    struct BRooms Class[ROOMS]; // Struct for the Rooms available for reservation
    int rec = 0; // Number recorded reservations
    int Roomcount = 0; //Number of Rooms available for reservation
    int dMenu, COption, ROption; // Varaibles to hold the int recieved from the function calls
    int check; //Varaible used for checking loop conditions for create reservations
    char ask; // Variable used to store the answer for creating a Consecutive reservation

    do{
        dMenu = displayMenu();
        switch(dMenu) // Switch case for the Main Menu
        {
            case 1:
                do{
                    COption = displayAdminModule();
                    switch(COption)
                    {
                        case 1: // Case 1 of Case 1 is for Importing Rooms
                            printf("\nImport Rooms\n");
                            ImportRooms(Class, &Roomcount);
                            break;
                        
                        case 2: // Case 2 of Case 1 is for Importing Reservations
                            printf("\nImport Reservations\n");
                            ImportReservations(Info, &rec);
                            break;
                        
                        case 3: // Case 3 of Case 1 is for Returns back to Main menu
                            printf("Returning to Main Menu\n\n");
                            break;
                        
                        default: // Default Case for desplaying error message
                            printf("Wrong input Try again!\n");
                    }

                }while(COption != 3); //Condition to terminate loop
                break;
            
            case 2:
                do{
                    ROption = displayReservationModule();
                    switch(ROption) // Switch case for the Reservation Module
                    {
                        case 1: // Case 1 of Case 2 is for Displaying Rooms and Time slots
                            printf("\nDisplaying Rooms and Time\n");
                            DisplayRooms(Class, &Roomcount);
                            break;

                        case 2: // Case 2 of Case 2 is for CreateReservation
                            printf("\nMaking Reservation\n");
                            do{
                                CreateReservation(Info, Class, &rec, &Roomcount);
                                printf("\nWould you like to make a consecutive reservation? (Y/N): "); // Ask if making consecutive reservation if Y performs loop if N returns to Reservation Module
                                scanf("%c", &ask); 
                                if(ask == 'Y' || ask == 'y')
                                {
                                    printf("\nMaking Consecutive Reservation\n\n");
                                    check = 0;
                                }
                                else if(ask == 'N' || ask == 'n')
                                {
                                    printf("Returning to Reservation Module\n\n");
                                    check = 1;
                                }

                            }while(check != 1);
                            printf("Returning to Reservation Module\n\n");
                            break;

                        case 3: // Case 3 of Case 2 is for Edit Reservation
                            if(rec == 0) 
                            {
                                printf("\nNO RESERVATION DETECTED\n");
                                printf("Add reservation to edit\n\n");
                            }
                            else
                            {
                                printf("\nEdit Reservation\n");
                                EditReservation(Info, Class, &rec, &Roomcount);
                            }
                            break;

                        case 4: // Case 4 of Case 2 is for Removing Reserations
                            if(rec == 0)
                            {
                                printf("\nNO RESERVATION DETECTED\n");
                                printf("Add reservation to delete\n\n");
                            }
                            else
                            {
                                printf("\nDelete Reservation\n");
                                DeleteReservation(Info, &rec);
                            }
                            break;
                        
                        case 5:// Case 5 of Case 2 is for Returning back to Main Menu
                            printf("Returning to Main Menu\n\n");
                            break;

                        default: // Default Case for desplaying error message
                            printf("Wrong Input Try again\n");
                    }

                }while(ROption != 5);
                break;
                
            case 3: // Case 3 Prints Reservation to a txt file and terminates the program
                printf("EXPORTING RESERVATIONS .....\n");
                ExportReservations(Info, &rec);
                printf("EXPORTING COMPLETED\n");
                printf("RESERVATIONS EXPORTED: %d", rec);
                printf("\nExecute Order 66");
                break;

            default: // Default Case for desplaying error message
                printf("Wrong input Try again!\n");
                break;  
        }

    }while(dMenu != 3);

    return 0;
}
