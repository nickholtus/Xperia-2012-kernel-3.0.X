/*
 * Copyright (C) ST-Ericsson SA 2010
 *
 * ST-Ericsson B2R2 dynamic debug
 *
 * Author: Fredrik Allansson <fredrik.allansson@stericsson.com>
 * for ST-Ericsson.
 *
 * License terms: GNU General Public License (GPL), version 2.
 */

#ifndef _LINUX_DRIVERS_VIDEO_B2R2_DEBUG_H_
#define _LINUX_DRIVERS_VIDEO_B2R2_DEBUG_H_

#include <linux/device.h>

#include "b2r2_internal.h"

#ifdef CONFIG_B2R2_DEBUG

/* Log macros */
enum b2r2_log_levels {
	B2R2_LOG_LEVEL_WARN,
	B2R2_LOG_LEVEL_INFO,
	B2R2_LOG_LEVEL_DEBUG,
	B2R2_LOG_LEVEL_REGDUMP,
	B2R2_LOG_LEVEL_COUNT,
};

/*
 * Booleans controlling the different log levels. The different log levels are
 * enabled separately (i.e. you can have info prints without the warn prints).
 */
extern int b2r2_log_levels[B2R2_LOG_LEVEL_COUNT];

extern struct device *b2r2_log_dev;

#define b2r2_log_err(...) do { \
		dev_err(b2r2_log_dev, __VA_ARGS__); \
	} while (0)

/* If dynamic debug is enabled it should be used instead of loglevels */
#ifdef CONFIG_DYNAMIC_DEBUG
#  define b2r2_log_warn(...) do { \
		dev_dbg(b2r2_log_dev, "WARN " __VA_ARGS__); \
	} while (0)
#  define b2r2_log_info(...) do { \
		dev_dbg(b2r2_log_dev, "INFO " __VA_ARGS__); \
	} while (0)
#  define b2r2_log_debug(...) do { \
		dev_dbg(b2r2_log_dev, "DEBUG " __VA_ARGS__); \
	} while (0)
#  define b2r2_log_regdump(...) do { \
		dev_dbg(b2r2_log_dev, "REGD " __VA_ARGS__); \
	} while (0)
#else
#  define b2r2_log_warn(...) do { \
		if (b2r2_log_levels[B2R2_LOG_LEVEL_WARN]) \
			dev_warn(b2r2_log_dev, "WARN " __VA_ARGS__); \
	} while (0)
#  define b2r2_log_info(...) do { \
		if (b2r2_log_levels[B2R2_LOG_LEVEL_INFO]) \
			dev_info(b2r2_log_dev, "INFO " __VA_ARGS__); \
	} while (0)
#  define b2r2_log_debug(...) do { \
		if (b2r2_log_levels[B2R2_LOG_LEVEL_DEBUG]) \
			dev_dbg(b2r2_log_dev, "DEBUG " __VA_ARGS__); \
	} while (0)
#  define b2r2_log_regdump(...) do { \
		if (b2r2_log_levels[B2R2_LOG_LEVEL_REGDUMP]) \
			dev_vdbg(b2r2_log_dev, "REGD " __VA_ARGS__); \
	} while (0)
#endif


int b2r2_debug_init(struct device *log_dev);
void b2r2_debug_exit(void);

void b2r2_debug_job_done(struct b2r2_node *node);

#else

#define b2r2_log_err(...)
#define b2r2_log_warn(...)
#define b2r2_log_info(...)
#define b2r2_log_debug(...)
#define b2r2_log_regdump(...)

static inline int b2r2_debug_init(struct device *log_dev)
{
	return 0;
}
static inline void b2r2_debug_exit(void)
{
	return;
}
static inline void b2r2_debug_job_done(struct b2r2_node *node)
{
	return;
}

#endif

#endif
