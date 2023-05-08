#include <iostream>
#include "Application.h"
#include <SFML/Graphics.hpp>
#include <time.h>

int main()
{
    srand(time(nullptr));
    Application application;
    application.run();
    return 0;
}
