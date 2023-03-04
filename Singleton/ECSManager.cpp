#include "ECSManager.h"
#include <iostream>

std::shared_ptr<ECSManager> ECSManager::instance(nullptr);
std::mutex ECSManager::mInstance;

ECSManager::ECSManager () {
    std::cout << "Instance created" << std::endl;
}

shared_ptr<ECSManager> ECSManager::GetInstance () {
    std::lock_guard<std::mutex> lock(mInstance);
    if(instance == nullptr) {
        std::shared_ptr<ECSManager> tempInstance(new ECSManager());
        tempInstance.swap(instance);
    }
    return instance;
}
