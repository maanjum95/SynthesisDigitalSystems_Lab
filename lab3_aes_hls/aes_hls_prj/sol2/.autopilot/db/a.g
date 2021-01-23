#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /nas/ei/share/TUEIEDA/LabSDS/SS20/ge29noy/labsds/aes_hls/aes_hls_prj/sol2/.autopilot/db/a.g.bc ${1+"$@"}
