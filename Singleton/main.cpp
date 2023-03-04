#include "ECSManager.h"

int main () {

    auto ECSInstance1 = ECSManager::GetInstance();
    auto ECSInstance2 = ECSManager::GetInstance();
    return 0;
}
