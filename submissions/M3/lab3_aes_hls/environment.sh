#!/bin/sh

################################################################
# \brief Environmental helper source for SDS in SS'20
# \author geier
# \date 04/23/20
################################################################
TUMID=$(id -n -u)
export SDS_LAB=/usr/local/labs/SDS/current
export SDS_TOOLS=$SDS_LAB/common/tools

# Add helper variables to environment
export ETISS_HOME=$SDS_TOOLS/etiss/core/
export ETISS_VPLIB_HOME=$SDS_TOOLS/etiss/vplib/
export SYSTEMC=$SDS_TOOLS/systemc/cpp17/
export SYSTEMC_HOME=$SDS_TOOLS/systemc/cpp17/
export SYSTEMC_INCLUDE_DIRS=$SYSTEMC/include/
export SYSTEMC_LIB_DIRS=$SYSTEMC/lib/
export SCC_MINRES_HOME=$SDS_TOOLS/systemc/minres_scc/
export RISCV=$SDS_TOOLS/sdk/riscv-gcc/
export VERILATOR_ROOT=$SDS_TOOLS/verilator/share/verilator/
export CMAKE_HOME=$SDS_TOOLS/cmake/
export BOOST_HOME=$SDS_TOOLS/boost/
#export EDADUINO_TCPPORT=$(grep -Eo "\b[0-9]+\b" $SDS_LAB/$TUMID/lab0_helloworld/edaduino/vp/ini/remote.ini)

# Add precompiled shared libraries to LD_LIBRARY_PATH
export LD_LIBRARY_PATH=$ETISS_HOME/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ETISS_HOME/lib/plugins
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$SYSTEMC_LIB_DIRS
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ETISS_VPLIB_HOME/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$SCC_MINRES_HOME/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$BOOST_HOME/lib

source $SDS_LAB/common/vivadoEnvSettings.sh
