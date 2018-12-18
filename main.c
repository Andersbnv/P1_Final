#include "allIncludes.h"

/* ---------------------- main ---------------------- */
int main(void)
{
    int numberOfStudents = 0,
        amountGroup;
    structGroup *groupResult;
    structStudent *student;
    
    student = loadStructStudent(&numberOfStudents);
    amountGroup = userInputGroups(numberOfStudents);
    groupResult = algoritme(student, numberOfStudents, amountGroup);
    
    switchForOutput(student, groupResult, amountGroup);

    freeAll(student, groupResult, amountGroup);
    return 0;
}

/* ---------------------- prompts user for amount of groups ---------------------- */
int userInputGroups(int numberOfStudents)
{
    int amountGroup = 0,
        condition = 0;
    printf("Enter a desired amount of groups - MUST be an integer\n :");
    
    do
    {
        if (condition)
        {
            printf("you inserted an invalid number, please insert a number between 2 and %d\n :", (numberOfStudents / 2));
        }
        scanf(" %d", &amountGroup);

        condition = amountGroup < 2 || amountGroup > (numberOfStudents / 2);
    } while (condition);
    return amountGroup;
}

void freeAll(structStudent *student, structGroup *groupResult, int amountGroup)
{
    int i;
    
    for(i = 0; i < amountGroup; i++)
    {
        free(groupResult[i].indexStudent);
    }
    free(groupResult);
    free(student);
}
