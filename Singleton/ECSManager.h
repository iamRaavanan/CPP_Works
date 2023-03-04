#ifndef ECSMANAGER_H
#define ECSMANAGER_H
#include <memory>
#include <mutex>

class ECSManager {
private:
    static std::shared_ptr<ECSManager> instance;
    static std::mutex mInstance;
    ECSManager();

public:
    static std::shared_ptr<ECSManager> GetInstance();
}
#endif