#pragma once

#include <boost/shared_ptr.hpp>
#include <Core/System/ISimVars.h>

class IPropertyReader
{
  public:
    IPropertyReader() {}
    virtual ~IPropertyReader() {}

    virtual void readInitialValues(boost::shared_ptr<ISimVars> sim_vars) = 0;
};
