# -debug-pass-manager 执行过程的有那些pass 参与
opt -O0 -debug-pass-manager test.ll -S -o testO0.ll
opt -O1 -debug-pass-manager test.ll -S -o testO1.ll
opt -O2 -debug-pass-manager test.ll -S -o testO2.ll