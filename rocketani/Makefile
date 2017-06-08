SRC = rc.c

BINAME = rocketnani
PREFIX ?= /usr/local
INSTALLPATH = ${DESTDIR}${PREFIX}/bin

rocketnani : ${SRC}

	@echo "building ${SRC}"
	gcc ${SRC} -o ${BINAME}

install : ${BINAME}

	@echo "installing rocketnani file to ${INSTALLPATH}/${BINAME}"
	@mkdir -p ${INSTALLPATH}
	@cp ${BINAME} ${INSTALLPATH}

uninstall :

	@echo "uninstalling binary file (${INSTALLPATH})"
	@rm -f ${INSTALLPATH}/${BINAME}
