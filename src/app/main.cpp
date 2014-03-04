#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include "person.h"
#include "company.h"

#include "log4qtdemoengine.h"

int main(int argc, char *argv[])
{
    initLogging();
    Person billGates("Bill Gates");
    Person stevenElop("Steven Elop");
    Company microsoft("Microsoft");
    microsoft.setCeo(&billGates);
    microsoft.setCeo(&stevenElop);
    return 0;
}
