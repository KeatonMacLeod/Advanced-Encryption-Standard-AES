cmake_minimum_required(VERSION 3.12)
project(CryptographyScripts)

set(CMAKE_CXX_STANDARD 14)

add_executable(CryptographyScripts main.cpp s_box.h s_box.cpp s_box_inverse.h s_box_inverse.cpp utility.cpp utility.h plaintext.cpp plaintext.h key.cpp key.h aes.cpp aes.h cipher.cpp cipher.h cipher_inverse.cpp cipher_inverse.h state.cpp state.h display.cpp display.h)