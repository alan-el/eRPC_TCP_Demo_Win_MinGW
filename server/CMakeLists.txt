cmake_minimum_required(VERSION 3.16)

project(eRPC_MatrixMutiplyServer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(eRPC_DemoServer
    app/main.cpp
    app/erpc_matrix_multiply.h
    app/erpc_matrix_multiply_server.cpp
    app/erpc_matrix_multiply_server.h
    config/erpc_config.h
    infra/erpc_basic_codec.cpp
    infra/erpc_basic_codec.h
    infra/erpc_client_server_common.h
    infra/erpc_codec.h
    infra/erpc_common.h
    infra/erpc_crc16.cpp
    infra/erpc_crc16.h
    infra/erpc_framed_transport.cpp
    infra/erpc_framed_transport.h
    infra/erpc_manually_constructed.h
    infra/erpc_message_buffer.cpp
    infra/erpc_message_buffer.h
    infra/erpc_server.cpp
    infra/erpc_server.h
    infra/erpc_simple_server.cpp
    infra/erpc_simple_server.h
    infra/erpc_transport.h
    infra/erpc_version.h
    port/erpc_config_internal.h
    port/erpc_port.h
    port/erpc_port_stdlib.cpp
    port/erpc_threading.h
    port/erpc_threading_win32.cpp
    setup/erpc_mbf_setup.h
    setup/erpc_server_setup.cpp
    setup/erpc_server_setup.h
    setup/erpc_setup_mbf_dynamic.cpp
    setup/erpc_setup_tcp.cpp
    setup/erpc_transport_setup.h
    transports/erpc_tcp_transport.cpp
    transports/erpc_tcp_transport.h)

set(ERPC_INCLUDE_PATH
    config/
    infra/
    port/
    setup/
    transports/)

target_include_directories(eRPC_DemoServer
    PRIVATE ${ERPC_INCLUDE_PATH})

set(WIN_SOCK_LIB "D:/Qt/Tools/mingw1120_64/x86_64-w64-mingw32/lib/libws2_32.a")

target_link_libraries(eRPC_DemoServer PRIVATE
    ${WIN_SOCK_LIB})
