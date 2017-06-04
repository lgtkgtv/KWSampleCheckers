KW_INSTALL_DIR=/Library/Frameworks/KlocworkInsight.framework/Versions/Current

install : 
	"$(KW_INSTALL_DIR)/bin/kwxpack" MASARU.C.CWE.SAMPLE checkers.xml help.xml
clean :
	rm -f kwinject.out
	rm -f MASARU.C.CWE.SAMPLE.zip
buildspec:
	"$(KW_INSTALL_DIR)/bin/kwinject" /bin/sh -c "gcc -c testcase.cc -o testcase.o"; rm -f testcase.o
.PHONY : install clean

