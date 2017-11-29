/*
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr.h>
#include <ztest.h>

bool valid_fault;

void _SysFatalErrorHandler(unsigned int reason, const NANO_ESF *pEsf)
{
	printk("Caught system error -- reason %d\n", reason);
	if(valid_fault) {
		valid_fault = false; /* reset back to normal */
		ztest_test_pass();
	}
	else {
		ztest_test_fail();
	}

#ifndef CONFIG_ARM
	CODE_UNREACHABLE;
#endif
}
