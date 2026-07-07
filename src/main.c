#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expense.h"


int main() {
  struct expense expenses[MAX_EXPENSES];

  int option = 0;
  int expenseCount = 0;

  expenseCount = loadExpenses(expenses, expenseCount);
  printf("Loaded %d expenses\n", expenseCount);

  while (option != 6) {
    printf("\n\n--------Expense Tracker--------\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Show Total Expenses\n");
    printf("4. Delete Expense\n");
    printf("5. Edit Expense\n");
    printf("6. Exit\n\n");

    printf("Choose your option: ");
    scanf("%d", &option);
    getchar();

    switch (option) {
      case 1:
        if (expenseCount >= MAX_EXPENSES) {
          printf("Max expenses reached");
        } else {
          addExpense(expenses, expenseCount);
          saveExpense(expenses, expenseCount);
          expenseCount++;
        }
        break;
      case 2:
        viewExpense(expenses, expenseCount);
        break;
      case 3:
        totalExpenses(expenses, expenseCount);
        break;
      case 4:
        expenseCount = deleteExpense(expenses, expenseCount);
        rewriteExpenses(expenses, expenseCount);
        break;
      case 5:
        expenseCount = editExpense(expenses,expenseCount);
        rewriteExpenses(expenses, expenseCount);
      break;
      case 6:
        printf("Program Ended\n");
        break;
      default:
        printf("Please choose a valid option!\n");
        break;
    }
  }
  return 0;
}