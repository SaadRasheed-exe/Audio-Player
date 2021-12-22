#include "Time.h"

Time::Time()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

Time::Time(int h, int min, int sec)
{
    if (h < 0 || min < 0 || sec < 0)
    {
        throw "Negative time attributes not allowed.";
    }

    hours = h;
    minutes = min;
    seconds = sec;

    applyChecks();
}

void Time::applyChecks()
{
    if (seconds > 59)
    {
        minutes += seconds / 60;
        hours += seconds / 3600;
        seconds = seconds % 60;
    }

    if (minutes > 59)
    {
        hours += minutes / 60;
        minutes %= 60;
    }

    if (hours > 11)
    {
        hours %= 12;
    }
}

void Time::display() const
{
    std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
}

Time Time::add(Time b) const
{
    Time c;
    c.hours = hours + b.hours;
    c.minutes = minutes + b.minutes;
    c.seconds = seconds + b.seconds;
    c.applyChecks();
    return c;
}

std::ostream& operator<<(std::ostream& out, const Time& t)
{
    out << t.hours << ":" << t.minutes << ":" << t.seconds;
    return out;
}
