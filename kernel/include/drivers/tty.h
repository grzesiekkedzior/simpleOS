#ifndef MONITOR_H
#define MONITOR_H

#ifdef __cplusplus
extern "C"
{
#endif

    // Write a single character out to the screen.
    void monitor_put(char c);

    // Clear the screen to all black.
    void monitor_clear();

    // Output a null-terminated ASCII string to the monitor.
    void monitor_write(const char *c);

    // Handle arrow keys
    void arrow_up();
    void arrow_right();
    void arrow_left();
    void arrow_down();

#ifdef __cplusplus
}
#endif
#endif // MONITOR_H
