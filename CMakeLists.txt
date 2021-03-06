project(game.moonlight)

cmake_minimum_required(VERSION 2.6)
enable_language(CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR})

ADD_SUBDIRECTORY(lib/moonlight)

find_package(kodi           REQUIRED)
find_package(kodiplatform   REQUIRED)
find_package(platform       REQUIRED)
find_package(OpenSSL        REQUIRED)
find_package(CURL           REQUIRED)
find_package(Opus           REQUIRED)

include_directories(
        ${INCLUDES}
        ${platform_INCLUDE_DIRS}
        ${kodiplatform_INCLUDE_DIRS}
        ${OPENSSL_INCLUDE_DIRS}
        ${KODI_INCLUDE_DIR}
        ${CURL_INCLUDE_DIR}
        ${OPUS_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/lib/pugixml/src
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/lib/moonlight/limelight-common)

list(APPEND DEPLIBS
            ${kodiplatform_LIBRARIES}
            ${platform_LIBRARIES}
            ${OPENSSL_LIBRARIES}
            ${CURL_LIBRARIES}
            ${OPUS_LIBRARIES}
            moonlight)

set(MOONLIGHT_SOURCES   
        src/MoonlightClient.cpp
        src/MoonlightEnvironment.cpp
        src/input/InputManager.cpp
        src/log/Log.cpp
        src/log/LogAddon.cpp
        src/log/LogConsole.cpp
        src/log/LogSyslog.cpp
        src/nvstream/CertKeyPair.cpp
        src/nvstream/NvApp.cpp
        src/nvstream/NvHTTP.cpp
        src/nvstream/PairingManager.cpp
        src/nvstream/http.c
        src/settings/Resolution.cpp
        src/settings/Settings.cpp
        src/callbacks/VideoCallbacks.cpp
        src/callbacks/ConnectionCallbacks.cpp
        src/callbacks/AudioCallbacks.cpp
        lib/pugixml/src/pugixml.cpp)


# build standalone
set(STANDALONE_SOURCES ${MOONLIGHT_SOURCES} src/main.cpp)
add_executable(moonlight_client ${STANDALONE_SOURCES})
target_link_libraries(moonlight_client ${DEPLIBS})

# build addon
set(ADDON_SOURCES ${MOONLIGHT_SOURCES} src/addon.cpp)
build_addon(game.moonlight ADDON DEPLIBS)

include(CPack)
