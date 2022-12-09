#ifndef SHELL_H
#define SHELL_H

#include "../kernel/include/common.h"

class shell {
public:
    void output_prompt();
    char *input_line();
    int start_process(char *command);
    int process_executing(int process);
    char input_char (u8int scancode);
private:
    char buffer[1024];
};

#endif