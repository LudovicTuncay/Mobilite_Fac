// Auteurs : Ludovic TUNCAY et Auguste VERDIER

#include "helper/fonctions.h"

std::string seconds_to_time(const double s)
{
    double time = s;
    int h = time / 3600;
    time -= h * 3600;
    int m = time / 60;
    time -= m * 60;
    return std::to_string(h) + "h" + std::to_string(m) + "m" + std::to_string((int)time) + "s";
}

std::string meters_to_string(const double distance)
{
    if (distance < 1000)
        return std::to_string((int)distance) + "m";
    else
        return std::to_string((int)(distance / 1000)) + "." + std::to_string((int)(distance / 100) % 10) + " km";
}
