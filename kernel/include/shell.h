#ifndef SHELL_H
#define SHELL_H

class shell
{
public:
    void output_prompt();
    char *input_line();
    int start_process(char *command);
    int process_executing(int process);
private:
    char buffer[1024];
};

#endif