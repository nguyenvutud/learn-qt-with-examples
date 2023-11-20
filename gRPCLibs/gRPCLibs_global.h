#ifndef GRPCLIBS_GLOBAL_H
#define GRPCLIBS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GRPCLIBS_LIBRARY)
#  define GRPCLIBS_EXPORT Q_DECL_EXPORT
#else
#  define GRPCLIBS_EXPORT Q_DECL_IMPORT
#endif

#endif // GRPCLIBS_GLOBAL_H
