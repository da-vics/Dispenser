#ifndef _SERVICES_H
#define _SERVICES_H

enum class Identifier {
  ServiceCold = 1,
  ServiceHot
};

enum class ServicePriority {
  Null = 0,
  coldService,
  hotService
};

#endif
