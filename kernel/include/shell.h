#ifndef SHELL_H
#define SHELL_H

#include "../kernel/include/common.h"
#include "../libc/include/string.h"

class shell {
public:
    void output_prompt();
    char *input_line();
    int start_process(char *command);
    void process_executing(int process);
    char input_char (u8int scancode);
    int is_command(char *str);
private:
    char *cmd = nullptr;
    char *builtins[10] = {
        "calendar"
    };
    char buffer[1024];
};

#endif