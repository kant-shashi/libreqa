WT_ADD_EXAMPLE(libreqa 
        Auth1.C
	model/Session.C
	model/User.C
)

TARGET_LINK_LIBRARIES(libreqa wtdbo wtdbosqlite3)

