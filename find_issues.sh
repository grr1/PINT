#!/bin/bash

# returns every filename with an unaddressed "TODO" tag (not case sensitive); ignores this file itself
grep -irl "TODO" | grep -v `basename "$0"`

# to be fancy, when grep returns no files
if [ "$?" -eq 1 ] ; then
	echo "-No files need attention."
fi
