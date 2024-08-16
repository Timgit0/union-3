#include <rocket.cpp>
#include <asteroid.cpp>


int main()
{
    //creating the rocket
    rocket = new Rocket();
    int numberOfParts = 0;
    std :: cout << "please, enter the number of parts in your rocket";
    std :: cin >> numberOfParts;
    for (int i = 0; i < numberOfParts; i++)
    {
        std :: cout << "now creating part number " << i;

        int numberOfPartWeAreAttachingThisPartTo = 0;
        std :: cout << "please, enter the number of part you want to attach this part to";
        std :: cin >> numberOfPartWeAreAttachingThisPartTo;

        char direction = "t";
        std :: cout << "please, enter the direction of attachement [t for top, b for bottom, l for left or r for right]";
        std :: cin >> direction;

        int width = 1; int height = 2; int mass = 1;
        std :: cout << "please, enter the width of the part [an integer]";
        std :: cin >> width;
        std :: cout << "please, enter the height of the part [an integer]";
        std :: cin >> height;
        std :: cout << "please, enter the mass of the part [an integer]";
        std :: cin >> mass;

        char partType = ' ';
        std :: cout << "please, enter part type [e for engine, f for fuel tank, s for shield, t for turret or anything else for frame part]";
        std :: cin << partType;
        switch (partType)
        {
        case 'e':
            Engine part = new Engine();
            break;
        case 'f':
            FuelTank part = new FuelTank();
            break;
        case 's':
            Shield part = new Shield();
            break;
        case 't':
            Turret part = new Turret();
            break;
        default:
            RocketPart part = new RocketPart();
            break;
        }
    }


    return 0;
}