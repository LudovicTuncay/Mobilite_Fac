// Auteurs : Ludovic TUNCAY et Auguste VERDIER

#pragma once

#include <iostream>

class CoordoneesGPS
{
    double latitude;
    double longitude;

public:
    CoordoneesGPS();
    CoordoneesGPS(double latitude, double longitude);
    double getLatitude();
    double getLongitude();

    std::string to_string();

    // Operator overloading
    friend std::ostream &operator<<(std::ostream &os, const CoordoneesGPS &coordonees);
};
