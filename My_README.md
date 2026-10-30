Before make, set root env:
setenv ROOTSYS `root-config --prefix`
setenv PATH "$ROOTSYS/bin:$PATH"
setenv LD_LIBRARY_PATH "$ROOTSYS/lib:$LD_LIBRARY_PATH"
./run_mc_single_arm_tree <inp file without .inp>

./run_mc_single_arm_tree hmsdis_3pass_phaseII_al
