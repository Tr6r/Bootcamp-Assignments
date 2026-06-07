#include <iostream>
#include "shell.h"

int main()
{
    shell.init();
    std::string cmd;
    while(true)
    {
        // get cmd from terminal
        std::getline(std::cin, cmd);
        // process cmd
        if(!shell.run(cmd)) break;
    }
    shell.exit();
    return 0;
}