#pragma once
#include <iostream>

class Time
{
private:
    int hours, minutes, seconds;

public:
    // Default Constructor.
    Time();

    /// <summary>
    /// Parameterized Constructor.
    /// </summary>
    /// <param name="hours"></param>
    /// <param name="minutes"></param>
    /// <param name="seconds"></param>
    Time(int, int, int);

    // Checks for any excess value in hours, minutes or seconds and distributes the values accordingly.
    void applyChecks();

    // Displays the time.
    void display() const;

    // Takes another time object and returns the sum.
    Time add(Time) const;

    // Allows Time objects to be used with cout.
    friend std::ostream& operator<<(std::ostream&, const Time&);
};

