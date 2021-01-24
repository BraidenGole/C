/**
 * @file dateTime.c
 * @author Braiden Gole
 * @brief This is a sample on the (C) programming language datetime.
 * 
 * [NOTE:] #include <time.h>
 * 
 * [IMPORTANT:] When working with dates and times do your best to use as
 *              much of the built in functionality already provided in <time.h>
 *              when you want to find the difference between 2 times we use "difftime()."
 *              If we want a string representation of a datetime then use "strftime()"
 *              to format the time object into a string readable representation ect.
 * @version 0.1
 * @date 2021-01-24
 * @copyright Copyright (c) Braiden Gole 2021
 */
#include <stdio.h>
#include <time.h>

// Header files.
#include "extra.h"

int main(void)
{   
    // When I was first working with these it helped to know what the structure
    // definition looked like so I could understand the interface in which I am
    // working in.

    // (Tutorialspoint - C Library - <time.h> [tm structure definition]).
    // [SOURCE / DOCUMENTATION]: https://www.tutorialspoint.com/c_standard_library/time_h.htm
    // --------------------------------------------------------------------------------------
    time_t now;

    struct tm *dateTime;
    char dateStorage[KONEHUNDRED] = {""};
    char dateStorageTwo[KONEHUNDRED] = {""};

    // Initialize a new time object.
    // Once we have one time object initialized then we can offset other times
    // objects off of this object using mktime().
    now = time(NULL);

    // Localize the time object.
    dateTime = localtime(&now);

    // Use strftime to format the datetimes.
    // We need to grab the local time now before it is manipulated where
    // one single day will be added to the current datetime.
    strftime(dateStorage, KONEHUNDRED, _DATE_FORMAT, dateTime);

    // Using the time(NULL) object add 1 day from the current datetime.
    // tm_mday = Month day.
    dateTime->tm_mday += 1;

    // Using the same date format example: "January: 2021-01-24"
    strftime(dateStorageTwo, KONEHUNDRED, _DATE_FORMAT, dateTime);

    // The result is written to the "Buffers" supplied !    [ One day ahead ]
    printf("Result date 1: (%s)\n", dateStorage);
    printf("Result date 1: (%s)\n", dateStorageTwo);
    putchar('\n');
    // -------------------------------------------------------------------------------------

    // -- Extra functions below -- //

    // Sample #2.
    time_t createTime = 0;
    sample_2(createTime);
    // End sample 2.

    // Sample #3
    sample_3();
    // End sample 3.

    // Sample 4
    sample_4();
    // End sample 4.
    return ZERO;
}
