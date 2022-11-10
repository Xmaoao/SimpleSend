set(HASH_ROOT_INCLUDE ${PROJECT_SOURCE_DIR}/lib/hash/include/hash/hash4cxx.h)
set(MD5_INCLUDE       ${PROJECT_SOURCE_DIR}/lib/hash/include/hash/md5.h)
set(MD5_SOURCE        ${PROJECT_SOURCE_DIR}/lib/hash/src/md5.cpp)
set(SHA1_INCLUDE      ${PROJECT_SOURCE_DIR}/lib/hash/include/hash/sha1.h)
set(SHA1_SOURCE       ${PROJECT_SOURCE_DIR}/lib/hash/src/sha1.cpp)
set(SHA224_INCLUDE    ${PROJECT_SOURCE_DIR}/lib/hash/include/hash/sha224.h)
set(SHA224_SOURCE     ${PROJECT_SOURCE_DIR}/lib/hash/src/sha224.cpp)
set(SHA256_INCLUDE    ${PROJECT_SOURCE_DIR}/lib/hash/include/hash/sha256.h)
set(SHA256_SOURCE     ${PROJECT_SOURCE_DIR}/lib/hash/src/sha256.cpp)
set(SHA384_INCLUDE    ${PROJECT_SOURCE_DIR}/lib/hash/include/hash/sha384.h)
set(SHA384_SOURCE     ${PROJECT_SOURCE_DIR}/lib/hash/src/sha384.cpp)
set(SHA512_INCLUDE    ${PROJECT_SOURCE_DIR}/lib/hash/include/hash/sha512.h)
set(SHA512_SOURCE     ${PROJECT_SOURCE_DIR}/lib/hash/src/sha512.cpp)

if(EXISTS ${HASH_ROOT_INCLUDE})
    message(STATUS "CHECK>  Hash static lib root include found")
else()
    message(FATAL "FATAL>  In folder ./lib/hash/include/hash: hash4cxx.h not found, cannot build Hash static lib")
endif()
# check hash4cxx.h

if(EXISTS ${MD5_INCLUDE} AND EXISTS ${MD5_SOURCE})
    message(STATUS "CHECK>  MD5 Module found")
else()
    message(STATUS "CHECK>  MD5 Module not found")
endif()
# check md5 module

if(EXISTS ${SHA1_INCLUDE} AND EXISTS ${SHA1_SOURCE})
    message(STATUS "CHECK>  SHA1 Module found")
else()
    message(STATUS "CHECK>  SHA1 Module not found")
endif()
# check sha1 module

if(EXISTS ${SHA224_INCLUDE} AND EXISTS ${SHA224_SOURCE})
    message(STATUS "CHECK>  SHA224 Module found")
else()
    message(STATUS "CHECK>  SHA224 Module not found")
endif()
# check sha224 module

if(EXISTS ${SHA256_INCLUDE} AND EXISTS ${SHA256_SOURCE})
    message(STATUS "CHECK>  SHA256 Module found")
else()
    message(STATUS "CHECK>  SHA256 Module not found")
endif()
# check sha256 module

if(EXISTS ${SHA384_INCLUDE} AND EXISTS ${SHA384_SOURCE})
    message(STATUS "CHECK>  SHA384 Module found")
else()
    message(STATUS "CHECK>  SHA384 Module not found")
endif()
# check sha384 module

if(EXISTS ${SHA512_INCLUDE} AND EXISTS ${SHA512_SOURCE})
    message(STATUS "CHECK>  SHA512 Module found \n")
else()
    message(STATUS "CHECK>  SHA512 Module not found \n")
endif()
# check sha512 module