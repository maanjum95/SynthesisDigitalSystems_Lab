#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /nas/ei/share/TUEIEDA/LabSDS/WS20/ge46bod/Design_Analysis/lab1/dct_prj/solution4/.autopilot/db/a.g.bc ${1+"$@"}
