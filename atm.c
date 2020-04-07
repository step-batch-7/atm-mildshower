#include <stdio.h>
#include "atm.h"

unsigned int get_money(unsigned short int amount)
{
  int_array denominations = denominations_list;
  unsigned int dispense_notes = 0x0;

  if (amount > 31999)
    return dispense_notes;

  for (int index = 0; index < 8; index++)
  {
    dispense_notes <<= 4;
    dispense_notes |= amount / denominations[index];
    amount %= denominations[index];
  }

  return dispense_notes;
}

void display_notes(unsigned int notes)
{
  int_array denominations = denominations_list;
  int notes_count;

  for (int index = 0; index < 8; index++)
  {
    notes_count = (notes & 0xf0000000) >> 28;
    if (notes_count)
      printf("%d %s of Rs %d\n", notes_count, label(notes_count), denominations[index]);
    notes <<= 4;
  }
}