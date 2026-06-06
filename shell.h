#ifndef SHELL_H
#define SHELL_H

#include <stdint.h>
#include <string.h>
#define SHELL_TASK_BUFFER 64
typedef enum : u_int8_t
{
    TASK_ACTION_HELP,
    TASK_ACTION_GET,
    TASK_ACTION_SET

}task_action_t;
typedef struct 
{
    const char *cmd;
    void (*callback)();
}shell_task_t;

void auth_task_handler(void);
void led_task_handler(void);

class Shell {
public:
    void init_shell();
    void exit_shell();
private:
    shell_task_t task_list[SHELL_TASK_BUFFER]=
    {
        {"auth",auth_task_handler},
        {"led",led_task_handler}
    };
};
extern Shell shell;
void shell_print_hello(void);

#endif //SHELL_H