aux_source_directory(./Core SRC_LIST)
aux_source_directory(./Structure SRC_LIST)
aux_source_directory(./Misc SRC_LIST)
aux_source_directory(./IO SRC_LIST)

add_library(RUtil2 ${SRC_LIST})
target_include_directories(RUtil2 PUBLIC "${CMAKE_SOURCE_DIR}/src")

install(FILES Core/OO.h
              Core/RAlloc.h
              Core/_RAlloc.h
              Core/RTemplate.h
              Core/Include_T1AllTypes.h
              Core/MacroUtil.h
              DESTINATION /usr/include/RUtil2/Core)
install(FILES Structure/Array.h
              Structure/PMatch.h
              Structure/_PMatch.h
              Structure/String.h
              Structure/Transition.h
              Structure/_Transition.h
              DESTINATION /usr/include/RUtil2/Structure)
install(FILES Misc/Convert.h
              Misc/Sort.h
              Misc/_Sort.h
              DESTINATION /usr/include/RUtil2/Misc)
install(FILES IO/File.h
              IO/_File.h
              IO/WaveFile.h
              DESTINATION /usr/include/RUtil2/IO)
install(FILES Include/RUtil2.h
              DESTINATION /usr/include/)
install(FILES Include/RUtil2.h
              DESTINATION /usr/include/RUtil2)

install(TARGETS RUtil2 ARCHIVE DESTINATION /usr/lib)

