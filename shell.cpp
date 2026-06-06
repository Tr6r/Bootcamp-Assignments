#include <iostream>
#include "shell.h"

Shell shell;
bool Shell::run(std::string cmd)
{
    if(cmd == "exit") return false;
    std::cout << "cmd: " << cmd<<std::endl;
    
    return true;
}
void Shell::init()
{
    std::cout << "Shell init" << std::endl;
}
void Shell::exit()
{
    std::cout << "Shell exit" << std::endl;
}
void auth_task_handler(void)
{
    std::cout<<"auth\n";
}
void led_task_handler(void)
{
    std::cout<<"led\n";
}
