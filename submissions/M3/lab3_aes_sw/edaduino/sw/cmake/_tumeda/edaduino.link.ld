/*
// Copyright 2017 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the “License”); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an “AS IS” BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

// This file was modified by the Chair of Electronic Design Automation, TUM
*/

SEARCH_DIR(.)
__DYNAMIC  =  0;

VAR_rom_start = DEFINED(_ROM_START) ?   _ROM_START : 0x0;
VAR_rom_size = DEFINED(_ROM_SIZE) ?     _ROM_SIZE : 0x80000;
VAR_ram_start = DEFINED(_RAM_START) ?   _RAM_START : 0x80000;
VAR_ram_size = DEFINED(_RAM_SIZE) ?     _RAM_SIZE : 0x80000;
VAR_stack_size = DEFINED(_STACK_SIZE) ? _STACK_SIZE : 0x2000;

MEMORY
{
    instrram    : ORIGIN = VAR_rom_start, LENGTH = VAR_rom_size
    dataram     : ORIGIN = VAR_ram_start, LENGTH = VAR_ram_size
}

/* Stack information variables */
_min_stack     = VAR_stack_size;   /* minimum stack space to reserve */
_stack_start   = ORIGIN(dataram) + LENGTH(dataram);
_heap_start    = _bss_end;
_heap_end      = _stack_start;

/* We have to align each sector to word boundaries as our current s19->slm
 * conversion scripts are not able to handle non-word aligned sections. */

SECTIONS
{
    .vectors :
    {
        . = ALIGN(4);
        KEEP(*(.vectors))
    } > instrram

    .text : {
        . = ALIGN(4);
        _stext = .;
        *(.text)
        _etext  =  .;
        __CTOR_LIST__ = .;
        LONG((__CTOR_END__ - __CTOR_LIST__) / 4 - 2)
        *(.ctors)
        LONG(0)
        __CTOR_END__ = .;
        __DTOR_LIST__ = .;
        LONG((__DTOR_END__ - __DTOR_LIST__) / 4 - 2)
        *(.dtors)
        LONG(0)
        __DTOR_END__ = .;
        *(.lit)
        *(.shdata)
        _endtext = .;
    }  > instrram

    /*--------------------------------------------------------------------*/
    /* Global constructor/destructor segement                             */
    /*--------------------------------------------------------------------*/

    .preinit_array     :
    {
      PROVIDE_HIDDEN (__preinit_array_start = .);
      KEEP (*(.preinit_array))
      PROVIDE_HIDDEN (__preinit_array_end = .);
    } > dataram

    .init_array     :
    {
      PROVIDE_HIDDEN (__init_array_start = .);
      KEEP (*(SORT(.init_array.*)))
      KEEP (*(.init_array ))
      PROVIDE_HIDDEN (__init_array_end = .);
    } > dataram

    .fini_array     :
    {
      PROVIDE_HIDDEN (__fini_array_start = .);
      KEEP (*(SORT(.fini_array.*)))
      KEEP (*(.fini_array ))
      PROVIDE_HIDDEN (__fini_array_end = .);
    } > dataram

    .rodata : {
        . = ALIGN(4);
        *(.rodata);
        *(.rodata.*)
        *(.srodata)
        *(.srodata.*)
    } > instrram

    .shbss :
    {
        . = ALIGN(4);
        *(.shbss)
    } > dataram

    .data : {
        . = ALIGN(4);
        sdata  =  .;
        _sdata  =  .;
        *(.data);
        *(.data.*)
        *(.sdata2.*)
        edata  =  .;
        _edata  =  .;
    } > dataram

    .bss :
    {
        . = ALIGN(4);
        _bss_start = .;
        *(.bss)
        *(.bss.*)
        *(.sbss)
        *(.sbss.*)
        *(COMMON)
        _bss_end = .;
    } > dataram

    /* do not place anything after this address, because the heap starts here! */

    /* ensure there is enough room for stack */
    .stack (NOLOAD): {
        . = ALIGN(4);
        . = . + _min_stack ;
        . = ALIGN(4);
        stack = . ;
        _stack = . ;
    } > dataram

    .stab  0 (NOLOAD) :
    {
        [ .stab ]
    }

    .stabstr  0 (NOLOAD) :
    {
        [ .stabstr ]
    }

    .bss :
    {
        . = ALIGN(4);
        _end = .;
    } > dataram
}
