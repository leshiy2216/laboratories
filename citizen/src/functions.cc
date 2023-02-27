#include <functions/functions.h>
#define MinSize 16242
using namespace citizen;
using namespace std;


double Human::SchoolPayday(int flag)
{
    if (flag == 1)
    {
        return 0.5 * MinSize;
    }
    return 0;
}

double Human::StudentPayday(double AverageScore)
{
    if (AverageScore < 3.5)
    {
        return 0;
    }
    if (AverageScore == 3.5)
    {
        return 0.5 * MinSize;
    }
    if (AverageScore == 4.0)
    {
        return 0.6 * MinSize;
    }
    if (AverageScore == 4.5)
    {
        return 0.7 * MinSize;
    }
    if (AverageScore == 5.0)
    {
        return 0.8 * MinSize;
    }

}

double Human::RetirePayday(int experience)
{
    if (experience < 5)
    {
        return 0;
    }
    if (experience <= 10 && experience >= 5)
    {
        return MinSize;
    }
    if (experience <= 20 && experience > 10)
    {
        return 0.2 * MinSize;
    }
    if (experience <= 25 && experience > 20)
    {
        return 0.3 * MinSize;
    }
    if (experience <= 30 && experience > 25)
    {
        return 0.4 * MinSize;
    }
}