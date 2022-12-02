/*
 * Queue.h
 *
 *  Created on: Dec 2, 2022
 *      Author: Ebram Habib
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "stdio.h"
#include "Platform_Types.h"
#include "stdlib.h"
#include "string.h"

#define DPRINTF(...) {fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}


typedef struct {     // student information structure
	uint8_t fname[50];
	uint8_t lname[50];
	uint32_t roll;
	float32_t GPA;
	uint32_t cid[10];
} st;

st buffer[50];   // the buffer contains 50 students data

//FIFO Data Types

typedef struct {
	uint32_t length;
	uint32_t count;
	st* base;
	st* head;
	st* tail;
}FIFO_Buff_t;

typedef enum {
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL,
	FIFO_ERROR
}FIFO_BUFF_STATUS;

//FIFO APIs
FIFO_BUFF_STATUS FIFO_Init (FIFO_Buff_t* fifo, st* buff, uint32_t length); //Initialize the FIFO Buffer
int check_roll(FIFO_Buff_t*fifo,uint32_t x);  		// to check if roll number is already taken
FIFO_BUFF_STATUS Add_Student_Manually(FIFO_Buff_t*fifo); 		// to add a student manually
FIFO_BUFF_STATUS Add_Students_From_File(FIFO_Buff_t*fifo); 		// to add a student from a text file
FIFO_BUFF_STATUS Find_Student_By_Roll(FIFO_Buff_t*fifo); 		// to find a student using the roll number
FIFO_BUFF_STATUS Find_Student_By_Fname(FIFO_Buff_t*fifo); 		// to find a student using the first name
FIFO_BUFF_STATUS Find_Student_By_CourseID(FIFO_Buff_t*fifo); 	// to find a student using the course ID
FIFO_BUFF_STATUS Find_Total_Num_Of_Students(FIFO_Buff_t*fifo); 	// to find the total number of students
FIFO_BUFF_STATUS Delete_Student_By_Roll(FIFO_Buff_t*fifo);		// to delete a student by roll number
FIFO_BUFF_STATUS Update_Student_By_Roll(FIFO_Buff_t*fifo); 		// to update a student by roll number
FIFO_BUFF_STATUS Show_All_Students(FIFO_Buff_t*fifo); 			// to show all students in the queue
void Exit_Program();											// to exit the program


#endif /* QUEUE_H_ */
