/*
 * Queue.c
 *
 *  Created on: Dec 2, 2022
 *      Author: Ebram Habib
 */

#include "Queue.h"

//FIFO APIs
FIFO_BUFF_STATUS FIFO_Init (FIFO_Buff_t* fifo, st* buff, uint32_t length) //Initialize the FIFO Buffer
{
	if(!fifo || !buff)
		return FIFO_NULL;

	fifo->base = buff;
	fifo->head = buff;
	fifo->tail = buff;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_NO_ERROR;
}

int check_roll(FIFO_Buff_t* fifo,uint32_t x)  // to check if roll number is exist before or not
{
	int y;
	st* ptr=fifo->base;

	for(y=0;y<(fifo->count);y++)
	{
		if(ptr->roll==x)
		{
			return 0;
		}
		ptr++;
	}
	return 1;
}

FIFO_BUFF_STATUS Add_Student_Manually(FIFO_Buff_t* fifo)
{
	uint32_t x,y;
	uint32_t temp_int=0;
	uint8_t temp_str[50];

	if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
	{
		DPRINTF("database not exist  \n");
		return FIFO_NULL;
	}
	if(fifo->count==fifo->length)   // check if queue is full
	{
		DPRINTF("[ERROR] data base is full\n");
		return FIFO_FULL;
	}

	DPRINTF("--------------------------------------------\n");
	DPRINTF("Add Student Details \n");
	DPRINTF("--------------------------------------------\n");
	DPRINTF("Enter the Roll Number\n");
	gets(temp_str);
	temp_int =atoi(temp_str);
	if(check_roll(fifo,temp_int)==0) // Checking if the roll number is already taken
	{
		DPRINTF("[ERROR] Roll Number is already taken \n");
		return FIFO_ERROR;
	}

	fifo->head->roll=atoi(temp_str);
	DPRINTF("Enter First name of the student:\n");
	gets(fifo->head->fname);
	DPRINTF("Enter Last name of the student:\n");
	gets(fifo->head->lname);
	DPRINTF("Enter the GPA you obtained\n");
	gets(temp_str);
	fifo->head->GPA=atof(temp_str);
	DPRINTF("Enter the course ID of each course\n");
	for(x=0;x<5;x++)
	{
		DPRINTF("course %d ID :\n",x+1);
		gets(temp_str);
		y=atoi(temp_str);
		if(y>0 && y<=30)              // check if course ID is valid Assuming there are 30 courses
		{
			fifo->head->cid[x]=y;
			continue;
		}
		DPRINTF("[ERROR] course ID is not valid\n");
		x--;
	}
	fifo->head++;
	fifo->count++;
	DPRINTF("[INFO] Student Details are added successfully \n");
	DPRINTF("--------------------------------------------\n");
	DPRINTF("[INFO] the total number of students is : %d\n",fifo->count);
	DPRINTF("[INFO] you can add up to %d students \n",fifo->length);
	DPRINTF("[INFO] you can add %d students more \n",fifo->length - fifo->count);
	DPRINTF("--------------------------------------------\n");
	return FIFO_NO_ERROR;

}

FIFO_BUFF_STATUS Add_Students_From_File(FIFO_Buff_t* fifo)
{

	uint8_t f_name[50];
	uint8_t l_name[50];
	uint32_t roll_num,cid[5],x,file_count=0,flag=0;
	float32_t GPA;
	uint32_t line = 0;
	if(!fifo->base || !fifo->head || !fifo->tail )  // check if queue exists or not
	{
		DPRINTF("database not exist  \n");
		return FIFO_NULL;
	}
	if(fifo->count==fifo->length)   // check if queue is full
	{
		DPRINTF("[ERROR] data base is full\n");
		return FIFO_FULL;
	}
	FILE *p_file = fopen("text.txt","r"); 	// opening text file to read data from it
	if(p_file==NULL)						// checking if the file exists
	{
		DPRINTF("------------------------------ \n");
		DPRINTF("[ERROR] File not found \n");
		return FIFO_ERROR;
	}

	// reading from file

	while( fscanf(p_file,"%d %s %s %f %d %d %d %d %d [^\n]", &roll_num, f_name,l_name,&GPA,&cid[0],&cid[1],&cid[2],&cid[3],&cid[4])!=EOF)
	{
		if(fifo->count==fifo->length)
		{   DPRINTF("----------------------------\n");
		DPRINTF("[ERROR] data base is full\n");
		DPRINTF("[INFO] students added : %d\n",file_count);
		DPRINTF("[INFO] remaining students due to size or errors are : %d\n",line-file_count);

		return FIFO_FULL;
		}
		if(check_roll(fifo,roll_num)==0)
		{
			DPRINTF("[ERROR] IN line %d : Roll Number is already taken before \n",line);
			line++;
			continue; // to skip this student
		}
		fifo->head->roll=roll_num;
		fifo->head->GPA=GPA;
		strcpy(fifo->head->fname,f_name);
		strcpy(fifo->head->lname,l_name);
		for(x=0; x<5; x++)
		{
			flag=0;
			if(cid[x]<=0 || cid[x]>30)
			{
				flag=1;    // that there is non-valid course ID
				break;
			}
			fifo->head->cid[x]=cid[x];
		}
		if(flag==1)  // non valid course ID
		{
			DPRINTF("[ERROR] IN line %d : non valid course ID we will skip this student \n",line);
			line++;
			continue; // to skip this student
		}
		fifo->head++;
		fifo->count++;
		line++;
		file_count++;    // to record successful records

	}
	DPRINTF("\nEnd of file.\n");

	// close connection
	fclose(p_file);
	DPRINTF("[INFO] students added : %d\n",file_count);
	DPRINTF("[INFO] remaining students due to errors are :%d\n",line-file_count);
	return FIFO_NO_ERROR;
}
FIFO_BUFF_STATUS Find_Student_By_Roll(FIFO_Buff_t* fifo)
{
	st* current_student = fifo->base;
	uint32_t i,y, roll_num = 0;

	if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
	{
		DPRINTF("database not exist  \n");
		return FIFO_NULL;
	}
	if(fifo->count==0)         // check if the database is empty
	{
		DPRINTF("[ERROR] Database Is Empty \n");
		DPRINTF("--------------------------------------------\n");
		return FIFO_EMPTY;
	}
	DPRINTF("Enter the Roll Number of the Student: ");
	scanf("%d", &roll_num);
	if(check_roll(fifo, roll_num) == 1)			// check if Roll number exists in the database
	{
		DPRINTF("[ERROR] Roll Number doesn't exist in the database \n");
		DPRINTF("--------------------------------------------\n");
		return FIFO_ERROR;
	}
	for(i=0;i<fifo->count;i++)
	{
		if(current_student->roll == roll_num)
		{
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Student Roll number : %d\n",current_student->roll);
			DPRINTF("Student first name : %s\n",current_student->fname);
			DPRINTF("Student last name : %s\n",current_student->lname);
			DPRINTF("Student GPA : %.2f\n",current_student->GPA);
			for(y=0;y<5;y++)
			{
				DPRINTF("course %d id : %d \n",y+1,current_student->cid[y]);
			}
			return FIFO_NO_ERROR;
		}
		current_student++;
	}
	return FIFO_NO_ERROR;
}
FIFO_BUFF_STATUS Find_Student_By_Fname(FIFO_Buff_t* fifo)
{
	st* current_student = fifo->base;
	uint8_t temp_str[50];
	uint32_t i,y,flag;
	if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
	{
		DPRINTF("database not exist  \n");
		return FIFO_NULL;
	}
	if(fifo->count==0)         // check if the database is empty
	{
		DPRINTF("[ERROR] Database Is Empty \n");
		DPRINTF("--------------------------------------------\n");
		return FIFO_EMPTY;
	}
	DPRINTF("Enter the First Name of the Student: ");
	gets(temp_str);
	for(i=0;i<fifo->count; i++) 	// search for the student inside the queue
	{
		if(strcmpi(current_student->fname, temp_str) == 0) 	// compare the first names of each student with the entered first name without case sensitive
		{
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Student Roll number : %d\n",current_student->roll);
			DPRINTF("Student first name : %s\n",current_student->fname);
			DPRINTF("Student last name : %s\n",current_student->lname);
			DPRINTF("Student GPA : %.2f\n",current_student->GPA);
			for(y=0;y<5;y++)
			{
				DPRINTF("course %d id : %d \n",y+1,current_student->cid[y]);
			}
			DPRINTF("--------------------------------------------\n");
			flag=1;        // flag to know the first name found at least 1 time
		}
		current_student++;
	}
	if(flag == 0)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[ERROR] No first name matches this name\n");      // loop finished and name not found
		DPRINTF("--------------------------------------------\n");
		return FIFO_ERROR;
	}
	return FIFO_NO_ERROR;
}
FIFO_BUFF_STATUS Find_Student_By_CourseID(FIFO_Buff_t* fifo)
{
	st* current_student = fifo->base;
	uint32_t i,j,y,counter=0, temp_cid = 0;
	if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
	{
		DPRINTF("database does not exist  \n");
		return FIFO_NULL;
	}
	if(fifo->count==0)         // check if the database is empty
	{
		DPRINTF("[ERROR] Database Is Empty \n");
		DPRINTF("--------------------------------------------\n");
		return FIFO_EMPTY;
	}
	DPRINTF("Enter the course ID : ");
	scanf("%d", &temp_cid);
	if(temp_cid < 1 || temp_cid > 30)		// checking if the course ID is valid
	{
		DPRINTF("Invalid Course ID \n");
		return FIFO_ERROR;
	}
	for(i=0; i<fifo->count; i++)
	{
		for(j=0; j<5; j++)
		{
			if(current_student->cid[j] == temp_cid)
			{
				DPRINTF("--------------------------------------------\n");
				DPRINTF("Student Roll number : %d\n",current_student->roll);
				DPRINTF("Student first name : %s\n",current_student->fname);
				DPRINTF("Student last name : %s\n",current_student->lname);
				DPRINTF("Student GPA : %.2f\n",current_student->GPA);
				for(y=0;y<5;y++)
				{
					DPRINTF("course %d id : %d \n",y+1,current_student->cid[y]);
				}
				counter++; // counting the number of students in the course
			}
		}
		current_student++;
	}

	if(counter==0)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[ERROR] No Students Enrolled in this course \n");    // loop finished and students not found
		DPRINTF("--------------------------------------------\n");
		return FIFO_ERROR;
	}
	else
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[INFO] Total Number of Students Enrolled in this course is %d \n", counter);
		DPRINTF("--------------------------------------------\n");
		return FIFO_NO_ERROR;
	}
}
FIFO_BUFF_STATUS Find_Total_Num_Of_Students(FIFO_Buff_t* fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
	{
		DPRINTF("database does not exist  \n");
		return FIFO_NULL;
	}
	if(fifo->count==0)         // check if the database is empty
	{
		DPRINTF("[ERROR] Database Is Empty \n");
		DPRINTF("--------------------------------------------\n");
		return FIFO_EMPTY;
	}
	DPRINTF("[INFO] The Total Number of Students is %d\n", fifo->count);
	DPRINTF("[INFO] You Can Add Up to %d Students\n", fifo->length);
	DPRINTF("[INFO] You Can Add %d more Students\n", fifo->length - fifo->count);
	DPRINTF("--------------------------------------------\n");

	return FIFO_NO_ERROR;
}
FIFO_BUFF_STATUS Delete_Student_By_Roll(FIFO_Buff_t* fifo)
{
	uint32_t i,y,x, roll_num;
	st* current_student = fifo->base;

	if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
	{
		DPRINTF("database does not exist  \n");
		return FIFO_NULL;
	}
	if(fifo->count==0)         // check if the database is empty
	{
		DPRINTF("[ERROR] Database Is Empty \n");
		DPRINTF("--------------------------------------------\n");
		return FIFO_EMPTY;
	}
	DPRINTF("Enter the Roll Number of the Student you Wish to Delete: ");
	scanf("%d", &roll_num);
	if(check_roll(fifo, roll_num) == 1)			// check if Roll number exists in the database
	{
		DPRINTF("[ERROR] Roll Number doesn't exist in the database \n");
		DPRINTF("--------------------------------------------\n");
		return FIFO_ERROR;
	}
	for(i=0;i<fifo->count;i++)		// searching for the student with the entered roll number
	{
		if(current_student->roll == roll_num)
		{
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Student Roll number : %d\n",current_student->roll);
			DPRINTF("Student first name : %s\n",current_student->fname);
			DPRINTF("Student last name : %s\n",current_student->lname);
			DPRINTF("Student GPA : %.2f\n",current_student->GPA);
			for(y=0;y<5;y++)
			{
				DPRINTF("course %d id : %d \n",y+1,current_student->cid[y]);
			}

			// Deleting student
			for(x=i;x<fifo->count;x++)
				{
					buffer[x]=buffer[x+1];
				}

			// Update count of queue
			fifo->count--;

			// Check if we reach the last item in the queue
			if((fifo->tail + 1) == (fifo->base + fifo->length))
			{
				// Set to the start
				fifo->tail = fifo->base;
			}
			else
			{
				// Just go to the next tail
				fifo->tail++;
			}
			DPRINTF("[INFO] The Student With Roll Number %d has been Deleted Successfully \n", roll_num);
			break;
		}
	}
	return FIFO_NO_ERROR;
}
FIFO_BUFF_STATUS Update_Student_By_Roll(FIFO_Buff_t* fifo)
{
	uint32_t i,j,y, roll_num, choice;
	uint8_t temp_str [50];
	st* current_student = fifo->base;

	if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
	{
		DPRINTF("database does not exist  \n");
		return FIFO_NULL;
	}
	if(fifo->count==0)         // check if the database is empty
	{
		DPRINTF("[ERROR] Database Is Empty \n");
		DPRINTF("--------------------------------------------\n");
		return FIFO_EMPTY;
	}
	DPRINTF("Enter the Roll Number of the Student you Wish to Update: ");
	scanf("%d", &roll_num);
	if(check_roll(fifo, roll_num) == 1)			// check if Roll number exists in the database
	{
		DPRINTF("[ERROR] Roll Number doesn't exist in the database \n");
		DPRINTF("--------------------------------------------\n");
		return FIFO_ERROR;
	}
	for(i=0;i<fifo->count;i++)		// searching for the student with the entered roll number
	{
		if(current_student->roll == roll_num)
		{
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Student Roll number : %d\n",current_student->roll);
			DPRINTF("Student first name : %s\n",current_student->fname);
			DPRINTF("Student last name : %s\n",current_student->lname);
			DPRINTF("Student GPA : %.2f\n",current_student->GPA);
			for(y=0;y<5;y++)
			{
				DPRINTF("course %d id : %d \n",y+1,current_student->cid[y]);
			}
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Enter the Number of the Item you Wish to Update\n");
			DPRINTF("1. First Name\n");
			DPRINTF("2. Last Name\n");
			DPRINTF("3. Roll Number\n");
			DPRINTF("4. GPA \n");
			DPRINTF("5. Courses\n");
			scanf("%d", &choice);
			switch(choice)
			{
			case 1:
				DPRINTF("Please Enter The New First Name\n");
				gets(current_student->fname);
				DPRINTF("[INFO] Updated Successfully \n");
				break;
			case 2:
				DPRINTF("Please Enter The New Last Name\n");
				gets(current_student->lname);
				DPRINTF("[INFO] Updated Successfully \n");
				break;
			case 3:
				DPRINTF("Please Enter The New Roll Number\n");
				scanf("%d", &roll_num);
				if(check_roll(fifo,roll_num)==0) // Checking if the roll number is already taken
				{
					DPRINTF("[ERROR] Roll Number is already taken \n");
					return FIFO_ERROR;
					break;
				}
				else
				{
					DPRINTF("[INFO] Updated Successfully \n");
					return FIFO_NO_ERROR;
					break;
				}
			case 4:
				DPRINTF("Please Enter The New GPA \n");
				gets(temp_str);
				current_student->GPA = (atof(temp_str));
				DPRINTF("[INFO] Updated Successfully \n");
				break;
			case 5:
				DPRINTF("Please Enter The New ID of each course\n");
				for(i=0;i<5;i++)
				{
					DPRINTF("course %d ID :\n",i+1);
					gets(temp_str);
					j=atoi(temp_str);
					if(j>0 && j<30)              // check if course id is available id
					{
						current_student->cid[i]=j;
						continue;
					}
					DPRINTF("[ERROR] Course ID is not Valid\n");
					i--;
				}
				DPRINTF("[INFO] Updated Successfully \n");
				break;
			default:
				DPRINTF("Incorrect Choice \n");
				return FIFO_ERROR;
			}
			// print student information after update
			DPRINTF("--------------------------------------------\n");
			DPRINTF("[INFO] Updated Successfully \n");
			DPRINTF("Student information after update \n");
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Student Roll number : %d\n",current_student->roll);
			DPRINTF("Student first name : %s\n",current_student->fname);
			DPRINTF("Student last name : %s\n",current_student->lname);
			DPRINTF("Student GPA : %.2f\n",current_student->GPA);
			for(y=0;y<5;y++)
			{
				DPRINTF("course %d id : %d \n",y+1,current_student->cid[y]);
			}
			return FIFO_NO_ERROR;
		}
		current_student++;
	}
	return FIFO_NO_ERROR;
}


FIFO_BUFF_STATUS Show_All_Students(FIFO_Buff_t* fifo)
{
	uint32_t i,y;
	st* current_student = fifo->base;

	if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
	{
		DPRINTF("database does not exist  \n");
		return FIFO_NULL;
	}
	if(fifo->count==0)         // check if the database is empty
	{
		DPRINTF("[ERROR] Database Is Empty \n");
		DPRINTF("--------------------------------------------\n");
		return FIFO_EMPTY;
	}
	for(i=0; i<fifo->count;i++)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("Student Roll number : %d\n",current_student->roll);
		DPRINTF("Student first name : %s\n",current_student->fname);
		DPRINTF("Student last name : %s\n",current_student->lname);
		DPRINTF("Student GPA : %.2f\n",current_student->GPA);
		for(y=0;y<5;y++)
		{
			DPRINTF("course %d id : %d \n",y+1,current_student->cid[y]);
		}
		current_student++;
	}
	return FIFO_NO_ERROR;
}
void Exit_Program()
{
	DPRINTF("The Program Will Close Now, GoodBye...");
	exit(0);
}
