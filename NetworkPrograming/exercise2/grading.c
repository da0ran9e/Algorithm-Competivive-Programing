#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100

typedef struct {
    char studentID[10];
    char firstName[20];
    char lastName[20];
    double progressMark;
    double finalExamMark;
    double mark;
    char grade;
} Student;

void removeSpaces(char *str) {
    if (str == NULL) {
        return; // Handle NULL input
    }

    int len = strlen(str);
    if (len == 0) {
        return; // Empty string, nothing to remove
    }

    // Remove trailing spaces
    while (len > 0 && (isspace(str[len - 1]) || str[len - 1] == '\t')) {
        len--;
    }
    str[len] = '\0'; // Null-terminate the trimmed string

    // Remove leading spaces
    int start = 0;
    while (isspace(str[start]) || str[start] == '\t') {
        start++;
    }

    // Shift the string to remove leading spaces
    if (start > 0) {
        memmove(str, str + start, len - start + 1); // +1 for the null terminator
    }
}

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

    char outputFileName[50];
    strcat(outputFileName, subjectID);
    strcat(outputFileName, "_");
    strcat(outputFileName, subjectID);
    strcat(outputFileName, "_rp.txt");
    FILE *outputFile = fopen(outputFileName, "a+");
    if (outputFile == NULL) {
        printf("Error: Unable to open output file %s\n", outputFileName);
        fclose(file);
        return;
    }

    // Read student information
    for (int i = 0; i < studentCount; i++) {
        fscanf(file, "S|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]| %c |\n",
               students[i].studentID,
               students[i].firstName,
               students[i].lastName,
               progessString,
               finalString,
               &students[i].grade);

        removeSpaces(students[i].firstName);
        removeSpaces(students[i].lastName);

        for (int j = 0; j < 6; j++) {
            if (progessString[j] == '.') {
                students[i].progressMark = (progessString[j - 2] == '1' ? 10.0 : 0.0) +
                                           (0.0 + progessString[j - 1] - '0') +
                                           (0.0 + (progessString[j + 1] - '0')) / 10 +
                                           (0.0 + (progessString[j + 2] > '0' ? progessString[j + 2] - '0' : 0)) / 100;
            }
            if (finalString[j] == '.') {
                students[i].finalExamMark = (finalString[j - 2] == '1' ? 10.0 : 0.0) +
                                             (0.0 + finalString[j - 1] - '0') +
                                             (0.0 + (finalString[j + 1] - '0')) / 10 +
                                             (0.0 + (finalString[j + 2] > '0' ? finalString[j + 2] - '0' : 0)) / 100;
            }
        }

        students[i].mark += (students[i].progressMark * progressWeight + students[i].finalExamMark * finalExamWeight) / 100;

        averageMark += students[i].mark;
        if (students[i].mark > students[highestMarkIndex].mark)
            highestMarkIndex = i;
        if (students[i].mark < students[lowestMarkIndex].mark)
            lowestMarkIndex = i;
    }
    averageMark /= studentCount;

    // Output grading summary to the output file
    fprintf(outputFile, "The student with the highest mark is: %s %s\n",
            students[highestMarkIndex].firstName,
            students[highestMarkIndex].lastName);
    fprintf(outputFile, "The student with the lowest mark is: %s %s\n",
            students[lowestMarkIndex].firstName,
            students[lowestMarkIndex].lastName);
    fprintf(outputFile, "The average mark is: %.2lf\n", averageMark);
    fprintf(outputFile, "\nA histogram of the subject %s is: \n", subjectID);

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

    // Output histogram to the output file
    fprintf(outputFile, "A:");
    for (int i = 0; i < gradeCounts[0]; i++) {
        fprintf(outputFile, "*");
    }
    fprintf(outputFile, "\nB:");
    for (int i = 0; i < gradeCounts[1]; i++) {
        fprintf(outputFile, "*");
    }
    fprintf(outputFile, "\nC:");
    for (int i = 0; i < gradeCounts[2]; i++) {
        fprintf(outputFile, "*");
    }
    fprintf(outputFile, "\nD:");
    for (int i = 0; i < gradeCounts[3]; i++) {
        fprintf(outputFile, "*");
    }
    fprintf(outputFile, "\nF:");
    for (int i = 0; i < gradeCounts[4]; i++) {
        fprintf(outputFile, "*");
    }
    fprintf(outputFile, "\n");

    // Close both input and output files
    fclose(file);
    fclose(outputFile);
}

int main() {
    const char *filename = "IT4062_20151.txt";
    calculateGradingSummary(filename);
    scanf("%s");
    return 0;
}
