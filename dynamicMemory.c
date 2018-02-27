#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int studentId;
	double grade;
} GradeRecord;

void printRecord(const GradeRecord* record) {
	printf("RECORD: student #%d grade = %0.2f\n", record->studentId, record->grade);
}
typedef struct {
	GradeRecord* pRecords;
	size_t numRecords;
} Gradebook;
Gradebook* initializeGradebook() {
	Gradebook* gradebook = malloc(sizeof(Gradebook));
	gradebook->pRecords = NULL;
	gradebook->numRecords = 0;
	return gradebook;
}
void addRecord(Gradebook* gradebook, int studentId, double grade) {
	// increase the size of the gradebook
	size_t newNumRecords = gradebook->numRecords + 1;
	GradeRecord* pNewRecords = malloc(newNumRecords * sizeof(GradeRecord));
// copy elements from old gradebook into new one and cleanup the old one

		if (gradebook->pRecords != NULL) {
			memcpy(pNewRecords, gradebook->pRecords, gradebook->numRecords * sizeof(GradeRecord));
			free(gradebook->pRecords);
		}
	// update current gradebook information
		gradebook->pRecords = pNewRecords;
		gradebook->numRecords = newNumRecords;
	// get pointer to added element and initialize 
		GradeRecord* newRecord = &(gradebook->pRecords[gradebook->numRecords - 1]);
		newRecord->studentId = studentId;
		newRecord->grade = grade;
}

	void updateRecord(Gradebook* gradebook, int studentId, double grade) {
		GradeRecord* record = NULL;
		// find the student record we want to update
		for (int i = 0; i < gradebook->numRecords; ++i){ 
			if (gradebook->pRecords[i].studentId == studentId)
			{            
				record = gradebook->pRecords + i;
				break;
			}
		}
		// update the record if we found it
		if (record != NULL)
		{ 
			record->grade = grade;
		}
	}
		void printGrades(const Gradebook* gradebook) {
			printf("GRADEBOOK contains %d students\n", gradebook->numRecords);
			for (int i = 0; i < gradebook->numRecords; ++i) {
				GradeRecord* record = gradebook->pRecords + i;
				printf("\t");
				printRecord(&gradebook->pRecords[i]);
			}
		}
		void cleanUp(const Gradebook* gradebook) {
			
			free(gradebook->pRecords);
			free(gradebook);
			gradebook = NULL;
		}
		
		int main() {
			Gradebook* grades = initializeGradebook();
			printGrades(grades);
			addRecord(grades, 24, 3.1);
			addRecord(grades, 129, 3.1);
			addRecord(grades, 31, 3.1);
			addRecord(grades, 44, 3.1);
			addRecord(grades, 5, 3.1);
			printGrades(grades);
			updateRecord(grades, 24, 4.0);
			updateRecord(grades, 31, 4.0);
			printGrades(grades);
			cleanUp(grades);
			

			// TODO cleanup the gradebook along with it's current graderecords


			// HINT: everything thas has been allocated on the heap needs to be freed
		}
			// copy elements from old gradebook into new one and cleanup the old one