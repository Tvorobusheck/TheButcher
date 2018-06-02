TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG += qt

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0

SUBDIRS = TheButcher Test_TheButcher #закаменть Test_TheButcher

CONFIG += ordered
