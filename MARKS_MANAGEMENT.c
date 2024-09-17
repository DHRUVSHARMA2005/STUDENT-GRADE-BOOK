/*Project 5: Student Grade Book
Description: Build a program that allows teachers to enter student grades and calculate the average, highest, and lowest scores.

Use Cases:

Teachers can use it for recording student grades and calculating statistics.
Students can check their own grades to monitor their academic performance.
Educational institutions can use it for generating reports and transcripts.*/
#include <stdio.h>
#include <string.h>
struct student
{
    char name[20],grade;
    int roll_no;
    int marks;
};
// FUNCTION TO CALCULATE THE AVERAGE//
void avg(int a, int b);
void avg(int a, int b)
{
    float average = (float)a / b;
    printf("The average of the class is: %f\n", average);
}
void show(struct student stu[],int n){
    char nam[10];
    printf("Enter your name:\n");
    scanf("%s",nam);
    for(int i=0;i<n;i++){
        if (strcmp(nam,stu[i].name)==0){
            printf("The name of the student is %s\n",nam);
            printf("The roll_no of the student is %d\n",stu[i].roll_no);
            printf("The marks scored by him is %d\n",stu[i].marks);
            printf("The grade secured by the student is %c\n",stu[i].grade);
            if (stu[i].grade=='F'){
                printf("THE STUDENT IS FAILED!!");
            }
            else{
                printf("THE STUDENT IS PASSED!!");
            }
            break;
        }
        else{
            continue;
        }

    }
}

int main()
{
    int password = 63121,user_pass,attempts=0;
    int access_granted=0;
    while(attempts<3){
    printf("Enter the password : \n");
    scanf("%d",&user_pass);
    if (user_pass!=password){
        printf("ACCESS TO THE SYSTEM DENIED!!\n");
        attempts++;
    }
    else{
        access_granted=1;
        break;
    }
    }
    if (access_granted!=1){
        return 1;
    }
    struct student stu[100];
    int n;
    printf("Enter the number of students you want to enter the data of: ");
    scanf("%d", &n);
    // INPUTING THE VALUES IOF THE STUDENT DETAILS//
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of student number %d:\n", i + 1);
        scanf("%s", stu[i].name);
        printf("Enter the roll_no of student number %d:\n", i + 1);
        scanf("%d", &stu[i].roll_no);
        printf("Enter the marks of student number %d:\n", i + 1);
        scanf("%d", &stu[i].marks);
        if (stu[i].marks>100 || stu[i].marks<0){
            printf("THE output is invalid!!\n");
            return 1;
        }
    }
    for(int i=0;i<n;i++){
        if (stu[i].marks>=90){
            stu[i].grade='S';
        }
        else if(stu[i].marks<90 && stu[i].marks>=80){
             stu[i].grade='A';
        }
        else if(stu[i].marks<80 && stu[i].marks>=70){
             stu[i].grade='B';
        }
        else if(stu[i].marks<70 && stu[i].marks>=60){
             stu[i].grade='C';
        }
        else if(stu[i].marks<60 && stu[i].marks>=50){
             stu[i].grade='D';
        }
        else{
            stu[i].grade='F';
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += stu[i].marks;
    }
    avg(sum, n);
    // FINDING THE MAXIMUM AND MINIMUM MARKS//
    int max = stu[0].marks, min = stu[0].marks;
    char max_name[10], min_name[10];
    strcpy(max_name, stu[0].name);
    strcpy(min_name, stu[0].name);
    for (int i = 1; i < n; i++)
    {
        if (max <= stu[i].marks)
        {
            max = stu[i].marks;
            strcpy(max_name, stu[i].name);
        }
        else if (min > stu[i].marks)
        {
            min = stu[i].marks;
            strcpy(min_name, stu[i].name);
        }
    }
    
    printf("The maximum marks are gained by %s\n", max_name);
    printf("The maximum marks is %d\n", max);
    printf("The minimum marks are gained by %s\n", min_name);
    printf("The minimum marks is %d\n", min);
    int y_n;
    printf("Do you want to get report card of a particular student (y/n)(1/0): \n");
    scanf("%d",&y_n);
    if (y_n==1){
        show(stu,n);
    }
    else{
        return 1;
    }
    return 0;
}