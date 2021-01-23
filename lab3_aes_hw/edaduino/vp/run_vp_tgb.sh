#source ../sds_environment.sh

if [ "$#" -lt 1 ]; then
    echo -e "Usage: $0 TargetExecutable\n" \

    exit 1
fi
ELF_INI=ini/elf.ini

TARGETSW_PATH_ELF=$(realpath $1)

echo "Found ELF file: ${TARGETSW_PATH_ELF} "

echo -e \
  "[StringConfigurations]\n" \
  "vp::elf_file=${TARGETSW_PATH_ELF}\n" \
    > $ELF_INI
    
build/edaduino_vp -iini/base.ini -iini/remote.ini -i${ELF_INI} 
