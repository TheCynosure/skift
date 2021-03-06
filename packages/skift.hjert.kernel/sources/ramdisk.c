/* Copyright © 2018-2019 MAKER.                                               */
/* This code is licensed under the MIT License.                               */
/* See: LICENSE.md                                                            */

#include <math.h>
#include <string.h>
#include <skift/tar.h>
#include <skift/logger.h>

#include "kernel/filesystem.h"
#include "kernel/multiboot.h"

void ramdisk_load(multiboot_module_t *module)
{
    // Extract the ramdisk tar archive.

    sk_log(LOG_INFO, "Loading ramdisk at 0x%x...", module->mod_start);

    void *ramdisk = (void *)module->mod_start;

    tar_block_t block;
    for (size_t i = 0; tar_read(ramdisk, &block, i); i++)
    {
        if (block.name[strlen(block.name) - 1] == '/')
        {
            sk_log(LOG_DEBUG, "Creating %s directory...", block.name);
            if (FSRESULT_SUCCEED != filesystem_mkdir(block.name))
            {
                sk_log(LOG_WARNING, "Failed to create directory %s...", block.name);
            }
        }
        else
        {
            stream_t *s = filesystem_open(block.name, OPENOPT_WRITE | OPENOPT_CREATE | OPENOPT_TRUNC);
            
            if (s != NULL)
            {
                filesystem_write(s, block.data, block.size);
                filesystem_close(s);
            }
            else
            {
                sk_log(LOG_WARNING, "Failed to open file %s!", block.name);
            }
        }
    }

    sk_log(LOG_FINE, "Loading ramdisk succeeded.");
}
