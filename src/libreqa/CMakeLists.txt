cmake_minimum_required(VERSION 2.6)
project(libreqa)

include_directories(${CMAKE_SOURCE_DIR})
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
#	apps/blog/post.cpp
#	apps/blog/page.cpp
#	add_executable(cppblog_migrate sql/migrate.cpp)
	apps/questions/questions.cpp
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
#	"${CMAKE_CURRENT_BINARY_DIR}/admin.cpp"
	)
	
# Actual Build

include_directories(${INC_BOOSTER})
include_directories(${INC_CPPCMS})

add_executable(libreqa ${QA_SRC})
target_link_libraries(libreqa ${LIB_CPPCMS})
target_link_libraries(libreqa ${LIB_BOOSTER})
add_subdirectory(apps/questions)