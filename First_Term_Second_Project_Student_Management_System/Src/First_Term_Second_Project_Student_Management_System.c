/*
 * First_Term_Second_Project_Student_Management_System.c
 *
 *  Created on: Dec 2, 2022
 *      Author: Ebram Habib
 */

#include "Queue.h"


int main()
{
	uint32_t choice = 0;
	FIFO_Buff_t FIFO_Controller;

	if(FIFO_Init(&FIFO_Controller, buffer, 50) == FIFO_NO_ERROR)
			printf("FIFO INIT --------- DONE \n");

	DPRINTF("Welcome to the Student Management System\n");

	while(1)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("Choose The Task that you want to perform\n");
		DPRINTF("1. Add the Student Details Manually\n");
		DPRINTF("2. Add the Student Details From Text File\n");
		DPRINTF("3. Find the Student Details by Roll Number\n");
		DPRINTF("4. Find the Student Details by First Name\n");
		DPRINTF("5. Find the Student Details by Course ID\n");
		DPRINTF("6. Find the Total number of Students\n");
		DPRINTF("7. Delete the Student Details by Roll Number \n");
		DPRINTF("8. Update the Student Details by Roll Number \n");
		DPRINTF("9. Show all information\n");
		DPRINTF("10. To Exit\n");
		DPRINTF("--------------------------------------------\n");
		DPRINTF(" Enter your choice to perform the task\n");
		scanf("%d", &choice);
		DPRINTF("--------------------------------------------\n");

		switch(choice)
		{
		case 1:
			Add_Student_Manually(&FIFO_Controller);
			break;
		case 2:
			Add_Students_From_File(&FIFO_Controller);
			break;
		case 3:
			Find_Student_By_Roll(&FIFO_Controller);
			break;
		case 4:
			Find_Student_By_Fname(&FIFO_Controller);
			break;
		case 5:
			Find_Student_By_CourseID(&FIFO_Controller);
			break;
		case 6:
			Find_Total_Num_Of_Students(&FIFO_Controller);
			break;
		case 7:
			Delete_Student_By_Roll(&FIFO_Controller);
			break;
		case 8:
			Update_Student_By_Roll(&FIFO_Controller);
			break;
		case 9:
			Show_All_Students(&FIFO_Controller);
			break;
		case 10:
			Exit_Program();
			break;
		default :
			DPRINTF("Wrong choice\n");

		}
	}
}
