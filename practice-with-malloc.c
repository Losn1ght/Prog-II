#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char fname[20];
	char lname[20];
}name;

typedef struct{
	char subjectName[10];
	int grade;
}subjectGrade;

typedef struct{
	int idNum;
	name studentName;
	char course[10];
	subjectGrade studentGrade[3];
}studentInfo;

typedef struct{
	studentInfo *studentList;
	int count;
}classRecord;


// Make function definition
studentInfo addNewStudent(char [], char [], char [], int , char [], int , char [], int , char [], int );
void addFront(classRecord*, studentInfo);


int main(){
	// ADT should have the following operations : Insert, Delete, Update, Traverse
	// Insert - Front, Last, Into, Sorted
	// Delete - Front, Last, at Position, Item
	
	classRecord record;
	studentInfo addFrontStudent;
	int i = 0;
	record.count = 0;
	int initSize;
	char fname[15];
	
	printf("Input class size: ");
	scanf("%d", &initSize);	

	record.studentList = (studentInfo*)malloc(sizeof(studentInfo) * initSize);
	
	for(i = 0; i < initSize; i++){
		scanf("%s", fname);
		record.studentList[i]= addNewStudent(fname, "Juab", "BS-IT", 22102538, "Web2", 90, "Prog2", 91, "IM2", 95);
		record.count++;
	}
	
	printf("Insert front: ");
	scanf("%s", fname);
	addFrontStudent =  addNewStudent(fname, "Juab", "BS-IT", 22102538, "Web2", 90, "Prog2", 91, "IM2", 95);
	addFront(&record, addFronStudent);

//  Display the STUDENT LIST
	printf("STUDENT LIST\n");
	for(i = 0; i < record.count; i++){
		printf("%s\n", record.studentList[i].studentName.fname);
	}
	
	
	free(record.studentList);
	return 0;
}
void addFront(classRecord *record,studentInfo studentToAdd){
	int i = 0;
	
	record->studentList = realloc(record->studentList,sizeof(studentInfo)*(record->count+1));
	for(i = record->count; i >= 0; i--){
		record->studentList[i] = record->studentList[i-1];
	}
	
	record->studentList[0] = studentToAdd;
 	record->count++;
	
}

// Finish the function definition
studentInfo addNewStudent(char fname[], char lname[], char courseName[], int idNum, char sub1[], int sub1Grade, char sub2[], int sub2Grade, char sub3[], int sub3Grade){
	
	studentInfo newStudent;
	
	newStudent.idNum = idNum;
	strcpy(newStudent.studentName.fname, fname);
	strcpy(newStudent.studentName.lname, lname);
	strcpy(newStudent.course, courseName);
	
	strcpy(newStudent.studentGrade[0].subjectName, sub1);
	newStudent.studentGrade[0].grade = sub1Grade;
	
	strcpy(newStudent.studentGrade[1].subjectName, sub2);
	newStudent.studentGrade[1].grade = sub2Grade;
	
	strcpy(newStudent.studentGrade[2].subjectName, sub3);
	newStudent.studentGrade[2].grade = sub3Grade;
	
	return newStudent;
	
}

// Insert Front || Start at the last
//	Concept | Logic
//	int x[5] = {1, 2, 3, 4};
//	int count = 4;	
//	
//	for(i = count; i > 0; i--){
//		x[i] = x[i-1];
//	}
//	
//	x[0] = 10;
//	count++;
//	
//	for(i = 0; i < count; i++){
//		printf("%d ", x[i]);
//	}
	

