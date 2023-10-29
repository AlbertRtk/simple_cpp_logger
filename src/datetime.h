#ifndef DATETIME_H
#define DATETIME_H

#include "scl_types.h"

namespace datetime {
SCL_ULong GetTimestampNow();
SCL_String GetDateTimeNow();
SCL_String GetTimeNow();
}  // namespace datetime

#endif  // DATETIME_H
