cmake_minimum_required(VERSION 2.6)
project(libreqa)

include_directories(${CMAKE_SOURCE_DIR} /opt/hypertable/current/include /opt/local/include )
include_directories(/opt/hypertable/current/include/thrift/)
link_directories(/opt/local/lib /usr/local/lib /usr/lib /opt/hypertable/current/lib/)
include(FindPkgConfig)
include(CPack)



# Options 

option(STATIC_VIEW "Build Static View instead of dynamically loaded one" ON)


# Dependencies

find_library(LIB_BOOSTER booster)
find_library(LIB_CPPCMS cppcms)
find_program(EXE_TMPL_CC cppcms_tmpl_cc)

find_path(INC_BOOSTER booster/config.h)
find_path(INC_CPPCMS cppcms/config.h)

pkg_search_module(IM REQUIRED ImageMagick++ GraphicsMagick++)
include_directories(${IM_INCLUDE_DIRS})


if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
	      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if(WIN32 OR CYGWIN)
	# We use shared libraries...
	add_definitions(-DDLL_EXPORT)
endif()

set(SKINS green)

set(ADMIN_TEMPLATES 
	views/admin/master.tmpl
	views/admin/users.tmpl
	views/admin/options.tmpl
	views/admin/tags.tmpl
	views/admin/caching.tmpl
	views/admin/comment.tmpl
	views/admin/categories.tmpl
	views/admin/config.tmpl
	)


set(QA_SRC
	apps/questions/master.cpp
	apps/htpool.cpp
#	apps/blog/post.cpp
#	apps/blog/page.cpp
#	add_executable(cppblog_migrate sql/migrate.cpp)
	apps/questions/questions.cpp
	apps/questions/home.cpp
#	apps/blog/summary.cpp
#	apps/feed/feed.cpp
	apps/basic_master.cpp
	apps/captcha.cpp
#	apps/config.cpp
	apps/main.cpp
#	apps/admin/admin.cpp
#	apps/admin/users.cpp
#	apps/admin/summary.cpp
#	apps/admin/page.cpp
#	apps/admin/post.cpp
#	apps/admin/caching.cpp
#	apps/admin/options.cpp
#	apps/admin/comment.cpp
#	apps/admin/categories.cpp
#	"${CMAKE_CURRENT_BINARY_DIR}/master.cpp"
#	"${CMAKE_CURRENT_BINARY_DIR}/home.cpp"
	)
	
	
foreach(SKIN ${SKINS})
	set(VIEW_NAME ${SKIN})
	set(VIEW_TEMPLATES 
		views/basic_master.tmpl
		views/skins/${SKIN}.tmpl
		#views/blog/post.tmpl
		#views/blog/page.tmpl
		views/questions/home.tmpl
		)

	set(VIEW_SRC "${CMAKE_CURRENT_BINARY_DIR}/${VIEW_NAME}.cpp")

	add_custom_command(
		OUTPUT ${VIEW_SRC}
		COMMAND ${EXE_TMPL_CC}
			-s "${VIEW_NAME}"
			${TMPL_CC_PARAMS}
			-o ${VIEW_SRC}
 			${VIEW_TEMPLATES}
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		DEPENDS ${VIEW_TEMPLATES})


	if(STATIC_VIEW)
		set(QA_SRC ${QA_SRC} ${VIEW_SRC})
	else()
		add_library(${VIEW_NAME} SHARED ${VIEW_SRC})
		target_link_libraries(${VIEW_NAME} ${LIB_CPPCMS})
		target_link_libraries(${VIEW_NAME} ${LIB_BOOSTER})
	endif()
endforeach()

# Actual Build

include_directories(${INC_BOOSTER})
include_directories(${INC_CPPCMS})

add_executable(libreqa ${QA_SRC})
target_link_libraries(libreqa ${LIB_CPPCMS} HyperThrift HyperThriftConfig Hypertable HyperCommon thrift boost_system-mt)
target_link_libraries(libreqa ${LIB_BOOSTER})
target_link_libraries(libreqa ${IM_LIBRARIES})
add_subdirectory(apps/questions)
add_subdirectory(data)
add_subdirectory(views)
add_subdirectory(media)
