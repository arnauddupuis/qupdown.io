#ifndef LIBQUPDOWNIO_GLOBAL_H
#define LIBQUPDOWNIO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBQUPDOWNIO_LIBRARY)
#  define LIBQUPDOWNIOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBQUPDOWNIOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBQUPDOWNIO_GLOBAL_H
