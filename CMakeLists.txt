cmake_minimum_required(VERSION 2.8)
PROJECT(libreqa)

add_executable(libreqa 
        Auth1.C
	model/Session.C
	model/User.C
)

TARGET_LINK_LIBRARIES(libreqa wt boost_system-mt boost_signals-mt wthttp wtdbo wtdbosqlite3)

