 /**
 *Joshua Whiteford
 *13/11/2017
 *Lab 11
 *Tomorrow's Date Calculator
 */

/**< Preprocessor Directives */
#include <iostream>
#include <math.h>
#include <tgmath.h>

using namespace std;

/**< A structure to group the Date in the form Day, Month, Year */
struct Date
{
    int Day;
    int Month;
    int Year;

};

/**< Function Decleration */
Date tomorrowsDate(  Date Today );

/**< Calling the Function */
int main(void)
{
    struct Date Today, Tomorrow;

    /**< Setting the Date to 0/0/0 before asking the user to enter a date */
    Today.Day = 0;
    Today.Month = 0;
    Today.Year = 0;

    /**< Introducoing the User */
    cout << "\tTomorrows Date Calculator!" << endl;
    cout << "Please Enter Todays Date in the manner asked!" << endl;

    /**< Asking the User to enter a Year  */
    cout << "Enter the year!" << endl;
    cin >> Today.Year;

    /**< Asking the User to enter a Month  */
    cout << "Enter the Month of the Year between 1 & 12!" << endl;
    cin >> Today.Month;

    /**< If the month is not between the 1st & 12th looping */
    while (Today.Month < 0 || Today.Month > 13)
    {
        cout << "Please Enter the Real Month!" << endl;
        cin >> Today.Month;
    }

    /**< asking the user to enter in a Day  */
    cout << "Enter the Day of the Month between 1 & 31!" << endl;
    cin >> Today.Day;

    /**< If the Day is not between the First and the 31st looping */
    while (Today.Day < 0 || Today.Day > 32)
    {
        cout << "Please Enter the Real Day!" << endl;
        cin >> Today.Day;
    }

    /**< Calling a function that will calculate tomorrows Date */
     Tomorrow = tomorrowsDate( Today );

     /**< Displaying tomorrows date */
     cout << "Tomorrows Date Is: ";
     cout << Tomorrow.Day;
     cout << "/" << Tomorrow.Month ;
     cout << "/" << Tomorrow.Year;

    return 0;
}

/**< Calling the Function */
Date tomorrowsDate( Date TodayD)
{
    /**<  passing a structure to the function */
    struct Date Tomorrow;

    /**<  decring tomorros date to be 0/0/0 */
    Tomorrow.Day = 0;
    Tomorrow.Month = 0;
    Tomorrow.Year = 0;

    /**< this is where there is a leap year and there are 29 days in Feb */
    if( TodayD.Day == 28 && TodayD.Month == 2 && TodayD.Year %4 == 0 )
    {
        if (TodayD.Year %100 == 0 || TodayD.Year %400 == 0 )
        {
            TodayD.Day = 1;
            TodayD.Month = 3;
        }
        else
        {
        /**< setting the date to the 29th */
        TodayD.Day = 29;
        }
    }
   /**< where its not a leap year */
    else if ( TodayD.Day == 28 && TodayD.Month == 2 && TodayD.Year %4 != 0 )
    {
        /**< setting the date to the first of march */
        TodayD.Day = 1;
        TodayD.Month = 3;
    }
    /**< when its not a leap year and the 29th + of march wa entered. */
    else if ( TodayD.Day == 29 && TodayD.Month == 2 && TodayD.Year %4 != 0 )
    {
        /**<  Telling the user its not a real date and returning them to the main function */
        cout << "That is not a real Date! Please Enter a correct Date!" << endl;
        return Tomorrow;
    }
    /**< Where the date entered is the 29th & its a leap year */
    else if ( (TodayD.Day == 29) && (TodayD.Month == 2) && (TodayD.Year %4 == 0) )
    {
        /**< setting the date to the first of march */
        TodayD.Day = 1;
        TodayD.Month = 3;
    }
    /**< If the Day entered is the 30th */
    else if ( TodayD.Day == 30 )
    {
        if ( TodayD.Month == 4 || TodayD.Month == 6 || TodayD.Month == 9 || TodayD.Month == 11 )
        {
            /**< The Next day is the First of the next month. */
            TodayD.Day = 1;
            TodayD.Month = TodayD.Month + 1 ;
        }
        /**< if 30th of febusry is entered its not a real date */
        else if ( TodayD.Month == 2 )
        {
            /**<  Telling the user its not a real date and returning them to the main function */
            cout << "That is not a real Date! Please Enter a correct Date!" << endl;
            return Tomorrow;
        }
        else
        {
            /**< Other wise its actually a month with 31 ddays  */
            TodayD.Day = 31;
        }

    }
    /**< if the user entered the 31 as the day */
    else if ( TodayD.Day == 31 )
    {
        /**< If the user entered 31/12 */
        if( TodayD.Month == 12 )
        {
            /**< Setting the Date to the First of the next month  */
            TodayD.Day = 1;
            TodayD.Month = 1;
            TodayD.Year = TodayD.Year + 1;
        }
        /**< If the user entered 31/02 */
        else if ( TodayD.Month == 2 )
        {
            /**<  Telling the user its not a real date and returning them to the main function */
            cout << "That is not a real Date! Please Enter a correct Date!" << endl;
            return Tomorrow;
        }
        /**< If the user entered any of these months 4th, 6th, 9th, 11th  */
        else if ( TodayD.Month == 4 || TodayD.Month == 6 || TodayD.Month == 9 || TodayD.Month == 11 )
        {
            /**<  Telling the user its not a real date and returning them to the main function */
            cout << "That is not a real Date! Please Enter a correct Date!" << endl;
            return Tomorrow;
        }
        /**< Otherwise it s the first of the Next month! */
        else
        {
            TodayD.Day = 1;
            TodayD.Month = TodayD.Month + 1;
        }
    }
    else
    {
        /**< If the day is a normal day in the middle of the the year in the middle of a month then just adding one day too it! */
        TodayD.Day = TodayD.Day + 1;
    }

    /**< Returning the tomorrows Date  */
    Tomorrow.Day = TodayD.Day;
    Tomorrow.Month = TodayD.Month;
    Tomorrow.Year = TodayD.Year;


    return Tomorrow;
}
