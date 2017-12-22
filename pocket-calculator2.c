#include <stdio.h>
#include <float.h>

#define DBL_MAX __DBL_MAX__
#define DBL_MIN __DBL_MIN__

int Add(double first_operand, double second_operand);
int Subtract(double first_operand, double second_operand);
int Multiply(double first_operand, double second_operand);
int Divide(double first_operand, double second_operand);

int main(int argc, char const *argv[])
{
  int number_choice;
  int try_again = 0;
  do
  {
    printf("Choose one of the following operations: \n");
    printf("Add (1)\n");
    printf("Subtract (2)\n");
    printf("Multiply (3)\n");
    printf("Divide (4)\n");
    printf("Stop program (-1)\n");
    printf("Enter your choice: ");
    scanf("%d", &number_choice);
    if(number_choice == 1 || number_choice == 2 || number_choice == 3 || number_choice == 4)
    {
      double first_operand = 0;
      double second_operand = 0;
      printf("Please enter the first operand: ");
      scanf("%lf", &first_operand);
      printf("Please enter the second operand: ");
      scanf("%lf", &second_operand);
      switch(number_choice){
          case 1: try_again = Add(first_operand, second_operand);
          break;
          case 2: try_again = Subtract(first_operand, second_operand);
          break;
          case 3: try_again = Multiply(first_operand, second_operand);
          break;
          case 4: try_again = Divide(first_operand, second_operand);
          break;
          default:
          break;
      }
    }
    else if(number_choice == -1){
      try_again = 1;
    }
    else
    {
        printf("Input not allowed, please try again\n");
        try_again = 0;
    }
    printf("\n");

  }while(try_again == 0);
  return 0;
}

int Add(double first_operand, double second_operand){
  double result = first_operand + second_operand;
  if(result > __DBL_MAX__){
    printf("Number overflow\n");
  }
  else if(result < __DBL_MIN__){
    printf("Number underflow\n");
  }
  else{
      printf("%.2lf + %.2lf = %.2lf \n", first_operand, second_operand, result);
  }
  return 0;
}

int Subtract(double first_operand, double second_operand){
  double result = first_operand - second_operand;
  if(result > __DBL_MAX__){
    printf("Number overflow\n");
  }
  else if(result < __DBL_MIN__){
    printf("Number underflow\n");
  }
  else{
      printf("%.2lf - %.2lf = %.2lf \n", first_operand, second_operand, result);
  }

  return 0;
}

int Multiply(double first_operand, double second_operand){
  double result = first_operand * second_operand;
  if(result > __DBL_MAX__){
    printf("Number overflow\n");
  }
  else if(result < __DBL_MIN__){
    printf("Number underflow\n");
  }
  else{
      printf("%.2lf * %.2lf = %.2lf \n", first_operand, second_operand, result);
  }

  return 0;
}

int Divide(double first_operand, double second_operand){
  if(second_operand != 0){
    double result = first_operand / second_operand;
    if(result > __DBL_MAX__){
      printf("Number overflow\n");
    }
    else if(result < __DBL_MIN__){
      printf("Number underflow\n");
    }
    else{
        printf("%.2lf / %.2lf = %.2lf \n", first_operand, second_operand, result);
    }
  }
  else{
    printf("Division by zero\n");
  }

  return 0;
}
