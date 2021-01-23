#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /nas/ei/share/TUEIEDA/LabSDS/WS20/ge46bod/lab3_aes_hls/aes_hls_prj/sol3/.autopilot/db/a.g.bc ${1+"$@"}
