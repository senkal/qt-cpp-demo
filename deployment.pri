OTHER_FILES = \
$${PWD}/files/newFile.txt

myfiles.files = \
$${PWD}/files/newFile.txt


unix:!android {
    isEmpty(target.path) {
        qnx {
            target.path = /tmp/$${TARGET}/bin
        } else {
            target.path = /opt/$${TARGET}/bin
            myfiles.path = /opt/$${TARGET}/bin/files
        }
        export(target.path)
        export(myfiles.path)
    }
    INSTALLS += target myfiles
}

export(INSTALLS)
