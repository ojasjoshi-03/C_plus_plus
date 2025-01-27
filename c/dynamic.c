// create structure of n students to store the info like roll no name marks in 3 subjects calculate total marks of each students display the students of each student with total marks use pointers to structures
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int roll_no;
    char name [50];
    float marks[3];
    float total_marks;

}Student;

void calculateTotalMarks(Student *student) {
    student->total_marks = 0;
    for (int i = 0; i < 3; i++) {
        student->total_marks += student->marks[i];
    }
}

void displayStudentDetails(Student *student) {
    printf("Roll No: %d\n", student->roll_no);
    printf("Name: %s\n", student->name );
    printf("Marks: %2f,%2f,%2f \n", student->marks[0],student->marks[1],student->marks[2]);
    printf("Total marks: %2f\n", student->total_marks);
    printf("---------------------------\n");
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);
 
    Student *students = (Student *)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enter Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Enter Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Enter marks in 3 subjects:\n");
        for (int j = 0; j < 3; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }
          calculateTotalMarks(&students[i]);
    }

     printf("\nStudent Details:\n");
    printf("============================\n");
    for (int i = 0; i < n; i++) {
        displayStudentDetails(&students[i]);
    }
  
    free(students);

    return 0;

}    
