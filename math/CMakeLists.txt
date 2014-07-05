# Collect sources into the variable MATH_SOURCES with 
# having to explicitly list each header and source file
file (GLOB MATH_SOURCES
	  "*.h")

# Collect sources into the variable SIMPLE_FUNCTION_SOURCES  
file (GLOB SIMPLE_FUNCTION_SOURCES
      "simple/*.h",
      "simple/*.cxx")

# Another way to collect sources into a variable ADVANCED_FUNCTION_SOURCES
# by explicitly specifying the source files
set  (ADVANCED_FUNCTION_SOURCES
      "advanced/AdvancedFunctions.h"
      "advanced/AdvancedFunctions.cxx")

# Create named folders for the sources within the .vcproj
# Empty name lists them directly under the .vcproj
source_group("" FILES ${MATH_SOURCES})
source_group("simple" FILES ${SIMPLE_FUNCTION_SOURCES})
source_group("advanced" FILES ${ADVANCED_FUNCTION_SOURCES})

# Properties->C/C++->General->Additional Include Directories
include_directories (.)

# Set Properties->General->Configuration Type to Dynamic Library(.dll)
# Creates math.dll with the listed sources collected in the variables
# Also adds sources to the Solution Explorer
add_library(math SHARED ${MATH_SOURCES} ${SIMPLE_FUNCTION_SOURCES} ${ADVANCED_FUNCTION_SOURCES})

# Creates a folder "libraries" and adds target project (math.vcproj) under it
set_property(TARGET math PROPERTY FOLDER "libraries")

# Adds logic to INSTALL.vcproj to copy math.dll to the destination directory
install (TARGETS math
		 RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)
