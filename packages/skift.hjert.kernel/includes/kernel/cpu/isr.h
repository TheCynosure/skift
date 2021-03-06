#pragma once

/* Copyright © 2018-2019 MAKER.                                               */
/* This code is licensed under the MIT License.                               */
/* See: LICENSE.md                                                            */

#include <skift/generic.h>

#include "kernel/processor.h"

typedef void (*isr_handler_t)(processor_context_t *);

void isr_setup();
isr_handler_t isr_register(int index, isr_handler_t handler);