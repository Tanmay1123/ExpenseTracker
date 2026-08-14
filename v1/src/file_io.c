#include <stdio.h>
#include "expense.h"
#include <string.h>
#include <stdlib.h>


// LOAD EXPENSES ALREADY IN FILE
int loadExpenses(struct expense expenses[MAX_EXPENSES], int expenseCount) {
  FILE* exp;
  exp = fopen("expenses.txt", "r");

  if (exp == NULL) {
    printf("Error: No expenses found to load.\n");
    return 0;
  } else {
    char line[200];
    char* dob;

    while (fgets(line, sizeof(line), exp) != NULL) {
      char* description = strtok(line, ";");
      char* amount = strtok(NULL, ";");
      char* category = strtok(NULL, ";");
      char* date = strtok(NULL,";");
      char* time = strtok(NULL,";");

      if (description != NULL && amount != NULL && category != NULL && date != NULL && time != NULL) {
        strcpy(expenses[expenseCount].description, description);

        double value = strtod(amount, &dob);
        expenses[expenseCount].amount = value;

        strcpy(expenses[expenseCount].category, category);
        strcpy(expenses[expenseCount].date, date);
        strcpy(expenses[expenseCount].time , time);

        expenseCount++;
      }
    }
    fclose(exp);
    return expenseCount;
  }
}

// SAVE EXPENSE TO FILE
void saveExpense(struct expense expenses[MAX_EXPENSES], int expenseCount) {
  FILE* exp;
  exp = fopen("expenses.txt", "a");

  if (exp == NULL) {
    printf("Error: Could not open file.\n");
    return;
  }
  fprintf(exp, "%s;%.2lf;%s;%s;%s\n", expenses[expenseCount].description,
          expenses[expenseCount].amount, expenses[expenseCount].category,expenses[expenseCount].date,expenses[expenseCount].time);
  fclose(exp);
}

// REWRITES EXPENSES IN FILE
void rewriteExpenses(struct expense expenses[MAX_EXPENSES], int expenseCount) {
  FILE* exp;
  exp = fopen("expenses.txt", "w");

  if (exp == NULL) {
    printf("Error: Could not open file.\n");
    return;
  }
  for (int i = 0; i < expenseCount; i++) {
    fprintf(exp, "%s;%.2lf;%s;%s;%s\n", expenses[i].description, expenses[i].amount,
            expenses[i].category,expenses[i].date,expenses[i].time);
  }
  fclose(exp);
}
