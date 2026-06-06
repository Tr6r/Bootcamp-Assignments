#include <iostream>
#include "shell.h"

int main()
{
    shell.init();
    std::string cmd;
    while(true)
    {
        std::getline(std::cin, cmd);
        if(!shell.run(cmd)) break;
    }
    shell.exit();
    return 0;
}