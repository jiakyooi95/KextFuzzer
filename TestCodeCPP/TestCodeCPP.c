//
//  TestCodeCPP.c
//  TestCodeCPP
//
//  Created by macbookpro on 04/01/2017.
//  Copyright © 2017 Prototype. All rights reserved.
//

#include <mach/mach_types.h>
#include <IOKit/IOLib.h>

kern_return_t TestCodeCPP_start(kmod_info_t * ki, void *d);
kern_return_t TestCodeCPP_stop(kmod_info_t *ki, void *d);

kern_return_t TestCodeCPP_start(kmod_info_t * ki, void *d)
{
    return KERN_SUCCESS;
}

kern_return_t TestCodeCPP_stop(kmod_info_t *ki, void *d)
{
    return KERN_SUCCESS;
}
