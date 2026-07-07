#include <stdio.h>
#include "expense.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>


//DATE AND TIME CONFIG
void setTimestamp(struct expense* target){

  time_t raw_time;
  raw_time = time(NULL);
  struct tm *local_time = localtime(&raw_time);
  strftime(target->time,sizeof(target->time),"%H:%M",local_time);
  strftime(target->date,sizeof(target->date),"%d/%m/%y",local_time);

}

//CHOOSING PREDIFINED CATEGORIES
void setCategory(struct expense* target){
  printf("--------CATEGORIES--------\n\n");
  printf("       1. Food       \n       2. Transport       \n       3. Utilities       \n       4. Entertainment       \n       5. Healthcare       \n       6. Shopping       \n       7. Education       \n       8. Rent/Housing       \n       9. Miscellaneous       \n\n");

  int choice = 0;
  printf("Choose your option (1-9): ");
  scanf("%d",&choice);

  while(choice < 1 || choice >9) {
    printf("Choose a valid option (1-9): ");
    scanf("%d",&choice);
  }

  switch (choice) {
  case 1: strcpy(target->category, "Food"); break;
  case 2: strcpy(target->category, "Transport"); break;
  case 3: strcpy(target->category, "Utilities"); break;
  case 4: strcpy(target->category, "Entertainment"); break;
  case 5: strcpy(target->category, "Healthcare"); break;
  case 6: strcpy(target->category, "Shopping"); break;
  case 7: strcpy(target->category, "Education"); break;
  case 8: strcpy(target->category, "Rent/Housing"); break;
  case 9: strcpy(target->category, "Miscellaneous"); break;
  }

}  


//ADD EXPENSE CORE
void promptExpenseDetails(struct expense* target){
  int n = 100;
  printf("Description: ");
    fgets(target->description,n,stdin);
    target->description[strcspn(target->description, "\n")] = '\0';
    // changes the annoying /n that fegets add everytime
    // scanf("%s",expenses[expenseCount].description); # this wont work with " "  in between so   we will use fgets();

  printf("Amount: ");
    while(scanf("%lf",&target->amount) != 1){
      printf("Invalid input. Please eneter a valid number.\n");

      int c;
      while((c = getchar()) != '\n' && c != EOF);

      printf("Enter a number: ");
    }
  //flushing the extra characters if some
  int c;
    while((c = getchar()) != '\n' && c != EOF);
  
  setCategory(target); 
  
}     
// ADD AN EXPENSE
void addExpense(struct expense expenses[MAX_EXPENSES], int expenseCount) {
  promptExpenseDetails(&expenses[expenseCount]);
  setTimestamp(&expenses[expenseCount]);
}

// VIEW EVERY EXPENSE
void viewExpense(struct expense expenses[MAX_EXPENSES], int expenseCount) {
  printf("\n--------Your Expenses--------\n\n");
  for (int i = 0; i < expenseCount; i++) {
    printf("Description: %s\n", expenses[i].description);
    printf("Amount: %.2lf\n", expenses[i].amount);
    printf("Category: %s\n", expenses[i].category);
    printf("Date & Time: %s %s\n\n",expenses[i].date,expenses[i].time);
  }
}

// TOTAL EXPENDITURE
void totalExpenses(struct expense expenses[MAX_EXPENSES], int expenseCount) {
  double total = 0.0;
  for (int i = 0; i < expenseCount; i++) {
    total = total + expenses[i].amount;
  }
  printf("The total expenditure is: %.2lf\n", total);
}

// SEE EXPENSES(ONLY DESCRIPTION)
void seeExpenses(struct expense expenses[MAX_EXPENSES], int expenseCount) {
  printf("\n--------Your Expenses--------\n\n");
  for (int i = 0; i < expenseCount; i++) {
    printf("%d. %s\n", i + 1, expenses[i].description);
  }
  printf("\n");
}

// DELETE EXPENSE
int deleteExpense(struct expense expenses[MAX_EXPENSES], int expenseCount) {
  seeExpenses(expenses, expenseCount);
  int choice = 0;

  printf("Enter an expense to delete (0 to cancel): ");
  scanf("%d", &choice);

  if (choice == 0) {
    return expenseCount;
  }

  while (choice < 1 || choice > expenseCount) {
    printf("Enter a valid choice (0 to cancel): ");
    scanf("%d", &choice);

    if (choice == 0) {
      return expenseCount;
    }
  }
  int index = choice - 1;

  for (int i = index; i < (expenseCount - 1); i++) {
    expenses[i] = expenses[i + 1];
  }

  expenseCount--;
  return expenseCount;
}

//EDIT EXISTING EXPENSE
int editExpense(struct expense expenses[MAX_EXPENSES],int expenseCount){
  seeExpenses(expenses, expenseCount);
  int choice = 0;

  printf("Enter an expense to edit (0 to cancel): ");
  scanf("%d", &choice);

  if (choice == 0) {
    return expenseCount;
  }

  while (choice < 1 || choice > expenseCount) {
    printf("Enter a valid choice (0 to cancel): ");
    scanf("%d", &choice);

    if (choice == 0) {
      return expenseCount;
    }
  }
  getchar();

  int index = choice - 1;

  promptExpenseDetails(&expenses[index]);

  return expenseCount;
  
}