TEMPLATE = subdirs

SUBDIRS = cppTests qmlTests

# Not to build qmlTests if cppTests fail to be built
CONFIG += ordered
