#include <iostream>
#include "shell.h"

using namespace std;

Shell shell;

//HELPER 
string get_param(const string& cmd, const string& key)
{
    size_t pos = cmd.find(key + "=");
    if(pos == string::npos)
        return "";
    pos += key.length() + 1;
    size_t end = cmd.find(' ', pos);
    if(end == string::npos)
        end = cmd.length();
    return cmd.substr(pos, end - pos);
}

//HELPER 
string get_action(const string& cmd)
{
    size_t pos = cmd.find("--");

    if(pos == string::npos)
        return "";

    pos += 2;

    size_t end = cmd.find(' ', pos);

    if(end == string::npos)
        end = cmd.length();

    return cmd.substr(pos, end - pos);
}

bool Shell::run(std::string cmd)
{
    if(cmd == "exit") return false;
    task_action_t action = check_action_valid(cmd);
    if (action == TASK_ACTION_NONE) 
    {
        introduce_action();
        return true;
    }
    shell_task_t* task = check_target_valid(cmd);
    if (!task)
    {
        introduce_target(action);
        return true;
    }
    task->callback(action,cmd);
    
    return true;
}
shell_task_t* Shell::check_target_valid(string cmd)
{
    string target = get_param(cmd, "tar");
    if(target == "") return NULL;
    for(uint8_t i = 0; task_list[i].cmd != NULL; i++)
    {
        if(task_list[i].cmd == target )return &task_list[i];
    }
    return NULL;
}

task_action_t Shell::check_action_valid(string cmd)
{
    string action = get_action(cmd);
    cout<<action<<endl;
    if(action == "") return TASK_ACTION_NONE;
    for(uint8_t i = 0; action_list[i].name != NULL; i++)
    {
        if(action_list[i].name == action)return action_list[i].action;
    }
    return TASK_ACTION_NONE;
}
void Shell::init()
{
    cout << "Shell init" << endl;
}
void Shell::exit()
{
    cout << "Shell exit" << endl;
}

const char* Shell::get_shell_act_by_name(task_action_t action)
{
    for(uint8_t i = 0; action_list[i].name != nullptr; i++)
    {
        if(action_list[i].action == action) return action_list[i].name;
    }
    return NULL;
}


void Shell::introduce_action()
{
    cout << "==========ACTION==========" << endl;    
    for(uint8_t i = 0; action_list[i].name != nullptr; i++)
    {
        cout << action_list[i].name<<" tar=<target> param=<param>"<< endl;
    }

    cout << "===========================" << endl;
}

void Shell::introduce_target(task_action_t action)
{
    cout << "==========TARGET==========" << endl;
    const char* task_name = get_shell_act_by_name(action);

    cout << "<action> tar=<target>" << endl;
    for(uint8_t i = 0; task_list[i].cmd != nullptr; i++)
    {
        cout<<task_name<<" tar="<< task_list[i].cmd << endl;
    }

    cout << "============================" << endl;
}

static void introduct_led()
{
    cout << "==========LED==========" << endl;
    cout << "--get tar=led" << endl;
    cout << "--set tar=led status=on" << endl;
    cout << "--set tar=led status=off" << endl;
    cout << "=========================" << endl;
}
static void introduct_auth()
{
    cout << "==========AUTH==========" << endl;
    cout << "--get tar=auth" << endl;;
    cout << "=========================" << endl;
}
void auth_task_handler(task_action_t action,string cmd)
{
    switch (action)
    {
    case TASK_ACTION_GET:
        cout<<"Auth: Dinh Cuong"<<endl;
        break;
    case TASK_ACTION_HELP:
        introduct_auth();
        break;
    default:
        introduct_auth();
        break;
    }
}
void led_task_handler(task_action_t action,string cmd)
{
    switch (action)
    {
    case TASK_ACTION_GET:
        cout<<"led :on (mock)"<<endl;
        break;
    case TASK_ACTION_SET:
    {
        string status = get_param(cmd, "status");
        if (status == "") introduct_led();
        cout<<"led :"<<status<<endl;
        break;
    }
    case TASK_ACTION_HELP:
        introduct_led();
        break;
    default:
        introduct_led();
        break;
    }
    
}
