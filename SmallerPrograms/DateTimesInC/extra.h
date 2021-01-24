/**
 * @file extra.h
 * @author Braiden Gole
 * @brief This is a file is used to keep things clean and
 *        organized in the main source file.
 * @version 0.1
 * @date 2021-01-24
 * @copyright Copyright (c) Braiden Gole 2021
 */
#ifndef _KEXTRA
#define _KEXTRA "extra.h"

#define KONEHUNDRED 100
#define ONE 1
#define ZERO 0

#define _DATE_FORMAT "%B: %Y-%m-%d"
#define _DATE_FORMAT2 "%H:%M"
#define _DATE_FORMAT3 "%A"
#define _DATE_FORMAT4 "%x"

// Function prototypes.

// The time_t in VSCode will be [ RED ] but wont effect the execution.
void sample_2(time_t timeVar, time_t timeToCompare);
void sample_3(void);
void sample_4(void);
#endif