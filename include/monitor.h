#ifndef MONITOR_H
#define MONITOR_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

// Write a single character out to the screen.
void monitor_put(char c);

// Clear the screen to all black.
void monitor_clear();

// Output a null-terminated ASCII string to the monitor.
void monitor_write(const char *c);

#ifdef __cplusplus
}
#endif
#endif // MONITOR_H
