#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char studentID[10];
    char firstName[20];
    char lastName[20];
    double progressMark;
    double finalExamMark;
    char grade;
} Student;

void calculateGradingSummary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    char subjectID[20];
    char subjectName[50];
    char semesterID[10];
    char progessString[6];
    char finalString[6];
    int progressWeight, finalExamWeight;
    int studentCount;
    Student students[MAX_STUDENTS];
    double averageMark = 0.0;
    int highestMarkIndex = 0;
    int lowestMarkIndex = 0;

    // Read subject information
    fscanf(file, "SubjectID|%s\n", subjectID);
    fscanf(file, "Subject|%[^\n]\n", subjectName);
    fscanf(file, "F|%d|%d\n", &progressWeight, &finalExamWeight);
    fscanf(file, "Semester|%s\n", semesterID);
    fscanf(file, "StudentCount|%d\n", &studentCount);

    // Read student information
    for (int i = 0; i < studentCount; i++) {
        fscanf(file, "S|%[^|]|%[^|]|%[^|]| %[^|]| %[^|]| %c |\n",
               students[i].studentID,
               students[i].firstName,
               students[i].lastName,
               progessString,
               finalString,
               &students[i].grade);

               for (int j=0; j<6; j++){
                printf("M %c\n",progessString[j]);
                if (progessString[j] == '.'){
                    students[i].progressMark += (progessString[j-2]==49?10:0) + progessString[j-1] - 48 + (progessString[j+1] - 48)/10 + (progessString[j+2] - 48)/10;
                    break;
                }
               }

               printf("std cnt %s \n", students[i].studentID);
               printf("std cnt %s \n", students[i].firstName);
               printf("std cnt %s \n", students[i].lastName);
               printf("std cnt |%d| \n", students[i].progressMark);
               printf("std cnt |%s| \n", finalString);
               printf("std cnt %c \n", students[i].grade);

        averageMark += (students[i].progressMark * progressWeight +
                        students[i].finalExamMark * finalExamWeight);
        if (students[i].grade > students[highestMarkIndex].grade)
            highestMarkIndex = i;
        if (students[i].grade < students[lowestMarkIndex].grade)
            lowestMarkIndex = i;
    }
    averageMark /= studentCount;

    fclose(file);

    // Output grading summary
    printf("The student with the highest mark is: %s\n %s\n %s\n",
           students[highestMarkIndex].firstName,
           students[highestMarkIndex].lastName,
           students[highestMarkIndex].studentID);
    printf("The student with the lowest mark is: %s %s %s\n",
           students[lowestMarkIndex].firstName,
           students[lowestMarkIndex].lastName,
           students[lowestMarkIndex].studentID);
    printf("The average mark is: %.2lf\n", averageMark);

    // Calculate histogram
    int gradeCounts[5] = {0};
    for (int i = 0; i < studentCount; i++) {
        switch (students[i].grade) {
            case 'A':
                gradeCounts[0]++;
                break;
            case 'B':
                gradeCounts[1]++;
                break;
            case 'C':
                gradeCounts[2]++;
                break;
            case 'D':
                gradeCounts[3]++;
                break;
            case 'F':
                gradeCounts[4]++;
                break;
        }
    }

    // Output histogram
    printf("A:");
    for (int i = 0; i < gradeCounts[0]; i++) {
        printf("*");
    }
    printf("\nB:");
    for (int i = 0; i < gradeCounts[1]; i++) {
        printf("*");
    }
    printf("\nC:");
    for (int i = 0; i < gradeCounts[2]; i++) {
        printf("*");
    }
    printf("\nD:");
    for (int i = 0; i < gradeCounts[3]; i++) {
        printf("*");
    }
    printf("\nF:");
    for (int i = 0; i < gradeCounts[4]; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    const char *filename = "IT4062_20151.txt";
    calculateGradingSummary(filename);
    scanf("%s");
    return 0;
}
