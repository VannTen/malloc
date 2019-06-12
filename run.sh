#!/bin/sh
export LD_LIBRAY_PATH=.
export LD_PRELOAD=$PWD/libft_malloc.so
export DYLD_LIBRARY_PATH=.
export DYLD_INSERT_LIBRARIES="libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE=1
$@
