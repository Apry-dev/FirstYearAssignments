/*
    
    Author: Andrew Carty
    Student Number: C22488994
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define STUDENTNUMB 42
#define STRLEN 50 

struct studentInfo //structure containing all relevant student info
{
	int year;
	char firstName[STRLEN] ;
	char surname[STRLEN];
	char module[STRLEN];
    char studentID [STRLEN];	
    char programmeType [STRLEN];
};

void AddStudent(struct studentInfo*, int *);
void RemoveStudent(struct studentInfo*, int *);
void ReadStudent(struct studentInfo*, int *);
void StudentInfo(struct studentInfo*, int);
void mergeSort(struct studentInfo students[], int left, int right);
void merge(struct studentInfo students[], int left, int middle, int right);

int main() {
    int optionSelected, numStudents = 0;
    struct studentInfo *students = malloc(sizeof(struct studentInfo) * STUDENTNUMB);
    do {
        printf("\nWhat do you want to do?:\nSelect your option by pressing the number displayed alongside each,\n[1] Add Student\n[2] Remove Student\n[3] Display student info \n[4] sort by surname \n[5] Exit program\nEnter option here:\n");
        scanf("%d", &optionSelected);
        while(getchar() != '\n');
        
        switch (optionSelected) { //calls the function from each input
            case 1:
                AddStudent(students, &numStudents);
                break;
            case 2:
                RemoveStudent(students, &numStudents);
                break;
            case 3:
                StudentInfo(students, numStudents);
                break;
            
            case 4:
                mergeSort(students, 0, numStudents-1);
                break;
            case 5:
                printf("Exiting program...\n");
                free(students); // free memory before exiting program
                return 0;
            default:
                printf("Not a valid input, please try again.\n");
                break;
        }
    } while (1);
}

void AddStudent(struct studentInfo *students, int *numberofStudents) //adds a student to the list
{
    
    struct studentInfo newStudent;
    printf("Enter Year here:\n");
    scanf("%d", &newStudent.year);
    while(getchar() != '\n'); //buffer to remove the enter key as an input

    printf("Enter first name:\n");
    fgets(newStudent.firstName, STRLEN, stdin);

    printf("Enter Second name:\n");
    fgets(newStudent.surname, STRLEN, stdin);
    
    printf("What module are they in:\n");
    fgets(newStudent.module, STRLEN, stdin);

    printf("Enter you student ID:\n");
    fgets(newStudent.studentID, STRLEN, stdin);

    printf("Enter Student programme type (full time or part time):\n");
    fgets(newStudent.programmeType, STRLEN, stdin);

    newStudent.firstName[strlen(newStudent.firstName)-1] = '\0'; //gets rid of the space at the end of each piece of information
    newStudent.surname[strlen(newStudent.surname)-1] = '\0';
    newStudent.module[strlen(newStudent.module)-1] = '\0';
    newStudent.studentID[strlen(newStudent.studentID)-1] = '\0';
    newStudent.programmeType[strlen(newStudent.studentID)-1] = '\0';

    students[*numberofStudents] = newStudent; // add new student to end of array
    (*numberofStudents)++; // increment number of students
    printf("Student added\n");

}

void RemoveStudent(struct studentInfo *students, int *numberofStudents) //removes a student from the list
{
    char studentID [STRLEN];
    printf("Enter the ID of Student you want to remove:\n");
    fgets(studentID, STRLEN, stdin);
    studentID[strlen(studentID)-1] = '\0';

    for (int i = 0; i < *(numberofStudents); i++) //loops through the array of students
    {
        if(strcmp(students[i].studentID, studentID)==0) //if the desired student id is found
        {
            for(int j = i; j < *(numberofStudents) - 1; j++) //moves all student id's over it therefore removing it 
            {
                students[j] = students[j+1];
            } 
            printf("Student removed\n");
        }
    }
}

void StudentInfo(struct studentInfo *students, int numberofStudents) //prints the student info as needed
{

    printf("Student information\n")
    for(int i = 0; i<numberofStudents; i++)
    {
        if(numberofStudents > 0)
        {
            
            printf("Students year is: %d\n", students[i].year);
            printf("Students first name is: %s\n",students[i].firstName);
            printf("Students surname is: %s\n", students[i].surname);
            printf("Students module is: %s\n", students[i].module);
            printf("Students StudentID is: %s\n", students[i].studentID);
            printf("Students programme type is: %s\n\n", students[i].programmeType);
        }
        else
        {
            printf("Student not found\n");
        }
    }

}

void merge(struct studentInfo arr[], int left, int middle, int right)
{ //merge sort to sort students based on surname in alphabetical order
    int i, j, k;

    //splits array into left and right side
    int n1 = middle - left + 1; 
    int n2 = right - middle;

    // Create temporary arrays
    struct studentInfo L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        Right[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) 
    {
        if (strcmp(L[i].surname, R[j].surname) < 0) 
        { //if the result is negative it comes before it in the alphabet and puts it above it in the sort
            arr[k] = L[i];
            i++;
        } 
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements from the left array
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements from the right array
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct studentInfo arr[], int left, int right) 
{ //function to call the merge
    if (left < right) {
        int middle = left + (right - l) / 2;

        // Sort first and second halves using recursion
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}