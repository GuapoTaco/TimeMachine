
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)

add_definitions("-DBOOST_HANA_CONFIG_ENABLE_STRING_UDL=1")

# NOTE: please keep these in alphebetical order
add_library( tmlibs SHARED
	Compiler.cpp
	Compiler.h
	DefaultPreprocessor.cpp
	DefaultPreprocessor.h
	DefaultPreprocessor.cpp 
	DefaultPreprocessor.h 
	OperationPattern.h
	RegisterPattern.h
)
target_link_libraries(tmlibs 
	debug ${Boost_PROGRAM_OPTIONS_LIBRARY_DEBUG}
	optimized ${Boost_PROGRAM_OPTIONS_LIBRARY_RELEASE}
)
target_compile_features(tmlibs PUBLIC
	cxx_right_angle_brackets
	cxx_auto_type
	cxx_variable_templates
)
install(TARGETS tmlibs LIBRARY DESTINATION lib)


add_executable(tmc Driver.cpp)
target_link_libraries(tmc tmlibs
	debug ${Boost_PROGRAM_OPTIONS_LIBRARY_DEBUG}
	optimized ${Boost_PROGRAM_OPTIONS_LIBRARY_RELEASE}
)

target_compile_features(tmc PUBLIC
	cxx_right_angle_brackets
	cxx_auto_type
	cxx_variable_templates
)
install(TARGETS tmc RUNTIME DESTINATION bin)

