/**
 * @file extra.c
 * @author Braiden Gole
 * @brief This is a file used to write extra datetime functions.
 * @version 0.1
 * @date 2021-01-24
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <time.h>

// Header files.
#include "extra.h"

/**     -- Function header comment
 *  FUNCTION        :   sample_2
 *  DESCRIPTION     :   This will add one hour, and one minute.
 *                      to the current time.
 *  PARAMETERS      :   timeVar
 *  RETURNS         :   None
 */
void sample_2(time_t timeVar)
{   
    struct tm *dateTime;
    char formattedTime[KONEHUNDRED] = {""};

    timeVar = time(NULL);
    dateTime = localtime(&timeVar);

    dateTime->tm_hour += ONE;
    dateTime->tm_min += ONE;

    // Use strftime() format the string.
    strftime(formattedTime, KONEHUNDRED, _DATE_FORMAT2, dateTime);
    fprintf(stdout, "24 Hour clock: %s", formattedTime);
}

/**     -- Function header comment
 *  FUNCTION        :   sample_3
 *  DESCRIPTION     :   This will add one day to the weekday and
 *                      we will be able to output the weekday one
 *                      day from today.
 *  PARAMETERS      :   None
 *  RETURNS         :   None
 */
void sample_3(void)
{   
    struct tm *dateTime;
    char formattedTime2[KONEHUNDRED] = {""};

    time_t now;
    now = time(NULL);
    dateTime = localtime(&now);

    dateTime->tm_wday += 1;

    // Use strftime() format the string.
    strftime(formattedTime2, KONEHUNDRED, _DATE_FORMAT3, dateTime);
    fprintf(stdout, "\nWeekday: %s", formattedTime2);
}

/**     -- Function header comment
 *  FUNCTION        :   sample_4
 *  DESCRIPTION     :   This will simply print just the date.
 *  PARAMETERS      :   None
 *  RETURNS         :   Noen
 */
void sample_4(void)
{
    struct tm *dateTime;
    char formattedDate2[KONEHUNDRED] = {""};

    time_t now;
    now = time(NULL);
    dateTime = localtime(&now);

    // Use strftime() format the string.
    strftime(formattedDate2, KONEHUNDRED, _DATE_FORMAT4, dateTime);
    fprintf(stdout, "\nDate: %s", formattedDate2);
}
