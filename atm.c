#include <stdio.h>
#include "atm.h"

typedef int int_array[];

unsigned int get_money(unsigned short int amount)
{
  int_array denominations = {1, 5, 10, 20, 50, 100, 500, 2000};
  unsigned int dispense_notes = 0x0;

  for (int index = 7; index >= 0 && amount <= 31999; index--)
  {
    dispense_notes |= (amount / denominations[index]) << (index * 4);
    amount %= denominations[index];
  }

  return dispense_notes;
}