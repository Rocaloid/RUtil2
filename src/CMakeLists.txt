aux_source_directory(./Core SRC_LIST)
aux_source_directory(./Structure SRC_LIST)
aux_source_directory(./Misc SRC_LIST)
aux_source_directory(./IO SRC_LIST)

add_library(RUtil2 ${SRC_LIST})
include_directories(RUtil2 PUBLIC "${CMAKE_SOURCE_DIR}/src")

install(FILES Core/OO.h
              Core/RAlloc.h
              Core/_RAlloc.h
              Core/RTemplate.h
              Core/Include_T1AllTypes.h
              Core/MacroUtil.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/RUtil2/Core)
install(FILES Structure/Array.h
              Structure/PMatch.h
              Structure/_PMatch.h
              Structure/String.h
              Structure/Transition.h
              Structure/_Transition.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/RUtil2/Structure)
install(FILES Misc/Convert.h
              Misc/Sort.h
              Misc/_Sort.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/RUtil2/Misc)
install(FILES IO/File.h
              IO/_File.h
              IO/WaveFile.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/RUtil2/IO)
install(FILES Include/RUtil2.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/)
install(FILES Include/RUtil2.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/RUtil2)

if(CYGWIN)
    message(FATAL_ERROR "
                        Cygwin is unsupported yet!
                        If you want build it on Windows. Use MinGW32!
                        ")
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message("Your system is 64bit.")
    install(TARGETS RUtil2 ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib64)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    message("Your system is 32bit.")
    install(TARGETS RUtil2 ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
else()
    message(FATAL_ERROR "Your system is unsupported!")
endif()

