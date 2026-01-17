#ifndef __PERIPH_USER_BUTTON_H
#define __PERIPH_USER_BUTTON_H

#include <stdint.h>

void Periph_UserButton_Init(void);
extern volatile uint8_t UserButton_Event;

#endif
