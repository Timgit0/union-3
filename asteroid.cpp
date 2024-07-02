class Asteroid
{
public:
    double x, y;
    double mass;
    double radius;
    bool CheckForCollision(Rocket rocketToCheck)
    {
        for (int i = 0; i < rocketToCheck.parts.capacity(); i++)
        {
            if (((rocketToCheck.parts[i].relativeY + rocketToCheck.y - y) < rocketToCheck.parts[i].height + radius) && ((rocketToCheck.parts[i].relativeX + rocketToCheck.x - x) < rocketToCheck.parts[i].width + radius)) return true;
        }
        return false;
    }
};