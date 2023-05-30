//
// Created by Christian Haase on 30/05/2023.
//

#include "SomeClass.h"
#include "Logging.h"
namespace evr
{

SomeClass::SomeClass() { EVR_RTLOG_DEBUG (LogRegion::Engine, "Some class created"); }

} // namespace evr