#!/usr/bin/env python3
######################################################################
import argparse
#import sys
import os
from os import listdir
from os.path import isfile, join
#######################################################################

if __name__=='__main__':
    parser = argparse.ArgumentParser(
        allow_abbrev=False,
        formatter_class=argparse.RawTextHelpFormatter
    )
    parser.add_argument('-dir', '--directory',
                        action='store', metavar='input directory', required=True,
                        help='input RTL directy to patch')

    parser.add_argument('-abs', '--absolute',
                        action='store', metavar='absolute values flag', default=False, required=False,
                        help='patch initializers to absolute values')

    (args, rem) = parser.parse_known_args()
    
    dir_ = args.directory #// + '.patched'
    
    print("Patching RTL files in: ", dir_)
    
    onlyfiles = [f for f in listdir(dir_) if isfile(join(dir_, f))]
    
    sourcefiles_p = []
    romfiles_p = []
    sourcefiles = []
    romfiles = []
    
    print("RTL source files (*.v/*.sv)")
    for f in onlyfiles:
        if(f.find(".v")>=0): 
            sourcefiles.append(f);
            sourcefiles_p.append(str(dir_ + '/' + f))
            print("-", f)
        
    print("ROM/Dat files (*_rom.dat)")
    for f in onlyfiles:
        if(f.find("_rom.dat")>=0):
            romfiles.append(f)
            romfiles_p.append(str(dir_ + '/' + f)) 
            print("-", f)    
    
    if args.absolute == False:
        i = 0
        for src in sourcefiles:
            print("Start patching ", src)
            k = 0
            for rom in romfiles:
                with open(sourcefiles_p[i], 'rt') as fin:
                    data = fin.read()
                    ndata = data.replace('./'+rom, os.path.abspath(romfiles_p[k]))
                    fin.close()
                with open(sourcefiles_p[i], 'wt') as fin:
                    fin.write(ndata)
                    fin.close()
                k = k+1
                print("... done with references to: ", rom)    
                    
            i = i + 1   

    else:
        
        i = 0
        for src in sourcefiles:
            print("Start patching absolute", src)
     
            replace_string = ''
            with open(sourcefiles_p[i], 'rt') as fin:
                src_string = fin.readlines()
                fin.close()
                k = 0

                set_of_replace_sets = []

                for line in src_string:
                    k = 0
                    for rom in romfiles:
                        toreplace = '$readmemh(\"./' + rom + '", '
                        replace_pos = line.find(toreplace)
                        varname = line[line.find(toreplace)+len(toreplace):line.find(');')]
                        if(replace_pos >= 0): 
                            replace_string = ''
                            with open(romfiles_p[k], 'rt') as fin:
                                rl = 0
                                for line in fin:
                                    if(line != '\n'):
                                        replace_string += varname + '[' + str(rl) + '] = 8\'h' + line[:-1] + ';\n'
                                        rl = rl +1
                                fin.close()
                                set_of_replace_sets.append([toreplace, replace_string, varname])
                                
                        k = k+1

                with open(sourcefiles_p[i], 'wt') as fin:    
                    print("-> update", sourcefiles_p[i])
                    for line in src_string:
                        repstr = line
                        for replace_set in set_of_replace_sets:
                            if line.find(replace_set[0]) >= 0 and line.find(replace_set[2]) >= 0 and line != '' and line != '\n': repstr = replace_set[1]
                                #find(replace_set[0] >= 0 and replace_set[0] != '') repstr = replace_set[1]
                        fin.write(repstr)    
                    fin.close()           

            i = i + 1
