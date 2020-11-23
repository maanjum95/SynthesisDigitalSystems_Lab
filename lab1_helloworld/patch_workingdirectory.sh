#!/bin/bash
SDS_LAB=/usr/local/labs/SDS/current/
PROJECT_NAME=$(basename $(dirname "$0"))
TUMID=$(id -n -u)

echo "Patching cross GCC settings in $PROJECT_NAME for $TUMID ..."

ERRORFILE=edaduino/sw/cmake/_tumeda/toolchain.cmake

rm $SDS_LAB/${TUMID}/${PROJECT_NAME}/${ERRORFILE}
cp $SDS_LAB/common/${PROJECT_NAME}/${ERRORFILE} $SDS_LAB/${TUMID}/${PROJECT_NAME}/edaduino/sw/cmake/_tumeda/

echo "done."
