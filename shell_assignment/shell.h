#ifndef SHELL_H
#define SHELL_H

#include <stdint.h>
#include <string.h>
#include <iostream>
using namespace std;

#define SHELL_ACTION_BUFFER 16
#define SHELL_TASK_BUFFER 64

typedef enum : uint8_t
    {
        TASK_ACTION_NONE,
        TASK_ACTION_HELP,
        TASK_ACTION_GET,
        TASK_ACTION_SET,
    }task_action_t;
typedef struct {
    const char *name;
    task_action_t action;
}shell_action_t;
typedef struct 
{
    const char *cmd;
    void (*callback)(task_action_t action,string cmd);
}shell_task_t;

void auth_task_handler(task_action_t action, string cmd);
void led_task_handler(task_action_t action, string cmd);

class Shell {
public:
    
    Shell() = default;
    ~Shell() = default;
    void init();
    bool run(string cmd);
    void exit();
    task_action_t check_action_valid(string cmd);
    shell_task_t* check_target_valid(string cmd);
    void introduce_action();
    void introduce_target(task_action_t action);
    // Getter
    const char* get_shell_act_by_name(task_action_t action);
private:
    shell_action_t action_list[SHELL_ACTION_BUFFER]=
    {
        {"--help",TASK_ACTION_HELP},
        {"--get",TASK_ACTION_GET},
        {"--set",TASK_ACTION_SET},
        {NULL,TASK_ACTION_NONE}
    };

    shell_task_t task_list[SHELL_TASK_BUFFER]=
    {
        {"auth",auth_task_handler},
        {"led",led_task_handler},
        {NULL,NULL}
    };
};
extern Shell shell;

#endif //SHELL_H