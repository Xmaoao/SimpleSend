if(EXISTS ${PROJECT_SOURCE_DIR}/GUI/SimplesendGUI.spec)
    execute_process(COMMAND pyinstaller -y SimplesendGUI.spec
                    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/GUI)
else()
    message(FATAL_ERROR "
    Fatal> In folder ./GUI: GUI.spec not found, cannot install GUI package
           Check this file or use \"pyi-makespec SimplesendGUI.py\" to create it
    ")
endif()