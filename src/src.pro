TEMPLATE = subdirs

#app is just a small wrapper for testability, i.e. for testing engine's objects
# without the need to link/compile-in everything
SUBDIRS = engine app

CONFIG += ordered
