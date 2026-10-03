TEMPLATE = app
CONFIG += console c++17 link_pkgconfig
CONFIG -= app_bundle
CONFIG -= qt

# Linux 下用 pkg-config 找系统 OpenCV（原来这里是 D:/Opencv/opencv_3.4.2_Qt，
# 那是 Windows 的路径，在 Linux 上不存在）
PKGCONFIG += opencv4

SOURCES += main.cpp
