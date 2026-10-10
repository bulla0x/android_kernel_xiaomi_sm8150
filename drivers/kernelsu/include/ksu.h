#ifndef __KSU_H_KSU
#define __KSU_H_KSU

#include <linux/types.h>
#include <linux/workqueue.h>
#include <linux/cred.h>

#define KERNEL_SU_VERSION KSU_VERSION
#define KERNEL_SU_VERSION_TAG KSU_VERSION_TAG

#define EVENT_POST_FS_DATA 1
#define EVENT_BOOT_COMPLETED 2
#define EVENT_MODULE_MOUNTED 3
#define EVENT_SERVICES 4

static inline bool startswith(const char *str, const char *prefix)
{
	return strncmp(str, prefix, strlen(prefix)) == 0;
}

static inline bool endswith(const char *str, const char *suffix)
{
	size_t str_len = strlen(str);
	size_t suffix_len = strlen(suffix);
	if (suffix_len > str_len)
		return false;
	return !strcmp(str + str_len - suffix_len, suffix);
}

extern struct cred* ksu_cred;
#ifdef MODULE
extern bool ksu_bundled;
#endif
extern bool ksu_late_loaded;

#endif
