#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /nas/ei/share/TUEIEDA/LabSDS/WS20/ge46bod/Introduction/lab1/fir-prj/solution1/.autopilot/db/a.g.bc ${1+"$@"}
