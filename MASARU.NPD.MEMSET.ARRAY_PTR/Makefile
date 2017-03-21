KW_INSTALL_DIR=/home/mhorioka/Klocwork/12.0.0_desktop

install : 
	"$(KW_INSTALL_DIR)/bin/kwxpack" MASARU.NPD.MEMSET.ARRAY_PTR checkers.xml help.xml
	unzip -o MASARU.NPD.MEMSET.ARRAY_PTR.zip -d  ~/.klocwork/plugins/
clean :
	rm -f kwinject.out
	rm -f MASARU.NPD.MEMSET.ARRAY_PTR.zip
buildspec:
	"$(KW_INSTALL_DIR)/bin/kwinject" /bin/sh -c "gcc -c testcase.cc -o testcase.o"; rm -f testcase.o
test : buildspec install
	rm -rf .kwlp .kwps
	"$(KW_INSTALL_DIR)/bin/kwcheck" create -b kwinject.out
	"$(KW_INSTALL_DIR)/bin/kwcheck" run
	
.PHONY : install clean

