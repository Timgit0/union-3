#include <vector>
#include <math>


class RocketPart
{
public:
    double relativeX, relativeY;
    double width, height;
    double mass;

    RocketPart(int _width = 1, int _height = 2, int _mass = 1)
    {
        relativeX = 0; relativeY = 0; width = _width; height = _height; mass = _mass;
    }
    RocketPart(RocketPart anotherPart, std :: string direction, int _width = 1, int _height = 2, int _mass = 1)
    {
        width = _width; height = _height; mass = _mass;
        switch (direction)
        {
            case "top": relativeX = anotherPart.relativeX; relativeY = anotherPart.relativeY - (anotherPart.height + height)/2; break;
            case "left": relativeY = anotherPart.relativeY; relativeX = anotherPart.relativeX - (anotherPart.width + width)/2; break;
            case "bottom": relativeX = anotherPart.relativeX; relativeY = anotherPart.relativeY + (anotherPart.height + height)/2; break;
            case "right": relativeY = anotherPart.relativeY; relativeX = anotherPart.relativeX + (anotherPart.width + width)/2; break;
            default: relativeX = anotherPart.relativeX; relativeY = anotherPart.relativeY; break;
        }
    }
};

class Engine : RocketPart
{
public:
    double thrustForward;
    double angularThrust;
};

class FuelTank : RocketPart
{
public:
    double fuel;
};

class Shield : RocketPart
{
public:
    double shield;
};

class Turret : RocketPart
{
public:
    double damage, bulletMass, amountOfBullets;
};

class Rocket
{
public:
    std :: vector<RocketPart> parts;
    double x, y, alpha, dx, dy, dalpha, ddx, ddy, ddalpha;
    double totalMass;
    double totalFuel;
    double totalThrustForward;
    double totalAngularThrust;
    void CalculateTotalNumbers()
    {
        for (int i = 0; i < parts.capacity(); i++)
        {
            totalMass += parts[i].mass;
            if (type(parts[i]) == FuelTank) totalFuel += parts[i].fuel;
            if (type(parts[i]) == Engine)
            {
                totalThrustForward += parts[i].thrustForward;
                totalAngularThrust += parts[i].angularThrust * sqrt(parts[i].relativeX*parts[i].relativeX + parts[i].relativeY*parts[i].relativeY);
            }
        }
    }
    void CalculateAcceleration()
    {
        double gravity = 1000/(100 + y*y);
        ddalpha = totalAngularThrust/totalMass;
        ddx = totalThrustForward*sin(alpha);
        ddy = totalThrustForward*cos(alpha);
    }
    void CalculatePosition()
    {
        dx += ddx; dy += ddy; dalpha += ddalpha; x += dx; if (x > (y + 100)*2*3.1415926535) x -= (y + 100)*2*3.1415926535; y += dy; alpha += dalpha; if (alpha > 2*3.1415926535) alpha -= 2*3.1415926535;
    }
};
