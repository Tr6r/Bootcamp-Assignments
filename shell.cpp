#include <iostream>
#include "shell.h"

void shell_print_hello(void)
{
    std::cout<<"shell hello\n";
}
void auth_task_handler(void)
{
    std::cout<<"auth\n";
}
void led_task_handler(void)
{
    std::cout<<"led\n";
}
Shell shell;