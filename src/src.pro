TEMPLATE = subdirs

# Engine supplies c++ objects (tested in the cppTests)
# App provides QMLs (tested in qmlTests) and wires c++/qml together
SUBDIRS = engine app

CONFIG += ordered
