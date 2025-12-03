#ifndef NotificationManager_HPP
#define NotificationManager_HPP
#include <iostream>

class NotificationManager{
    public:
    void notifyExpirationDateApproaching();
    void notifyExpiredProducts();
    void notifyAddedProduct();
    void notifyRemovedProduct();
};
#endif