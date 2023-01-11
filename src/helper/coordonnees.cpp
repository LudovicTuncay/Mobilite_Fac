#include <helper/coordonnees.h>
#include <helper/commande.h>
#include <iostream>

CoordoneesGPS::CoordoneesGPS()
{
    this->latitude = 0;
    this->longitude = 0;
}

CoordoneesGPS::CoordoneesGPS(double latitude, double longitude)
{
    this->latitude = latitude;
    this->longitude = longitude;
}

double CoordoneesGPS::getLatitude()
{
    return this->latitude;
}

double CoordoneesGPS::getLongitude()
{
    return this->longitude;
}

std::string CoordoneesGPS::to_string()
{
    return std::to_string(this->longitude) + "," + std::to_string(this->latitude);
}

std::ostream &
operator<<(std::ostream &os, const CoordoneesGPS &coordonees)
{
    os << "(" << coordonees.latitude << ", " << coordonees.longitude << ")";
    return os;
}
