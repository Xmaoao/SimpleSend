set(GUI_MAIN           ${PROJECT_SOURCE_DIR}/GUI/SimplesendGUI.py)
set(GUI_MAIN_HASH      ${PROJECT_SOURCE_DIR}/GUI/SimplesendGUI.py.md5)

set(GUI_MAIN_SPEC      ${PROJECT_SOURCE_DIR}/GUI/SimplesendGUI.spec)
set(GUI_MAIN_SPEC_HASH ${PROJECT_SOURCE_DIR}/GUI/SimplesendGUI.spec.md5)

message(STATUS "FILE>   GUI src: " ${GUI_MAIN} "\n")

set(BUILD_GUI_NEEDED "NO")
# if GUI src is needed to be rebuilt

message(STATUS "CHECK>  Start calculating all GUI src files' MD5")

file(MD5 ${GUI_MAIN} GUI_MAIN_HASH_AFTER)
message(STATUS "CHECK>  SimplesendGUI.py MD5:   " ${GUI_MAIN_HASH_AFTER})

file(MD5 ${GUI_MAIN_SPEC} GUI_MAIN_SPEC_HASH_AFTER)
message(STATUS "CHECK>  SimplesendGUI.spec MD5: " ${GUI_MAIN_SPEC_HASH_AFTER})

message(STATUS "CHECK>  Finish calculating all GUI src files' MD5 \n")

message(STATUS "CHECK>  Start checking all GUI src files and judge if they've been changed")

if(EXISTS ${GUI_MAIN_HASH})
    file(STRINGS ${GUI_MAIN_HASH} GUI_MAIN_HASH_BEFORE LIMIT_COUNT 1)
    if(NOT ${GUI_MAIN_HASH_AFTER} STREQUAL ${GUI_MAIN_HASH_BEFORE})
        message(STATUS "CHECK>  File " ${GUI_MAIN} " is changed")
        set(BUILD_GUI_NEEDED "YES")
        file(WRITE ${GUI_MAIN_HASH} ${GUI_MAIN_HASH_AFTER})
    else()
        message(STATUS "CHECK>  File " ${GUI_MAIN} " isn't changed")
    endif()
else()
    message(STATUS "CHECK>  File " ${GUI_MAIN_HASH} " isn't found, create it")
    file(WRITE ${GUI_MAIN_HASH} ${GUI_MAIN_HASH_AFTER})
    set(BUILD_GUI_NEEDED "YES")
endif()
# check if file SimplesendGUI.py is changed

if(EXISTS ${GUI_MAIN_SPEC_HASH})
    file(STRINGS ${GUI_MAIN_SPEC_HASH} GUI_MAIN_SPEC_HASH_BEFORE LIMIT_COUNT 1)
    if(NOT ${GUI_MAIN_SPEC_HASH_AFTER} STREQUAL ${GUI_MAIN_SPEC_HASH_BEFORE})
        message(STATUS "CHECK>  File " ${GUI_MAIN_SPEC} " is changed")
        set(BUILD_GUI_NEEDED "YES")
        file(WRITE ${GUI_MAIN_SPEC_HASH} ${GUI_MAIN_SPEC_HASH_AFTER})
    else()
        message(STATUS "CHECK>  File " ${GUI_MAIN_SPEC} " isn't changed")
    endif()
else()
    message(STATUS "CHECK>  File " ${GUI_MAIN_SPEC_HASH} " isn't found, create it")
    file(WRITE ${GUI_MAIN_SPEC_HASH} ${GUI_MAIN_SPEC_HASH_AFTER})
    set(BUILD_GUI_NEEDED "YES")
endif()
# check if file SimplesendGUI.spec is changed

message(STATUS "CHECK>  Finish checking all GUI src files \n")

set(REBUILT_GUI ${BUILD_GUI_NEEDED} PARENT_SCOPE)
# send message contains if GUI target is rebuilt to parent folder

if(EXISTS ${GUI_MAIN_SPEC})
    if(${BUILD_GUI_NEEDED} STREQUAL "YES")
        message(STATUS "STATUS> GUI src has been updated, start repacking GUI source files")
        execute_process(COMMAND pyinstaller -y SimplesendGUI.spec
                        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/GUI)
        message(STATUS "STATUS> Finish repacking GUI source files \n")
    else()
        message(STATUS "STATUS> GUI src hasn't been changed, no need to repack \n")
    endif()
else()
    message(FATAL_ERROR "
    Fatal>  In folder ./GUI: SimplesendGUI.spec not found, cannot pack GUI source files
            Check this file in folder ./GUI or use \"pyi-makespec SimplesendGUI.py\" to create it
    ")
endif()