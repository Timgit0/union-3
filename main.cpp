#include <rocket.cpp>
#include <asteroid.cpp>


int main()
{
    //creating the rocket
    int numberOfParts = 0;
    std :: cout << "please, enter the number of parts in your rocket";
    std :: cin >> numberOfParts;
    for (int i = 0; i < numberOfParts; i++)
    {
        var part;
        char partType = ' ';
        std :: cout << "please, enter part type [e for engine, f for fuel tank, s for shield, t for turret, anything else for frame part]";
        std :: cin << partType;
        switch (partType)
        {
        case 'e':
            part = new Engine();
            break;
        
        default:
            break;
        }
    }


    return 0;
}