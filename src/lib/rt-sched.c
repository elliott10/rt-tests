// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * rt-sched.h - sched_setattr() and sched_getattr() API
 *
 * (C) Dario Faggioli <raistlin@linux.it>, 2009, 2010
 * Copyright (C) 2014 BMW Car IT GmbH, Daniel Wagner <daniel.wagner@bmw-carit.de
 */

/* This file is based on Dario Faggioli's libdl. Eventually it will be
   replaced by a proper implemenation of this API. */

#include <unistd.h>
#include <sys/syscall.h>

#include "rt-sched.h"

int sched_setattr(pid_t pid,
		  const struct sched_attr *attr,
		  unsigned int flags)
{
	return syscall(__NR_sched_setattr, pid, attr, flags);
}

int sched_getattr(pid_t pid,
		  struct sched_attr *attr,
		  unsigned int size,
		  unsigned int flags)
{
        return syscall(__NR_sched_getattr, pid, attr, size, flags);
}

/* Repaired for Musl gcc */
int sched_getparam(pid_t pid, struct sched_param *param)
{
        printf("To sched_getparam\n");
        return syscall(__NR_sched_getparam, pid, param);
}
int sched_getscheduler(pid_t pid)
{
        printf("To sched_getscheduler\n");
        return syscall(__NR_sched_getscheduler, pid);
}
int sched_setparam(pid_t pid, const struct sched_param *param)
{
        printf("To sched_setparam\n");
        return syscall(__NR_sched_setparam, pid, param);
}
int sched_setscheduler(pid_t pid, int sched, const struct sched_param *param)
{
        printf("To sched_setscheduler\n");
        return syscall(__NR_sched_setscheduler, pid, sched, param);
}
