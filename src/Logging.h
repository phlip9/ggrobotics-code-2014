// Logging macros
// Can be removed at compile time
// log_error
// log_warn
// log_debug
// log_info

#ifndef _LOGGING_H_
#define _LOGGING_H_

#include <stdio.h>

// Uncomment/comment these to add/remove debugging at a particular level
#define LEVEL_ERROR
#define LEVEL_WARN
#define LEVEL_DEBUG
#define LEVEL_INFO

#ifdef LEVEL_ERROR
#define log_error(message, ...) printf("[ERROR] (%s:%d) " message "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define log_error(message, ...)
#endif

#ifdef LEVEL_WARN
#define log_warn(message, ...) printf("[WARN] (%s:%d) " message "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define log_warn(message, ...)
#endif

#ifdef LEVEL_DEBUG
#define log_debug(message, ...) printf("[DEBUG] (%s:%d) " message "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define log_debug(message, ...)
#endif

#ifdef LEVEL_INFO
#define log_info(message, ...) printf("[INFO] (%s:%d) " message "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define log_info(message, ...)
#endif

#endif
