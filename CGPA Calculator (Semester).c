#include <stdio.h>

void print_grade(double cgpa) {
    if (cgpa >= 4.00)
        printf("Your grade: A+ (Outstanding)\n");
    else if (cgpa >= 3.75)
        printf("Your grade: A (Excellent)\n");
    else if (cgpa >= 3.50)
        printf("Your grade: A- (Quite Excellent)\n");
    else if (cgpa >= 3.25)
        printf("Your grade: B+ (Very Good)\n");
    else if (cgpa >= 3.00)
        printf("Your grade: B (Good)\n");
    else if (cgpa >= 2.75)
        printf("Your grade: B- (Quite Good)\n");
    else if (cgpa >= 2.50)
        printf("Your grade: C+ (Above Average)\n");
    else if (cgpa >= 2.25)
        printf("Your grade: C (Average)\n");
    else if (cgpa >= 2.00)
        printf("Your grade: D (Poor)\n");
    else
        printf("Your grade: F (Fail)\n");
}

double calculate_cgpa(int num_courses)
{
    double total_cgpa = 0;
    int num_passed_courses = 0;
    int num_failed_courses = 0;
    int failed_courses[num_courses]; // Array to store failed courses
    int has_failed_course = 0;

    for (int i = 1; i <= num_courses; ++i)
    {
        double cgpa;
        printf("Enter CGPA for course %d: ", i);
        scanf("%lf", &cgpa);

        if (cgpa < 1.00 || cgpa > 4.00)
        {
            printf("Invalid CGPA. Please enter a valid CGPA between 1.00 and 4.00.\n");
            return 0; // Stop processing due to invalid CGPA
        }
        else if (cgpa < 2.00)
        {
            printf("Course %d CGPA is below 2.00. You have failed this course.\n", i);
            failed_courses[num_failed_courses++] = i;
            has_failed_course = 1;
        }
        else
        {
            total_cgpa += cgpa;
            num_passed_courses++;
        }
    }

    double average_cgpa = total_cgpa / num_courses;
    printf("\n");
    printf("Average CGPA: %.2lf\n", average_cgpa);

    if (has_failed_course)
    {

        printf("\n");
        printf("You have been failed in ");
        for (int i = 0; i < num_failed_courses; ++i)
        {
            printf("course %d", failed_courses[i]);
            if (i < num_failed_courses - 1)
                printf(" , ");
            else
                printf(".\n");
        }
        printf("\n");
        printf("Since you have failed in one or more courses, your overall grade is Fail.\n");
        printf("\n");
        print_grade(1.00); // Print fail grade
    }
    else
    {
        print_grade(average_cgpa);
    }

    return average_cgpa;
}

int main()
{
    int num_courses;
    printf("Enter the total number of courses: ");
    scanf("%d", &num_courses);

    calculate_cgpa(num_courses);
    printf("\n");
    printf("Created by Al-Mahin");

    return 0;
}
