cmake_minimum_required (VERSION 3.2)

set (PLUGIN_NAME "conti")

project ("plugin-${PLUGIN_NAME}"
    VERSION 0.0.1
    LANGUAGES CXX)

find_package (ReFramed REQUIRED)
include (ReFramedPlugin)

reframed_add_plugin (plugin-${PLUGIN_NAME}
    SOURCES
        "src/models/ContiModel.cpp"
        "src/views/ContiView.cpp"
		"src/ContiPlugin.cpp"
        "src/Plugin.cpp"
	HEADERS
		"include/${PLUGIN_NAME}/models/ContiModel.hpp"
		"include/${PLUGIN_NAME}/views/ContiView.hpp"
		"include/${PLUGIN_NAME}/ContiPlugin.hpp"
    INCLUDE_DIRECTORIES
        "include"
    MOC_HEADERS
        "include/${PLUGIN_NAME}/views/ContiView.hpp")

if (${REFRAMED_plugin-${PLUGIN_NAME}})
endif ()

